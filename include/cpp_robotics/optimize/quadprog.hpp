#pragma once

#include <cmath>
#include <tuple>
#include <vector>
#include <functional>
#include <Eigen/Dense>
#include <Eigen/IterativeLinearSolvers>
#include <cassert>
#include "constraint.hpp"
#include "derivative.hpp"
#include "bracketing_serach.hpp"
#include "newton_method.hpp"

namespace cpp_robotics
{

// min 1/2 x^T Q x + c^T x
// s.t. Aeq x = b, Ax <= b, lb <= x <= ub

struct QuadProgProblem
{
    Eigen::MatrixXd Q;
    Eigen::VectorXd c;
    Eigen::MatrixXd Aeq;
    Eigen::VectorXd beq;
    Eigen::MatrixXd A;
    Eigen::VectorXd b;
    Eigen::VectorXd lb;
    Eigen::VectorXd ub;

    void set_problem_size(const size_t valiable_size, const size_t ineq_constraint_size, const size_t eq_constraint_size, bool exit_bound)
    {
        Q.conservativeResize(valiable_size, valiable_size);
        c.conservativeResize(valiable_size);
        Aeq.conservativeResize(eq_constraint_size, valiable_size);
        beq.conservativeResize(eq_constraint_size);
        A.conservativeResize(ineq_constraint_size, valiable_size);
        b.conservativeResize(ineq_constraint_size);
        if(exit_bound)
        {
            lb.conservativeResize(valiable_size);
            ub.conservativeResize(valiable_size);
        }
    }
};

/**
 * @brief 線形等式制約と線形不等式制約を持つ2次計画法
 * 
 */
class QuadProg
{
public:
    constexpr static double huge_value = 1e6;
    struct Param
    {
        struct
        {
            // ステップに対する収束条件
            double tol_step = 1e-6;

            // 制約に対する収束条件
            double tol_con = 1e-6;

            // ゲイン
            double t = 0.5;
        }interior_point;

        struct
        {
            double tol_abs = 1e-3;
            double tol_rel = 1e-3;
            double sigma = 1e-6;
            double rho_init = 0.1;
            double alpha = 1.6;
            bool use_indirect_method = true;
            size_t max_equil_iter = 100;
            double eps_equil = 1e-6;
        }admm;

        // 最大反復回数
        size_t max_iter = 300;
    };
    Param param;

    struct Result
    {
        bool is_solved = false;
        Eigen::VectorXd x;
        Eigen::VectorXd lambda_ineq;
        Eigen::VectorXd lambda_eq;
        Eigen::VectorXd lambda_lb;
        Eigen::VectorXd lambda_ub;
        size_t iter_cnt = 0;
    };

    enum class Method
    {
        InteriorPointMethod,
        ADMM,
    };

    QuadProg(Method method = Method::ADMM):
        method_(method){}

    QuadProg(const QuadProgProblem &prob, Method method = Method::ADMM):
        method_(method)
    {
        set_problem(prob);
    }

