#include <iostream>
#include <cpp_robotics/algorithm/auto_diff.hpp>
#include <cpp_robotics/third_party/matplotlib-cpp/matplotlibcpp.h>
#include <cpp_robotics/utility/space.hpp>
#include <chrono>
#include <vector>

#include <cpp_robotics/optimize/derivative.hpp>

#define debug(x) std::cout << x << std::endl;
#define MAT_SIZE(mat) std::cout << #mat << " = " << mat.rows() << " x " << mat.cols() << std::endl;
#define MAT(mat) std::cout << #mat << " = " << std::endl << mat << std::endl;

using namespace cpp_robotics;

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
        nx_(3), nu_(2), x_(x_vec()), u_(u_vec()), x_next_(x_vec()){}

    template<class Scalar>
    using VectorX = Eigen::Matrix<Scalar, Eigen::Dynamic, 1>;

    template<class Scalar>
    void dynamics(const VectorX<Scalar>&x, const VectorX<Scalar>&u, VectorX<Scalar> &x_next) const
    {
        // debug("dynamics");
        x_next << x[0] + u[0] * cos(x[2]) - u[1] * sin(x[2]),
                  x[1] + u[0] * sin(x[2]) + u[1] * cos(x[2]),
                  x[2] + u[0] - u[1]; 
    }

    Eigen::VectorXd dynamics_eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u)
    {
        // debug("dynamics_eval");
        // x_ = x;
        // u_ = u;
        Eigen::VectorXd x_next(nx_);
        dynamics(x, u, x_next);
        // Eigen::VectorXd x_next_val(nx_);
        // for (size_t i = 0; i < nx_; i++)
            // x_next_val[i] = x_next_[i].value();
        return x_next;
    }

    Eigen::MatrixXd dynamics_jacobian_fx(const Eigen::VectorXd &x, const Eigen::VectorXd &u)
    {
        // debug("dynamics_jacobian_fx");
        x_ = x;
        u_ = u;
        dynamics(x_, u_, x_next_);
        Eigen::MatrixXd J_fx(nx_, nx_);
        for (size_t i = 0; i < nx_; i++)
            J_fx.row(i) = x_next_[i].derivatives().head(nx_);
        return J_fx;
    }

    Eigen::MatrixXd dynamics_jacobian_fu(const Eigen::VectorXd &x, const Eigen::VectorXd &u)
    {
        // debug("dynamics_jacobian_fu");
        x_ = x;
        u_ = u;
        dynamics(x_, u_, x_next_);
        Eigen::MatrixXd J_fu(nx_, nu_);
        for (size_t i = 0; i < nx_; i++)
            J_fu.row(i) = x_next_[i].derivatives().tail(nu_);
        return J_fu;
    }

    template<class Scalar>
    void cost(const VectorX<Scalar>&x, const VectorX<Scalar>&u, Scalar &l)
    {
        // debug("cost");
        l = (x.transpose()*x + u.transpose()*u)[0];
    }

    double cost_eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u)
    {
        // debug("cost_eval");
        double l;
        cost(x, u, l);
        return l;
    }

    Eigen::VectorXd cost_jacobian_fx(const Eigen::VectorXd &x, const Eigen::VectorXd &u)
    {
        // debug("cost_jacobian_fx");
        x_ = x;
        u_ = u;
        ADScalar<Eigen::VectorXd> l;
        cost(x_, u_, l);
        Eigen::VectorXd J_fx(nx_);
        for (size_t i = 0; i < nx_; i++)
            J_fx[i] = l.derivatives()(i);
        return J_fx;
    }

    Eigen::MatrixXd cost_hessian_fxx(const Eigen::VectorXd &x, const Eigen::VectorXd &u)
    {
        // debug("cost_hessian_fxx");
        x_ = x;
        u_ = u;
        ADScalar<Eigen::VectorXd> l;
        cost(x_, u_, l);
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
    ADVectorXd x_, u_, x_next_;
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

template<class OCPTester = OCPAD>
void check_val(OCPTester &ocp)
{
    Eigen::VectorXd x(3);
    Eigen::VectorXd u(2);
    x << 0.1, 0.2, 0.3;
    u << 0.4, 0.5;

    // dynamics 
    Eigen::VectorXd x_next_ad = ocp.dynamics_eval(x, u);
    Eigen::MatrixXd J_fx_ad = ocp.dynamics_jacobian_fx(x, u);

    // cost
    Eigen::VectorXd J_l_fx_ad = ocp.cost_jacobian_fx(x, u);
    Eigen::MatrixXd H_l_fxx_ad = ocp.cost_hessian_fxx(x, u);

    std::cout << "x_next_ad = " << std::endl << x_next_ad << std::endl;
    std::cout << "J_fx_ad = " << std::endl << J_fx_ad << std::endl;
    std::cout << "J_l_fx_ad = " << std::endl << J_l_fx_ad << std::endl;
    std::cout << "H_l_fxx_ad = " << std::endl << H_l_fxx_ad << std::endl;
}

#define TEST_FOR(ret_idx, cmd)\
    start = std::chrono::system_clock::now();\
    for(size_t i = 0; i < batchN; i++)\
    {\
        x = Eigen::VectorXd::Random(3);\
        u = Eigen::VectorXd::Random(2);\
        cmd;\
    }\
    end = std::chrono::system_clock::now();\
    time_vec[ret_idx] += (std::chrono::duration_cast<std::chrono::microseconds>(end - start).count());

template<class OCPTester = OCPAD>
std::vector<double> check_time(OCPTester &ocp)
{
    constexpr size_t loopN = 100;
    constexpr size_t batchN = 10000;

    Eigen::VectorXd x(3);
    Eigen::VectorXd u(2);
    std::chrono::system_clock::time_point start, end;

    std::vector<double> time_vec(4);

    for(size_t j = 0; j < loopN; j++)
    {
        TEST_FOR(0, Eigen::VectorXd x_next_ad = ocp.dynamics_eval(x, u));
        TEST_FOR(1, Eigen::MatrixXd J_fx_ad = ocp.dynamics_jacobian_fx(x, u));
        TEST_FOR(2, double J = ocp.cost_eval(x, u));
        TEST_FOR(3, Eigen::VectorXd J_l_fx_ad = ocp.cost_jacobian_fx(x, u));
        // TEST_FOR(Eigen::MatrixXd H_l_fxx_ad = ocp.cost_hessian_fxx(x, u));
    }
    std::cout << "eval_time             = " << time_vec[0] << " [us]" << std::endl;
    std::cout << "jacobian_fx_time      = " << time_vec[1] << " [us]" << std::endl;
    std::cout << "cost_eval_time        = " << time_vec[2] << " [us]" << std::endl;
    std::cout << "cost_jacobian_fx_time = " << time_vec[3] << " [us]" << std::endl;
    // std::cout << "cost_hessian_fxx_time = " << time_vec[4] << " [us]" << std::endl;

    return time_vec;
}

int main()
{
    OCPAD ocpad;
    OCPManual ocpmanual;
    OCPFiniteDifference ocpfd;

    std::cout << "------------- value check -------------" << std::endl;

    std::cout << "\nManual" << std::endl;
    check_val(ocpmanual);
    std::cout << "\nFiniteDifference" << std::endl;
    check_val(ocpfd);
    std::cout << "\nAD" << std::endl;
    check_val(ocpad);

    std::cout << "------------- time check -------------" << std::endl;
    std::cout << "\nManual" << std::endl;
    auto time_manual = check_time(ocpmanual);
    std::cout << "\nFiniteDifference" << std::endl;
    auto time_fd = check_time(ocpfd);
    std::cout << "\nAD" << std::endl;
    auto time_ad = check_time(ocpad);

    namespace plt = matplotlibcpp;
    size_t N = time_manual.size();
    double step = N;
    std::map<std::string, std::string> bar_map;
    bar_map["label"] = "Manual";
    plt::bar(linspace(0, N*step+0-1, N), time_manual, "black", "-", 1.0, bar_map);
    bar_map["label"] = "FiniteDiff";
    plt::bar(linspace(1, N*step+1-1, N), time_fd, "black", "-", 1.0, bar_map);
    bar_map["label"] = "AutoDiff";
    plt::bar(linspace(2, N*step+2-1, N), time_ad, "black", "-", 1.0, bar_map);
    plt::legend();
    plt::show();

    return 0;
}