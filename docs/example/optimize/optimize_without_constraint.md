# 無制約最適化

```cpp
#include <iostream>
#include <Eigen/Dense>
#include <cpp_robotics/optimize/optimize.hpp>

int main()
{
    namespace cr = cpp_robotics;

    std::cout << "test" << std::endl;

    auto f1 = [](Eigen::VectorXd x)
    {
        return std::sin(x(0)) + std::cos(x(1)) + std::sin(x(1) + M_PI) + std::sin(x(2));
    };
    std::cout << "f({0, 0, 0}) = " << f1(Eigen::VectorXd::Zero(3))<< std::endl;
    std::cout << "f'({0, 0, 0}) = " << cr::derivative(f1, Eigen::VectorXd::Zero(3)).transpose() << std::endl;


    auto f = [](Eigen::VectorXd x)
    {
        //return 4.5*(std::pow(std::cos(x(0)), 4) + std::pow(std::cos(x(1)), 4));
        // return std::sin(x(0)) + std::sin(x(1));
        return std::pow(x(0)-2,2) + std::pow(x(1)-3,2);
    };

    auto g = [&](const Eigen::VectorXd &x)
    {
        return cr::derivative(f, x);
    };

    // auto g = [](Eigen::VectorXd x)
    // {
    //     Eigen::VectorXd gval(2);

    //     gval(0) = 2*(x(0)-2);
    //     gval(1) = 2*(x(1)-3);

    //     return gval;
    // };

    // auto h = [](Eigen::VectorXd x)
    // {
    //     (void) x;
    //     Eigen::MatrixXd hval(2, 2);

    //     hval(0, 0) = 2;
    //     hval(1, 0) = 0;
    //     hval(0, 1) = 0;
    //     hval(1, 1) = 2;

    //     return hval;
    // };

    Eigen::VectorXd x_init = Eigen::VectorXd::Zero(2);
    x_init(0) = 0;
    x_init(1) = 0;
    
    {
        auto [ret, rx, rcnt] = cr::steepest_descent_method(f, g, x_init);
        std::cout << "steepest_descent_method" << std::endl;
        std::cout << rx.transpose() << ", " << rcnt << std::endl;
    }

    x_init(0) = 0;
    x_init(1) = 0;
    {
        auto [ret, rx, rcnt] = cr::newton_method(g, h, x_init);
        std::cout << "newton_method" << std::endl;
        std::cout << rx.transpose() << ", " << rcnt << std::endl;
    }

    x_init(0) = 0;
    x_init(1) = 0;
    {
        auto [ret, rx, rcnt] = cr::quasi_newton_method(f, g, x_init);
        std::cout << "quasi_newton_method" << std::endl;
        std::cout << rx.transpose() << ", " << rcnt << std::endl;
    }
}
```