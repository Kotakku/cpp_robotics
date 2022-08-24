#include <iostream>
#include <Eigen/Dense>
#include <cpp_robotics/optimize/optimize.hpp>

int main()
{
    namespace cr = cpp_robotics;

    std::cout << "test" << std::endl;

    auto f = [](Eigen::VectorXd x) -> double
    {
        return 100*( std::pow(  (x(1) - std::pow(x(0),2)), 2) ) + std::pow(1 - x(1), 2);
    };

    auto g = [&](const Eigen::VectorXd &x) -> Eigen::VectorXd
    {
        Eigen::VectorXd grad(2);

        grad <<
            -400*(x(1) - std::pow(x(0),2))*x(0) - 2*(1-x(0)),
            200*(x(1)-std::pow(x(0), 2));
        return grad;
    };
    // auto g = [&](const Eigen::VectorXd &x)
    // {
    //     return cr::derivative(f, x);
    // };

    Eigen::VectorXd x_init = Eigen::VectorXd::Zero(2);
    x_init(0) = -1;
    x_init(1) = 2;
    {
        auto [ret, rx, rcnt] = cr::quasi_newton_method(f, g, x_init);
        std::cout << "quasi_newton_method" << std::endl;
        std::cout << rx.transpose() << ", " << rcnt << std::endl;
    }
}