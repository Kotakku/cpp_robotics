#pragma once

#include <cmath>
#include <cpp_robotics/system/transfer_function.hpp>

namespace cpp_robotics
{

/**
 * @brief ハイパスフィルタ
 * 
 */
// G(s) = s / (s + omega)
// 双一次変換で離散化したもの
class HighPassFilter: public TransferFunction
{
public:
    /**
     * @brief Construct a new High Pass Filter object
     * 
     * @param omega 折れ点周波数[rad/s]
     * @param dt サンプリング周期
     */
    HighPassFilter(double omega, double dt):
        omega_(omega)
    {
        TransferFunction::set_continuous({1, 0}, {1, omega_}, dt);
    }

    /**
     * @brief フィルタリングする
     * 
     * @param u 
     * @return double 
     */
    double filtering(double u) { return responce(u); } 

    /**
     * @brief 時定数の取得
     * 
     * @return double 
     */
    double omega() const { return omega_; }
private:
    const double omega_;
};

}