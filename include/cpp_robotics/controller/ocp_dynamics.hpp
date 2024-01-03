#pragma once

#include <Eigen/Dense>
#include <cpp_robotics/optimize/derivative.hpp>
#include <cpp_robotics/system/discret.hpp>
#include <memory>

namespace cpp_robotics
{

class OCPDynamics
{
public:
    using SharedPtr = std::shared_ptr<OCPDynamics>;

    double eps = 1e-6;
    OCPDynamics(size_t nx, size_t nu, size_t horizon):
        nx_(nx), nu_(nu), horizon_(horizon) {}

    virtual Eigen::VectorXd eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const = 0;

    virtual Eigen::MatrixXd jacobian_x(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        return cpp_robotics::derivative(
            std::bind(&OCPDynamics::eval, this, std::placeholders::_1, u), x, eps);
    }

    virtual Eigen::MatrixXd jacobian_u(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        return cpp_robotics::derivative(
            std::bind(&OCPDynamics::eval, this, x, std::placeholders::_1), u, eps);
    }

    size_t state_size() const { return nx_; }
    size_t input_size() const { return nu_; }
    size_t horizon() const { return horizon_; }

private:
    const size_t nx_;
    const size_t nu_;
    const size_t horizon_;
};

class OCPDiscreteLinearDynamics : public OCPDynamics
{
public:
    OCPDiscreteLinearDynamics(const size_t nx, const size_t nu, const size_t horizon):
        OCPDynamics(nx, nu, horizon),
        A(Eigen::MatrixXd::Zero(nx, nx)),
        B(Eigen::MatrixXd::Zero(nx, nu)){}

    OCPDiscreteLinearDynamics(const Eigen::MatrixXd &A, const Eigen::MatrixXd &B, size_t horizon):
        OCPDynamics(A.rows(), B.cols(), horizon),
        A(A),
        B(B){}

    Eigen::VectorXd eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        return A * x + B * u;
    }

    Eigen::MatrixXd jacobian_x(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        (void) x;
        (void) u;
        return A;
    }

    Eigen::MatrixXd jacobian_u(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        (void) x;
        (void) u;
        return B;
    }

private:
    Eigen::MatrixXd A;
    Eigen::MatrixXd B;
};

class OCPContinuousLinearDynamics : public OCPDynamics
{
public:
    OCPContinuousLinearDynamics(const size_t nx, const size_t nu, const size_t horizon):
        OCPDynamics(nx, nu, horizon){}

    void set_continuous_dynamics(const Eigen::MatrixXd &Acon, const Eigen::MatrixXd &Bcon, double dt)
    {
        std::tie(A, B) = Discret::discritize(Acon, Bcon, dt);
    }

    Eigen::VectorXd eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        return A * x + B * u;
    }

    Eigen::MatrixXd jacobian_x(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        (void) x;
        (void) u;
        return A;
    }

    Eigen::MatrixXd jacobian_u(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        (void) x;
        (void) u;
        return B;
    }

private:
    Eigen::MatrixXd A;
    Eigen::MatrixXd B;
};

// using OCPDiscreteNonlinearDynamics = OCPDynamics;
class OCPDiscreteNonlinearDynamics : public OCPDynamics
{
public:
    OCPDiscreteNonlinearDynamics(size_t nx, size_t nu, size_t horizon):
        OCPDynamics(nx, nu, horizon){}
};

class OCPContinuousNonlinearDynamics : public OCPDynamics
{
public:
    OCPContinuousNonlinearDynamics(size_t nx, size_t nu, size_t horizon, double dt):
        OCPDynamics(nx, nu, horizon), dt_(dt) {}

    virtual Eigen::VectorXd dynamics(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const = 0;

    Eigen::VectorXd eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override final
    {
        // Todo: other integration methods
        return x + dt_ * dynamics(x, u);
    }

    double dt() const { return dt_; }
private:
    double dt_;
};


}