    void set_problem(const QuadProgProblem &prob)
    {
        prob_ = prob;

        assert(prob_.Q.rows() == prob_.Q.cols());
        assert(prob_.c.rows() == prob_.Q.rows());
        n = prob_.Q.rows(); 

        if(prob_.Aeq.rows() != 0)
        {
            assert(prob_.Aeq.cols() == (int)n);
            assert(prob_.Aeq.rows() == prob_.beq.rows());
        }
        if(prob_.A.rows() != 0)
        {
            assert(prob_.A.cols() == (int)n);
            assert(prob_.A.rows() == prob_.b.rows());
        }
        if(prob_.lb.size() != 0)
        {
            assert(prob_.lb.size() == (int)n);
        }
        assert(prob_.ub.size() == prob_.lb.size());

        // setup workspace
        auto &Q = prob_.Q;
        auto &c = prob_.c;
        auto &Aeq = prob_.Aeq;
        auto &beq = prob_.beq;
        auto &A = prob_.A;
        auto &b = prob_.b;
        auto &lb = prob_.lb;
        auto &ub = prob_.ub;

        // 有効な制約のインデックスを確認
        valid_eq_con_idx.clear();
        valid_ineq_con_idx.clear();
        for(int i = 0; i < Aeq.rows(); i++)
        {
            // 0
            if(Aeq.row(i).cwiseAbs().maxCoeff() == 0)
                continue;

            // inf, nan
            if((Aeq.row(i).array().isNaN()|| Aeq.row(i).array().isInf()).any())
                continue;
            
            valid_eq_con_idx.push_back(i);
        }
        for(int i = 0; i < A.rows(); i++)
        {
            // 0
            if(A.row(i).cwiseAbs().maxCoeff() == 0)
                continue;

            // inf, nan
            if((A.row(i).array().isNaN()|| A.row(i).array().isInf()).any())
                continue;
            
            valid_ineq_con_idx.push_back(i);
        }

        auto extract_matrix = [&](auto from, auto to, const std::vector<size_t> &idxs)
        {
            for(size_t i = 0; i < idxs.size(); i++)
            {
                to.row(i) = from.row(idxs[i]);
            }
        };

        if(method_ == Method::InteriorPointMethod)
        {
            m_eq = prob_.Aeq.rows();
            m_b = prob_.lb.size();
            size_t m_original_ineq = prob_.A.rows();
            m_ineq = m_original_ineq + 2*m_b;
            
            m = m_eq + m_ineq; // 制約の数

            A_all = Eigen::MatrixXd(m_ineq, n);
            z_ub = Eigen::VectorXd(m_ineq);

            if(m_ineq > 0)
            {
                A_all.block(0,0,m_original_ineq,n) = A;
                z_ub.segment(0,m_original_ineq) = b;
            }
            if(m_b > 0)
            {
                Eigen::MatrixXd Ilb = Eigen::MatrixXd::Identity(n,n);
                Eigen::MatrixXd Iub = Eigen::MatrixXd::Identity(n,n);
                Eigen::VectorXd lb_tmp = prob_.lb;
                Eigen::VectorXd ub_tmp = prob_.ub;
                for(size_t i = 0; i < n; i++)
                {
                    if(lb_tmp(i) <= -huge_value)
                    {
                        Ilb(i,i) = 0;
                        lb_tmp(i) = 0;
                    }
                    if(huge_value <= ub_tmp(i))
                    {
                        Iub(i,i) = 0;
                        ub_tmp(i) = 0;
                    }
                }
                A_all.block(m_original_ineq,0,m_b,n) = -Ilb;
                A_all.block(m_original_ineq+m_b,0,m_b,n) = Iub;
                z_ub.segment(m_original_ineq,m_b) = -lb_tmp;
                z_ub.segment(m_original_ineq+m_b,m_b) = ub_tmp;
            }
        }
        if(method_ == Method::ADMM)
        {
            m_eq = valid_eq_con_idx.size();
            m_ineq = valid_ineq_con_idx.size();
            m_b = prob_.lb.size();
            m = m_eq + m_ineq + m_b; // 制約の数

            A_all = Eigen::MatrixXd(m, n);
            z_lb = Eigen::VectorXd(m);
            z_ub = Eigen::VectorXd(m);
            rho_scale_vec = Eigen::VectorXd::Ones(m);

            if(m_eq > 0)
            {
                extract_matrix(Aeq, A_all.block(0,0,m_eq,n), valid_eq_con_idx);
                extract_matrix(beq, z_lb.segment(0,m_eq), valid_eq_con_idx);
                extract_matrix(beq, z_ub.segment(0,m_eq), valid_eq_con_idx);
                rho_scale_vec.segment(0,m_eq) = Eigen::VectorXd::Constant(m_eq, 1e3);
            }
            if(m_ineq > 0)
            {
                extract_matrix(A, A_all.block(m_eq,0,m_ineq,n), valid_ineq_con_idx);
                extract_matrix(b, z_ub.segment(m_eq,m_ineq), valid_ineq_con_idx);
                z_lb.segment(m_eq,m_ineq) = Eigen::VectorXd::Constant(m_ineq, -huge_value);
            }
            if(m_b > 0)
            {
                Eigen::MatrixXd I = Eigen::MatrixXd::Identity(n,n);
                Eigen::VectorXd lb_tmp = prob_.lb;
                Eigen::VectorXd ub_tmp = prob_.ub;
                for(size_t i = 0; i < n; i++)
                {
                    if(lb_tmp(i) <= -huge_value && huge_value <= ub_tmp(i))
                    {
                        I(i,i) = 0;
                        lb_tmp(i) = 0;
                        ub_tmp(i) = 0;
                    }
                    if(lb_tmp(i) == ub_tmp(i))
                    {
                        rho_scale_vec(i) = 1e3;
                    }
                }
                A_all.block(m_eq+m_ineq,0,m_b,n) = I;
                z_lb.segment(m_eq+m_ineq,m_b) = lb_tmp;
                z_ub.segment(m_eq+m_ineq,m_b) = ub_tmp;
            }
            if(0 < m)
                modified_ruiz_equilibration();
        }
    }

