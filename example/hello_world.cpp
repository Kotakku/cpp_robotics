#define CR_USE_MATPLOTLIB
#include <iostream>
#include <Eigen/Dense>
#include <cpp_robotics/cpp_robotics.hpp>

int main()
{
    namespace cr = cpp_robotics;

    constexpr cr::Vector2d vec(3.0, 4.0);
    printf("constexpr 2D vector: %f, %f\n", vec.x, vec.y);

    Eigen::MatrixXd A(2,2), B(2,1), Q(2,2), R(1,1), P(2,2);
    A << 0, 1, -10, -1;
    B << 0, 1;
    Q << 300, 0, 0, 60;
    R << 1;

    Eigen::MatrixXd K = cr::lqr(A, B, Q, R);
    std::cout << "LQR feedback vector" << std::endl;
    std::cout << K << std::endl;

    std::cout << "polynomial" << std::endl;
    cr::Polynomial p0({1, 0, 3});
    std::cout << p0 << std::endl;
    cr::Polynomial p1 = cr::Polynomial({1, -2}) * cr::Polynomial({1, 2});
    std::cout << "(x-2)*(x+2) = " << p1 << std::endl;

    std::cout << "G(s) = 1/(s+1)" << std::endl;
    cr::TransferFunction tf({1.0}, {1.0, 1.0}, 0.01);

    namespace plt = matplotlibcpp;
    std::cout << "transfer function step responce" << std::endl;
    {
        auto [t, y] = cr::step(tf, 30);
        plt::plot(t, y);
        plt::show();
    }

    std::cout << "transfer function sin cruve input responce" << std::endl;
    {
        tf.reset();
        auto input = cr::sinspace(1, 0.1, 1000);
        auto [t, y] = cr::lsim(tf, input);
        plt::plot(t, y);
        plt::show();
    }
    
    std::cout << "transfer function bode fig plot" << std::endl;
    cr::bode_plot(tf);

    std::cout << "transfer function nyquist fig plot" << std::endl;
    cr::nyquist_plot(tf);
}