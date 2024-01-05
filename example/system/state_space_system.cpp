#include <iostream>
#include <cpp_robotics/system.hpp>
#include <cpp_robotics/controller.hpp>
#include <cpp_robotics/controller/modern_control.hpp>

int main()
{
    namespace cr = cpp_robotics;
    
    Eigen::Matrix2d A;
    Eigen::Matrix<double, 2, 1> B;
    Eigen::Matrix<double, 1, 2> C;

    A << 0, 1, 1, 0.5;
    B << 0, 0.5;
    C << 1, 0;
    const double dt = 0.01;

    cr::StateSpaceSystem sys(A, B, C, dt);

    if(cr::is_controllable(A, B))
    {
        std::cout << "Controllable" << std::endl;
    }
    else
    {
        std::cout << "Uncontrollable" << std::endl;
    }
    
    if(cr::is_observable(A, C))
    {
        std::cout << "Observable" << std::endl;
    }
    else
    {
        std::cout << "Unobservable" << std::endl;
    }
}