    double evaluate(const Eigen::VectorXd &x)
    {
        return 0.5*(x.transpose()*prob_.Q).dot(x) + prob_.c.dot(x);
    }

    bool satisfy(const Eigen::MatrixXd &x, double eps = 2e-2)
    {
        bool satisfy = true;

        if(m == 0)
            return true;

        if(prob_.Aeq.rows())
        {
            Eigen::VectorXd d = prob_.Aeq*x - prob_.beq;
            for(Eigen::MatrixXd::Index i = 0; i < d.size(); i++)
            {
                if(eps < std::abs(d(i)))
                    satisfy = false;
            }
        }

        if(prob_.A.rows())
        {
            Eigen::VectorXd d = prob_.A*x - prob_.b;
            for(Eigen::MatrixXd::Index i = 0; i < d.size(); i++)
            {
                if(eps < d(i))
                    satisfy = false;
            }
        }

        if(prob_.lb.size())
        {
            Eigen::VectorXd d = prob_.lb - x;
            for(Eigen::MatrixXd::Index i = 0; i < d.size(); i++)
            {
                if(eps < d(i))
                    satisfy = false;
            }
        }

        if(prob_.ub.size())
        {
            Eigen::VectorXd d = x - prob_.ub;
            for(Eigen::MatrixXd::Index i = 0; i < d.size(); i++)
            {
                if(eps < d(i))
                    satisfy = false;
            }
        }
        
        return satisfy;
    }

    Result solve()
    {
        Eigen::VectorXd x0 = Eigen::VectorXd::Zero(prob_.Q.rows());
        return solve(x0);
    }

