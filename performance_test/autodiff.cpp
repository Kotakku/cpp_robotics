#include <iostream>
#include <Eigen/Dense>
#include <unsupported/Eigen/AutoDiff>
#include <chrono>

#include <cpp_robotics/optimize/derivative.hpp>

#define debug(x) std::cout << x << std::endl;
#define MAT_SIZE(mat) std::cout << #mat << " = " << mat.rows() << " x " << mat.cols() << std::endl;
#define MAT(mat) std::cout << #mat << " = " << std::endl << mat << std::endl;


template<class DerType = Eigen::VectorXd>
using ADScalar = Eigen::AutoDiffScalar<DerType>;

template<class DerType, int NX>
class ADVector : public Eigen::Matrix<ADScalar<DerType>, NX, 1>
{
public:
    ADVector(const size_t dim): 
        Eigen::Matrix<ADScalar<DerType>, NX, 1>(dim) 
    {
        for(size_t i = 0; i < dim; i++)
        {
            this->operator()(i).value() = 0;
            this->operator()(i).derivatives() = Eigen::VectorXd::Unit(dim, i);
        }
    }

    ADVector(const size_t dim, const DerType &x)
    {
        assert(static_cast<long int>(dim) == x.size());
        Eigen::Matrix<ADScalar<DerType>, NX, 1>::resize(dim);
        for(size_t i = 0; i < dim; i++)
        {
            this->operator()(i).value() = x(i);
            this->operator()(i).derivatives() = Eigen::VectorXd::Unit(dim, i);
        }
    }

    ADVector(const size_t dim, const size_t all_dim, const size_t start)
    {
        Eigen::Matrix<ADScalar<DerType>, NX, 1>::resize(dim);
        for(size_t i = 0; i < dim; i++)
        {
            this->operator()(i).value() = 0;
            this->operator()(i).derivatives() = Eigen::VectorXd::Unit(all_dim, start + i);
        }
    }

    ADVector(const size_t dim, const size_t all_dim, const size_t start, const DerType &x)
    {   
        assert(static_cast<long int>(dim) == x.size());
        Eigen::Matrix<ADScalar<DerType>, NX, 1>::resize(dim);
        for(size_t i = 0; i < dim; i++)
        {
            this->operator()(i).value() = x(i);
            this->operator()(i).derivatives() = Eigen::VectorXd::Unit(all_dim, start + i);
        }
    }
};

using ADVectorXd = ADVector<Eigen::VectorXd, Eigen::Dynamic>;

void test1()
{
    size_t nx = 3; // Dimension of x
    size_t nu = 2; // Dimension of u
    size_t n_total = nx + nu; // Total dimension

    // Initialize x and u with the total dimension
    ADVectorXd x(nx, n_total, 0); 
    ADVectorXd u(nu, n_total, nx); // Note: u's derivatives start after x's
    ADVectorXd y(nx, n_total, 0); // Note: y's derivatives start at 0

    y(0) = sin(x(0)) + u(0); // This should now work without dimension mismatch

    MAT_SIZE(x);
    MAT_SIZE(u);
    debug(u(0));
}

class OCPAD
{
public:
    OCPAD():
        nx_(3), nu_(2)
    {}

    void dynamics(const ADVectorXd&x, const ADVectorXd&u, ADVectorXd &x_next) const
    {
        // debug("dynamics");
        x_next << x[0] + u[0] * cos(x[2]) - u[1] * sin(x[2]),
                  x[1] + u[0] * sin(x[2]) + u[1] * cos(x[2]),
                  x[2] + u[0] - u[1]; 
    }

