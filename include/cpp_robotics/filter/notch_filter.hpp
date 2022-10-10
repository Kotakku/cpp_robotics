#pragma once

#include <cpp_robotics/system/transfer_function.hpp>

namespace cpp_robotics
{

/// ノッチフィルタ
//         s^2 + d*2*zeta*omega*s + omega^2
// G(s) = -------------------------------- を双一次変換
//          s^2 + 2*zeta*omega*s + omega^2
class NotchFilter : public TransferFunction
{
public:
    /**
     * @brief Construct a new Notch Filter object
     * 
     * @param omega 中心周波数[rad/s]
     * @param zeta 鋭さ
     * @param d 深さ(0.0で一番深く、1.0に近づけるほどフィルタの効果が弱くなる)
     * @param dt サンプリング周期
     */
    NotchFilter(double omega, double zeta, double d, double dt):
        omega_(omega), zeta_(zeta), d_(d)
    {
        TransferFunction::set_continuous({1, (d_*2*zeta_*omega_), (omega_*omega_)}, {1, (2*zeta_*omega_), (omega_*omega_)}, dt);
    }

    /**
     * @brief フィルタリングする
     * 
     * @param u 
     * @return double 
     */
    double filtering(double u) { return responce(u); } 

    /**
     * @brief 中心周波数[rad/s]
     * 
     * @return double 
     */
    double omega() const { return omega_; }

    /**
     * @brief 鋭さ
     * 
     * @return double 
     */
    double zeta() const { return zeta_; }

    /**
     * @brief 深さ
     * 
     * @return double 
     */
    double d() const { return d_; }
private:
    const double omega_;
    const double zeta_;
    const double d_;
};

}