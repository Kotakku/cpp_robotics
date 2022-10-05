#include <gtest/gtest.h>

#include <cpp_robotics/optimize/optimize.hpp>
#include <cpp_robotics/algorithm/auto_diff.hpp>

#define EXPECT_NEAR_VEC(v1, v2, eps)\
    EXPECT_NEAR((v1-v2).norm(), 0.0, eps)

TEST(fmin_search, rosenbrock_2d) {

    namespace cr = cpp_robotics;

    // 2変数 Rosenbrock関数
    // 最適解は x = (1, 1)
    auto f = [](Eigen::VectorXd x) -> double
    {
        return 100*( std::pow( (x(0) - std::pow(x(1),2)), 2) ) + std::pow(1 - x(1), 2);
    };

    auto g = [&](const Eigen::VectorXd &x)
    {
        return cr::derivative(f, x);
    };

    Eigen::VectorXd x_init = Eigen::VectorXd::Zero(2);
    auto [ret, rx, rcnt] = cr::quasi_newton_method(f, g, x_init);

    EXPECT_NEAR_VEC(rx, Eigen::Vector2d(1,1), 1e-5);
}

struct Rosenbrock2d
{
    template<typename T>
    void eval_func(const Eigen::Matrix<T,Eigen::Dynamic,1>& x, Eigen::Matrix<T,Eigen::Dynamic,1>& y)
    {
        y(0) = 100*( pow( (x(0) - pow(x(1),2)), 2) ) + pow(1 - x(1), 2);;
    } 
};

TEST(fmin_search, rosenbrock_2d_ad) {
    namespace cr = cpp_robotics;

    Eigen::VectorXd x_init = Eigen::VectorXd::Zero(2);
    Rosenbrock2d functor;
    cr::AutoDiffAdaptor<Rosenbrock2d> ad(functor, 2, 1);
    auto [ret, rx, rcnt] = cr::quasi_newton_method(ad.evalute_func_scalar(), ad.jacobian_func_row_vector(), x_init);

    EXPECT_NEAR_VEC(rx, Eigen::Vector2d(1,1), 1e-5);
}