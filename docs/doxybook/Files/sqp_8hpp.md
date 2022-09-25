---
title: include/cpp_robotics/optimize/sqp.hpp

---

# include/cpp_robotics/optimize/sqp.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::SQP](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SQP/)**  |
| struct | **[cpp_robotics::SQP::Problem](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SQP_1_1Problem/)**  |
| struct | **[cpp_robotics::SQP::Result](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SQP_1_1Result/)**  |




## Source code

```cpp
#pragma once

#include <functional>
#include <cmath>
#include <Eigen/Dense>
#include "./constraint.hpp"
#include "./bracketing_serach.hpp"
#include "./bfgs.hpp"
#include "./quasi_newton_method.hpp"
#include "./quadprog.hpp"

namespace cpp_robotics
{

// SQP(逐次二次計画法)
class SQP
{
public:
    using func_type = std::function<double(Eigen::VectorXd)>;

    struct Problem
    {
        func_type func;
        ConstraintArray con;

        double tol_step = 1e-6;
        double tol_con = 1e-6;
        size_t max_iter = 10;
    };

    struct Result
    {
        bool is_solved = false;
        Eigen::VectorXd x;
        // Eigen::VectorXd lambda_opt;
        size_t iter_cnt = 0;
    };

    Result solve(Problem prob, const Eigen::VectorXd &x0, std::optional<std::function<void(Eigen::VectorXd)>> callback)
    {
        Result result;

        // 制約がない時, 準ニュートン法で解く
        if(prob.con.size() == 0)
        {
            std::tie(result.is_solved, result.x, result.iter_cnt) = 
                quasi_newton_method(prob.func, [&](const Eigen::VectorXd &x){ return derivative(prob.func, x); }, x0, 1e-6, prob.max_iter);
            return result;
        }

        Eigen::VectorXd x = x0;
        Eigen::MatrixXd B = Eigen::MatrixXd::Identity(x.rows(), x.rows());
        Eigen::VectorXd grad_L = Eigen::VectorXd::Zero(x.rows());

        // Todo: x0が実行不可能な場合実行可能領域まで移動させる

        // 制約
        auto eq_con = prob.con.gen_eq_constraint_list();
        auto ineq_con = prob.con.gen_ineq_constraint_list();

        // サブ問題の2次計画問題のソルバー
        QuadProg qp_solver;
        qp_solver.set_problem_size(x.size(), ineq_con.size(), eq_con.size());

        // 直線探索用メリット関数の制約重み
        // Todo: 初期値
        // const double df0_norm = derivative(prob.func, x).norm();
        Eigen::VectorXd eq_mw   = Eigen::VectorXd::Ones(eq_con.size());
        Eigen::VectorXd ineq_mw = Eigen::VectorXd::Ones(ineq_con.size());
        // for(size_t i = 0; i < eq_con.size(); i++)
        // {
        //     eq_mw(i) /= eq_con[i].grad(x).norm();
        // }
        // for(size_t i = 0; i < ineq_con.size(); i++)
        // {
        //     ineq_mw(i) /= std::min(ineq_con[i].grad(x).norm(), 10e3);
        // }

        for(size_t i = 1; i < prob.max_iter+1; i++)
        {
            // 探索方向の決定
            // サブの問題設定
            qp_solver.Q = B;
            qp_solver.c = derivative(prob.func, x).transpose();

            // 等式制約の一次近似
            for(size_t con_i = 0; con_i < eq_con.size(); con_i++)
            {
                qp_solver.Aeq.row(con_i) = eq_con[con_i].grad(x).transpose();
                qp_solver.beq(con_i) = -eq_con[con_i].eval(x);
            }

            // 不等式制約の一次近似
            for(size_t con_i = 0; con_i < ineq_con.size(); con_i++)
            {
                qp_solver.A.row(con_i) = ineq_con[con_i].grad(x).transpose();
                qp_solver.b(con_i) = -ineq_con[con_i].eval(x);
            }

            std::cout << "//////////" << std::endl;
            // std::cout << "x" << std::endl;
            // std::cout << x << std::endl;
            // qp_solver.debug_prog();


            // サブの2次計画問題を解く
            auto sub_result = qp_solver.solve(x);
            if(not sub_result.is_solved)
            {
                result.is_solved = false;
                result.iter_cnt = i;
                result.x = x;
                // result.lambda_opt = sub_result.lambda_opt;
                std::cout << "cant solve sub qp" << std::endl;
                return result;
            }
            auto d = sub_result.x;

            std::cout << "d" << std::endl;
            std::cout << d << std::endl;

            // ステップ幅の決定
            // 直線探索
            auto merit_func = [&](const Eigen::VectorXd &x)
            {
                double val = prob.func(x);

                // 等式制約
                for(size_t con_i = 0; con_i < eq_con.size(); con_i++)
                {
                    val += eq_mw(con_i) * std::abs(eq_con[con_i].eval(x));
                }

                // 不等式制約
                for(size_t con_i = 0; con_i < ineq_con.size(); con_i++)
                {
                    val += ineq_mw(con_i) * std::max(ineq_con[con_i].eval(x), 0.0);
                }

                return val;
            };
            double alpha = bracketing_serach(merit_func, [&](const Eigen::VectorXd &x){ return derivative(merit_func, x); }, x, d);
            // std::cout << "alpha" << std::endl;
            // std::cout << alpha << std::endl;

            if(callback)
                callback.value()(x);
            x += alpha * d;


            // 収束判定
            if(d.norm() < prob.tol_step && prob.con.all_satisfy(x, prob.tol_con))
            {
                result.is_solved = true;
                result.iter_cnt = i;
                result.x = x;
                return result;
            }

            std::cout << "ineq_mw" << std::endl;
            std::cout << ineq_mw << std::endl;


            // メリット関数の重み更新
            for(size_t con_i = 0; con_i < eq_con.size(); con_i++)
            {
                eq_mw(con_i) = std::max(eq_mw(con_i), 0.5*(eq_mw(con_i) + sub_result.lambda_eq(con_i)));
            }
            for(size_t con_i = 0; con_i < ineq_con.size(); con_i++)
            {
                ineq_mw(con_i) = std::max(ineq_mw(con_i), 0.5*(ineq_mw(con_i) + sub_result.lambda_ineq(con_i)));
            }

            // 解の保存
            result.x = x;
            result.iter_cnt = i;

            // ラグランジュ関数の勾配の変化量
            Eigen::VectorXd delta_grad_L = -grad_L;
            grad_L = derivative(prob.func, x);
            if(ineq_con.size() > 0)
                grad_L += qp_solver.A.transpose() * sub_result.lambda_ineq;
            if(eq_con.size() > 0)
                grad_L += qp_solver.Aeq.transpose() * sub_result.lambda_eq;
            delta_grad_L += grad_L;

            // std::cout << "test =" << std::endl;
            // std::cout << grad_L  << std::endl;

            // Bマトリクスの更新
            powells_modified_bfgs_step(B, alpha*d, delta_grad_L);

            if(B.array().isNaN().any())
            {
                std::cout << "NaNが存在します" << std::endl;
                break;
            }
        }

        return result;
    }

private:
    template <typename Mat>
    bool is_posdef(Mat H)
    {
        Eigen::EigenSolver<Mat> eigensolver(H);
        for (int i = 0; i < eigensolver.eigenvalues().rows(); i++) {
            double v = eigensolver.eigenvalues()(i).real();
            if (v <= 0) {
                return false;
            }
        }
        return true;
    }
};

}
```


-------------------------------

Updated on 2022-09-25 at 23:20:39 +0900
