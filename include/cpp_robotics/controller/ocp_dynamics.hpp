#pragma once

#include <Eigen/Dense>
#include <cpp_robotics/optimize/derivative.hpp>
#include <cpp_robotics/system/discret.hpp>
#include <cpp_robotics/algorithm/auto_diff.hpp>
#include <cpp_robotics/system/dynamics_integrate.hpp>
#include <memory>

namespace cpp_robotics
{

class OCPDynamics
{
public:
    using SharedPtr = std::shared_ptr<OCPDynamics>;

    double eps = 1e-6;
    OCPDynamics(size_t nx, size_t nu):
        nx_(nx), nu_(nu) {}

    virtual Eigen::VectorXd eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) = 0;

    virtual Eigen::MatrixXd jacobian_x(const Eigen::VectorXd &x, const Eigen::VectorXd &u) 
    {
        return derivative(std::bind(&OCPDynamics::eval, this, std::placeholders::_1, u), x, eps);
    }

    virtual Eigen::MatrixXd jacobian_u(const Eigen::VectorXd &x, const Eigen::VectorXd &u)
    {
        return derivative(std::bind(&OCPDynamics::eval, this, x, std::placeholders::_1), u, eps);
    }

    size_t state_size() const { return nx_; }
    size_t input_size() const { return nu_; }
private:
    const size_t nx_;
    const size_t nu_;
};

class OCPDiscreteLinearDynamics : public OCPDynamics
{
public:
    OCPDiscreteLinearDynamics(const size_t nx, const size_t nu):
        OCPDynamics(nx, nu),
        A(Eigen::MatrixXd::Zero(nx, nx)),
        B(Eigen::MatrixXd::Zero(nx, nu)){}

    OCPDiscreteLinearDynamics(const Eigen::MatrixXd &A, const Eigen::MatrixXd &B):
        OCPDynamics(A.rows(), B.cols()),
        A(A),
        B(B){}

    Eigen::VectorXd eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) override
    {
        return A * x + B * u;
    }

    Eigen::MatrixXd jacobian_x(const Eigen::VectorXd &x, const Eigen::VectorXd &u) override
    {
        (void) x;
        (void) u;
        return A;
    }

    Eigen::MatrixXd jacobian_u(const Eigen::VectorXd &x, const Eigen::VectorXd &u) override
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
    OCPContinuousLinearDynamics(const size_t nx, const size_t nu):
        OCPDynamics(nx, nu){}

    OCPContinuousLinearDynamics(const Eigen::MatrixXd &Acon, const Eigen::MatrixXd &Bcon, double dt):
        OCPDynamics(Acon.rows(), Bcon.cols())
    {
        set_continuous_dynamics(Acon, Bcon, dt);
    }

    void set_continuous_dynamics(const Eigen::MatrixXd &Acon, const Eigen::MatrixXd &Bcon, double dt)
    {
        std::tie(A, B) = Discret::discritize(Acon, Bcon, dt);
    }

    Eigen::VectorXd eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) override
    {
        return A * x + B * u;
    }

    Eigen::MatrixXd jacobian_x(const Eigen::VectorXd &x, const Eigen::VectorXd &u) override
    {
        (void) x;
        (void) u;
        return A;
    }

    Eigen::MatrixXd jacobian_u(const Eigen::VectorXd &x, const Eigen::VectorXd &u) override
    {
        (void) x;
        (void) u;
        return B;
    }

private:
    Eigen::MatrixXd A;
    Eigen::MatrixXd B;
};

class OCPDiscreteNonlinearDynamics : public OCPDynamics
{
public:
    OCPDiscreteNonlinearDynamics(size_t nx, size_t nu):
        OCPDynamics(nx, nu){}
};

enum class OCPIntegrationMethod
{
    ForwardEuler,
    ModifiedEuler,
    RK4,
};

class OCPContinuousNonlinearDynamics : public OCPDynamics
{
public:
    OCPContinuousNonlinearDynamics(OCPIntegrationMethod method, size_t nx, size_t nu, double dt):
        OCPDynamics(nx, nu), method_(method), dt_(dt) {}

    virtual Eigen::VectorXd dynamics(const Eigen::VectorXd &x, const Eigen::VectorXd &u) = 0;

    Eigen::VectorXd eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) override
    {
        Eigen::VectorXd x_next(state_size());
        std::function<Eigen::VectorXd(const Eigen::VectorXd&, const Eigen::VectorXd&)> dynf = 
            std::bind(&OCPContinuousNonlinearDynamics::dynamics, this, std::placeholders::_1, u);
        switch (method_)
        {
            case OCPIntegrationMethod::ForwardEuler:
                x_next = integrate_forward_euler(dt_, x, u, dynf);
                break;
            case OCPIntegrationMethod::ModifiedEuler:
                x_next =  integrate_modified_euler(dt_, x, u, dynf);
                break;
            case OCPIntegrationMethod::RK4:
                x_next =  integrate_rk4(dt_, x, u, dynf);
                break;
        }
        return x_next;
    }

    double dt() const { return dt_; }
