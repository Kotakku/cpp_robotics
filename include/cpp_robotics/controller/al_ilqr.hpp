#pragma once

#include <Eigen/Dense>
#include "cpp_robotics/controller/optimal_control_problem.hpp"
#include "cpp_robotics/utility/eigen_utils.hpp"

#include <iostream>

#define debug(x) std::cout << "[" <<  __func__  << "]: " << x << std::endl;
#define MAT_SIZE(mat) std::cout << #mat << ": " << mat.rows() << "x" << mat.cols() << std::endl;
#define MAT(mat) std::cout << #mat << ": \n" << mat << std::endl;

namespace cpp_robotics
{

namespace detail
{

enum class ALiLQRResult
{
    SUCCESS = 0,

    // failed
    MAX_INNER_ITER_REACHED,
    MAX_ITER_REACHED,
    MAX_PENALTY_EXCEEDED,
    FAILED
};

struct ALConfig
{
    size_t max_iter = 30;
    size_t max_ilqr_iter = 100;

    // cost torelance
    double cost_torelance = 1e-4;

    // constraint torelance
    double constraint_torelance = 1e-3;
    
    // forward pass line search stopping criteria
    double beta1 = 1e-4;
    double beta2 = 10.0;

    // forward pass update rate
    double alpha_scale = 0.5;
    size_t max_forward_itr = 10;

    // dual tolerance
    double dual_torelance = 1e-4;

    // penalty update rate
    double penalty_initial = 1e-4;
    double penalty_scale_factor = 10;
    double penalty_max = 1e8;

    // regularization
    double reg_initial = 1e-6;
    double reg_min = 1e-8;
    double reg_max = 1e8;
    double reg_scale_factor = 1.6;

    // finite difference step
    double eps = 1e-4;
};

class ALiLQR
{
public:
    ALiLQR(OCPDynamics::SharedPtr dynamics, OCPCost::SharedPtr cost, const OCPConstraintArray &constraints = OCPConstraintArray(), ALConfig config = ALConfig()):
        ALiLQR(OptimalControlProblem(dynamics, cost, constraints), config) {}
    
    ALiLQR(const OptimalControlProblem &prob, ALConfig config = ALConfig()):
        prob_(prob), config_(config)
    {
        // setup workspace
        U.resize(prob_.horizon());
        tmpU.resize(prob_.horizon());
        for(size_t i = 0; i < prob_.horizon(); i++)
        {
            U[i] = Eigen::VectorXd::Zero(prob_.input_size());
            tmpU[i] = Eigen::VectorXd::Zero(prob_.input_size());
        }
        X.resize(prob_.horizon() + 1);
        tmpX.resize(prob_.horizon() + 1);
        for(size_t i = 0; i < prob_.horizon() + 1; i++)
        {
            X[i] = Eigen::VectorXd::Zero(prob_.state_size());
            tmpX[i] = Eigen::VectorXd::Zero(prob_.state_size());
        }
        K.resize(prob_.horizon());
        for(size_t i = 0; i < prob_.horizon(); i++)
        {
            K[i] = Eigen::MatrixXd::Zero(prob_.input_size(), prob_.state_size());
        }
        d.resize(prob_.horizon());
        for(size_t i = 0; i < prob_.horizon(); i++)
        {
            d[i] = Eigen::VectorXd::Zero(prob_.input_size());
        }

        lambdas.resize(prob_.horizon());
        for(size_t i = 0; i < prob_.horizon(); i++)
        {
            lambdas[i] = Eigen::VectorXd::Zero(prob_.constraints.size());
        }

        penaltys.resize(prob_.horizon());
        for(size_t i = 0; i < prob_.horizon(); i++)
        {
            penaltys[i] = Eigen::VectorXd::Zero(prob_.constraints.size());
        }

        constraints_val.resize(prob_.horizon());
        for(size_t i = 0; i < prob_.horizon(); i++)
        {
            constraints_val[i] = Eigen::VectorXd::Zero(prob_.constraints.size());
        }
    }

