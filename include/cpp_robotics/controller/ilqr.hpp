#pragma once

#include <Eigen/Dense>
#include "optimal_control_problem.hpp"
#include <cpp_robotics/optimize/quadprog.hpp>

// #include <iostream>

// #define MAT_SIZE(mat) std::cout << #mat << ": " << mat.rows() << "x" << mat.cols() << std::endl;
// #define MAT(mat) std::cout << #mat << ": \n" << mat << std::endl;
namespace cpp_robotics
{

enum class iLQRResult
{
    SUCCESS = 0,
    MAX_ITER_REACHED,
    FAILED
};

template<class Model>
class iLQR
{
    static constexpr bool is_linear_ocp = std::is_base_of<DiscreteLinearOCP, Model>::value;
    static constexpr bool is_nonlinear_ocp = std::is_base_of<DiscreteNonlinearOCP, Model>::value;
public:
    struct Config
    {
        size_t max_iter = 100;

        // cost torelance
        double cost_torelance = 1e-3;
        
        // forward pass line search stopping criteria
        double beta1 = 1e-4;
        double beta2 = 10.0;

        // forward pass update rate
        double alpha_scale = 0.5;
        size_t max_forward_itr = 10;

        // finite difference step
        double eps = 1e-4;
    };

    iLQR(const Model &model, Config config = Config()):
        model_(model), config_(config)
    {
        static_assert(is_linear_ocp || is_nonlinear_ocp, "Model must be DiscreteLinearOCP or DiscreteNonlinearOCP");

        // setup workspace
        U.resize(model_.horizon());
        tmpU.resize(model_.horizon());
        for(size_t i = 0; i < model_.horizon(); i++)
        {
            U[i] = Eigen::VectorXd::Zero(model_.input_size());
            tmpU[i] = Eigen::VectorXd::Zero(model_.input_size());
        }
        X.resize(model_.horizon() + 1);
        tmpX.resize(model_.horizon() + 1);
        for(size_t i = 0; i < model_.horizon() + 1; i++)
        {
            X[i] = Eigen::VectorXd::Zero(model_.state_size());
            tmpX[i] = Eigen::VectorXd::Zero(model_.state_size());
        }
        K.resize(model_.horizon());
        for(size_t i = 0; i < model_.horizon(); i++)
        {
            K[i] = Eigen::MatrixXd::Zero(model_.input_size(), model_.state_size());
        }
        d.resize(model_.horizon());
        for(size_t i = 0; i < model_.horizon(); i++)
        {
            d[i] = Eigen::VectorXd::Zero(model_.input_size());
        }
    }

    iLQRResult generate_trajectory(const Eigen::VectorXd &x0)
    {
        predict_trajectory(x0);

        double J = total_cost(X, U);
        for(size_t itr = 0; itr < config_.max_iter; ++itr)
        {
            bool backward_done = backward_pass();
            double new_J = forward_pass(x0, J);
            if(std::abs(new_J - J) < config_.cost_torelance)
            {
                return iLQRResult::SUCCESS;
            }
            J = new_J;
        }

        return iLQRResult::MAX_ITER_REACHED;
    }

    const std::vector<Eigen::VectorXd> &get_input() const { return U; }
    const std::vector<Eigen::VectorXd> &get_state() const { return X; }

private:
    void predict_trajectory(const Eigen::VectorXd &x0)
    {
        X[0] = x0;
        for (size_t i = 0; i < model_.horizon(); ++i)
        {
            X[i + 1] = model_.dynamics(X[i], U[i]);
        }
    }

    double total_cost(std::vector<Eigen::VectorXd> &X, std::vector<Eigen::VectorXd> &U)
    {
        double J = 0.0;

        for (size_t i = 0; i < model_.horizon(); ++i)
        {
            J += model_.running_cost(X[i], U[i], i);
        }
        J += model_.terminal_cost(X[model_.horizon()]);
        
        return J;
    }

