# 伝達関数のステップ応答

```cpp
#include <cpp_robotics/system/system.hpp>

int main()
{
    namespace cr = cpp_robotics;
    namespace plt = matplotlibcpp;
    
    // 2次系の伝達関数を0.01秒で離散化
    //                  omega^2
    // G(s) = ------------------------------
    //         s^2 + 2*zeta*omega*s + omega^2
    const double omega = 4.0;
    const double zeta = 0.5;
    cr::TransferFunction tf({omega*omega}, {1.0, 2.0*zeta*omega, omega*omega}, 0.01);

    // 初期状態から4秒分のステップ応答を計算
    auto [t, y] = cr::step(tf, 4.0);
    plt::plot(t, y);
    plt::show();
}
```