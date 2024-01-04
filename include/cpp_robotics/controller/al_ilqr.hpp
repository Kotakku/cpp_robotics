#pragma once

#include <Eigen/Dense>
#include "cpp_robotics/controller/optimal_control_problem.hpp"
#include "cpp_robotics/utility/eigen_utils.hpp"

// #include <iostream>
// #define debug(x) std::cout << "[" <<  __func__  << "]: " << x << std::endl;
// #define MAT_SIZE(mat) std::cout << #mat << ": " << mat.rows() << "x" << mat.cols() << std::endl;
// #define MAT(mat) std::cout << #mat << ": \n" << mat << std::endl;

namespace cpp_robotics
{

struct ALConfig
{
    size_t max_iter = 30;
    size_t max_ilqr_iter = 100;

    // cost torelance
    double cost_torelance = 1e-4;

    // constraint torelance
    double constraint_torelance = 1e-2;
    
    // forward pass line search stopping criteria
    double beta1 = 1e-4;
    double beta2 = 10.0;

    // forward pass update rate
    double alpha_scale = 0.5;
    size_t max_forward_itr = 10;

    // dual tolerance
    double dual_torelance = 1e-6;

    // penalty update rate
    double penalty_initial = 1e-4;
    double penalty_scale_factor = 10;
    double penalty_max = 1e8;

    // regularization
    double reg_initial = 1e-6;
    double reg_min = 1e-8;
    double reg_max = 1e8;
    double reg_scale_factor = 1.6;
    size_t reg_max_count = 50;

    // finite difference step
    double eps = 1e-6;
};

class ALiLQR
{
public:
    enum class Result
    {
        SUCCESS = 0,

        // failed
        MAX_INNER_ITER_REACHED,
        MAX_ITER_REACHED,
        MAX_PENALTY_EXCEEDED,
        FAILED
    };

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

        lambdas.resize(prob_.horizon()+1);
        for(size_t i = 0; i < prob_.horizon()+1; i++)
        {
            lambdas[i].setZero(prob_.constraints.size());
        }

        penaltys.resize(prob_.horizon()+1);
        for(size_t i = 0; i < prob_.horizon()+1; i++)
        {
            penaltys[i].setZero(prob_.constraints.size());
        }

        constraints_val.resize(prob_.horizon()+1);
        for(size_t i = 0; i < prob_.horizon()+1; i++)
        {
            constraints_val[i].setZero(prob_.constraints.size());
        }

        fx.setZero(prob_.state_size(), prob_.state_size());
        fu.setZero(prob_.state_size(), prob_.input_size());
    }

    Result generate_trajectory(const Eigen::VectorXd &x0)
    {
        // slide ws data
        for(size_t i = 0; i < prob_.horizon()-1; i++)
        {
            U[i] = U[i + 1];
        }

        for(size_t i = 0; i < prob_.horizon(); i++)
        {
            X[i] = X[i + 1];
        }

        for(size_t i = 0; i < prob_.horizon()-1; i++)
        {
            lambdas[i] = lambdas[i + 1];
        }

        for(size_t i = 0; i < prob_.horizon(); i++)
        {
            penaltys[i].setConstant(config_.penalty_initial);
        }

        // simple iLQR
        if(not has_constraints())
        {
            return ilqr(x0);
        }

        for(size_t i = 0; i < config_.max_iter; i++)
        {
            auto ret = ilqr(x0);

            if(ret == Result::FAILED)
            {
                // debug("sub iLQR failed");
                return ret;
            }

            update_duals();
            double u_max = update_penalties();

            if(c_max < config_.constraint_torelance)
            {
                // debug("constraint torelance reached: " << c_max);
                return Result::SUCCESS;
            }

            if(u_max >= config_.penalty_max)
            {
                // debug("max penalty exceeded");
                return Result::MAX_PENALTY_EXCEEDED;
            }
        }

        // debug("max iter reached");
        return Result::MAX_ITER_REACHED;
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

    Result ilqr(const Eigen::VectorXd &x0)
    {
        rho = config_.reg_initial;
        drho = 0.0;

        rollout_trajectory(x0);

        double J = total_cost(X, U);
        for(size_t itr = 0; itr < config_.max_ilqr_iter; ++itr)
        {
            bool backward_done = backward_pass();
            if(not backward_done)
            {
                // debug("backward pass failed");
                return Result::FAILED;
            }

            double new_J = forward_pass(x0, J);

            // torelance check
            if(std::abs(new_J - J) < config_.cost_torelance)
            {
                return Result::SUCCESS;
            }
            J = new_J;
        }

        // debug("max inner iter reached");
        return Result::MAX_INNER_ITER_REACHED;
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
    }

    void decrease_regularization()
    {
        drho = std::min(drho/config_.reg_scale_factor, 1.0/config_.reg_scale_factor);
        rho = std::max(config_.reg_min, rho*drho);
    }

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
        for (size_t i = 0; i < prob_.horizon(); i++)
        {
            J += prob_.cost->eval(X[i], U[i], i) + arglag_cost(X[i], U[i], i);
        }
        // Todo: add terminal arglag term
        J += prob_.cost->eval_terminal(X[prob_.horizon()]);
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
        double c_max_dummy;
        Iuvec(tmp_constraint_val, i, Ivec, c_max_dummy);
        double cost = ((lambdas[i].transpose() + 0.5*tmp_constraint_val.transpose()*Ivec.asDiagonal()) * tmp_constraint_val)[0];
        return cost;
    }

