---
title: example/system/disc_tf.cpp

---

# example/system/disc_tf.cpp



## Functions

|                | Name           |
| -------------- | -------------- |
| int | **[main](/cpp_robotics/doxybook/Files/disc__tf_8cpp/#function-main)**() |


## Functions Documentation

### function main

```cpp
int main()
```




## Source code

```cpp
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
    //           K*dt*z^-1 + K*dt
    // G(z) = -----------------------
    //         (dt-2T)z^-1 + (dt+2T)
    const double K = 1.5;
    const double T = 0.6;
    const double dt = 0.01;
    cr::DiscreteTransferFunction tf({K*dt, K*dt}, {dt-2*T, dt+2*T}, dt);

    // 初期状態から4秒分のステップ応答を計算
    auto [t, y] = cr::step(tf, 4.0);
    plt::plot(t, y);
    plt::show();
}
```


-------------------------------

Updated on 2022-09-25 at 23:20:39 +0900