    bool backward_pass()
    {
        OCPDifferentiator diff(model_, config_.eps);
        Vx = diff.lNx(X.back());
        Vxx = diff.lNxx(X.back());

        dV1 = 0.0;
        dV2 = 0.0;
        Eigen::MatrixXd Quu_inv;
        for(int i = static_cast<int>(model_.horizon()) - 1; i >= 0; i--)
        {
            Eigen::MatrixXd fx = diff.fx(X[i], U[i]);
            Eigen::MatrixXd fu = diff.fu(X[i], U[i]);

            Qx  = diff.lx(X[i], U[i], i) + fx.transpose() * Vx;
            Qu  = diff.lu(X[i], U[i], i) + fu.transpose() * Vx;
            Qxx = diff.lxx(X[i], U[i], i) + fx.transpose() * Vxx * fx;
            Quu = diff.luu(X[i], U[i], i) + fu.transpose() * Vxx * fu;
            Qux = diff.lux(X[i], U[i], i) + fu.transpose() * Vxx * fx;

            // du = K*dx + d
            if constexpr (is_linear_ocp)
            {
                // Todo: 入力のbox制約がある場合
                // if(model_.u_limit)
                // {
                //     QuadProg prob;
                //     const size_t n = model_.input_size();
                //     prob.set_problem_size(n, 2*n, 0);
                //     prob.Q = Quu; // + lambda * Eigen::MatrixXd::Identity(n,n);
                //     prob.c = Qu;

                //     // std::cout << "tpA" << std::endl;
                //     prob.A << Eigen::MatrixXd::Identity(n,n), -Eigen::MatrixXd::Identity(n,n);
                //     // std::cout << "tpB" << std::endl;
                //     prob.b << model_.u_limit->second - U[i], -(model_.u_limit->first - U[i]);
                    
                //     auto ret = prob.solve(Eigen::VectorXd::Zero(n));

                //     if(ret.is_solved)
                //     {
                //         // Todo
                //         K[i] = -Qux;
                //         d[i] = ret.x;
                //     }
                //     else
                //     {
                //         return false;
                //     }
                // }
                // else
                {
                    // 制約がない場合
                    Quu_inv = Quu.inverse();
                    K[i] = -Quu_inv * Qux;
                    d[i] = -Quu_inv * Qu;
                }
            }
            else if constexpr (is_nonlinear_ocp)
            {
                // Todo: 制約がある場合

                // 制約がない場合
                Eigen::MatrixXd Quu_inv = Quu.inverse();
                K[i] = -Quu_inv * Qux;
                d[i] = -Quu_inv * Qu;
            }

            // update Vx, Vxx
            Vxx = Qxx + (K[i].transpose()*Quu*K[i]) + K[i].transpose()*Qux + Qux.transpose()*K[i];
            Vx = Qx + K[i].transpose()*Quu*d[i] + K[i].transpose()*Qu + Qux.transpose()*d[i];

            // calclate dV1, dV2
            dV1 += (d[i].transpose()*Qu)[0];
            dV2 += (0.5*d[i].transpose()*Quu*d[i])[0];
        }

        return true;
    }

    double forward_pass(const Eigen::VectorXd &x0, const double J)
    {
        double alpha = 1.0;

        tmpX[0] = x0;
        for(size_t j = 0; j < config_.max_forward_itr; j++)
        {
            for(size_t i = 0; i < model_.horizon(); i++)
            {
                tmpU[i] = U[i] + K[i]*(tmpX[i]-X[i]) + alpha * d[i];

                // Todo: Tessa 2012のbox制約の実装
                if(model_.u_limit)
                {
                    tmpU[i] = tmpU[i].cwiseMax(model_.u_limit->first).cwiseMin(model_.u_limit->second);
                }

                // rollout
                tmpX[i + 1] = model_.dynamics(tmpX[i], tmpU[i]);
            }

            double new_J = total_cost(tmpX, tmpU);
            double dV1_ = alpha * dV1;
            double dV2_ = alpha*alpha * dV2;
            double z = (new_J - J) / (dV1_ + dV2_);
            // line search
            if (config_.beta1 <= z && z <= config_.beta2)
            {
                U = tmpU;
                X = tmpX;
                return new_J; // update
            }
            alpha *= config_.alpha_scale;
        }
        return J; // already optimal
    }

    const Model &model_;
    Config config_;

    // workspace
    std::vector<Eigen::VectorXd> U, X, tmpU, tmpX;
    std::vector<Eigen::MatrixXd> K;
    std::vector<Eigen::VectorXd> d;
    Eigen::VectorXd Vx;
    Eigen::MatrixXd Vxx;
    Eigen::MatrixXd Qx, Qu, Qxx, Quu, Qux, Quxu;
    double dV1, dV2;
};

}