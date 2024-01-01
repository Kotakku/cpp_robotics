#pragma once

#include <Eigen/Dense>
#include "optimal_control_problem.hpp"

#include <iostream>

#define MAT_SIZE(mat) std::cout << #mat << ": " << mat.rows() << "x" << mat.cols() << std::endl;

namespace cpp_robotics
{

template<class Model = DiscreteLinearOCP>
class iLQR
{
public:
    struct Config
    {
        bool use_ddp = false;
        bool use_augmented_lagrangian = false;

        size_t max_iter = 100;
        double cost_torelance = 1e-3;
        
        double beta1 = 1e-4;
        double beta2 = 10.0;
    };

    enum Result
    {
        SUCCESS = 0,
        MAX_ITER_REACHED,
        FAILED
    };

    iLQR(const Model &model, Config config = Config()):
        model_(model), config_(config)
    {
        // setup workspace
        U.resize(model_.N);
        tmpU.resize(model_.N);
        for(size_t i = 0; i < model_.N; i++)
        {
            U[i] = Eigen::VectorXd::Zero(model_.input_size());
            tmpU[i] = Eigen::VectorXd::Zero(model_.input_size());
        }
        X.resize(model_.N + 1);
        tmpX.resize(model_.N + 1);
        for(size_t i = 0; i < model_.N + 1; i++)
        {
            X[i] = Eigen::VectorXd::Zero(model_.state_size());
            tmpX[i] = Eigen::VectorXd::Zero(model_.state_size());
        }
        K.resize(model_.N);
        for(size_t i = 0; i < model_.N; i++)
        {
            K[i] = Eigen::MatrixXd::Zero(model_.input_size(), model_.state_size());
        }
        d.resize(model_.N);
        for(size_t i = 0; i < model_.N; i++)
        {
            d[i] = Eigen::VectorXd::Zero(model_.input_size());
        }
    }

    Result generate_trajectory(const Eigen::VectorXd &x0)
    {
        // std::cout << "tp3" << std::endl;
        predict_trajectory(x0);

        // std::cout << "tp4" << std::endl;
        double J = total_cost(X, U);

        for(size_t itr = 0; itr < config_.max_iter; ++itr)
        {
            // std::cout << "itr: " << itr << std::endl;
            // backward oass
            // std::cout << "backward_pass" << std::endl;
            bool backward_done = backward_pass();

            // forward pass
            // std::cout << "forward_pass" << std::endl;
            double new_J;
            bool forward_done = forward_pass(x0, J, new_J);

            // std::cout << "backward_done: " << backward_done << std::endl;
            // std::cout << "forward_done: " << forward_done << std::endl;
            // std::cout << "cost: " << J << " -> " << new_J << std::endl;

            // torelance check
            if(std::abs(new_J - J) < config_.cost_torelance)
            {
                return SUCCESS;
            }

            J = new_J;
        }

        return MAX_ITER_REACHED;
    }

    const std::vector<Eigen::VectorXd> &get_input() const { return U; }
    const std::vector<Eigen::VectorXd> &get_state() const { return X; }

private:
    void predict_trajectory(const Eigen::VectorXd &x0)
    {
        X[0] = x0;
        for (size_t i = 0; i < model_.N; ++i)
        {
            X[i + 1] = model_.Ad * X[i] + model_.Bd * U[i];
        }
    }

    double total_cost(std::vector<Eigen::VectorXd> &X, std::vector<Eigen::VectorXd> &U)
    {
        double J = 0.0;

        for (size_t i = 0; i < model_.N; ++i)
        {
            J += model_.running_cost(X[i], U[i], i);
        }
        J += model_.terminal_cost(X[model_.N]);
        
        return J;
    }

    bool backward_pass();

