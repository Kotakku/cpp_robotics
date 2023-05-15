#pragma once

#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <ginac/ginac.h>
#include "../utility/ginac_utils.hpp"

namespace cpp_robotics
{

struct LinkConfig
{
    using ex = GiNaC::ex;
    using symbol = GiNaC::symbol;
    using lst = GiNaC::lst;
    
    using VectorXex = Eigen::Matrix<ex,Eigen::Dynamic,1>;
    using Vector3ex = Eigen::Matrix<ex,3,1>;
    using Affine3ex = Eigen::Transform<ex,3,Eigen::Affine>;
    using Translation3ex = Eigen::Translation<ex,3>;
    using AngleAxisex = Eigen::AngleAxis<ex>;
    using Matrix3ex = Eigen::Matrix<ex, 3, 3>;

    enum class LinkType
    {
        RotationX,
        RotationY,
        RotationZ,
        // LinearX,
        // LinearY,
        // LinearZ
    };
    LinkType link_type;
    Eigen::Translation3d position; // 親リンクからの相対位置
    double mass;                   // 自リンクの質量
    Eigen::Translation3d link_com; // 自リンクの重心
    Eigen::Matrix3d I;             // 自リンクの慣性行列
    // std::optional<std::pair<double, double>> limit;

    // Eigen::Affine3d trans_matrix(double val) const 
    // {
    //     Eigen::Affine3d affine;
    //     switch(link_type)
    //     {
    //         case LinkType::RotationX:
    //             affine = Eigen::AngleAxisd(val, Eigen::Vector3d::UnitX()) * position;
    //             break;
    //         case LinkType::RotationY:
    //             affine = Eigen::AngleAxisd(val, Eigen::Vector3d::UnitY()) * position;
    //             break;
    //         case LinkType::RotationZ:
    //             affine = Eigen::AngleAxisd(val, Eigen::Vector3d::UnitZ()) * position;
    //             break;

    //         // case LinkType::LinearX:
    //         //     affine = position * Eigen::Translation3d(val, 0, 0);
    //         //     break;
    //         // case LinkType::LinearY:
    //         //     affine = position * Eigen::Translation3d(0, val, 0);
    //         //     break;
    //         // case LinkType::LinearZ:
    //         //     affine = position * Eigen::Translation3d(0, 0, val);
    //         //     break;
    //         default:
    //             affine = Eigen::Matrix3d::Identity();
    //     }

    //     return affine;
    // }
};

class LinkRobot
{
    using ex = GiNaC::ex;
    using symbol = GiNaC::symbol;
    using lst = GiNaC::lst;

