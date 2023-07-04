#include <iostream>
#include <Eigen/Dense>
#include <cpp_robotics/optimize.hpp>

int main()
{
    namespace cr = cpp_robotics;

    // 目的関数
    auto f = [](Eigen::VectorXd x)
    {
        return std::pow(x(0)-2,2) + std::pow(x(1)-3,2);
    };

    auto g = [&](const Eigen::VectorXd &x)
    {
        return cr::derivative(f, x);
    };

    Eigen::VectorXd x_init = Eigen::VectorXd::Zero(2);
    x_init(0) = 0.1;
    x_init(1) = 0.1;
    {
        auto [ret, rx, rcnt] = cr::steepest_descent_method(f, g, x_init);
        std::cout << "steepest_descent_method" << std::endl;
        std::cout << "(" << rx.transpose() << "), itr: " << rcnt << std::endl;
    }

    x_init(0) = 0.1;
    x_init(1) = 0.1;
    {
        auto [ret, rx, rcnt] = cr::quasi_newton_method(f, g, x_init);
        std::cout << "quasi_newton_method" << std::endl;
        std::cout << "(" << rx.transpose() << "), itr: " << rcnt << std::endl;
    }
}