    Eigen::VectorXd dynamics_eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("dynamics_eval");
        ADVectorXd x_ad = x_vec(x);
        ADVectorXd u_ad = u_vec(u);
        ADVectorXd x_next = x_vec();
        dynamics(x_ad, u_ad, x_next);
        Eigen::VectorXd x_next_val(nx_);
        x_next[0] = x_next[0].value();
        // for (size_t i = 0; i < nx_; i++)
        //     x_next_val[i] = x_next[i].value();
        return x_next_val;
    }

    Eigen::MatrixXd dynamics_jacobian_fx(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("dynamics_jacobian_fx");
        ADVectorXd x_ad = x_vec(x);
        ADVectorXd u_ad = u_vec(u);
        ADVectorXd x_next = x_vec();
        dynamics(x_ad, u_ad, x_next);
        Eigen::MatrixXd J_fx(nx_, nx_);
        for (size_t i = 0; i < nx_; i++)
            J_fx.row(i) = x_next[i].derivatives().head(nx_);
        return J_fx;
    }

    Eigen::MatrixXd dynamics_jacobian_fu(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("dynamics_jacobian_fu");
        ADVectorXd x_ad = x_vec(x);
        ADVectorXd u_ad = u_vec(u);
        ADVectorXd x_next = x_vec();
        dynamics(x_ad, u_ad, x_next);
        Eigen::MatrixXd J_fu(nx_, nu_);
        for (size_t i = 0; i < nx_; i++)
            J_fu.row(i) = x_next[i].derivatives().tail(nu_);
        return J_fu;
    }

    void cost(const ADVectorXd&x, const ADVectorXd&u, ADScalar<Eigen::VectorXd> &l) const
    {
        // debug("cost");
        l = (x.transpose()*x + u.transpose()*u)[0];
    }

    double cost_eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("cost_eval");
        ADVectorXd x_ad = x_vec(x);
        ADVectorXd u_ad = u_vec(u);
        ADScalar<Eigen::VectorXd> l;
        cost(x_ad, u_ad, l);
        return l.value();
    }

    Eigen::VectorXd cost_jacobian_fx(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("cost_jacobian_fx");
        ADVectorXd x_ad = x_vec(x);
        ADVectorXd u_ad = u_vec(u);
        ADScalar<Eigen::VectorXd> l;
        cost(x_ad, u_ad, l);
        Eigen::VectorXd J_fx(nx_);
        for (size_t i = 0; i < nx_; i++)
            J_fx[i] = l.derivatives()(i);
        return J_fx;
    }

    Eigen::MatrixXd cost_hessian_fxx(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("cost_hessian_fxx");
        ADVectorXd x_ad = x_vec(x);
        ADVectorXd u_ad = u_vec(u);
        ADScalar<Eigen::VectorXd> l;
        cost(x_ad, u_ad, l);
        Eigen::MatrixXd H_fxx(nx_, nx_);
        // for (size_t i = 0; i < nx_; i++)
        //     H_fxx.row(i) = l.derivatives().tail(nx_).transpose().block(i, 0, 1, nx_);
        return H_fxx;
    }

private:
    ADVectorXd x_vec() const
    {
        return ADVectorXd(nx_, nx_ + nu_, 0);
    }

    ADVectorXd x_vec(const Eigen::VectorXd &x) const
    {
        return ADVectorXd(nx_, nx_ + nu_, 0, x);
    }

    ADVectorXd u_vec() const
    {
        return ADVectorXd(nu_, nx_ + nu_, nx_);
    }

    ADVectorXd u_vec(const Eigen::VectorXd &u) const
    {
        return ADVectorXd(nu_, nx_ + nu_, nx_, u);
    }

    const size_t nx_, nu_;
};

class OCPManual
{
public:
    OCPManual():
        nx_(3), nu_(2)
    {}

    void dynamics(const Eigen::VectorXd&x, const Eigen::VectorXd&u, Eigen::VectorXd &x_next) const
    {
        // debug("dynamics");
        x_next << x[0] + u[0] * cos(x[2]) - u[1] * sin(x[2]),
                  x[1] + u[0] * sin(x[2]) + u[1] * cos(x[2]),
                  x[2] + u[0] - u[1]; 
    }

