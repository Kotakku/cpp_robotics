---
title: include/cpp_robotics/filter/extended_kalman_filter.hpp

---

# include/cpp_robotics/filter/extended_kalman_filter.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |




## Source code

```cpp
#pragma once

#include <Eigen/Dense>

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

#if 0
template<typename FLOATING_TYPE, size_t INPUT_SIZE, size_t STATE_SIZE, size_t OBSERVE_SIZE>
class ExtendedKalmanFilter
{
public:
    using value_type = FLOATING_TYPE;
    static constexpr size_t input_size = INPUT_SIZE;
    static constexpr size_t state_size = STATE_SIZE;
    static constexpr size_t observe_size = OBSERVE_SIZE;

    static constexpr auto x_vec_t = Eigen::Vector<value_type, state_size>;
    static constexpr auto u_vec_t = Eigen::Vector<value_type, input_size>;
    static constexpr auto z_vec_t = Eigen::Vector<value_type, observe_size>;

    static constexpr auto f_mat_t = Eigen::Matrix<value_type, state_size, state_size>;
    static constexpr auto b_mat_t = Eigen::Matrix<value_type, state_size, input_size>;
    static constexpr auto h_mat_t = Eigen::Matrix<value_type, observe_size, state_size>;

    static constexpr auto q_mat_t = Eigen::Matrix<value_type, state_size, state_size>;
    static constexpr auto r_mat_t = Eigen::Matrix<value_type, observe_size, observe_size>;

    static constexpr auto p_mat_t = Eigen::Matrix<value_type, state_size, state_size>;

    // static constexpr auto p_mat_t = Eigen::Matrix<value_type, state_size, state_size>;

    ExtendedKalmanFilter(const value_type dt):
        dt_(dt)
    {
        
    };

    void reset(x_vec_t x, p_mat_t P)
    {
        x_ = x;
        P_ = P;
    }

    x_vec_t update(u_vec_t u)
    {
        // 状態予測
        x_ = f(x_, u);

        const auto F_ = matF(x_, u);
        const auto Q_ = matQ(x_, u);

        // 事前共分散行列
        P_ = F_*P_*transpose(F_) + Q_;

        auto zs = get_z();
        auto estimated_z = h(x_);
        if(estimated_z.has_value())
        {
            for(auto & z : zs)
            {
                const auto H_ = matH(x_);
                const auto R_ = matR(x_, u);

                // カルマンゲイン計算((S*S) * (S*O) * (O*O) = (S*O))
                auto K_ = P_*transpose(H_)*inverse(R_ + H_*P_*transpose(H_) );

                // 状態更新
                x_ += K_*(z - estimated_z.value());

                // 事後誤差共分散行列
                constexpr auto I = eye<value_type, state_size>();
                P_ = (I - K_*H_)*P_;
            }
        }

        return x_;
    }

    x_vec_t get_x() { return x_; }
    p_mat_t get_P() { return P_; }

protected:
    // ここらへんをオーバーライドして使う

    // システム
    virtual x_vec_t f(x_vec_t x, u_vec_t u) = 0;

    // 観測
    virtual std::optional<z_vec_t> h(x_vec_t x) = 0;

    // 観測データ
    virtual std::vector<z_vec_t> get_z() = 0;

    // システムノイズ共分散行列
    virtual q_mat_t Q(x_vec_t x, u_vec_t u) = 0;

    // 観測ノイズの共分散行列
    virtual r_mat_t R(x_vec_t x, u_vec_t u) = 0;

    // システム線形化行列
    virtual f_mat_t F(x_vec_t x, u_vec_t u)
    {
        // 近似解
        f_mat_t matF;

        x_vec_t new_x; 
        for(size_t r = 0; r < state_size; r++)
        {
            for(size_t c = 0; c < state_size; c++)
            {
                const value_type dx = 1e-3;
                new_x = x;
                new_x(c) += dx;
                matF(r, c) = ( f(new_x, u)(r) - f(x, u)(r) ) / dx;
            }
        }

        return matF;
    };

    // 観測線形化行列
    virtual h_mat_t H(x_vec_t x)
    {
        // 近似解
        h_mat_t matH;

        x_vec_t new_x;
        for(size_t r = 0; r < observe_size; r++)
        {
            for(size_t c = 0; c < state_size; c++)
            {
                const value_type dx = 1e-3;
                new_x = x;
                new_x(c) += dx;
                auto h1 = h(x);
                auto h2 = h(new_x);
                if(h1 && h2)
                {
                    auto &h1_mat = h1.value();
                    auto &h2_mat = h2.value();

                    matH(r, c) = (h2_mat(r) - h1_mat(r)) / dx;
                }
                else
                {
                    matH(r, c) = 0.0f;
                }
            }
        }

        return matH;
    }

protected:
    // サンプリング時間[s]
    const value_type dt_;

private:
    // 状態量
    x_vec_t x_;
    // 誤差共分散行列
    p_mat_t P_;
};
#endif

}
```


-------------------------------

Updated on 2022-09-28 at 01:12:56 +0900
