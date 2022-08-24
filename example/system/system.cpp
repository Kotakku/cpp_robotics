#include <iostream>
#include <Eigen/Dense>
#include <cpp_robotics/system/system.hpp>
#include <cpp_robotics/controller/controller.hpp>

int main()
{
    namespace cr = cpp_robotics;

    Eigen::MatrixXd A(2,2), B(2,1), Q(2,2), R(1,1), P(2,2);
    A << 0, 1, -10, -1;
    B << 0, 1;
    Q << 300, 0, 0, 60;
    R << 1;

    Eigen::MatrixXd K = -cr::lqr(A, B, Q, R);
    std::cout << K << std::endl;

    cr::Polynomial p0({1, 0, 3});
    std::cout << p0 << std::endl;
    cr::Polynomial p1 = cr::Polynomial({1, -2}) * cr::Polynomial({1, 2});
    std::cout << p1 << std::endl;

    namespace plt = matplotlibcpp;
    // plt::plot({1, 2, 4, 8, 16});
    // plt::show();
    cr::TransferFunction<0, 1> tf({1.0}, {1, 1.0}, 0.01);
    // cr::bode_plot(tf);
    // cr::nyquist_plot(tf);
    // {
    //     auto [t, y] = cr::step(tf, 30);
    //     plt::plot(t, y);
    // }
    

    // auto input = cr::sinspace(1, 0.1, 1000);
    // auto [t, y] = cr::lsim(tf, input);
    
    // plt::plot(t, y);
    // plt::plot(t, input);
    
    // plt::show();

}