    Eigen::VectorXd dynamics_eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("dynamics_eval");
        Eigen::VectorXd x_next(nx_);
        dynamics(x, u, x_next);
        return x_next;
    }

    Eigen::MatrixXd dynamics_jacobian_fx(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("dynamics_jacobian_fx");
        Eigen::MatrixXd J_fx(nx_, nx_);
        J_fx << 1, 0, -u[0]*sin(x[2])-u[1]*cos(x[2]),
                0, 1, u[0]*cos(x[2])-u[1]*sin(x[2]),
                0, 0, 1;
        return J_fx;
    }

    Eigen::MatrixXd dynamics_jacobian_fu(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("dynamics_jacobian_fu");
        Eigen::MatrixXd J_fu(nx_, nu_);
        J_fu << cos(x[2]), -sin(x[2]),
                sin(x[2]), cos(x[2]),
                1, -1;
        return J_fu;
    }

    void cost(const Eigen::VectorXd&x, const Eigen::VectorXd&u, double &l) const
    {
        // debug("cost");
        l = (x.transpose()*x + u.transpose()*u)[0];
    }

    double cost_eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("cost_eval");
        double l;
        cost(x, u, l);
        return l;
    }

    Eigen::VectorXd cost_jacobian_fx(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("cost_jacobian_fx");
        Eigen::VectorXd J_fx(nx_);
        J_fx = 2 * x;
        return J_fx;
    }

    Eigen::MatrixXd cost_hessian_fxx(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("cost_hessian_fxx");
        Eigen::MatrixXd H_fxx(nx_, nx_);
        H_fxx = 2 * Eigen::MatrixXd::Identity(nx_, nx_);
        return H_fxx;
    }

private:
    const size_t nx_, nu_;
};

class OCPFiniteDifference
{
public:
    OCPFiniteDifference():
        nx_(3), nu_(2)
    {}

    void dynamics(const Eigen::VectorXd&x, const Eigen::VectorXd&u, Eigen::VectorXd &x_next) const
    {
        // debug("dynamics");
        x_next << x[0] + u[0] * cos(x[2]) - u[1] * sin(x[2]),
                  x[1] + u[0] * sin(x[2]) + u[1] * cos(x[2]),
                  x[2] + u[0] - u[1]; 
    }

    Eigen::VectorXd dynamics_eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("dynamics_eval");
        Eigen::VectorXd x_next(nx_);
        dynamics(x, u, x_next);
        return x_next;
    }

    Eigen::MatrixXd dynamics_jacobian_fx(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("dynamics_jacobian_fx");
        Eigen::MatrixXd J_fx(nx_, nx_);
        J_fx = cpp_robotics::derivative(
            std::bind(&OCPFiniteDifference::dynamics_eval, this, std::placeholders::_1, u), x);
        return J_fx;
    }

    Eigen::MatrixXd dynamics_jacobian_fu(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("dynamics_jacobian_fu");
        Eigen::MatrixXd J_fu(nx_, nu_);
        J_fu = cpp_robotics::derivative(
            std::bind(&OCPFiniteDifference::dynamics_eval, this, x, std::placeholders::_1), u);
        return J_fu;
    }

    void cost(const Eigen::VectorXd&x, const Eigen::VectorXd&u, double &l) const
    {
        // debug("cost");
        l = (x.transpose()*x + u.transpose()*u)[0];
    }

    double cost_eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("cost_eval");
        double l;
        cost(x, u, l);
        return l;
    }

    Eigen::VectorXd cost_jacobian_fx(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("cost_jacobian_fx");
        Eigen::VectorXd J_fx(nx_);
        J_fx = cpp_robotics::derivative(
            std::bind(&OCPFiniteDifference::cost_eval, this, std::placeholders::_1, u), x);
        return J_fx;
    }

    Eigen::MatrixXd cost_hessian_fxx(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const
    {
        // debug("cost_hessian_fxx");
        Eigen::MatrixXd H_fxx(nx_, nx_);
        H_fxx = cpp_robotics::second_derivative(
            std::bind(&OCPFiniteDifference::cost_eval, this, std::placeholders::_1, u), x);
        return H_fxx;
    }

private:
    const size_t nx_, nu_;
};

