#pragma once

#include <optional>
#include <Eigen/Dense>
#include "cpp_robotics/optimize/derivative.hpp"

namespace cpp_robotics
{

/*
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
    S = HPH^T + R
    K = PH^T(S)^-1

    状態推定
    x = x + K(z - h(x))

    事後誤差共分散行列
    P = P - KST^T
*/

class ExtendedKalmanFilter
{
public:
    /// @brief 状態量
    Eigen::VectorXd x;
    /// @brief 遷移行列
    Eigen::MatrixXd F;
    /// @brief 制御行列
    Eigen::MatrixXd B;
    /// @brief 観測行列
    Eigen::MatrixXd H;
    /// @brief 状態量ノイズ分散行列
    Eigen::MatrixXd Q;
    /// @brief 観測量ノイズ分散行列
    Eigen::MatrixXd R;
    /// @brief 誤差共分散行列
    Eigen::MatrixXd P;

    ExtendedKalmanFilter(const double dt, size_t input_size, size_t state_size, size_t observe_size, std::optional<double> correction_threshold = std::nullopt):
        dt_(dt), input_size_(input_size), state_size_(state_size), observe_size_(observe_size), mn_threshold_(correction_threshold)
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
        ////////////////////////////// 線形化モデルの更新 //////////////////////////////
        system_noise_conv(Q, x, u);
        observe_noise_conv(R, x, z);
        linearized_system_matrix(F, x, u);
        linearized_observe_matrix(H, x, z);

        ////////////////////////////// 予測 //////////////////////////////
        // 状態予測
        x = system(x, u);

        // 事前共分散行列
        P = F*P*F.transpose() + Q;

        ////////////////////////////// フィルタリング //////////////////////////////
        // カルマンゲイン計算
        Eigen::MatrixXd S = H*P*H.transpose() + R;
        Eigen::MatrixXd K = P*H.transpose()*S.inverse();

        // 状態更新
        Eigen::VectorXd xdiff = K*(z - observe(x));
        double mahalanobis_distance = std::sqrt( xdiff.dot( P.inverse()*xdiff ) );
        if(not mn_threshold_ || (mn_threshold_ && mahalanobis_distance < mn_threshold_.value()))
        {
            x += xdiff;
            // 事後誤差共分散行列
            P -= K*S*K.transpose();
        }

        return x;
    }

    double dt() const { return dt_; }
    Eigen::VectorXd get_x() const { return x; }
    Eigen::MatrixXd get_P() const { return P; }

    /// @brief システム
    virtual Eigen::VectorXd system(Eigen::VectorXd x, Eigen::VectorXd u) = 0;

    /// @brief 観測
    virtual Eigen::VectorXd observe(Eigen::VectorXd x) = 0;

    /// @brief システムノイズ共分散行列
    virtual void system_noise_conv(Eigen::MatrixXd &Q, Eigen::VectorXd x, Eigen::VectorXd u) = 0;

    /// @brief 観測ノイズの共分散行列
    virtual void observe_noise_conv(Eigen::MatrixXd &R, Eigen::VectorXd x, Eigen::VectorXd z) = 0;

    /// @brief システム線形化行列
    virtual void linearized_system_matrix(Eigen::MatrixXd &F, Eigen::VectorXd x, Eigen::VectorXd u)
    {
        F = derivative([&](const Eigen::VectorXd &x_dash){ return system(x_dash, u); }, x);
    };

    /// @brief 観測線形化行列
    virtual void linearized_observe_matrix(Eigen::MatrixXd &H, Eigen::VectorXd x, Eigen::VectorXd z)
    {
        (void) z;
        H = derivative(std::bind(&ExtendedKalmanFilter::observe, this, std::placeholders::_1), x);
    }

protected:
    // サンプリング時間[s]
    const double dt_;

    const size_t input_size_;
    const size_t state_size_;
    const size_t observe_size_;
    std::optional<double> mn_threshold_;
};

}