#pragma once

#include <cmath>
#include <tuple>
#include <functional>
#include <Eigen/Dense>
// #include <unsupported/Eigen/IterativeSolvers>
#include <cassert>
#include "constraint.hpp"
#include "derivative.hpp"
#include "bracketing_serach.hpp"

namespace cpp_robotics
{

// min 1/2 x^T Q x + c^T x
// s.t. Aeq x = b, Ax <= b

/**
 * @brief 線形等式制約と線形不等式制約を持つ2次計画法
 * 
 */
class QuadProg
{
public:
    Eigen::MatrixXd Q;
    Eigen::VectorXd c;
    Eigen::MatrixXd Aeq;
    Eigen::VectorXd beq;
    Eigen::MatrixXd A;
    Eigen::VectorXd b;
    
    struct Param
    {
        // ステップに対する収束条件
        double tol_step = 1e-6;

        // 制約に対する収束条件
        double tol_con = 1e-6;

        // ゲイン
        double t = 0.5;

        // 最大反復回数
        size_t max_iter = 100;

        bool print_variable = false;
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

    void set_problem_size(const size_t valiable_size, const size_t ineq_constraint_size, const size_t eq_constraint_size)
    {
        Q.conservativeResize(valiable_size, valiable_size);
        c.conservativeResize(valiable_size);
        Aeq.conservativeResize(eq_constraint_size, valiable_size);
        beq.conservativeResize(eq_constraint_size);
        A.conservativeResize(ineq_constraint_size, valiable_size);
        b.conservativeResize(ineq_constraint_size);
    }

    void debug_prog()
    {
        std::cout << "///// debug /////" << std::endl;
        std::cout << "Q" << std::endl;
        std::cout << Q << std::endl;
        std::cout << "c" << std::endl;
        std::cout << c << std::endl;
        std::cout << "Aeq" << std::endl;
        std::cout << Aeq << std::endl;
        std::cout << "beq" << std::endl;
        std::cout << beq << std::endl;
        std::cout << "A" << std::endl;
        std::cout << A << std::endl;
        std::cout << "b" << std::endl;
        std::cout << b << std::endl;
        
    }

    Result solve(Eigen::VectorXd x_init)
    {
        const auto [tol_step, tol_con, t, max_iter, print_variable] = param;
        Result result;
        // Size check
        assert(Q.rows() == Q.cols());
        assert(c.rows() == Q.rows());
        assert(x_init.size() == Q.rows());

        // 変数のサイズ
        const size_t n = Q.rows(); 

        if(Aeq.rows() != 0)
        {
            assert(Aeq.cols() == (int)n);
            assert(Aeq.rows() == beq.rows());
        }
        const size_t m = Aeq.rows();

        if(A.rows() != 0)
        {
            assert(A.cols() == (int)n);
            assert(A.rows() == b.rows());
        }
        const size_t l = A.rows();

        auto preprossesing = [&]()
        {
            for(int i = 0; i < Aeq.rows(); i++)
            {
                if(not Aeq.row(i).allFinite() || not std::isfinite(beq(i)))
                {
                    Aeq.row(i).setZero();
                    beq(i) = 0;
                }
            }
            for(int i = 0; i < A.rows(); i++)
            {
                if(not A.row(i).allFinite() || not std::isfinite(b(i)))
                {
                    A.row(i).setZero();
                    b(i) = 0;
                }
            }
        };
        preprossesing();

        Eigen::VectorXd x(n);

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
                P.block(0, n+l, n, l) = A.transpose();
                P.block(n,0,l,n) = A;
                P.block(n,n,l,l) = Eigen::MatrixXd::Identity(l,l);
                P.block(n+l, n, l,l) = u.asDiagonal();
                P.block(n+l, n+l, l,l) = s.asDiagonal();

                r.segment(0,n) += A.transpose() * u;
                r.segment(n,l) = A*x - b + s;
                r.segment(n+l,l) = -rho*Eigen::VectorXd::Ones(l) + Eigen::VectorXd(u.array()*s.array());
            }

            // 等式制約
            if(m>0)
            {
                P.block(n + 2*l, 0, m, n) = Aeq;
                P.block(0, n + 2*l, n, m) = Aeq.transpose();

                r.segment(0,n) += Aeq.transpose() * v;
                r.segment(n+2*l,m) = Aeq*x - beq;
            }

            // 連立一次方程式を解く
            Eigen::VectorXd delta = P.fullPivLu().solve(-r);
            
            Eigen::VectorXd dx = delta.segment(0,n);
            Eigen::VectorXd ds = delta.segment(n,l);
            Eigen::VectorXd du = delta.segment(n+l,l);
            Eigen::VectorXd dv = delta.segment(n+2*l,m);
            
            if(print_variable)
            {
                std::cout << "//////////////// " << i << std::endl;
                std::cout << "x" << std::endl;
                std::cout << x << std::endl;
                std::cout << "dx" << std::endl;
                std::cout << dx << std::endl;
                std::cout << "s" << std::endl;
                std::cout << s << std::endl;
                std::cout << "ds" << std::endl;
                std::cout << ds << std::endl;
                std::cout << "u" << std::endl;
                std::cout << u << std::endl;
                std::cout << "du" << std::endl;
                std::cout << du << std::endl;
                std::cout << "v" << std::endl;
                std::cout << v << std::endl;
                std::cout << "dv" << std::endl;
                std::cout << dv << std::endl;
            }
            
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

    double evaluate(const Eigen::VectorXd &x)
    {
        return 0.5*(x.transpose()*Q).dot(x) + c.dot(x);
    }

    Eigen::VectorXd grad_lagrange(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const Eigen::VectorXd &v)
    {
        Eigen::VectorXd gl;
        gl = Q*x + c;
        
        if(u.size() > 0)
            gl += A.transpose()*u;
            
        if(v.size() > 0)
            gl += Aeq.transpose()*v;
        return gl;
    }

    bool satisfy(const Eigen::MatrixXd &x, double eps = 1e-5)
    {
        bool satisfy = true;

        if(Aeq.rows())
        {
            Eigen::VectorXd d = Aeq*x - beq;
            for(Eigen::MatrixXd::Index i = 0; i < d.size(); i++)
            {
                if(eps < std::abs(d(i)))
                    satisfy = false;
            }
        }

        if(A.rows())
        {
            Eigen::VectorXd d = A*x - b;
            for(Eigen::MatrixXd::Index i = 0; i < d.size(); i++)
            {
                if(eps < d(i))
                    satisfy = false;
            }
        }
        
        return satisfy;
    }
};

}