    void Iuvec(const Eigen::VectorXd &constraint_val, size_t i, Eigen::VectorXd &Iuvec, double &c_max)
    {
        auto &constraints = prob_.constraints;
        for(size_t j = 0; j < constraints.size(); j++)
        {
            if(constraints[j]->type == OCPConstraintType::Ineq)
            {
                if(constraint_val(j) < 0.0 && std::abs(lambdas[i][j]) < config_.dual_torelance)
                {
                    Iuvec[j] = 0.0;
                }
                else
                {
                    Iuvec[j] = penaltys[i][j];
                    c_max = std::max(c_max, constraint_val(j));
                }
            }
            else
            {
                Iuvec[j] = penaltys[i][j];
                c_max = std::max(c_max, std::abs(constraint_val(j)));
            }
        }
    }

    bool backward_pass()
    {
        auto &constraints = prob_.constraints;
        Eigen::VectorXd Ivec(constraints.size());

        // Todo: add terminal constraints term
        Vx = prob_.cost->jacobian_x_terminal(X.back());
        Vxx = prob_.cost->hessian_xx_terminal(X.back());

        size_t rho_increase_count = 0;
        c_max = 0.0;
        dV1 = 0.0;
        dV2 = 0.0;
        Eigen::MatrixXd Quu_reg;
        Eigen::MatrixXd Quu_inv;
        Eigen::MatrixXd cx(constraints.size(),  prob_.state_size());
        Eigen::MatrixXd cu(constraints.size(),  prob_.input_size());
        for(int i = static_cast<int>(prob_.horizon()) - 1; i >= 0;)
        {
            fx = prob_.dynamics->jacobian_x(X[i], U[i]);
            fu = prob_.dynamics->jacobian_u(X[i], U[i]);

            // argumented lagrangian
            if(has_constraints())
            {
                constraints_val[i] = constraints.eval_all_vec(X[i], U[i]);
                for(size_t j = 0; j < constraints.size(); j++)
                {
                    cx.row(j) = constraints[j]->grad_x(X[i], U[i]);
                }

                for(size_t j = 0; j < constraints.size(); j++)
                {
                    cu.row(j) = constraints[j]->grad_u(X[i], U[i]);
                }

                Iuvec(constraints_val[i], i, Ivec, c_max);
                Qx  = prob_.cost->jacobian_x(X[i], U[i], i) + fx.transpose() * Vx + cx.transpose() * (lambdas[i] + Ivec.asDiagonal() * constraints_val[i]);
                Qu  = prob_.cost->jacobian_u(X[i], U[i], i) + fu.transpose() * Vx + cu.transpose() * (lambdas[i] + Ivec.asDiagonal() * constraints_val[i]);
                Qxx = prob_.cost->hessian_xx(X[i], U[i], i) + fx.transpose() * Vxx * fx + cx.transpose() * Ivec.asDiagonal() * cx;
                Quu = prob_.cost->hessian_uu(X[i], U[i], i) + fu.transpose() * Vxx * fu + cu.transpose() * Ivec.asDiagonal() * cu;
                Qux = prob_.cost->hessian_ux(X[i], U[i], i) + fu.transpose() * Vxx * fx + cu.transpose() * Ivec.asDiagonal() * cx;
            }
            else
            {
                Qx  = prob_.cost->jacobian_x(X[i], U[i], i) + fx.transpose() * Vx;
                Qu  = prob_.cost->jacobian_u(X[i], U[i], i) + fu.transpose() * Vx;
                Qxx = prob_.cost->hessian_xx(X[i], U[i], i) + fx.transpose() * Vxx * fx;
                Quu = prob_.cost->hessian_uu(X[i], U[i], i) + fu.transpose() * Vxx * fu;
                Qux = prob_.cost->hessian_ux(X[i], U[i], i) + fu.transpose() * Vxx * fx;
            }

            // Quu_reg = Quu + rho * I;
            // Quu_inv = Quu_reg.inverse();
            // K[i] = -Quu_inv * Qux;
            // d[i] = -Quu_inv * Qu;
            Quu_reg = Quu;
            for(int j = 0; j < Quu.rows(); j++)
            {
                Quu_reg(j, j) += rho;
            }
            Eigen::LLT<Eigen::MatrixXd> Quu_chol(Quu_reg);
            if(Quu_chol.info() == Eigen::Success)
            {
                // du = K*dx + d
                K[i] = -Quu_chol.solve(Qux);
                d[i] = -Quu_chol.solve(Qu);
            }
            else
            {
                // debug("Quu is not positive definite");
                increase_regularization();
                rho_increase_count++;

                if(rho_increase_count > config_.reg_max_count)
                {
                    // debug("rho increase count exceeded");
                    return false;
                }
                continue;
            }

            // update Vx, Vxx
            Vxx = Qxx + (K[i].transpose()*Quu*K[i]) + K[i].transpose()*Qux + Qux.transpose()*K[i];
            Vx = Qx + K[i].transpose()*Quu*d[i] + K[i].transpose()*Qu + Qux.transpose()*d[i];

            // calclate dV1, dV2
            dV1 += (d[i].transpose()*Qu)[0];
            dV2 += (0.5*d[i].transpose()*Quu*d[i])[0];

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
    Eigen::MatrixXd fx, fu;
    double dV1, dV2;

    std::vector<Eigen::VectorXd> constraints_val;
    std::vector<Eigen::VectorXd> lambdas, penaltys;
    double rho;
    double drho;
    double c_max;
};

// class ALTRO : private detail::ALiLQR<DiscreteNonlinearOCP>
// {
//     using ALiLQR = detail::ALiLQR<DiscreteNonlinearOCP>;
// public:
//     using ALTROResult = detail::Result;
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