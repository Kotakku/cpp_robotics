#pragma once

#include <cmath>
#include <cpp_robotics/system/discrete_transfer_function.hpp>

namespace cpp_robotics
{

/// ローパスフィルター
// G(s) = omega / (s + omega)
class LowPassFilter : public DiscreteTransferFunction
{
public:
    /**
     * @brief Construct a new Low Pass Filter object
     * 
     * @param omega 折れ点周波数[rad/s]
     * @param dt サンプリング周期
     */
    LowPassFilter(double omega, double dt):
        omega_(omega)
    {
        set_continuous({omega}, {1, omega}, dt);
    }

    /**
     * @brief フィルタリングする
     * 
     * @param u 
     * @return double 
     */
    double filtering(double u) { return responce(u); } 

    /**
     * @brief 折れ点周波数[rad/s]の取得
     * 
     * @return double 
     */
    double omega() const { return omega_; }
private:
    const double omega_;
};

}