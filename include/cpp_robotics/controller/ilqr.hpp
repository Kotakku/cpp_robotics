#pragma once

#include <Eigen/Dense>
#include "optimal_control_problem.hpp"

namespace cpp_robotics
{

struct iLQRConfig
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

class iLQR
{
public:
    enum class Result
    {
        SUCCESS = 0,
        MAX_ITER_REACHED,
        FAILED
    };

    iLQR(OCPDynamics::SharedPtr dynamics, OCPCost::SharedPtr cost, iLQRConfig config = iLQRConfig()):
        iLQR(OptimalControlProblem(dynamics, cost), config) {}

    // Note: constraints are ignored
    iLQR(const OptimalControlProblem &prob, iLQRConfig config = iLQRConfig()):
        prob_(prob), config_(config)
    {
        // setup workspace
        U.resize(prob_.horizon());
        tmpU.resize(prob_.horizon());
        for(size_t i = 0; i < prob_.horizon(); i++)
        {
            U[i].setZero(prob_.input_size());
            tmpU[i].setZero(prob_.input_size());
        }
        X.resize(prob_.horizon() + 1);
        tmpX.resize(prob_.horizon() + 1);
        for(size_t i = 0; i < prob_.horizon() + 1; i++)
        {
            X[i].setZero(prob_.state_size());
            tmpX[i].setZero(prob_.state_size());
        }
        K.resize(prob_.horizon());
        for(size_t i = 0; i < prob_.horizon(); i++)
        {
            K[i].setZero(prob_.input_size(), prob_.state_size());
        }
        d.resize(prob_.horizon());
        for(size_t i = 0; i < prob_.horizon(); i++)
        {
            d[i].setZero(prob_.input_size());
        }

        fx.setZero(prob_.state_size(), prob_.state_size());
        fu.setZero(prob_.state_size(), prob_.input_size());
    }

    Result generate_trajectory(const Eigen::VectorXd &x0)
    {
        rollout_trajectory(x0);

        double J = total_cost(X, U);
        for(size_t itr = 0; itr < config_.max_iter; ++itr)
        {
            bool backward_done = backward_pass();
            double new_J = forward_pass(x0, J);
            if(std::abs(new_J - J) < config_.cost_torelance)
            {
                return Result::SUCCESS;
            }
            J = new_J;
        }

        return Result::MAX_ITER_REACHED;
    }

    const std::vector<Eigen::VectorXd> &get_input() const { return U; }
    const std::vector<Eigen::VectorXd> &get_state() const { return X; }

private:
    void rollout_trajectory(const Eigen::VectorXd &x0)
    {
        X[0] = x0;
        for (size_t i = 0; i < prob_.horizon(); ++i)
        {
            X[i + 1] = prob_.dynamics->eval(X[i], U[i]);
        }
    }

    double total_cost(std::vector<Eigen::VectorXd> &X, std::vector<Eigen::VectorXd> &U)
    {
        double J = 0.0;
        for (size_t i = 0; i < prob_.horizon(); ++i)
        {
            J += prob_.cost->eval(X[i], U[i], i);
        }
        J += prob_.cost->eval_terminal(X[prob_.horizon()]);
        return J;
    }

    bool backward_pass()
    {
        auto &constraints = prob_.constraints;
        Vx = prob_.cost->jacobian_x_terminal(X.back());
        Vxx = prob_.cost->hessian_xx_terminal(X.back());

        dV1 = 0.0;
        dV2 = 0.0;
        Eigen::MatrixXd Quu_inv;
        for(int i = static_cast<int>(prob_.horizon()) - 1; i >= 0; i--)
        {
            // Eigen::MatrixXd fx = diff.fx(X[i], U[i]);
            // Eigen::MatrixXd fu = diff.fu(X[i], U[i]);
            fx = prob_.dynamics->jacobian_x(X[i], U[i]);
            fu = prob_.dynamics->jacobian_u(X[i], U[i]);

            Qx  = prob_.cost->jacobian_x(X[i], U[i], i) + fx.transpose() * Vx;
            Qu  = prob_.cost->jacobian_u(X[i], U[i], i) + fu.transpose() * Vx;
            Qxx = prob_.cost->hessian_xx(X[i], U[i], i) + fx.transpose() * Vxx * fx;
            Quu = prob_.cost->hessian_uu(X[i], U[i], i) + fu.transpose() * Vxx * fu;
            Qux = prob_.cost->hessian_ux(X[i], U[i], i) + fu.transpose() * Vxx * fx;

            // du = K*dx + d
            // 制約がない場合
            Quu_inv = Quu.inverse();
            K[i] = -Quu_inv * Qux;
            d[i] = -Quu_inv * Qu;

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
            for(size_t i = 0; i < prob_.horizon(); i++)
            {
                tmpU[i] = U[i] + K[i]*(tmpX[i]-X[i]) + alpha * d[i];

                // rollout
                tmpX[i + 1] = prob_.dynamics->eval(tmpX[i], tmpU[i]);
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

    const OptimalControlProblem prob_;
    iLQRConfig config_;

    // workspace
    std::vector<Eigen::VectorXd> U, X, tmpU, tmpX;
    std::vector<Eigen::MatrixXd> K;
    std::vector<Eigen::VectorXd> d;
    Eigen::VectorXd Vx;
    Eigen::MatrixXd Vxx;
    Eigen::MatrixXd Qx, Qu, Qxx, Quu, Qux, Quxu;
    Eigen::MatrixXd fx, fu;
    double dV1, dV2;
};

}