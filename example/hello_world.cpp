#define CR_USE_MATPLOTLIB
#include <iostream>
#include <Eigen/Dense>
#include <cpp_robotics/vector.hpp>
#include <cpp_robotics/controller/lqr.hpp>
#include <cpp_robotics/system.hpp>
#include <cpp_robotics/matplotlibcpp.hpp>

int main()
{
    namespace cr = cpp_robotics;

    constexpr cr::Vector2d vec(3.0, 4.0);
    std::cout << "constexpr 2D vector: (" << vec.x << "," << vec.y  << "), norm = " << vec.norm() << std::endl;

    Eigen::MatrixXd A(2,2), B(2,1), Q(2,2), R(1,1), P(2,2);
    A << 0, 1, -10, -1;
    B << 0, 1;
    Q << 300, 0, 0, 60;
    R << 1;

    Eigen::MatrixXd K = cr::lqr(A, B, Q, R);
    std::cout << "\nLQR feedback vector" << std::endl;
    std::cout << K << std::endl;

    std::cout << "\npolynomial" << std::endl;
    cr::Polynomial p0({1, 0, 3});
    std::cout << p0 << std::endl;
    cr::Polynomial p1 = cr::Polynomial({1, -2}) * cr::Polynomial({1, 2});
    std::cout << "(x-2)*(x+2) = " << p1 << std::endl;

    cr::TransferFunction G({1.0}, {1.0, 1.0}, 0.01);
    cr::TransferFunction C({1.0, 1.0}, {0.01, 1.0}, 0.01);
    cr::TransferFunction CG = C*G;
    
    std::cout << "\nG(s) = " << std::endl;
    std::cout << G << std::endl;
    std::cout << "\nC(s) = " << std::endl;
    std::cout << C << std::endl;
    std::cout << "\nC(s)*G(s) = " << std::endl;
    std::cout << CG << std::endl;

    namespace plt = matplotlibcpp;
    std::cout << "\ntransfer function step responce" << std::endl;
    {
        auto [t, y] = cr::step(G, 30);
        plt::plot(t, y);
        plt::show();
    }

    std::cout << "transfer function bode fig plot" << std::endl;
    cr::bode_plot(G);

    std::cout << "transfer function nyquist fig plot" << std::endl;
    cr::nyquist_plot(G);
}