    ALiLQRResult generate_trajectory(const Eigen::VectorXd &x0)
    {
        // debug("1");

        for(size_t i = 0; i < prob_.horizon(); i++)
        {
            for(size_t j = 0; j < prob_.constraints.size(); j++)
            {
                lambdas[i](j) = 0.0;
                penaltys[i](j) = config_.penalty_initial;
            }
        }

        if(not has_constraints())
        {
            return ilqr(x0);
        }

        // debug("2");

        // double J = total_cost(x0);

        rho = 0;
        double drho = 0.0;

        for(size_t i = 0; i < config_.max_iter; i++)
        {

            // debug("3");
            auto ret = ilqr(x0);

            // debug("4");

            if(ret != ALiLQRResult::SUCCESS)
            {
                debug("sub iLQR failed");
                return ret;
            }

            // debug("5");
            update_duals();

            // debug("6");
            double u_max = update_penalties();

            // debug("7: c_max: " << c_max << ", u_max: " << u_max);

            if(c_max < config_.constraint_torelance)
            {
                // debug("success");
                return ALiLQRResult::SUCCESS;
            }

            if(u_max > config_.penalty_max)
            {
                debug("max penalty exceeded");
                return ALiLQRResult::MAX_PENALTY_EXCEEDED;
            }
        }


        debug("max iter reached");
        return ALiLQRResult::MAX_ITER_REACHED;
    }

    const std::vector<Eigen::VectorXd> &get_input() const { return U; }
    const std::vector<Eigen::VectorXd> &get_state() const { return X; }

private:
    bool has_constraints() const
    {
        if (prob_.constraints.size())
            return true;
        return false;
    }

    ALiLQRResult ilqr(const Eigen::VectorXd &x0)
    {
        // debug("1");
        rho = config_.reg_initial;
        drho = 0.0;

        predict_trajectory(x0);
        
        // debug("3");
        double J = total_cost(X, U);
        for(size_t itr = 0; itr < config_.max_ilqr_iter; ++itr)
        {
            // debug("4");
            bool backward_done = backward_pass();
            if(not backward_done)
            {
                debug("backward pass failed");
                // return ALiLQRResult::FAILED;
            }

            // debug("5");
            double new_J = forward_pass(x0, J);

            // debug("6");
            // torelance check
            if(std::abs(new_J - J) < config_.cost_torelance)
            {
                return ALiLQRResult::SUCCESS;
            }
            J = new_J;
        }

        return ALiLQRResult::MAX_INNER_ITER_REACHED;
    }

    void update_duals()
    {
        for(size_t i = 0; i < prob_.horizon(); i++)
        {
            auto &constraints = prob_.constraints;
            for(size_t j = 0; j < constraints.size(); j++)
            {
                double new_lambda = lambdas[i](j) + penaltys[i](j) * constraints_val[i](j);
                if(constraints[j]->type == OCPConstraintType::Ineq)
                {
                    lambdas[i](j) = std::max(new_lambda, 0.0);
                }
                else
                {
                    lambdas[i](j) = new_lambda;
                }
            }
        }
    }

    double update_penalties()
    {
        double max_penalty = 0.0;
        for(size_t i = 0; i < prob_.horizon(); i++)
        {
            for(size_t j = 0; j < prob_.constraints.size(); j++)
            {
                penaltys[i](j) *= config_.penalty_scale_factor;
                max_penalty = std::max(max_penalty, penaltys[i](j));
            }
        }

        return max_penalty;
    }

    void increase_regularization()
    {
        drho = std::max(drho*config_.reg_scale_factor, config_.reg_scale_factor);
        rho = std::max(config_.reg_min, rho*drho);
        rho = std::min(config_.reg_max, rho);
        debug("rho: " << rho);
    }

    void decrease_regularization()
    {
        drho = std::min(drho/config_.reg_scale_factor, 1.0/config_.reg_scale_factor);
        rho = std::max(config_.reg_min, rho*drho);
    }

    void predict_trajectory(const Eigen::VectorXd &x0)
    {
        X[0] = x0;
        for (size_t i = 0; i < prob_.horizon(); ++i)
        {
            X[i + 1] = prob_.dynamics->eval(X[i], U[i]);
        }
    }

    double total_cost(std::vector<Eigen::VectorXd> &X, std::vector<Eigen::VectorXd> &U)
    {
        // debug("1");
        double J = 0.0;

        for (size_t i = 0; i < prob_.horizon(); i++)
        {
            J += prob_.cost->eval(X[i], U[i], i) + arglag_cost(X[i], U[i], i);
        }
        // debug("2");
        J += prob_.cost->eval_terminal(X[prob_.horizon()]);
        // debug("3");
        return J;
    }

