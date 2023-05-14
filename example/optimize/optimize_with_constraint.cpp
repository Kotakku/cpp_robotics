#include <iostream>
#include <Eigen/Dense>
#include <cpp_robotics/optimize.hpp>

int main()
{
    using namespace cpp_robotics;

    std::cout << "test" << std::endl;

    auto f = [](Eigen::VectorXd x)
    {
        return std::pow(x(0)-2,2) + std::pow(x(1),2);
    };

    Eigen::VectorXd x_init = Eigen::VectorXd::Zero(2);

    ConstraintArray con;
    con.push_back({
        Constraint::Type::Ineq,
        [](Eigen::VectorXd x)
        {
            return (std::pow(x(0), 2) + std::pow(x(1), 2)) - 1;
        }
    });

    {
        x_init(0) = 0.4;
        x_init(1) = 0.5;
        auto [ret, rx, rcnt] = penalty_method(f, con, x_init);
        std::cout << rx.transpose() << "(norm: " << rx.norm() << "), " << rcnt << std::endl;
    }

    {
        x_init(0) = 0.4;
        x_init(1) = 0.5;
        auto [ret, rx, rcnt] = barrier_method(f, con, x_init);
        std::cout << rx.transpose() << "(norm: " << rx.norm() << "), " << rcnt << std::endl;
    }
}