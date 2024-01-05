#define CR_USE_MATPLOTLIB
#include <iostream>
#include <iomanip>
#include <cpp_robotics/system.hpp>
#include <cpp_robotics/controller.hpp>
#include <cpp_robotics/controller/modern_control.hpp>

#define PRINT_MAT(MAT) \
    std::cout << #MAT << std::endl;\
    std::cout << MAT << std::endl << std::endl;

int main()
{
    namespace cr = cpp_robotics;
    namespace plt = matplotlibcpp;
    
    // http://arduinopid.web.fc2.com/O7.html
    Eigen::MatrixXd A(2,2);
    Eigen::MatrixXd B(2,1);
    Eigen::MatrixXd C(1,2);

    A << 
        -10, -10,
        5, 0;
    B << 10, 0;
    C << 0, 1;

    const double dt = 0.01;
    cr::StateSpaceSystem sys(A, B, C, dt);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "pole place" << std::endl;
    std::vector<double> pole = {-6, -6};
    auto K = cr::place(sys, pole);
    
    PRINT_MAT(K);
}