#define CR_USE_MATPLOTLIB
#include <iostream>
#include <Eigen/Dense>
#include <cpp_robotics/system.hpp>

int main()
{
    namespace cr = cpp_robotics;

    const double omega = 4.0;
    const double zeta = 0.5;
    cr::TransferFunction tf({omega*omega}, {1.0, 2.0*zeta*omega, omega*omega}, 0.01);

    // ボード線図
    cr::bode_plot(tf);

    // ナイキスト線図
    cr::nyquist_plot(tf);
}