#pragma once

#include <Eigen/Dense>

namespace cpp_robotics
{

/*
[モデル]
x(t) = F*x(t-1) + G*u(t) + w(t)
z(t) = H*x(t) + v(t)

x: 状態量 (n*1)
u: 制御量 (r*1)
z: 観測量 (p*1)
F: 状態遷移行列 (n*n)
G: 制御行列 (n*r)
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
    x = Fx + Gu

    事前誤差共分散行列
    P = FPF^T + Q

- フィルタリング
    カルマンゲイン
    K = PH^T(HPH^T + R)^-1

    状態推定
    x = x + K(z - Hx)

    事後誤差共分散行列
    P = (I -KH)P

*/

/**
 * @brief カルマンフィルタ
 * 
 * @tparam FLOATING_TYPE 浮動小数点型
 * @tparam STATE_SIZE 状態量のサイズ
 * @tparam INPUT_SIZE 入力量のサイズ
 * @tparam OBSERVE_SIZE 観測量のサイズ
 */
template<typename FLOATING_TYPE, size_t STATE_SIZE, size_t INPUT_SIZE, size_t OBSERVE_SIZE>
class KalmanFilter
{
public:
    using value_type = FLOATING_TYPE;
    static constexpr size_t state_size = STATE_SIZE;
    static constexpr size_t input_size = INPUT_SIZE;
    static constexpr size_t observe_size = OBSERVE_SIZE;

    using x_vec_t = Eigen::Matrix<value_type, state_size, 1>;
    using u_vec_t = Eigen::Matrix<value_type, input_size, 1>;
    using z_vec_t = Eigen::Matrix<value_type, observe_size, 1>;

    using f_mat_t = Eigen::Matrix<value_type, state_size, state_size>;
    using g_mat_t = Eigen::Matrix<value_type, state_size, input_size>;
    using h_mat_t = Eigen::Matrix<value_type, observe_size, state_size>;

    using q_mat_t = Eigen::Matrix<value_type, state_size, state_size>;
    using r_mat_t = Eigen::Matrix<value_type, observe_size, observe_size>;

    using p_mat_t = Eigen::Matrix<value_type, state_size, state_size>;

    f_mat_t F;
    g_mat_t G;
    h_mat_t H;
    q_mat_t Q;
    r_mat_t R;

    KalmanFilter() = default;

    void reset(x_vec_t x, p_mat_t P)
    {
        x_ = x;
        P_ = P;
    }

    x_vec_t filtering(u_vec_t u, z_vec_t z)
    {
        ////////////////////////////// 予測 //////////////////////////////
        // 状態予測 x = Fx + Bu
        x_ = F*x_ + G*u;

        // 事前共分散行列 P = FPF^T + Q
        P_ = F*P_*(F.transpose()) + Q;

        ////////////////////////////// フィルタリング //////////////////////////////
        // カルマンゲイン計算 K = PH^T(HPH^T + R)^-1
        auto K = P_*H.transpose() * (R + H*P_*H.transpose()).inverse();

        // 状態更新 x = x + K(z - Hx)
        x_ += K*(z - H*x_);

        // 事後誤差共分散行列 P = (I - KH)P
        auto I = Eigen::Matrix<value_type, state_size, state_size>::Identity();

        P_ = (I - K*H)*P_;

        return x_;
    }

    x_vec_t get_x() { return x_; } // 推定した状態
    p_mat_t get_P() { return P_; } // 共分散行列

private:
    // 状態量
    x_vec_t x_;
    // 誤差共分散行列
    p_mat_t P_;
};

}
