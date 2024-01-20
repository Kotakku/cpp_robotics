#pragma once

#include <cmath>
#include <tuple>
#include <functional>
#include <Eigen/Dense>
#include <cassert>
#include "constraint.hpp"
#include "derivative.hpp"
#include "bracketing_serach.hpp"
#include "newton_method.hpp"

#include <iostream>

#define debug(x) // std::cout << __func__ << ": " << x << std::endl;
// #define debug2(x) std::cout << __func__ << ": " << x << std::endl;
#define debug_mat(x) std::cout << #x << std::endl << x << std::endl;

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
        // ステップに対する収束条件
        double tol_step = 1e-6;

        // 制約に対する収束条件
        double tol_con = 1e-6;

        // ゲイン
        double t = 0.5;

        struct
        {
            double rho_init = 0.1;
            double sigma = 1e-6;
            double alpha = 1.6;
            double eps_abs = 1e-4;
            double eps_rel = 1e-3;
        }admm;

        // 最大反復回数
        size_t max_iter = 100;
    };
    Param param;

    struct Result
    {
        bool is_solved = false;
        Eigen::VectorXd x;
        Eigen::VectorXd lambda_ineq;
        Eigen::VectorXd lambda_eq;
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

        if(method_ == Method::InteriorPointMethod)
        {
            debug("1");
            m_eq = prob_.Aeq.rows();
            m_b = prob_.lb.size();
            size_t m_original_ineq = prob_.A.rows();
            m_ineq = m_original_ineq + 2*m_b;
            
            m = m_eq + m_ineq; // 制約の数

            A_bar = Eigen::MatrixXd(m_ineq, n);
            z_ub = Eigen::VectorXd(m_ineq);

            if(m_ineq > 0)
            {
                A_bar.block(0,0,m_original_ineq,n) = A;
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
                A_bar.block(m_original_ineq,0,m_b,n) = -Ilb;
                A_bar.block(m_original_ineq+m_b,0,m_b,n) = Iub;
                z_ub.segment(m_original_ineq,m_b) = -lb_tmp;
                z_ub.segment(m_original_ineq+m_b,m_b) = ub_tmp;
            }
            debug("2");
        }
        if(method_ == Method::ADMM)
        {
            m_eq = prob_.Aeq.rows();
            m_ineq = prob_.A.rows();
            m_b = prob_.lb.size();
            m = m_eq + m_ineq + m_b; // 制約の数
            rho_eq_bound_scale = Eigen::VectorXd::Ones(m);

            debug("1");
            A_bar = Eigen::MatrixXd(m, n);
            z_lb = Eigen::VectorXd(m);
            z_ub = Eigen::VectorXd(m);

            if(m_eq > 0)
            {
                A_bar.block(0,0,m_eq,n) = Aeq;
                z_lb.segment(0,m_eq) = beq;
                z_ub.segment(0,m_eq) = beq;
                rho_eq_bound_scale.segment(0,m_eq) = Eigen::VectorXd::Constant(m_eq, 1e3);
            }
            if(m_ineq > 0)
            {
                A_bar.block(m_eq,0,m_ineq,n) = A;
                z_lb.segment(m_eq,m_ineq) = Eigen::VectorXd::Constant(m_ineq, -huge_value);
                z_ub.segment(m_eq,m_ineq) = b;
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
                }
                A_bar.block(m_eq+m_ineq,0,m_b,n) = I;
                z_lb.segment(m_eq+m_ineq,m_b) = lb_tmp;
                z_ub.segment(m_eq+m_ineq,m_b) = ub_tmp;
            }

            rho_eq_bound_scale_inv = Eigen::VectorXd(m);
            for(size_t i = 0; i < m; i++)
            {
                rho_eq_bound_scale_inv(i) = 1.0 / rho_eq_bound_scale(i);
            }
            debug("2");
        }
    }

    double evaluate(const Eigen::VectorXd &x)
    {
        return 0.5*(x.transpose()*prob_.Q).dot(x) + prob_.c.dot(x);
    }

    bool satisfy(const Eigen::MatrixXd &x, double eps = 1e-2)
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

        // 制約がない場合はニュートン法で解く
        if(m == 0)
        {
            Result result;
            std::tie(result.is_solved, result.x, result.iter_cnt) = 
                newton_method([&](Eigen::VectorXd x)->Eigen::VectorXd{ return prob_.Q*x + prob_.c; }, 
                    [&](auto)->Eigen::MatrixXd{ return prob_.Q; }, x0, 1e-6, param.max_iter);
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
        const auto [tol_step, tol_con, t, admm_param, max_iter] = param;
        auto &Q = prob_.Q;
        auto &c = prob_.c;
        auto &Aeq = prob_.Aeq;
        auto &beq = prob_.beq;
        // auto &A = prob_.A;
        // auto &b = prob_.b;
        auto &lb = prob_.lb;
        auto &ub = prob_.ub;

        Result result;

        debug("start");
        // 変数のサイズ
        const size_t m = Aeq.rows();
        const size_t l = A_bar.rows();
        

        // auto preprossesing = [&]()
        // {
        //     for(int i = 0; i < Aeq.rows(); i++)
        //     {
        //         if(not Aeq.row(i).allFinite() || not std::isfinite(beq(i)))
        //         {
        //             Aeq.row(i).setZero();
        //             beq(i) = 0;
        //         }
        //     }
        //     for(int i = 0; i < A.rows(); i++)
        //     {
        //         if(not A.row(i).allFinite() || not std::isfinite(b(i)))
        //         {
        //             A.row(i).setZero();
        //             b(i) = 0;
        //         }
        //     }
        // };
        // preprossesing();

        debug("setup workspace");

        Eigen::VectorXd x = x0;

        double rho = l; // 不等式制約の平均相補性残差
        Eigen::VectorXd s = Eigen::VectorXd::Ones(l); // 不等式制約のスラック変数
        Eigen::VectorXd u = Eigen::VectorXd::Ones(l); // 不等式制約のラグランジュ乗数
        Eigen::VectorXd v = Eigen::VectorXd::Zero(m); // 等式制約のラグランジュ乗数
        Eigen::VectorXd foom = grad_lagrange(x, u, v); // KKT条件1次の最適性

        debug("start loop");
        for(size_t i = 0; i < max_iter; i++)
        {
            Eigen::MatrixXd P = Eigen::MatrixXd::Zero(n + 2*l + m, n + 2*l + m);
            Eigen::VectorXd r = Eigen::VectorXd::Zero(n + 2*l + m);

            P.block(0,0,n,n) = Q;
            r.segment(0,n) = Q*x + c;

            // 不等式制約
            if(l>0)
            {
                P.block(0, n+l, n, l) = A_bar.transpose();
                P.block(n,0,l,n) = A_bar;
                P.block(n,n,l,l) = Eigen::MatrixXd::Identity(l,l);
                P.block(n+l, n, l,l) = u.asDiagonal();
                P.block(n+l, n+l, l,l) = s.asDiagonal();

                r.segment(0,n) += A_bar.transpose() * u;
                r.segment(n,l) = A_bar*x - z_ub + s;
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
                rho = t * (u.dot(s)) / l;
            }
            if(m>0)
            {
                v += dv;
            }

            // Todo 最適性と制約をチェックする
            Eigen::VectorXd new_foom = grad_lagrange(x, u, v);
            if(dx.norm() <= tol_step*(1.0+x.norm()) && (new_foom - foom).norm() <= tol_con*(1.0+foom.norm()))
            {
                result.is_solved = true;
                result.x = x;
                result.lambda_ineq = u;
                result.lambda_eq = v;
                result.iter_cnt = i;
                return result;
            }
            foom = new_foom;
        }

        result.is_solved = false;
        result.x = x;
        result.lambda_ineq = u;
        result.lambda_eq = v;
        result.iter_cnt = max_iter;
        return result;
    }

    Eigen::VectorXd grad_lagrange(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const Eigen::VectorXd &v)
    {
        Eigen::VectorXd gl;
        gl = prob_.Q*x + prob_.c;
        
        if(u.size() > 0)
            gl += A_bar.transpose()*u;
            
        if(v.size() > 0)
            gl += prob_.Aeq.transpose()*v;
        return gl;
    }

    Result solve_admm_based_method(Eigen::VectorXd x0)
    {
        const auto [tol_step, tol_con, t, admm_param, max_iter] = param;
        auto &Q = prob_.Q;
        auto &c = prob_.c;
        auto &Aeq = prob_.Aeq;
        auto &beq = prob_.beq;
        auto &A = prob_.A;
        auto &b = prob_.b;
        auto &lb = prob_.lb;
        auto &ub = prob_.ub;

        Result result;

        // 変数のサイズ
        double rho = admm_param.rho_init;
        const double sigma = admm_param.sigma;
        const double alpha = admm_param.alpha;

        assert(rho > 0);
        assert(sigma > 0);
        assert(alpha > 0 && alpha < 2.0);

        Eigen::VectorXd x = x0;
        Eigen::VectorXd z(m);  // A*x
        Eigen::VectorXd y(m);  // 双対変数
        Eigen::VectorXd nu;    // 制約のラグランジュ乗数
        Eigen::VectorXd new_z, z_tilde, x_tilde, B(n+m);
        Eigen::VectorXd r_prim, r_dual;

        z.setZero();
        y.setZero();

        Eigen::MatrixXd M(n+m, n+m);
        bool update_M = true;

        debug("start loop");

        for(size_t i = 0; i < max_iter; i++)
        {
            Eigen::MatrixXd rho_mat = rho_eq_bound_scale.asDiagonal() * rho;
            Eigen::MatrixXd rho_mat_inv = (Eigen::MatrixXd)(rho_eq_bound_scale_inv.asDiagonal()) / rho;
            if(update_M)
            {
                debug("update M");
                M.setZero();
                M.block(0,0,n,n) = Q + sigma*Eigen::MatrixXd::Identity(n,n);
                M.block(n,0,m,n) = A_bar;
                M.block(0,n,n,m) = A_bar.transpose();
                M.block(n,n,m,m) = -rho_mat_inv;
                M = M.inverse();
                update_M = false;
            }
            B.head(n) = sigma*x - c;
            B.tail(m) = z-rho_mat_inv*y;

            debug("solve linear system");

            auto linopt = M*B;
            x_tilde = linopt.head(n);
            nu = linopt.tail(m);

            debug("update x, z, y");

            z_tilde = z + rho_mat_inv*(nu-y);
            x = alpha*x_tilde + (1.0-alpha)*x;
            new_z = alpha*z_tilde + (1.0-alpha)*z + rho_mat_inv*y;
            // Euclidean projection
            for(size_t i = 0; i < m; i++)
            {
                debug("check");
                if(new_z(i) <= z_lb(i))
                {
                    debug("project lb(" << i << "): " << new_z(i) << " -> " << z_lb(i));
                    new_z(i) = z_lb(i);
                }
                if(z_ub(i) <= new_z(i))
                {
                    debug("project ub(" << i << "): " << new_z(i) << " -> " << z_ub(i));
                    new_z(i) = z_ub(i);
                }
            }
            y += rho_mat*(alpha*z_tilde + (1.0-alpha)*z - new_z);
            z = new_z;

            debug("check convergence");

            // 収束判定
            r_prim = A_bar*x - z;
            r_dual = Q*x + c + A_bar.transpose()*y;
            double r_prim_inf_norm = r_prim.cwiseAbs().maxCoeff();
            double r_dual_inf_norm = r_dual.cwiseAbs().maxCoeff();
            double rel_prim_val = std::max((A_bar*x).cwiseAbs().maxCoeff(), z.cwiseAbs().maxCoeff());
            double rel_dual_val = std::max({(Q*x).cwiseAbs().maxCoeff(), (A_bar.transpose()*y).cwiseAbs().maxCoeff(), c.cwiseAbs().maxCoeff()});
            if(r_prim_inf_norm < admm_param.eps_abs + admm_param.eps_rel*rel_prim_val && 
                r_dual_inf_norm < admm_param.eps_abs + admm_param.eps_rel*rel_dual_val)
            {
                debug("success");
                result.is_solved = true;
                result.x = x;
                // result.lambda_ineq = nu;
                // result.lambda_eq = Eigen::VectorXd::Zero(m_eq);
                result.iter_cnt = i;
                return result;
            }

            debug("update rho");
            // update rho
            double rho_scale = sqrt( (r_prim_inf_norm/rel_prim_val) / (r_dual_inf_norm/rel_dual_val) );
            rho *= rho_scale;
            constexpr double rho_scale_threshold = 5.0;
            if(rho_scale > rho_scale_threshold || rho_scale < 1.0/rho_scale_threshold)
            {
                update_M = true;
            }
        }

        debug("failed");
        result.is_solved = false;
        result.x = x;
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
    // size_t m_ub;
    size_t m; // 制約の数
    
    Eigen::MatrixXd A_bar;
    Eigen::VectorXd z_lb, z_ub;
    Eigen::VectorXd rho_eq_bound_scale, rho_eq_bound_scale_inv;
};

}