private:
    const OCPIntegrationMethod method_;
    double dt_;
};

namespace internal
{

template<typename DerClass, typename Scalar, typename = void>
struct has_ad_dynamics : std::false_type {};

template<typename DerClass, typename Scalar>
struct has_ad_dynamics<DerClass, Scalar,
    std::void_t<decltype(
        std::declval<const DerClass>().dynamics(
            std::declval<const Eigen::Matrix<Scalar, Eigen::Dynamic, 1>&>(),
            std::declval<const Eigen::Matrix<Scalar, Eigen::Dynamic, 1>&>(),
            std::declval<Eigen::Matrix<Scalar, Eigen::Dynamic, 1>&>()
        )
    )>
> : std::true_type {};

}

template<class Derived>
class OCPContinuousNonlinearDynamicsAD : public OCPDynamics
{
public:
    OCPContinuousNonlinearDynamicsAD(OCPIntegrationMethod method, size_t nx, size_t nu, double dt):
        OCPDynamics(nx, nu), method_(method), dt_(dt),
        x_(nx, nx + nu, 0), u_(nu, nx + nu, nx), dx_(nx, nx + nu, 0), x_next_(nx, nx + nu, 0)
    {
        static_assert(internal::has_ad_dynamics<Derived, Eigen::VectorXd::Scalar>::value, 
            "Derived class must implement void dynamics(const VectorX<Scalar> &x, const VectorX<Scalar> &u, VectorX<Scalar> &dx) for double");
        static_assert(internal::has_ad_dynamics<Derived, ADVectorXd::Scalar>::value, 
            "Derived class must implement void dynamics(const VectorX<Scalar> &x, const VectorX<Scalar> &u, VectorX<Scalar> &dx) for ADScalar");
    }

    Eigen::VectorXd eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) override
    {
        Eigen::VectorXd x_next(state_size());
        Eigen::VectorXd dx(state_size());
        std::function<Eigen::VectorXd(const Eigen::VectorXd&, const Eigen::VectorXd&)> dynf = 
            [&](auto &x, auto &u){ static_cast<const Derived*>(this)->dynamics(x, u, dx); return dx; };
        switch(method_)
        {
            case OCPIntegrationMethod::ForwardEuler:
                x_next = integrate_forward_euler(dt_, x, u, dynf);
                break;
            case OCPIntegrationMethod::ModifiedEuler:
                x_next =  integrate_modified_euler(dt_, x, u, dynf);
                break;
            case OCPIntegrationMethod::RK4:
                x_next =  integrate_rk4(dt_, x, u, dynf);
                break;
        }
        return x_next;
    }

    Eigen::MatrixXd jacobian_x(const Eigen::VectorXd &x, const Eigen::VectorXd &u) override
    {
        eval_ad(x, u);
        Eigen::MatrixXd J_fx(state_size(), state_size());
        for (size_t i = 0; i < state_size(); i++)
            J_fx.row(i) = x_next_[i].derivatives().head(state_size());
        return J_fx;
    }

    Eigen::MatrixXd jacobian_u(const Eigen::VectorXd &x, const Eigen::VectorXd &u) override
    {
        eval_ad(x, u);
        Eigen::MatrixXd J_fu(state_size(), input_size());
        for (size_t i = 0; i < state_size(); i++)
            J_fu.row(i) = x_next_[i].derivatives().tail(input_size());
        return J_fu;
    }

private:
    void eval_ad(const Eigen::VectorXd &x, const Eigen::VectorXd &u)
    {
        x_ = x;
        u_ = u;
        std::function<ADVectorXd(const ADVectorXd&, const ADVectorXd&)> dynf = 
            [&](auto &x, auto &u) { static_cast<const Derived*>(this)->dynamics(x, u, dx_); return dx_; };
        switch(method_)
        {
            case OCPIntegrationMethod::ForwardEuler:
                x_next_ = integrate_forward_euler(dt_, x_, u_, dynf);
                break;
            case OCPIntegrationMethod::ModifiedEuler:
                x_next_ = integrate_modified_euler(dt_, x_, u_, dynf);
                break;
            case OCPIntegrationMethod::RK4:
                x_next_ = integrate_rk4(dt_, x_, u_, dynf);
                break;
        }
    }

    const OCPIntegrationMethod method_;
    const double dt_;
    ADVectorXd x_, u_, dx_, x_next_; 
};

}