    using VectorXex = Eigen::Matrix<ex,Eigen::Dynamic,1>;
    using Vector3ex = Eigen::Matrix<ex,3,1>;
    using Affine3ex = Eigen::Transform<ex,3,Eigen::Affine>;
    using Translation3ex = Eigen::Translation<ex,3>;
    using AngleAxisex = Eigen::AngleAxis<ex>;
    using Matrix3ex = Eigen::Matrix<ex, 3, 3>;
    using MatrixXex = Eigen::Matrix<ex,Eigen::Dynamic,Eigen::Dynamic>;

public:
    LinkRobot(std::vector<LinkConfig> &config):
        config_(config)
    {
        // GiNaC::Digits = 2;

        const size_t n = degree();
        //////////////////// symbols ////////////////////
        for(size_t i = 0; i < n; i++)
        {
            symbols_.push_back(symbol("q"+std::to_string(i+1)));
            dsymbols_.push_back(symbol("dq"+std::to_string(i+1), "\\dot{q"+std::to_string(i+1)+"}"));
            ddsymbols_.push_back(symbol("ddq"+std::to_string(i+1), "\\ddot{q"+std::to_string(i+1)+"}"));
        }

        auto trans_matrix = [](const LinkConfig &config, ex val) -> Affine3ex 
        {
            Affine3ex affine;

            auto position_ex = config.position.cast<ex>();
            switch(link_type)
            {
                case LinkType::RotationX:
                    affine = AngleAxisex(val, Vector3ex::UnitX()) * position_ex;
                    break;
                case LinkType::RotationY:
                    affine = AngleAxisex(val, Vector3ex::UnitY()) * position_ex;
                    break;
                case LinkType::RotationZ:
                    affine = AngleAxisex(val, Vector3ex::UnitZ()) * position_ex;
                    break;

                // case LinkType::LinearX:
                //     affine = position_ex * Translation3ex(val, 0, 0);
                //     break;
                // case LinkType::LinearY:
                //     affine = position_ex * Translation3ex(0, val, 0);
                //     break;
                // case LinkType::LinearZ:
                //     affine = position_ex * Translation3ex(0, 0, val);
                //     break;
                default:
                    affine = Matrix3ex::Identity();
            }

            return affine;
        };

        auto rot = [](const LinkConfig &config, ex val) -> Matrix3ex
        {
            Affine3ex affine;
            switch(config.link_type)
            {
                case LinkType::RotationX:
                    affine = AngleAxisex(val, Vector3ex::UnitX());
                    break;
                case LinkType::RotationY:
                    affine = AngleAxisex(val, Vector3ex::UnitY());
                    break;
                case LinkType::RotationZ:
                    affine = AngleAxisex(val, Vector3ex::UnitZ());
                    break;
                default:
                    affine = Matrix3ex::Identity();
            }
            return affine.matrix().block(0,0,3,3);
        };

        auto axis = [&](const LinkConfig &config) -> Vector3ex
        {
            switch (config.link_type)
            {
                case LinkConfig::LinkType::RotationX:
                    return Vector3ex::UnitX();
                    break;
                case LinkConfig::LinkType::RotationY:
                    return Vector3ex::UnitY();
                    break;
                case LinkConfig::LinkType::RotationZ:
                    return Vector3ex::UnitZ();
                    break;
                default:
                    return Vector3ex::Zero();
            }
        };

        //////////////////// forward kinematics ////////////////////
        forward_kinematics_ex_ = Vector3ex::Zero();
        for(size_t i = 0; i < n; i++)
        {
            auto &config = config_[i];
            auto q = symbols_[i];
            auto af = trans_matrix(config, q);
            forward_kinematics_ex_ = af*forward_kinematics_ex_;
        }

        //////////////////// jacobian ////////////////////
        jacobian_.resize(forward_kinematics_ex_.rows(), degree());
        for(int r = 0; r < jacobian_.rows(); r++)
        {
            auto &p = forward_kinematics_ex_[r];
            for(int c = 0; c < jacobian_.cols(); c++)
            {
                jacobian_(r, c) = p.diff(symbols_[c]);
                // std::cout << jacobian_(r, c) << ",\t";
            }
            // std::cout << std::endl;
        }

        //////////////////// dynamics ////////////////////
        // step2
        std::vector<Vector3ex>  w(n+1);  // 角速度
        std::vector<Vector3ex> dw(n+1); // 角加速度
        std::vector<Vector3ex> dv(n+1); // 加速度

        std::vector<Vector3ex> fvec(n+1); // 
        std::vector<Vector3ex> nvec(n+1); // 

        w[0].setZero();
        dw[0].setZero();

        symbol g("g");
        dv[0] << 0, g, 0; // Todo

        fvec.back().setZero();
        nvec.back().setZero();

        // Todo: configから生成する
        std::vector<Vector3ex> p_hat;//
        p_hat.reserve(n+1);
        p_hat.push_back(Vector3ex::Zero());
        for(size_t i = 0; i < n ; i++)
        {
            config_[i].position.vector().cast<ex>();
        }

        for(size_t i = 0; i < n; i++)
        {
            // printf("////////////////////////\n");

            auto &q = symbols_[i];
            auto &dq = dsymbols_[i];
            auto &ddq = ddsymbols_[i];
            Matrix3ex RT = config_[i].rot(q).transpose();
            auto axisq = axis(config_[i]); 
            
            w[i+1]  = RT*w[i] + axisq * dq; // Todo
            dw[i+1] = RT*dw[i] + axisq * ddq; // Todo
            dv[i+1] = RT*( dv[i] + dw[i].cross(p_hat[i]) + w[i].cross(w[i].cross(p_hat[i])) );
            simplify_indexed(dv[i+1]);

            // cout_exmat(w[i+1].transpose().eval(), std::string("w"));
            // cout_exmat(dw[i+1].transpose().eval(), "dw");
            // cout_exmat(dv[i+1].eval(), "dv");
        }

        // Todo: configから生成する
        std::vector<Vector3ex> p_hat_ii;
        p_hat_ii.reserve(n+1);
        p_hat_ii.push_back(Vector3ex::Zero());
        for(size_t i = 0; i < n; i++)
        {

        }

        p_hat_ii = 
        {
            {0,0,0},
            {cos(symbols_[1]),-sin(symbols_[1]),0}, // {symbol("L1")*cos(symbols_[1]),-symbol("L1")*sin(symbols_[1]),0},
            {0,0,0},
        };
        
        tau_.resize(n);
        for(size_t ri = 0; ri < n; ri++)
        {
            size_t i = n-1-ri;
            auto &q = symbols_[i];
            auto &dq = dsymbols_[i];
            auto &ddq = ddsymbols_[i];
            auto m = config_[i].mass;
            auto s = config_[i].link_com.vector().cast<ex>().eval();
            auto I = config_[i].I.cast<ex>().eval();
            auto R = rot(config_[i], q);
            auto &w_ = w[i+1];
            auto &dw_ = dw[i+1];
            auto &dv_ = dv[i+1];

            fvec[i] = m*dv_ + dw_.cross(m*s) + w_.cross(w_.cross(m*s)) + R*fvec[i+1];
            nvec[i] = I*dw_ + w_.cross(I*w_) + (m*s).cross(dv_) + R*(p_hat_ii[i+1].cross(fvec[i+1]) + nvec[i+1]);
            tau_[i] = Vector3ex(0,0,1).dot(nvec[i]);
        }

        Hq_.resize(n,n);
        gq_.resize(n);
        cq_ = tau_;
        for(size_t r = 0; r < n; r++)
        {
            gq_[r] = tau_[r].collect(g).coeff(g);
            cq_[r] -= gq_[r]*g;

            for(size_t c = 0; c < n; c++)
            {
                Hq_(r, c) = tau_[r].collect(ddsymbols_[c]).coeff(ddsymbols_[c]);
                cq_[r] -= Hq_(r, c)*ddsymbols_[c];
            }
        }

        simplify_indexed(Hq_);
        simplify_indexed(cq_);
        simplify_indexed(gq_);

        // cout_exmat(Hq_, "H");
        // cout_exmat(cq_, "c");
        // cout_exmat(gq_, "g");

    }

