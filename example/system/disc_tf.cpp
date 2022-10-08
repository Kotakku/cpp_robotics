#define CR_USE_MATPLOTLIB
#include <cpp_robotics/system/system.hpp>

int main()
{
    namespace cr = cpp_robotics;
    namespace plt = matplotlibcpp;

    // LPF
    //            K
    // G(s) = --------
    //         Ts + 1
    //
    // 離散化して
    //           K*dt*z + K*dt
    // G(z) = -----------------------
    //         (dt+2T)z + (dt+2T)
    const double K = 1.5;
    const double T = 0.6;
    const double dt = 0.01;
    cr::DiscreteTransferFunction tf({K*dt, K*dt}, {dt+2*T, dt-2*T}, dt);

    // 初期状態から4秒分のステップ応答を計算
    auto [t, y] = cr::step(tf, 4.0);
    plt::plot(t, y);
    plt::show();
}