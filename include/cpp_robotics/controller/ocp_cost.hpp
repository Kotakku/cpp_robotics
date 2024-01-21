#pragma once

#include <Eigen/Dense>
#include <cpp_robotics/optimize/derivative.hpp>
#include <cpp_robotics/controller/ocp_dynamics.hpp>
#include <memory>

#include <iostream>

namespace cpp_robotics
{

class OCPCost
{
public:
    using SharedPtr = std::shared_ptr<OCPCost>;

    double eps = 1e-6;
    OCPCost(size_t nx, size_t nu, size_t horizon):
        nx_(nx), nu_(nu), horizon_(horizon){}

    OCPCost(std::shared_ptr<OCPDynamics> model, size_t horizon):
        OCPCost(model->state_size(), model->input_size(), horizon){}

    virtual double eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const = 0;

    virtual double eval_terminal(const Eigen::VectorXd &x) const = 0;

    virtual Eigen::VectorXd jacobian_x(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const
    {
        return derivative(
            std::bind(&OCPCost::eval, this, std::placeholders::_1, u, i), x, eps);
    }

    virtual Eigen::VectorXd jacobian_u(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const
    {
        return derivative(
            std::bind(&OCPCost::eval, this, x, std::placeholders::_1, i), u, eps);
    }

    virtual Eigen::MatrixXd hessian_xx(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const
    {
        return second_derivative(
            std::bind(&OCPCost::eval, this, std::placeholders::_1, u, i), x, eps);
    }

    virtual Eigen::MatrixXd hessian_uu(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const
    {
        return second_derivative(
            std::bind(&OCPCost::eval, this, x, std::placeholders::_1, i), u, eps);
    }

    virtual Eigen::MatrixXd hessian_ux(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const
    {
        return mixed_derivative(
            std::bind(&OCPCost::eval, this, std::placeholders::_1, std::placeholders::_2, i), x, u, eps);
    }

    virtual Eigen::VectorXd jacobian_x_terminal(const Eigen::VectorXd &x) const
    {
        return derivative(
            std::bind(&OCPCost::eval_terminal, this, std::placeholders::_1), x, eps);
    }

    virtual Eigen::MatrixXd hessian_xx_terminal(const Eigen::VectorXd &x) const
    {
        return second_derivative(
            std::bind(&OCPCost::eval_terminal, this, std::placeholders::_1), x, eps);
    }

    bool is_terminal(const size_t i) const
    {
        return i == horizon();
    }
    size_t state_size() const { return nx_; }
    size_t input_size() const { return nu_; }
    size_t horizon() const { return horizon_; }

private:
    const size_t nx_;
    const size_t nu_;
    const size_t horizon_;
};

class OCPCostQuadratic : public OCPCost
{
public:
    OCPCostQuadratic(OCPDynamics::SharedPtr model, size_t horizon):
        OCPCostQuadratic(model->state_size(), model->input_size(), horizon){}

    OCPCostQuadratic(size_t nx, size_t nu, size_t horizon):
        OCPCost(nx, nu, horizon)
    {
        Q = Eigen::MatrixXd::Zero(nx, nx);
        R = Eigen::MatrixXd::Zero(nu, nu);
        Qf = Eigen::MatrixXd::Zero(nx, nx);
    }

    double eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const override
    {
        (void) i;
        return (0.5 * x.transpose() * Q * x + 0.5*u.transpose() * R * u)(0);
    }

    Eigen::VectorXd jacobian_x(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const override
    {
        (void) i;
        (void) u;
        return Q * x;
    }

    Eigen::VectorXd jacobian_u(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const override
    {
        (void) i;
        (void) x;
        return R * u;
    }

    Eigen::MatrixXd hessian_xx(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const override
    {
        (void) i;
        (void) u;
        (void) x;
        return Q;
    }

    Eigen::MatrixXd hessian_uu(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const override
    {
        (void) i;
        (void) x;
        (void) u;
        return R;
    }

    Eigen::MatrixXd hessian_ux(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const override
    {
        (void) i;
        return Eigen::MatrixXd::Zero(u.rows(), x.rows());
    }

    double eval_terminal(const Eigen::VectorXd &x) const override
    {
        return (0.5 * x.transpose() * Qf * x)(0);
    }

    Eigen::VectorXd jacobian_x_terminal(const Eigen::VectorXd &x) const override
    {
        return Qf * x;
    }

    Eigen::MatrixXd hessian_xx_terminal(const Eigen::VectorXd &x) const override
    {
        (void) x;
        return Qf;
    }

    Eigen::MatrixXd Q;
    Eigen::MatrixXd R;
    Eigen::MatrixXd Qf;
};

class OCPCostServoQuadratic : public OCPCost
{
public:
    OCPCostServoQuadratic(OCPDynamics::SharedPtr model, size_t horizon):
        OCPCostServoQuadratic(model->state_size(), model->input_size(), horizon){}

    OCPCostServoQuadratic(size_t nx, size_t nu, size_t horizon):
        OCPCost(nx, nu, horizon)
    {
        Q = Eigen::MatrixXd::Zero(nx, nx);
        R = Eigen::MatrixXd::Zero(nu, nu);
        Qf = Eigen::MatrixXd::Zero(nx, nx);
        x_ref.resize(horizon+1);
        for(size_t i = 0; i < horizon+1; i++)
        {
            x_ref[i] = Eigen::MatrixXd::Zero(nx, 1);
        }
    }

    void set_x_ref_const(const Eigen::VectorXd &x_ref)
    {
        for(size_t i = 0; i < horizon()+1; i++)
        {
            this->x_ref[i] = x_ref;
        }
    }

    double eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const override
    {
        auto e = x - x_ref[i];
        return (0.5 * e.transpose() * Q * e + 0.5*u.transpose() * R * u)(0);
    }

    Eigen::VectorXd jacobian_x(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const override
    {
        (void) i;
        (void) u;
        return Q * (x - x_ref[i]);
    }

    Eigen::VectorXd jacobian_u(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const override
    {
        (void) i;
        (void) x;
        return R * u;
    }

    Eigen::MatrixXd hessian_xx(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const override
    {
        (void) i;
        (void) u;
        (void) x;
        return Q;
    }

    Eigen::MatrixXd hessian_uu(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const override
    {
        (void) i;
        (void) x;
        (void) u;
        return R;
    }

    Eigen::MatrixXd hessian_ux(const Eigen::VectorXd &x, const Eigen::VectorXd &u, const size_t i) const override
    {
        (void) i;
        return Eigen::MatrixXd::Zero(u.rows(), x.rows());
    }

    double eval_terminal(const Eigen::VectorXd &x) const override
    {
        auto e = x - x_ref[horizon()];
        return (0.5 * e.transpose() * Qf * e)(0);
    }

    Eigen::VectorXd jacobian_x_terminal(const Eigen::VectorXd &x) const override
    {
        auto e = x - x_ref[horizon()];
        return Qf * e;
    }

    Eigen::MatrixXd hessian_xx_terminal(const Eigen::VectorXd &x) const override
    {
        (void) x;
        return Qf;
    }

    Eigen::MatrixXd Q;
    Eigen::MatrixXd R;
    Eigen::MatrixXd Qf;
    std::vector<Eigen::MatrixXd> x_ref;
};

} // namespace cpp_robotics