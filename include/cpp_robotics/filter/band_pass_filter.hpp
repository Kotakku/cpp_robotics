#pragma once

#include <cpp_robotics/system/transfer_function.hpp>

namespace cpp_robotics
{

/// バンドパスフィルタ
//               2*zeta*omega*s
// G(s) = ------------------------------ を双一次変換
//         s^2 + 2*zeta*omega*s + omega^2
class BandPassFilter : public TransferFunction
{
public:
    /**
     * @brief Construct a new Notch Filter object
     * 
     * @param omega 中心周波数[rad/s]
     * @param zeta 鋭さ
     * @param dt サンプリング周期
     */
    BandPassFilter(double omega, double zeta, double dt):
        omega_(omega), zeta_(zeta)
    {
        TransferFunction::set_continuous({(2*zeta_*omega_),0}, {1,(2*zeta_*omega_),(omega*omega)}, dt);
    }

    /**
     * @brief フィルタリングする
     * 
     * @param u 
     * @return double 
     */
    double filtering(double u) { return responce(u); } 

    /**
     * @brief 中心周波数[rad/s]の取得
     * 
     * @return double 
     */
    double omega() const { return omega_; }

    /**
     * @brief 鋭さの取得
     * 
     * @return double 
     */
    double zeta() const { return zeta_; }
private:
    const double omega_;
    const double zeta_;
};

}