int main()
{
    // test1();

    constexpr size_t N = 10000;

    OCPAD ocpad;
    OCPManual ocpmanual;
    OCPFiniteDifference ocpfd;

    double eval_time = 0;
    double jacobian_fx_time = 0;
    double cost_jacobian_fx_time = 0;
    double cost_hessian_fxx_time = 0;

    Eigen::VectorXd x(3);
    Eigen::VectorXd u(2);


    std::cout << "AD" << std::endl;
    for(size_t i = 0; i < N; i++)
    {
        x = Eigen::VectorXd::Random(3);
        u = Eigen::VectorXd::Random(2);

        auto start = std::chrono::system_clock::now();
        Eigen::VectorXd x_next_ad = ocpad.dynamics_eval(x, u);
        auto end = std::chrono::system_clock::now();
        eval_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        start = std::chrono::system_clock::now();
        Eigen::MatrixXd J_fx_ad = ocpad.dynamics_jacobian_fx(x, u);
        end = std::chrono::system_clock::now();
        jacobian_fx_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        start = std::chrono::system_clock::now();
        Eigen::VectorXd J_l_fx_ad = ocpad.cost_jacobian_fx(x, u);
        end = std::chrono::system_clock::now();
        cost_jacobian_fx_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        // start = std::chrono::system_clock::now();
        // Eigen::MatrixXd H_l_fxx_ad = ocpad.cost_hessian_fxx(x, u);
        // end = std::chrono::system_clock::now();
        // cost_hessian_fxx_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }
    std::cout << "eval_time             = " << eval_time << " ns" << std::endl;
    std::cout << "jacobian_fx_time      = " << jacobian_fx_time << " ns" << std::endl;
    std::cout << "cost_jacobian_fx_time = " << cost_jacobian_fx_time << " ns" << std::endl;
    std::cout << "cost_hessian_fxx_time = " << cost_hessian_fxx_time << " ns" << std::endl;

    eval_time = 0;
    jacobian_fx_time = 0;
    cost_jacobian_fx_time = 0;
    cost_hessian_fxx_time = 0;
    std::cout << "Manual" << std::endl;
    for(size_t i = 0; i < N; i++)
    {
        x = Eigen::VectorXd::Random(3);
        u = Eigen::VectorXd::Random(2);

        auto start = std::chrono::system_clock::now();
        Eigen::VectorXd x_next_manual = ocpmanual.dynamics_eval(x, u);
        auto end = std::chrono::system_clock::now();
        eval_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        start = std::chrono::system_clock::now();
        Eigen::MatrixXd J_fx_manual = ocpmanual.dynamics_jacobian_fx(x, u);
        end = std::chrono::system_clock::now();
        jacobian_fx_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        start = std::chrono::system_clock::now();
        Eigen::VectorXd J_l_fx_manual = ocpmanual.cost_jacobian_fx(x, u);
        end = std::chrono::system_clock::now();
        cost_jacobian_fx_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        start = std::chrono::system_clock::now();
        Eigen::MatrixXd H_l_fxx_manual = ocpmanual.cost_hessian_fxx(x, u);
        end = std::chrono::system_clock::now();
        cost_hessian_fxx_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }
    std::cout << "eval_time             = " << eval_time << " ns" << std::endl;
    std::cout << "jacobian_fx_time      = " << jacobian_fx_time << " ns" << std::endl;
    std::cout << "cost_jacobian_fx_time = " << cost_jacobian_fx_time << " ns" << std::endl;
    std::cout << "cost_hessian_fxx_time = " << cost_hessian_fxx_time << " ns" << std::endl;

    eval_time = 0;
    jacobian_fx_time = 0;
    cost_jacobian_fx_time = 0;
    cost_hessian_fxx_time = 0;
    std::cout << "FiniteDifference" << std::endl;
    for(size_t i = 0; i < N; i++)
    {
        x = Eigen::VectorXd::Random(3);
        u = Eigen::VectorXd::Random(2);

        auto start = std::chrono::system_clock::now();
        Eigen::VectorXd x_next_fd = ocpfd.dynamics_eval(x, u);
        auto end = std::chrono::system_clock::now();
        eval_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        start = std::chrono::system_clock::now();
        Eigen::MatrixXd J_fx_fd = ocpfd.dynamics_jacobian_fx(x, u);
        end = std::chrono::system_clock::now();
        jacobian_fx_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        start = std::chrono::system_clock::now();
        Eigen::VectorXd J_l_fx_fd = ocpfd.cost_jacobian_fx(x, u);
        end = std::chrono::system_clock::now();
        cost_jacobian_fx_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        start = std::chrono::system_clock::now();
        Eigen::MatrixXd H_l_fxx_fd = ocpfd.cost_hessian_fxx(x, u);
        end = std::chrono::system_clock::now();
        cost_hessian_fxx_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    }
    std::cout << "eval_time             = " << eval_time << " ns" << std::endl;
    std::cout << "jacobian_fx_time      = " << jacobian_fx_time << " ns" << std::endl;
    std::cout << "cost_jacobian_fx_time = " << cost_jacobian_fx_time << " ns" << std::endl;
    std::cout << "cost_hessian_fxx_time = " << cost_hessian_fxx_time << " ns" << std::endl;


    return 0;
}