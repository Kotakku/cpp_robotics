#pragma once

#include <functional>
#include <cmath>
#include <optional>
#include <Eigen/Dense>
#include "./constraint.hpp"
#include "./bracketing_serach.hpp"
#include "./bfgs.hpp"
#include "./quasi_newton_method.hpp"
#include <cpp_robotics/optimize/quadprog.hpp>
#include "./lsei_transition.hpp"

namespace cpp_robotics
{

/**
 * @brief SQP(逐次二次計画法)
 * 
 */
class SQP
{
public:
    using func_type = std::function<double(Eigen::VectorXd)>;
    using grad_func_type = std::function<Eigen::VectorXd(Eigen::VectorXd)>;

    struct Problem
    {
        func_type func;
        std::optional<grad_func_type> grad;
        ConstraintArray con;

        bool use_slsqp = true;
        double tol_step = 1e-4;
        double tol_con = 2e-3;
        size_t max_iter = 300;
        // bool print_variable = false;
    };

    struct Result
    {
        bool is_solved = false;
        Eigen::VectorXd x;
        // Eigen::VectorXd lambda_opt;
        size_t iter_cnt = 0;
    };

    Result solve(Problem prob, const Eigen::VectorXd &x0, std::optional<std::function<void(Eigen::VectorXd)>> callback = std::nullopt)
    {
        Result result;

        grad_func_type grad_f = prob.grad.value_or([&](const Eigen::VectorXd &x){ return derivative(prob.func, x); });

        // 制約がない時, 準ニュートン法で解く
        if(prob.con.size() == 0)
        {
            std::tie(result.is_solved, result.x, result.iter_cnt) = 
                quasi_newton_method(prob.func, grad_f, x0, 1e-6, prob.max_iter);
            return result;
        }

        Eigen::VectorXd x = x0;
        Eigen::VectorXd grad_f0 = grad_f(x0);
        Eigen::MatrixXd B = Eigen::MatrixXd::Identity(x.rows(), x.rows());
        Eigen::VectorXd grad_fx = grad_f0;
        Eigen::VectorXd step = grad_f0;
        Eigen::VectorXd dgg = Eigen::VectorXd::Zero(x.size());

        // Todo: x0が実行不可能な場合実行可能領域まで移動させる

        // 制約
        auto eq_con = prob.con.gen_eq_constraint_list();
        auto ineq_con = prob.con.gen_ineq_constraint_list();

        // サブ問題の2次計画問題のソルバー
        QuadProgProblem qp_prob;
        QuadProg qp_solver;
        qp_solver.param.admm.tol_abs = 5e-3;
        qp_solver.param.admm.tol_rel = 5e-3;
        qp_prob.set_problem_size(x.size(), ineq_con.size(), eq_con.size(), false);

        // 直線探索用メリット関数の制約重み
        const double df0_norm = grad_f(x).norm();
        Eigen::VectorXd eq_mw   = df0_norm * Eigen::VectorXd::Ones(eq_con.size());
        Eigen::VectorXd ineq_mw = df0_norm * Eigen::VectorXd::Ones(ineq_con.size());
        for(size_t i = 0; i < eq_con.size(); i++)
        {
            eq_mw(i) /= std::max(eq_con[i].grad(x).norm(), 1.0);
        }
        for(size_t i = 0; i < ineq_con.size(); i++)
        {
            ineq_mw(i) /= std::max(ineq_con[i].grad(x).norm(), 1.0);
        }

        // 等式制約の一次近似
        for(size_t con_i = 0; con_i < eq_con.size(); con_i++)
        {
            qp_prob.Aeq.row(con_i) = eq_con[con_i].grad(x).transpose();
            qp_prob.beq(con_i) = -eq_con[con_i].eval(x);
        }

        // 不等式制約の一次近似
        for(size_t con_i = 0; con_i < ineq_con.size(); con_i++)
        {
            qp_prob.A.row(con_i) = ineq_con[con_i].grad(x).transpose();
            qp_prob.b(con_i) = -ineq_con[con_i].eval(x);
        }

        Eigen::MatrixXd new_Aeq(qp_prob.Aeq.rows(), qp_prob.Aeq.cols());
        Eigen::VectorXd new_beq(qp_prob.beq.size());
        Eigen::MatrixXd new_A(qp_prob.A.rows(), qp_prob.A.cols());
        Eigen::VectorXd new_b(qp_prob.b.size());

        // Todo: この前処理が有効になった時にdelta_grad_L？がおかしくなってヘッシアンが発散する？
        auto preprossesing = [&](Eigen::MatrixXd &Aeq, Eigen::VectorXd &beq, Eigen::MatrixXd &A, Eigen::VectorXd &b)
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
        preprossesing(qp_prob.Aeq, qp_prob.beq, qp_prob.A, qp_prob.b);

        for(size_t i = 1; i < prob.max_iter+1; i++)
        {
            // 探索方向の決定
            // サブの問題設定
            if (prob.use_slsqp)
            {
                auto ldlt_obj = B.ldlt();
                Eigen::MatrixXd L = ldlt_obj.transpositionsP().transpose()*(Eigen::MatrixXd)ldlt_obj.matrixL();
                Eigen::MatrixXd LT = L.transpose();
                Eigen::MatrixXd Linv = L.inverse();
                Eigen::VectorXd D = ldlt_obj.vectorD();
                Eigen::VectorXd Dsq = D.array().sqrt();
                Eigen::VectorXd Dinvsq = (D.array()).inverse();
                Eigen::MatrixXd C = Dsq.asDiagonal()*LT;
                Eigen::VectorXd d = Dinvsq.asDiagonal()*Linv*grad_f(x);
                std::tie(qp_prob.Q, qp_prob.c) = lsi2qp(C, d);
            }
            else
            {
                qp_prob.Q = B;
                qp_prob.c = grad_f(x).transpose();
            }

            // サブの2次計画問題を解く
            qp_solver.set_problem(qp_prob);
            auto sub_result = qp_solver.solve(Eigen::VectorXd::Zero(x.size()));
            if(not sub_result.is_solved)
            {
                result.is_solved = false;
                result.iter_cnt = i;
                result.x = x;
                // result.lambda_opt = sub_result.lambda_opt;
                // std::cout << "cant solve sub qp: " << sub_result.iter_cnt << std::endl;
                // qp_solver.debug_prog();
                return result;
            }
            auto d = sub_result.x;

            // ステップ幅の決定
            // 直線探索
            auto merit_func = [&](const Eigen::VectorXd &x)
            {
                double val = prob.func(x);

                // 等式制約
                for(size_t con_i = 0; con_i < eq_con.size(); con_i++)
                {
                    const double eval = eq_con[con_i].eval(x);
                    if(std::isfinite(eval))
                        val += eq_mw(con_i) * std::abs(eval);
                }

                // 不等式制約
                for(size_t con_i = 0; con_i < ineq_con.size(); con_i++)
                {
                    const double eval = ineq_con[con_i].eval(x);
                    if(std::isfinite(eval))
                    val += ineq_mw(con_i) * std::max(eval, 0.0);
                }

                return val;
            };
            double alpha = bracketing_serach(merit_func, [&](const Eigen::VectorXd &x){ return derivative(merit_func, x); }, x, d);

            if(callback)
                callback.value()(x);
            step = alpha * d;
            x += step;

            // 収束判定
            // Todo: KKT条件の1次の最適性チェック入れる
            if(step.norm() < prob.tol_step*(1.0+x.norm())) // && prob.con.all_satisfy(x, prob.tol_con))
            {
                result.is_solved = true;
                result.iter_cnt = i;
                result.x = x;
                return result;
            }

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
            /*
            Bの値がe10以上のオーダーで大きくなる
            制約に掛かるgrad_Lの値が正しいのか確認する
            */
            // https://jp.mathworks.com/help/optim/ug/constrained-nonlinear-optimization-algorithms.html#bsgppl4
            Eigen::VectorXd delta_grad_L = -grad_fx;
            grad_fx = grad_f(x);
            delta_grad_L += grad_fx;
            // 等式制約の一次近似
            for(size_t con_i = 0; con_i < eq_con.size(); con_i++)
            {
                new_Aeq.row(con_i) = eq_con[con_i].grad(x).transpose();
                new_beq(con_i) = -eq_con[con_i].eval(x);
            }

            // 不等式制約の一次近似
            for(size_t con_i = 0; con_i < ineq_con.size(); con_i++)
            {
                new_A.row(con_i) = ineq_con[con_i].grad(x).transpose();
                new_b(con_i) = -ineq_con[con_i].eval(x);
            }

            preprossesing(new_Aeq, new_beq, new_A, new_b);

            delta_grad_L += (new_Aeq - qp_prob.Aeq).transpose() * sub_result.lambda_eq;
            delta_grad_L += (new_A   - qp_prob.A  ).transpose() * sub_result.lambda_ineq;

            qp_prob.Aeq = new_Aeq;
            qp_prob.beq = new_beq;
            qp_prob.A = new_A;
            qp_prob.b = new_b;

            // \grad_g(x) * g(x) = [n]*[1]
            Eigen::VectorXd new_dgg = -new_Aeq.transpose()*new_beq -new_A.transpose()*new_b - x;

            // ラグランジュ関数の疑似ヘッシアンの更新
            powells_modified_bfgs_step(B, step, delta_grad_L, new_dgg - dgg);
            dgg = new_dgg;

            if(B.array().isNaN().any())
            {
                // std::cout << "NaNが存在します" << std::endl;
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