    Result solve(Eigen::VectorXd x0)
    {
        // Size check
        assert(x0.size() == prob_.Q.rows());

        // 有効な制約がない場合はニュートン法で解く
        // 制約を設定しても全ての制約に無効な値を含む場合、制約がないものとして解く
        if(m == 0)
        {
            Result result;
            std::tie(result.is_solved, result.x, result.iter_cnt) = 
                newton_method([&](Eigen::VectorXd x)->Eigen::VectorXd{ return prob_.Q*x + prob_.c; }, 
                    [&](auto)->Eigen::MatrixXd{ return prob_.Q; }, x0, 1e-6, param.max_iter);
            result.lambda_eq.setZero(prob_.Aeq.rows());
            result.lambda_ineq.setZero(prob_.A.rows());
            return result;
        }

        if(method_ == Method::ADMM)
            return solve_admm_based_method(x0);
        else
            return solve_interior_point_method(x0);
    }

private:
    Result solve_interior_point_method(Eigen::VectorXd x0)
    {
        const auto [interior_point_param, admm_param, max_iter] = param;
        auto &Q = prob_.Q;
        auto &c = prob_.c;
        auto &Aeq = prob_.Aeq;
        auto &beq = prob_.beq;
        auto &lb = prob_.lb;
        auto &ub = prob_.ub;

        Result result;

        // 変数のサイズ
        const size_t m = Aeq.rows();
        const size_t l = A_all.rows();
        Eigen::VectorXd x = x0;

        double rho = l; // 不等式制約の平均相補性残差
        Eigen::VectorXd s = Eigen::VectorXd::Ones(l); // 不等式制約のスラック変数
        Eigen::VectorXd u = Eigen::VectorXd::Ones(l); // 不等式制約のラグランジュ乗数
        Eigen::VectorXd v = Eigen::VectorXd::Zero(m); // 等式制約のラグランジュ乗数
        Eigen::VectorXd foom = grad_lagrange(x, u, v); // KKT条件1次の最適性

        auto set_result_variables = [&]()
        {
            result.x = x;
            result.lambda_ineq = u.head(prob_.A.rows());
            result.lambda_eq = v;
            result.lambda_lb = u.segment(prob_.A.rows(), m_b);
            result.lambda_ub = u.segment(prob_.A.rows()+m_b, m_b);
        };

        for(size_t i = 0; i < max_iter; i++)
        {
            Eigen::MatrixXd P = Eigen::MatrixXd::Zero(n + 2*l + m, n + 2*l + m);
            Eigen::VectorXd r = Eigen::VectorXd::Zero(n + 2*l + m);

            P.block(0,0,n,n) = Q;
            r.segment(0,n) = Q*x + c;

            // 不等式制約
            if(l>0)
            {
                P.block(0, n+l, n, l) = A_all.transpose();
                P.block(n,0,l,n) = A_all;
                P.block(n,n,l,l) = Eigen::MatrixXd::Identity(l,l);
                P.block(n+l, n, l,l) = u.asDiagonal();
                P.block(n+l, n+l, l,l) = s.asDiagonal();

                r.segment(0,n) += A_all.transpose() * u;
                r.segment(n,l) = A_all*x - z_ub + s;
                r.segment(n+l,l) = -rho*Eigen::VectorXd::Ones(l) + Eigen::VectorXd(u.array()*s.array());
            }

            // 等式制約
            if(m>0)
            {
                P.block(n + 2*l, 0, m, n) = Aeq;
                P.block(0, n + 2*l, n, m) = Aeq.transpose();

                r.segment(0,n) += Aeq.transpose() * v;
                r.segment(n+2*l,m) = prob_.Aeq*x - prob_.beq;
            }

            // 連立一次方程式を解く
            Eigen::VectorXd delta = P.fullPivLu().solve(-r);
            
            Eigen::VectorXd dx = delta.segment(0,n);
            Eigen::VectorXd ds = delta.segment(n,l);
            Eigen::VectorXd du = delta.segment(n+l,l);
            Eigen::VectorXd dv = delta.segment(n+2*l,m);

            // 更新
            x += dx;
            if(l>0)
            {
                s += ds;
                u += du;
                rho = interior_point_param.t * (u.dot(s)) / l;
            }
            if(m>0)
            {
                v += dv;
            }

            // Todo 最適性と制約をチェックする
            Eigen::VectorXd new_foom = grad_lagrange(x, u, v);
            if(dx.norm() <= interior_point_param.tol_step*(1.0+x.norm()) && (new_foom - foom).norm() <= interior_point_param.tol_con*(1.0+foom.norm()))
            {
                result.is_solved = true;
                set_result_variables();
                result.iter_cnt = i;
                return result;
            }
            foom = new_foom;
        }

        result.is_solved = false;
        set_result_variables();
        result.iter_cnt = max_iter;
        return result;
    }

    Eigen::VectorXd grad_lagrange(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const Eigen::VectorXd &v)
    {
        Eigen::VectorXd gl;
        gl = prob_.Q*x + prob_.c;
        
        if(u.size() > 0)
            gl += A_all.transpose()*u;
            
        if(v.size() > 0)
            gl += prob_.Aeq.transpose()*v;
        return gl;
    }

    void modified_ruiz_equilibration()
    {
        auto &admm_param = param.admm;
        double c = 1.0;
        Eigen::MatrixXd S = Eigen::MatrixXd::Identity(n+m, n+m);
        Eigen::VectorXd delta = Eigen::VectorXd::Zero(n+m);
        double gamma;

        Q_bar = prob_.Q;
        c_bar = prob_.c;
        A_all_bar = A_all;
        z_lb_bar = z_lb;
        z_ub_bar = z_ub;

        Eigen::MatrixXd M(n+m, n+m);
        M.block(n,n,m,m) = Eigen::MatrixXd::Zero(m,m);

        for (size_t iter = 0; iter < admm_param.max_equil_iter; iter++)
        {
            M.block(0,0,n,n) = Q_bar;
            M.block(n,0,m,n) = A_all_bar;
            M.block(0,n,n,m) = A_all_bar.transpose();

            // M equilibration
            for (size_t i = 0; i < n+m; i++)
            {
                double cnorm = std::sqrt(M.col(i).cwiseAbs().maxCoeff());
                delta(i) = 1.0 / (cnorm);
            }

            auto delta_mat_n = delta.head(n).asDiagonal();
            auto delta_mat_m = delta.tail(m).asDiagonal();
            
            // Scale P, q, A, C using diag(delta)
            Q_bar = delta_mat_n * Q_bar * delta_mat_n;
            c_bar = delta_mat_n * c_bar;
            A_all_bar = delta_mat_m * A_all_bar * delta_mat_n;
            z_lb_bar = delta_mat_m * z_lb_bar;
            z_ub_bar = delta_mat_m * z_ub_bar;
            
            // Cost scaling
            double Pi_mean = 0.0;
            for(size_t i = 0; i < n; i++)
            {
                Pi_mean += (Q_bar.col(i).cwiseAbs().maxCoeff()) / static_cast<double>(n);
            }
            gamma = 1.0 / std::max(Pi_mean, c_bar.cwiseAbs().maxCoeff());
            Q_bar *= gamma;
            c_bar *= gamma;
            
            // Update S and c
            S = delta.asDiagonal() * S;
            c *= gamma;
            
            // Check for convergence
            if ((Eigen::VectorXd::Ones(n+m)-delta).cwiseAbs().maxCoeff() < admm_param.eps_equil)
                break;
        }
        D_diag = S.block(0,0,n,n).diagonal();
        E_diag = S.block(n,n,m,m).diagonal();
        D_inv_diag = D_diag.cwiseInverse();
        E_inv_diag = E_diag.cwiseInverse();
        ruiz_c = c;
    }