    double arglag_cost(const Eigen::VectorXd &X, const Eigen::VectorXd &U, size_t i)
    {
        if(not has_constraints())
        {
            return 0.0;
        }
        auto &constraints = prob_.constraints;
        Eigen::VectorXd tmp_constraint_val = constraints.eval_all_vec(X, U);
        Eigen::VectorXd Ivec(constraints.size());
        for(size_t j = 0; j < constraints.size(); j++)
        {
            if(constraints[j]->type == OCPConstraintType::Ineq)
            {
                if(tmp_constraint_val(j) < config_.constraint_torelance && std::abs(lambdas[i](j)) < config_.dual_torelance)
                {
                    Ivec[j] = 0.0;
                }
                else
                {
                    Ivec[j] = penaltys[i](j);
                }
            }
            else
            {
                Ivec[j] = penaltys[i](j);
            }
        }
        Eigen::MatrixXd I = Ivec.asDiagonal();
        double cost = ((lambdas[i].transpose() + 0.5*tmp_constraint_val.transpose()*I) * tmp_constraint_val)[0];
        return cost;
    }

    bool backward_pass()
    {
        // debug("2");
        // Todo: add terminal constraints term
        Vx = prob_.cost->jacobian_x_terminal(X.back());
        Vxx = prob_.cost->hessian_xx_terminal(X.back());

        // debug("3");

        size_t rho_increase_count = 0;
        c_max = 0.0;
        dV1 = 0.0;
        dV2 = 0.0;
        Eigen::MatrixXd Quu_inv;
        for(int i = static_cast<int>(prob_.horizon()) - 1; i >= 0;)
        {
            // debug("4");
            Eigen::MatrixXd fx = prob_.dynamics->jacobian_x(X[i], U[i]);
            Eigen::MatrixXd fu = prob_.dynamics->jacobian_u(X[i], U[i]);

            Qx  = prob_.cost->jacobian_x(X[i], U[i], i) + fx.transpose() * Vx;
            Qu  = prob_.cost->jacobian_u(X[i], U[i], i) + fu.transpose() * Vx;
            Qxx = prob_.cost->hessian_xx(X[i], U[i], i) + fx.transpose() * Vxx * fx;
            Quu = prob_.cost->hessian_uu(X[i], U[i], i) + fu.transpose() * Vxx * fu;
            Qux = prob_.cost->hessian_ux(X[i], U[i], i) + fu.transpose() * Vxx * fx;

            // debug("5");

            // argumented lagrangian
            if(has_constraints())
            {
                // debug("5-1");
                auto &constraints = prob_.constraints;
                Eigen::MatrixXd cx(constraints.size(),  prob_.state_size());
                for(size_t j = 0; j < constraints.size(); j++)
                {
                    cx.row(j) = constraints[j]->grad_x(X[i], U[i]);
                }

                // debug("5-2");

                Eigen::MatrixXd cu(constraints.size(),  prob_.input_size());
                for(size_t j = 0; j < constraints.size(); j++)
                {
                    cu.row(j) = constraints[j]->grad_u(X[i], U[i]);
                }

                // debug("5-3");

                constraints_val[i] = constraints.eval_all_vec(X[i], U[i]);

                // debug("5-4: U[i]: " << U[i].transpose());
                // debug("5-4: constraints_val[i]: " << constraints_val[i].transpose());
                Eigen::VectorXd Ivec(constraints.size());
                for(size_t j = 0; j < constraints.size(); j++)
                {
                    // debug("5-5");
                    

                    // debug("5-6");
                    if(constraints[j]->type == OCPConstraintType::Ineq)
                    {
                        if(constraints_val[i](j) < config_.constraint_torelance && std::abs(lambdas[i](j)) < config_.dual_torelance)
                        {
                            Ivec[j] = 0.0;
                        }
                        else
                        {
                            Ivec[j] = penaltys[i](j);
                        }
                        c_max = std::max(c_max, constraints_val[i](j));
                    }
                    else
                    {
                        Ivec[j] = penaltys[i](j);
                        c_max = std::max(c_max, std::abs(constraints_val[i](j)));
                    }
                }

                // debug("5-7");

                Eigen::MatrixXd I = Ivec.asDiagonal();
                Qx += cx.transpose() * (lambdas[i] + I * constraints_val[i]);
                Qu += cu.transpose() * (lambdas[i] + I * constraints_val[i]);
                Qxx += cx.transpose() * I * cx;
                Quu += cu.transpose() * I * cu;
                Qux += cu.transpose() * I * cx;
            }

            // debug("6");

            if (not isPositiveDefinite(Quu))
            {
                // debug("Quu is not positive definite");
                increase_regularization();
                rho_increase_count++;

                if(rho_increase_count > 50)
                {
                    debug("rho increase count exceeded");
                    return false;
                }
                continue;
            }

            // debug("7: rho: " << rho);

            // du = K*dx + d
            // MAT_SIZE(Qxx);
            // MAT_SIZE(Quu);
            if(1)
            {
                // auto I = Eigen::MatrixXd::Identity(prob_.input_size(), prob_.input_size());
                // Eigen::MatrixXd Quu_inv = (Quu + rho * I).inverse();
                // K[i] = -Quu_inv * Qux;
                // d[i] = -Quu_inv * Qu;

                // Eigen::MatrixXd QuuReg = Quu + rho * I;
                // Eigen::LLT<Eigen::MatrixXd> Quu_chol;
                // Eigen::LLT<Eigen::MatrixXd> Qxx_chol;
                // Quu_chol.compute(QuuReg);
                // if(Quu_chol.info() == Eigen::Success && Quu_chol.info() == Eigen::Success)
                // {
                //     // K[i] = -Quu_chol.solve(Qux);
                //     // d[i] = -Quu_chol.solve(Qu);

                //     Eigen::MatrixXd Zxx = Qxx_chol.matrixU();
                //     Eigen::MatrixXd Zuu = Quu_chol.matrixU();

                //     K[i] = -Zuu.inverse() * Zuu.transpose() * Qux;
                //     d[i] = -Zuu.inverse() * Zuu.transpose() * Qu;
                // }
                // else
                {
                    // debug("LLT failed");
                    Eigen::MatrixXd Quu_reg = Quu; //(Quu + rho * I).inverse();
                    for(int j = 0; j < Quu.rows(); j++)
                    {
                        Quu_reg(j, j) += rho;
                    }
                    // Eigen::MatrixXd Quu_inv = Quu_reg.inverse();
                    // K[i] = -Quu_inv * Qux;
                    // d[i] = -Quu_inv * Qu;
                    Eigen::LLT<Eigen::MatrixXd> Quu_chol(Quu_reg);
                    if(Quu_chol.info() == Eigen::Success)
                    {
                        K[i] = -Quu_chol.solve(Qux);
                        d[i] = -Quu_chol.solve(Qu);
                    }
                    else
                    {
                        debug("LLT failed");
                        return false;
                    }
                }
            }
            else
            {
                // QR
                // Eigen::HouseholderQR<Eigen::MatrixXd> qr(Quu);
            }

            // debug("8");

            // update Vx, Vxx
            Vxx = Qxx + (K[i].transpose()*Quu*K[i]) + K[i].transpose()*Qux + Qux.transpose()*K[i];
            Vx = Qx + K[i].transpose()*Quu*d[i] + K[i].transpose()*Qu + Qux.transpose()*d[i];

            // calclate dV1, dV2
            dV1 += (d[i].transpose()*Qu)[0];
            dV2 += (0.5*d[i].transpose()*Quu*d[i])[0];

            // debug("9");

            // next for loop
            i--;
        }

        // debug("decrease regularization");
        decrease_regularization();

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
    ALConfig config_;

    // workspace
    std::vector<Eigen::VectorXd> U, X, tmpU, tmpX;
    std::vector<Eigen::MatrixXd> K;
    std::vector<Eigen::VectorXd> d;
    Eigen::VectorXd Vx;
    Eigen::MatrixXd Vxx;
    Eigen::MatrixXd Qx, Qu, Qxx, Quu, Qux, Quxu;
    double dV1, dV2;

    std::vector<Eigen::VectorXd> constraints_val;
    std::vector<Eigen::VectorXd> lambdas, penaltys;
    double rho;
    double drho;
    double c_max;
};

} // namespace detail

// class ALTRO : private detail::ALiLQR<DiscreteNonlinearOCP>
// {
//     using ALiLQR = detail::ALiLQR<DiscreteNonlinearOCP>;
// public:
//     using ALTROResult = detail::ALiLQRResult;
//     using Config = ALiLQR::Config;

//     ALTRO(const DiscreteNonlinearOCP &model):
//         ALiLQR(model)
//     {
        
//     }

//     ALTROResult generate_trajectory(const Eigen::VectorXd &x0)
//     {
//         // if infeasible

//         auto ret = ALiLQR::generate_trajectory(x0);

//         projection();

//         return ALTROResult::SUCCESS;
//     }

//     using ALiLQR::get_input;
//     using ALiLQR::get_state;

// private:
//     void projection()
//     {

//     }

//     void line_search()
//     {

//     }

// };


} // namespace cpp_robotics