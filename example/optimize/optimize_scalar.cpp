#include <iostream>
#include <Eigen/Dense>
#include <cpp_robotics/optimize/optimize.hpp>

int main()
{
    namespace cr = cpp_robotics;

    std::cout << "optimize_scalar" << std::endl;

    std::cout << "min x => (x+1)^2 = " << cr::golden_search([](double x){ return std::pow(x+1, 2); }, -10, 10) << std::endl;

    std::cout << "sin'(0) = cos(0) = " << cr::derivative([](double x){ return std::sin(x); }, 0) << std::endl;
}