    Result solve_admm_based_method(Eigen::VectorXd x0)
    {
        const auto [interior_point_param, admm_param, max_iter] = param;
        Result result;

        // 変数のサイズ
        double rho = admm_param.rho_init;
        const double sigma = admm_param.sigma;
        const double alpha = admm_param.alpha;

        assert(rho > 0);
        assert(sigma > 0);
        assert(alpha > 0 && alpha < 2.0);

        auto &lb = prob_.lb;
        auto &ub = prob_.ub;
        x = x0;
        z.setZero(m);
        y.setZero(m);
        if(admm_param.use_indirect_method)
        {
            M.resize(n,n);
            B.resize(n);
        }
        else
        {
            M.resize(n+m, n+m);
            B.resize(n+m);
        }
        if(not satisfy(x) && (int)m_b == x.size())
        {
            for(size_t i = 0; i < m_b; i++)
            {
                if(x(i) < lb(i) || ub(i) < x(i))
                {
                    if(-huge_value < lb(i) && ub(i) < huge_value)
                    {
                        x(i) = (lb(i) + ub(i)) / 2.0;
                    }
                    else if(-huge_value < lb(i))
                    {
                        x(i) = lb(i);
                    }
                    else if(ub(i) < huge_value)
                    {
                        x(i) = ub(i);
                    }
                    else
                    {
                        x(i) = 0;
                    }
                }
            }
        }

        auto set_result_variables = [&]()
        {
            result.x = D_diag.asDiagonal()*x;
            Eigen::VectorXd original_y = 1.0/ruiz_c*E_diag.asDiagonal()*y;
            result.lambda_eq.setZero(prob_.Aeq.rows());
            for(size_t i = 0; i < valid_eq_con_idx.size(); i++)
            {
                result.lambda_eq(valid_eq_con_idx[i]) = original_y(i);
            }
            result.lambda_ineq.setZero(prob_.A.rows());
            for(size_t i = 0; i < valid_ineq_con_idx.size(); i++)
            {
                result.lambda_ineq(valid_ineq_con_idx[i]) = original_y(valid_eq_con_idx.size() + i);
            }
            Eigen::VectorXd lamda_bound = original_y.segment(valid_eq_con_idx.size()+valid_ineq_con_idx.size(), m_b);
            result.lambda_lb.setZero(m_b);
            result.lambda_ub.setZero(m_b);
            for(size_t i = 0; i < m_b; i++)
            {
                if(lamda_bound(i) < 0)
                {
                    result.lambda_lb(i) = -lamda_bound(i);
                }
                else
                {
                    result.lambda_ub(i) = lamda_bound(i);
                }
            }
        };

        x = D_inv_diag.asDiagonal() * x;
        bool update_M = true;
        for(size_t i = 0; i < max_iter; i++)
        {
            Eigen::MatrixXd rho_mat = rho * rho_scale_vec.asDiagonal();
            Eigen::MatrixXd rho_inv_mat = 1.0/rho * rho_scale_vec.cwiseInverse().asDiagonal().toDenseMatrix();
            if(admm_param.use_indirect_method)
            {
                // 間接法(勾配共役法)
                M = Q_bar + sigma*Eigen::MatrixXd::Identity(n,n) + A_all_bar.transpose()*rho_mat*A_all_bar;
                B = sigma*x - c_bar + A_all_bar.transpose()*(rho_mat*z - y);
                cg.compute(M);
                x_tilde = cg.solve(B);
                z_tilde = A_all_bar*x_tilde;
            }
            else
            {
                // 直接法
                if(update_M)
                {
                    M.setZero();
                    M.block(0,0,n,n) = Q_bar + sigma*Eigen::MatrixXd::Identity(n,n);
                    M.block(n,0,m,n) = A_all_bar;
                    M.block(0,n,n,m) = A_all_bar.transpose();
                    M.block(n,n,m,m) = -rho_inv_mat;
                    M_ldlt.compute(M);
                    update_M = false;
                }
                B.head(n) = sigma*x - c_bar;
                B.tail(m) = z-rho_inv_mat*y;

                auto linopt = M_ldlt.solve(B);
                x_tilde = linopt.head(n);
                nu = linopt.tail(m);
                z_tilde = z + rho_inv_mat*(nu-y);
            }

            x = alpha*x_tilde + (1.0-alpha)*x;
            new_z = alpha*z_tilde + (1.0-alpha)*z + rho_inv_mat*y;
            // Euclidean projection
            for(size_t i = 0; i < m; i++)
            {
                if(new_z(i) <= z_lb_bar(i))
                {
                    new_z(i) = z_lb_bar(i);
                }
                if(z_ub_bar(i) <= new_z(i))
                {
                    new_z(i) = z_ub_bar(i);
                }
            }
            y += rho_mat*(alpha*z_tilde + (1.0-alpha)*z - new_z);
            z = new_z;

            // 収束判定
            auto D_inv = D_inv_diag.asDiagonal();
            auto E_inv = E_inv_diag.asDiagonal();
            r_prim = E_inv*(A_all_bar*x - z);
            r_dual = 1.0/ruiz_c*D_inv*(Q_bar*x + c_bar + A_all_bar.transpose()*y);
            double r_prim_inf_norm = r_prim.cwiseAbs().maxCoeff();
            double r_dual_inf_norm = r_dual.cwiseAbs().maxCoeff();
            double rel_prim_val = std::max((E_inv*A_all_bar*x).cwiseAbs().maxCoeff(), (E_inv*z).cwiseAbs().maxCoeff());
            double rel_dual_val = 1.0/ruiz_c*std::max({(D_inv*Q_bar*x).cwiseAbs().maxCoeff(), (D_inv*A_all_bar.transpose()*y).cwiseAbs().maxCoeff(), (D_inv*c_bar).cwiseAbs().maxCoeff()});
            if(r_prim_inf_norm < admm_param.tol_abs + admm_param.tol_rel*rel_prim_val && 
                r_dual_inf_norm < admm_param.tol_abs + admm_param.tol_rel*rel_dual_val)
            {
                result.is_solved = true;
                set_result_variables();
                result.iter_cnt = i;
                return result;
            }

            // update rho
            constexpr double rho_scale_eps = 1e-8;
            double rho_scale = sqrt( ((r_prim_inf_norm+rho_scale_eps)/(rel_prim_val+rho_scale_eps)) / ((r_dual_inf_norm+rho_scale_eps)/(rel_dual_val+rho_scale_eps)) );
            rho *= rho_scale;
            constexpr double rho_scale_threshold = 5.0;
            if(rho_scale > rho_scale_threshold || rho_scale < 1.0/rho_scale_threshold)
            {
                update_M = true;
            }
        }

        result.is_solved = false;
        set_result_variables();
        result.iter_cnt = max_iter;
        return result;
    }

private:
    QuadProgProblem prob_;
    Method method_;

