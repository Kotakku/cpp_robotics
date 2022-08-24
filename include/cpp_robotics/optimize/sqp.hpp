#pragma once

#include <functional>
#include <cmath>
#include <Eigen/Dense>
#include "./active_set_method.hpp"
#include "./constraint.hpp"
#include "./bracketing_serach.hpp"
#include "./bfgs.hpp"
#include "./quasi_newton_method.hpp"

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

        double tol = 1e-6;
        size_t max_iter = 1000;
    };

    struct Result
    {
        bool is_solved = false;
        Eigen::VectorXd x_opt;
        Eigen::VectorXd lambda_opt;
        size_t iter_cnt = 0;
    };

    Result solve(Problem prob, const Eigen::VectorXd &x_init)
    {
        Result result;

        // 制約がない時, 準ニュートン法で解く
        if(prob.con.size() == 0)
        {
            std::tie(result.is_solved, result.x_opt, result.iter_cnt) = 
                quasi_newton_method(prob.func, [&](const Eigen::VectorXd &x){ return derivative(prob.func, x); }, x_init, 1e-6, prob.max_iter);
            return result;
        }

        Eigen::VectorXd x = x_init;
        Eigen::MatrixXd B = Eigen::MatrixXd::Identity(x.rows(), x.rows()); //approx_hessian(prob.func, x);
        Eigen::VectorXd grad_L = Eigen::VectorXd::Zero(x.rows());

        // // ヘッセ行列が半正定じゃない時
        // if (!is_posdef(B)) {
        //     double tau = 1e-3;
        //     Eigen::VectorXd v = Eigen::VectorXd(x.rows());
        //     while (!is_posdef(B)) {
        //         v.setConstant(tau);
        //         B += v.asDiagonal();
        //         tau *= 10;
        //     }
        // }

        // サブ問題の2次計画問題のソルバー
        ActiveSetMethod asm_solver;

        // 制約
        auto eq_con = prob.con.gen_eq_constraint_list();
        auto ineq_con = prob.con.gen_ineq_constraint_list();

        for(size_t i = 1; i < prob.max_iter+1; i++)
        {
            // std::cout << "------------------------------" << std::endl;
            // 探索方向の決定
            // サブの問題設定
            ActiveSetMethod::Problem sub_prob_(x_init.rows());
            sub_prob_.Q = B;
            // sub_prob_.Q = approx_hessian(prob.func, x);
            sub_prob_.c = derivative(prob.func, x).transpose();

            // 等式制約の登録
            for(auto & con : eq_con)
            {
                Eigen::VectorXd Aq = con.grad(x);
                Eigen::Matrix<double, 1, 1> bq(-con.eval(x));
                sub_prob_.add_equality_constraint(Aq.transpose(), bq);
            }

            // 不等式制約の登録
            for(auto & con : ineq_con)
            {
                Eigen::VectorXd Aq = con.grad(x);
                Eigen::Matrix<double, 1, 1> bq(-con.eval(x));
                sub_prob_.add_inequality_constraint(Aq.transpose(), bq);
            }

            std::cout << "Q =" << std::endl;
            std::cout << sub_prob_.Q << std::endl;
            std::cout << "c =" << std::endl;
            std::cout << sub_prob_.c << std::endl;
            std::cout << "A =" << std::endl;
            std::cout << sub_prob_.A << std::endl;
            std::cout << "b =" << std::endl;
            std::cout << sub_prob_.b << std::endl;
            std::cout << "-----" << std::endl;
            

            // サブの2次計画問題を解く
            auto sub_result = asm_solver.solve(sub_prob_, Eigen::VectorXd::Zero(x.size()));

            // std::cout << "tp5" << std::endl;

            if(not sub_result.is_solved)
            {
                std::cout << "サブ問題解けなかった" << std::endl;
                result.is_solved = false;
                result.iter_cnt = i;
                result.x_opt = x;
                result.lambda_opt = sub_result.lambda_opt;
                return result;
            }

            auto d = sub_result.x_opt;
            auto lambda = sub_result.lambda_opt;

            // std::cout << "d: " << std::endl;
            // std::cout << d.transpose() << std::endl;

            // 収束判定
            if(d.norm() < prob.tol)
            {
                result.is_solved = true;
                result.iter_cnt = i;
                result.x_opt = x;
                result.lambda_opt = sub_result.lambda_opt;
                break;
            }

            // ステップ幅の決定
            // 直線探索
            // Todo: メリット関数の係数の計算
            double rho = 10;
            auto merit_func = [&](const Eigen::VectorXd &x)
            {
                // auto x_hat = x+a*d;
                double val = prob.func(x);

                for(auto & con : eq_con)
                {
                    val += rho * std::abs(con.eval(x));
                }

                // 不等式制約の登録
                for(auto & con : ineq_con)
                {
                    val += rho * std::max(con.eval(x), 0.0);
                }

                return val;
            };

            // std::cout << "tp6" << std::endl;
            double alpha = bracketing_serach(merit_func, [&](const Eigen::VectorXd &x){ return derivative(merit_func, x); }, x, d);

            x += alpha * d;

            // std::cout << "alpha = " << alpha << std::endl;
            // std::cout << "new x = " << std::endl;
            // std::cout << x.transpose() << std::endl;

            // 解の保存
            result.x_opt = x;
            result.lambda_opt = lambda;
            result.iter_cnt = i;

            // std::cout << "tp7" << std::endl;

            // ラグランジュ関数の勾配の変化量
            Eigen::VectorXd delta_grad_L = -grad_L;
            grad_L = derivative(prob.func, x) + sub_prob_.A.transpose() * lambda;
            delta_grad_L += grad_L;

            // std::cout << "tp8" << std::endl;

            // if(std::abs(alpha) < 1e-6)
            //     alpha = 1.0;

            std::cout << "alpha" << std::endl;
            std::cout << alpha << std::endl;
            std::cout << "d" << std::endl;
            std::cout << d << std::endl;
            std::cout << "delta_grad_L" << std::endl;
            std::cout << delta_grad_L << std::endl;
            
            // Bマトリクスの更新
            powells_modified_bfgs_step(B, alpha*d, delta_grad_L);

            std::cout << "B = " << std::endl;
            std::cout << B << std::endl;

            if(B.array().isNaN().any())
            {
                std::cout << "NaNが存在します" << std::endl;
                break;
            }

            // std::cout << "tp9" << std::endl;
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