    void show_dynamics()
    {
        std::cout << "////////// dynamics //////////" << std::endl;
        std::cout << "tau = H(q)*ddq + c(q, dq) + g(q)*g" << std::endl << std::endl;
        std::cout << "where" << std::endl;
        cout_exmat(Hq_, "H(q)");
        cout_exmat(cq_, "c(q, dq)");
        cout_exmat(gq_, "g(g)");
    }

    size_t degree() const
    {
        return config_.size();
    }
    
    Eigen::Vector3d forward_kinematics(Eigen::VectorXd joint_param)
    {
        lst q;
        for(size_t i = 0; i < degree(); i++)
        {
            q.append(symbols_[i]==joint_param[i]);
        }
        
        Eigen::Vector3d pos;
        for(size_t i = 0; i < 3; i++)
        {
            pos[i] = GiNaC::ex_to<GiNaC::numeric>(forward_kinematics_ex_[i].subs(q)).to_double();
        }
        return pos;
    }

    Eigen::VectorXd inverse_kinematics(Eigen::Vector3d pos, Eigen::Vector3d euler_angle)
    {
        const size_t n = degree();

        Eigen::VectorXd q(n);

        return q;
    }

    // 順運動学問題
    // A \\ddot(q) + b = \tau
    // return A, b
    std::tuple<Eigen::MatrixXd, Eigen::VectorXd> forward_dynamics_matrix(Eigen::VectorXd pos, Eigen::VectorXd vel)
    {
        const size_t n = degree();
        Eigen::MatrixXd A(n,n);
        Eigen::VectorXd c(n);
        Eigen::VectorXd g(n);

        lst exlst;
        for(size_t i = 0; i < n; i++)
        {
            exlst.append(symbols_[i] == pos[i]);
            exlst.append(dsymbols_[i] == vel[i]);
        }

        MatrixXex tmp;
        
        tmp = Hq_;
        subs(tmp, exlst);

        to_double_matrix(tmp, A);

        tmp = cq_;
        subs(tmp, exlst);
        to_double_matrix(tmp, c);

        tmp = gq_;
        subs(tmp, exlst);
        to_double_matrix(tmp, g);

        return {A, c+g*9.81};
    }

    // 一般化座標での位置・速度・加速度から一般化力を求める
    Eigen::VectorXd dynamics(Eigen::VectorXd pos, Eigen::VectorXd vel, Eigen::VectorXd acc)
    {
        auto [A, b] = forward_dynamics_matrix(pos, vel);
        return A*acc + b;
    }

    Eigen::VectorXd forward_dynamics(Eigen::VectorXd pos, Eigen::VectorXd vel, Eigen::VectorXd force)
    {
        const size_t n = degree();
        auto [A, b] = forward_dynamics_matrix(pos, vel);
        return A.fullPivLu().solve(force - b); // Todo
    }

private:
    std::vector<LinkConfig> &config_;

    std::vector<symbol> symbols_;
    std::vector<symbol> dsymbols_;
    std::vector<symbol> ddsymbols_;
    
    Vector3ex forward_kinematics_ex_;
    MatrixXex jacobian_;

    // 運動方程式
    VectorXex tau_;
    MatrixXex Hq_;
    VectorXex cq_;
    VectorXex gq_;
};

}