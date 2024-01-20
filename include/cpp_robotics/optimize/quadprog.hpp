#pragma once

#include <cmath>
#include <tuple>
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
            double rho_init = 0.1;
            double sigma = 1e-6;
            double alpha = 1.6;
            double tol_abs = 1e-3;
            double tol_rel = 1e-3;
            bool use_indirect_method = true;
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
        }
        if(method_ == Method::ADMM)
        {
            m_eq = prob_.Aeq.rows();
            m_ineq = prob_.A.rows();
            m_b = prob_.lb.size();
            m = m_eq + m_ineq + m_b; // 制約の数
            // rho_eq_bound_scale = Eigen::VectorXd::Ones(m);

            A_bar = Eigen::MatrixXd(m, n);
            z_lb = Eigen::VectorXd(m);
            z_ub = Eigen::VectorXd(m);

            if(m_eq > 0)
            {
                A_bar.block(0,0,m_eq,n) = Aeq;
                z_lb.segment(0,m_eq) = beq;
                z_ub.segment(0,m_eq) = beq;
                // rho_eq_bound_scale.segment(0,m_eq) = Eigen::VectorXd::Constant(m_eq, 1e3);
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

            // rho_eq_bound_scale_inv = Eigen::VectorXd(m);
            // for(size_t i = 0; i < m; i++)
            // {
                // rho_eq_bound_scale_inv(i) = 1.0 / rho_eq_bound_scale(i);
            // }
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
        const auto [interior_point_param, admm_param, max_iter] = param;
        auto &Q = prob_.Q;
        auto &c = prob_.c;
        auto &Aeq = prob_.Aeq;
        auto &beq = prob_.beq;
        // auto &A = prob_.A;
        // auto &b = prob_.b;
        auto &lb = prob_.lb;
        auto &ub = prob_.ub;

        Result result;

        // 変数のサイズ
        const size_t m = Aeq.rows();
        const size_t l = A_bar.rows();
        Eigen::VectorXd x = x0;

        double rho = l; // 不等式制約の平均相補性残差
        Eigen::VectorXd s = Eigen::VectorXd::Ones(l); // 不等式制約のスラック変数
        Eigen::VectorXd u = Eigen::VectorXd::Ones(l); // 不等式制約のラグランジュ乗数
        Eigen::VectorXd v = Eigen::VectorXd::Zero(m); // 等式制約のラグランジュ乗数
        Eigen::VectorXd foom = grad_lagrange(x, u, v); // KKT条件1次の最適性

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
        const auto [interior_point_param, admm_param, max_iter] = param;
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

        bool update_M = true;
        for(size_t i = 0; i < max_iter; i++)
        {
            // Eigen::MatrixXd rho_mat = rho_eq_bound_scale.asDiagonal() * rho;
            // Eigen::MatrixXd rho_mat_inv = (Eigen::MatrixXd)(rho_eq_bound_scale_inv.asDiagonal()) / rho;
            if(admm_param.use_indirect_method)
            {
                // 間接法(勾配共役法)
                M = Q + sigma*Eigen::MatrixXd::Identity(n,n) + rho*A_bar.transpose()*A_bar;
                B = sigma*x - c + A_bar.transpose()*(rho*z - y);
                cg.compute(M);
                x_tilde = cg.solve(B);
                z_tilde = A_bar*x_tilde;
            }
            else
            {
                // 直接法
                if(update_M)
                {
                    M.setZero();
                    M.block(0,0,n,n) = Q + sigma*Eigen::MatrixXd::Identity(n,n);
                    M.block(n,0,m,n) = A_bar;
                    M.block(0,n,n,m) = A_bar.transpose();
                    M.block(n,n,m,m) = -1.0/rho*Eigen::MatrixXd::Identity(m,m);
                    M_ldlt.compute(M);
                    update_M = false;
                }
                B.head(n) = sigma*x - c;
                B.tail(m) = z-y/rho;

                auto linopt = M_ldlt.solve(B);
                x_tilde = linopt.head(n);
                nu = linopt.tail(m);
                z_tilde = z + (nu-y)/rho;
            }

            x = alpha*x_tilde + (1.0-alpha)*x;
            new_z = alpha*z_tilde + (1.0-alpha)*z + y/rho;
            // Euclidean projection
            for(size_t i = 0; i < m; i++)
            {
                if(new_z(i) <= z_lb(i))
                {
                    new_z(i) = z_lb(i);
                }
                if(z_ub(i) <= new_z(i))
                {
                    new_z(i) = z_ub(i);
                }
            }
            y += rho*(alpha*z_tilde + (1.0-alpha)*z - new_z);
            z = new_z;

            // 収束判定
            r_prim = A_bar*x - z;
            r_dual = Q*x + c + A_bar.transpose()*y;
            double r_prim_inf_norm = r_prim.cwiseAbs().maxCoeff();
            double r_dual_inf_norm = r_dual.cwiseAbs().maxCoeff();
            double rel_prim_val = std::max((A_bar*x).cwiseAbs().maxCoeff(), z.cwiseAbs().maxCoeff());
            double rel_dual_val = std::max({(Q*x).cwiseAbs().maxCoeff(), (A_bar.transpose()*y).cwiseAbs().maxCoeff(), c.cwiseAbs().maxCoeff()});
            if(r_prim_inf_norm < admm_param.tol_abs + admm_param.tol_rel*rel_prim_val && 
                r_dual_inf_norm < admm_param.tol_abs + admm_param.tol_rel*rel_dual_val)
            {
                result.is_solved = true;
                result.x = x;
                // Todo ラグランジュ定数を返す
                // result.lambda_ineq = nu;
                // result.lambda_eq = Eigen::VectorXd::Zero(m_eq);
                result.iter_cnt = i;
                return result;
            }

            // update rho
            double rho_scale = sqrt( (r_prim_inf_norm/rel_prim_val) / (r_dual_inf_norm/rel_dual_val) );
            rho *= rho_scale;
            constexpr double rho_scale_threshold = 5.0;
            if(rho_scale > rho_scale_threshold || rho_scale < 1.0/rho_scale_threshold)
            {
                update_M = true;
            }
        }

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
    size_t m; // 制約の数
    
    Eigen::MatrixXd A_bar;
    Eigen::VectorXd z_lb, z_ub;
    // Eigen::VectorXd rho_eq_bound_scale, rho_eq_bound_scale_inv;

    Eigen::VectorXd x;
    Eigen::VectorXd z;  // A*x
    Eigen::VectorXd y;  // 双対変数
    Eigen::VectorXd nu; // 制約のラグランジュ乗数
    Eigen::VectorXd new_z, z_tilde, x_tilde, B;
    Eigen::VectorXd r_prim, r_dual;
    Eigen::MatrixXd M;
    Eigen::LDLT<Eigen::MatrixXd> M_ldlt;
    Eigen::ConjugateGradient<Eigen::MatrixXd/*, Eigen::Lower|Eigen::Upper*/> cg;
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