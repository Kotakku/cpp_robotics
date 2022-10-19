---
title: include/cpp_robotics/filter/extended_kalman_filter.hpp

---

# include/cpp_robotics/filter/extended_kalman_filter.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::ExtendedKalmanFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/)**  |




## Source code

```cpp
#pragma once

#include <Eigen/Dense>
#include "cpp_robotics/optimize/derivative.hpp"

namespace cpp_robotics
{

/*
[モデル]
x(t) = F*x(t-1) + B*u(t) + w(t)
z(t) = H*x(t) + v(t)

x: 状態量 (n*1)
u: 制御量 (r*1)
z: 観測量 (p*1)
F: 状態遷移行列 (n*n)
B: 制御行列 (n*r)
H: 観測行列 (p*n)

Q: システムノイズの共分散行列 (n*n)
w: システムノイズ (n*1) 
    N[0, Q]に従う
R: 観測ノイズの共分散行列 (p*p)
v: 観測ノイズ (p*1)
    N[0, R]に従う

[カルマンフィルタ]
- 予測
    事前状態推定
    x = Fx + Bu

    事前誤差共分散行列
    P = FPF^T + Q

- フィルタリング
    カルマンゲイン
    K = PH^T(HPH^T + R)^-1

    状態推定
    x = x + K(z - Hx)

    事後誤差共分散行列
    P = (I -KH)P

[拡張カルマンフィルタ]
- 予測
    事前状態推定
    x = f(x, u)

    モデル線形近似
    F = \partial f(x,u) / \partial x | x=x, u=u
    H = \partial h(x) / \partial x | x=x

    事前誤差共分散行列
    P = FPF^T + Q

- フィルタリング
    カルマンゲイン
    K = PH^T(HPH^T + R)^-1

    状態推定
    x = x + K(z - h(x))

    事後誤差共分散行列
    P = (I -KH)P

*/

class ExtendedKalmanFilter
{
public:
    Eigen::VectorXd x;
    Eigen::MatrixXd F;
    Eigen::MatrixXd B;
    Eigen::MatrixXd H;
    Eigen::MatrixXd Q;
    Eigen::MatrixXd R;
    Eigen::MatrixXd P;

    ExtendedKalmanFilter(const double dt, size_t input_size, size_t state_size, size_t observe_size):
        dt_(dt), input_size_(input_size), state_size_(state_size), observe_size_(observe_size)
    {
        x = Eigen::VectorXd::Zero(state_size_);
        F = Eigen::MatrixXd::Zero(state_size, state_size);
        B = Eigen::MatrixXd::Zero(state_size, input_size);
        H = Eigen::MatrixXd::Zero(observe_size, state_size);
        Q = Eigen::MatrixXd::Zero(state_size, state_size);
        R = Eigen::MatrixXd::Zero(observe_size, observe_size);
        P = Eigen::MatrixXd::Zero(state_size, state_size);
    };

    void reset(Eigen::VectorXd new_x, Eigen::MatrixXd new_P)
    {
        x = new_x;
        P = new_P;
    }

    Eigen::VectorXd filtering(Eigen::VectorXd u, Eigen::VectorXd z)
    {
        system_noise_conv(Q, x, u);
        observe_noise_conv(R, x, u);
        linearized_system_matrix(F, x, u);
        linearized_observe_matrix(H, x);

        // 状態予測
        x = system(x, u);

        // 事前共分散行列
        P = F*P*F.transpose() + Q;

        // カルマンゲイン計算
        Eigen::MatrixXd K = P*H.transpose()*(R + H*P*H.transpose()).inverse();

        // 状態更新
        x += K*(z - observe(x));

        // 事後誤差共分散行列
        P = (Eigen::MatrixXd::Identity(state_size_, state_size_) - K*H)*P;

        return x;
    }

    double dt() const { return dt_; }
    Eigen::VectorXd get_x() const { return x; }
    Eigen::MatrixXd get_P() const { return P; }

    virtual Eigen::VectorXd system(Eigen::VectorXd x, Eigen::VectorXd u) = 0;

    virtual Eigen::VectorXd observe(Eigen::VectorXd x) = 0;

    virtual void system_noise_conv(Eigen::MatrixXd &Q, Eigen::VectorXd x, Eigen::VectorXd u) = 0;

    virtual void observe_noise_conv(Eigen::MatrixXd &R, Eigen::VectorXd x, Eigen::VectorXd u) = 0;

    virtual void linearized_system_matrix(Eigen::MatrixXd &F, Eigen::VectorXd x, Eigen::VectorXd u)
    {
        F = derivative([&](const Eigen::VectorXd &x_dash){ return system(x_dash, u); }, x);
    };

    virtual void linearized_observe_matrix(Eigen::MatrixXd &H, Eigen::VectorXd x)
    {
        H = derivative(std::bind(&ExtendedKalmanFilter::observe, this, std::placeholders::_1), x);
    }

protected:
    // サンプリング時間[s]
    const double dt_;

    const size_t input_size_;
    const size_t state_size_;
    const size_t observe_size_;
};

}
```


-------------------------------

Updated on 2022-10-19 at 13:20:53 +0900
