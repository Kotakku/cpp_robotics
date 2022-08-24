#include <iostream>
#include <Eigen/Dense>
#include <cpp_robotics/system/system.hpp>

int main()
{
    namespace cr = cpp_robotics;

    // 伝達関数
    // tf(s) = 1 / (s + 1)
    cr::TransferFunction<0, 1> tf({1.0}, {1.0, 1.0}, 0.01);

    // ボード線図
    cr::bode_plot(tf);

    // ナイキスト線図
    cr::nyquist_plot(tf);
}