    bool forward_pass(const Eigen::VectorXd &x0, const double J, double &new_J)
    {
        double alpha = 1.0;

        tmpX[0] = x0;

        for(size_t j = 0; j < 15; j++)
        {
            for(size_t i = 0; i < model_.N; ++i)
            {
                tmpU[i] = U[i] + K[i]*(tmpX[i]-X[i]) + alpha * d[i];

                // limit input
                if(model_.u_limit)
                {
                    tmpU[i] = tmpU[i].cwiseMax(model_.u_limit->first).cwiseMin(model_.u_limit->second);
                }

                // rollout
                tmpX[i + 1] = model_.model(tmpX[i], tmpU[i]);
            }

            new_J = total_cost(tmpX, tmpU);

            double dV1_ = alpha * dV1;
            double dV2_ = alpha*alpha * dV2;
            double z = (new_J - J) / (dV1_ + dV2_);

            // line search
            if (config_.beta1 <= z && z <= config_.beta2)
            {
                U = tmpU;
                X = tmpX;

                return true; // update
            }

            alpha *= 0.5;
        }

        new_J = J;
        return false; // already optimal
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

// implementation for DiscreteLinearOCP
template<>
bool iLQR<DiscreteLinearOCP>::backward_pass()
{
    // std::cout << "- bk 1" << std::endl;
    Vx = model_.Qf * (X.back() - model_.x_ref.back());
    Vxx = model_.Qf;

    dV1 = 0.0;
    dV2 = 0.0;
    Eigen::MatrixXd Quu_inv;
    for(int i = static_cast<int>(model_.N) - 1; i >= 0; i--)
    {
        // std::cout << "- bk 2" << std::endl;
        // 変分を求める
        Qx = model_.Q * (X[i] - model_.x_ref[i])
            + model_.Ad.transpose() * Vx;
        Qu = model_.R * U[i] 
            + model_.Bd.transpose() * Vx;
        Qxx = model_.Q 
            + model_.Ad.transpose() * Vxx * model_.Ad;
        Quu = model_.R 
            + model_.Bd.transpose() * Vxx * model_.Bd;
        Qux = model_.Bd.transpose() * Vxx * model_.Ad;

        // std::cout << "- bk 3" << std::endl;

        if(config_.use_ddp)
        {
            // nothing to do
            // Qxx += Vx[i+1] * fxx;
            // Quu += Vx[i+1] * fuu;
            // Qux += Vx[i+1] * fux;
        }

        // du = K*dx + d
        // 制約がない場合
        Quu_inv = Quu.inverse();

        // MAT_SIZE(Quu_inv);
        // MAT_SIZE(Qux);
        // MAT_SIZE(Qu.transpose());

        // std::cout << "- bk 3-2" << std::endl;

        K[i] = -Quu_inv * Qux;


        // std::cout << "- bk 3-3" << std::endl;
        d[i] = -Quu_inv * Qu;

        // MAT_SIZE(K[i]);
        // MAT_SIZE(d[i]);
        

        // std::cout << "- bk 4" << std::endl;

        // update Vx, Vxx
        // std::cout << "- bk 4-2" << std::endl;
        Vxx = Qxx + (K[i].transpose()*Quu*K[i]) + K[i].transpose()*Qux + Qux.transpose()*K[i];

        // std::cout << "- bk 4-3" << std::endl;
        Vx = Qx + K[i].transpose()*Quu*d[i] + K[i].transpose()*Qu + Qux.transpose()*d[i];


        // std::cout << "- bk 5" << std::endl;

        // MAT_SIZE(Qu);
        // MAT_SIZE(d[i]);
        
        // MAT_SIZE(Quu);

        // calclate dV1, dV2
        // MAT_SIZE((d[i].transpose()*Qu));
        // MAT_SIZE((0.5*d[i].transpose()*Quu*d[i]));
        
        dV1 += (d[i].transpose()*Qu)[0];

        // std::cout << "- bk 5-1" << std::endl;
        dV2 += (0.5*d[i].transpose()*Quu*d[i])[0];

        // std::cout << "- bk 5-2" << std::endl;
    }

    return true;
}

}