    size_t n; // 変数の数
    size_t m_eq;
    size_t m_ineq;
    size_t m_b;
    size_t m; // 制約の数
    
    std::vector<size_t> valid_eq_con_idx;
    std::vector<size_t> valid_ineq_con_idx;
    
    Eigen::MatrixXd A_all;
    Eigen::VectorXd z_lb, z_ub;

    Eigen::VectorXd x;
    Eigen::VectorXd z;  // A*x
    Eigen::VectorXd y;  // 双対変数
    Eigen::VectorXd nu; // 制約のラグランジュ乗数
    Eigen::VectorXd new_z, z_tilde, x_tilde, B;
    Eigen::VectorXd r_prim, r_dual;
    Eigen::MatrixXd M;
    Eigen::LDLT<Eigen::MatrixXd> M_ldlt;
    Eigen::ConjugateGradient<Eigen::MatrixXd> cg;
    Eigen::MatrixXd Q_bar, A_all_bar;
    Eigen::VectorXd c_bar, z_lb_bar, z_ub_bar;
    Eigen::VectorXd D_diag, D_inv_diag, E_diag, E_inv_diag;
    Eigen::VectorXd rho_scale_vec;
    double ruiz_c;
};


static QuadProg::Result quadprog(const QuadProgProblem &prob, const Eigen::VectorXd &x0, QuadProg::Method method = QuadProg::Method::ADMM)
{
    QuadProg qp(prob, method);
    return qp.solve(x0);
}

static QuadProg::Result quadprog(const Eigen::MatrixXd &Q, const Eigen::VectorXd &c, const Eigen::VectorXd &x0, QuadProg::Method method = QuadProg::Method::ADMM)
{
    QuadProgProblem prob;
    prob.set_problem_size(x0.size(), 0, 0, false);
    prob.Q = Q;
    prob.c = c;

    QuadProg qp(prob, method);
    return qp.solve(x0);
}

static QuadProg::Result quadprog(const Eigen::MatrixXd &Q, const Eigen::VectorXd &c, const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const Eigen::VectorXd &x0, QuadProg::Method method = QuadProg::Method::ADMM)
{
    QuadProgProblem prob;
    prob.set_problem_size(x0.size(), A.rows(), 0, false);
    prob.Q = Q;
    prob.c = c;
    prob.A = A;
    prob.b = b;

    QuadProg qp(prob, method);
    return qp.solve(x0);
}

static QuadProg::Result quadprog(const Eigen::MatrixXd &Q, const Eigen::VectorXd &c, const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const Eigen::MatrixXd &Aeq, const Eigen::VectorXd &beq, const Eigen::VectorXd &lb, const Eigen::VectorXd &ub, const Eigen::VectorXd &x0, QuadProg::Method method = QuadProg::Method::ADMM)
{
    QuadProgProblem prob;
    prob.set_problem_size(x0.size(), A.rows(), Aeq.rows(), true);
    prob.Q = Q;
    prob.c = c;
    prob.A = A;
    prob.b = b;
    prob.Aeq = Aeq;
    prob.beq = beq;
    prob.lb = lb;
    prob.ub = ub;

    QuadProg qp(prob, method);
    return qp.solve(x0);
}

static QuadProg::Result quadprog_ineq_con(const Eigen::MatrixXd &Q, const Eigen::VectorXd &c, const Eigen::MatrixXd &A, const Eigen::VectorXd &b, const Eigen::VectorXd &x0, QuadProg::Method method = QuadProg::Method::ADMM)
{
    QuadProgProblem prob;
    prob.set_problem_size(x0.size(), A.rows(), 0, false);
    prob.Q = Q;
    prob.c = c;
    prob.A = A;
    prob.b = b;

    QuadProg qp(prob, method);
    return qp.solve(x0);
}

static QuadProg::Result quadprog_eq_con(const Eigen::MatrixXd &Q, const Eigen::VectorXd &c, const Eigen::MatrixXd &Aeq, const Eigen::VectorXd &beq, const Eigen::VectorXd &x0, QuadProg::Method method = QuadProg::Method::ADMM)
{
    QuadProgProblem prob;
    prob.set_problem_size(x0.size(), 0, Aeq.rows(), false);
    prob.Q = Q;
    prob.c = c;
    prob.Aeq = Aeq;
    prob.beq = beq;

    QuadProg qp(prob, method);
    return qp.solve(x0);
}

static QuadProg::Result quadprog_bound_con(const Eigen::MatrixXd &Q, const Eigen::VectorXd &c, const Eigen::VectorXd &lb, const Eigen::VectorXd &ub, const Eigen::VectorXd &x0, QuadProg::Method method = QuadProg::Method::ADMM)
{
    QuadProgProblem prob;
    prob.set_problem_size(x0.size(), 0, 0, true);
    prob.Q = Q;
    prob.c = c;
    prob.lb = lb;
    prob.ub = ub;

    QuadProg qp(prob, method);
    return qp.solve(x0);
}

}