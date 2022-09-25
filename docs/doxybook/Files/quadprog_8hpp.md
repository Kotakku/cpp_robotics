---
title: include/cpp_robotics/optimize/quadprog.hpp

---

# include/cpp_robotics/optimize/quadprog.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::QuadProg](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1QuadProg/)**  |
| struct | **[cpp_robotics::QuadProg::Param](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1QuadProg_1_1Param/)**  |
| struct | **[cpp_robotics::QuadProg::Result](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1QuadProg_1_1Result/)**  |




## Source code

```cpp
#pragma once

#include <cmath>
#include <tuple>
#include <functional>
#include <Eigen/Dense>
#include <cassert>
#include "constraint.hpp"
#include "derivative.hpp"
#include "bracketing_serach.hpp"

namespace cpp_robotics
{

// 2次計画法
// min 1/2 x^T Q x + c^T x
// s.t. Aeq x = b, Ax <= b
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

        // メリット関数の制約にかかる重み
        double eta = 0.1;

        // 直線探索の囲い込み法におけるステップごとの更新倍率
        double beta = 0.9;

        // rhoゲイン
        double t = 0.5;

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
        const auto [tol_step, tol_con, eta, beta, t, max_iter] = param;
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

        Eigen::VectorXd x(n);

        double rho = 1; // 不等式制約に使用する
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

                r.segment(n,l) = A*x - b + s;
                r.segment(n+l,l) = -rho*Eigen::VectorXd::Ones(l) + Eigen::VectorXd(u.array()*s.array());
            }

            // 等式制約
            if(m>0)
            {
                P.block(n + 2*l, 0, m, n) = Aeq;
                P.block(0, n + 2*l, n, m) = Aeq.transpose();

                r.segment(n+2*l,m) = Aeq*x - beq;
            }

            // 連立一次方程式を解く
            Eigen::VectorXd delta = P.fullPivLu().solve(-r);
            Eigen::VectorXd dx = delta.segment(0,n);
            Eigen::VectorXd ds = delta.segment(n,l);
            Eigen::VectorXd du = delta.segment(n+l,l);
            Eigen::VectorXd dv = delta.segment(n+2*l,m);
            // ステップ幅の決定
            // Todo: ステップ幅の初期値を絞る
            const double max_alpha = std::min({1.0, 1.0});
            double alpha = bracketing_serach([&](double alpha)
            {
                return evaluate_merit(x + alpha*dx, s + alpha*ds, rho, eta);
            }, max_alpha, beta);

            // 更新
            x += dx;
            if(l>0)
            {
                s += ds;
                u += du;
            }
            if(m>0)
            {
                v += dv;
            }

            // メリット関数のパラメータ更新
            if(l>0)
            {
                rho = t * (u.dot(s)) / l;
            }

            // Todo 最適性と制約をチェックする
            Eigen::VectorXd new_foom = grad_lagrange(x, u, v);
            if(dx.norm() <= tol_step*(1.0+x.norm())) // && (new_foom - foom).norm() <= tol_con*(1.0+foom.norm()))
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

    double evaluate_merit(const Eigen::VectorXd &x, const Eigen::VectorXd &s, const double rho, const double eta)
    {
        double val = evaluate(x);
        
        for(int i = 0; i < s.rows(); i++)
        {
            val += rho*std::log(s(i));
        }

        Eigen::VectorXd v = A*x-b+s;
        for(int i = 0; i < v.rows(); i++)
        {
            val += eta*std::log(std::abs(v(i)));
        }

        Eigen::VectorXd veq = Aeq*x-beq;
        for(int i = 0; i < veq.rows(); i++)
        {
            val += eta*std::log(std::abs(veq(i)));
        }
        return val;
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
};

}
```


-------------------------------

Updated on 2022-09-25 at 23:29:49 +0900
