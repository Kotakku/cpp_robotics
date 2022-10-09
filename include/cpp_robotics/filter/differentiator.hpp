#pragma once

#include <cmath>
#include <cpp_robotics/system/discrete_transfer_function.hpp>

namespace cpp_robotics
{

/**
 * @brief 疑似微分器
 * 
 */
/// G(s) = omega*s / (s + omega)
/// 双一次変換で離散化したもの
class Differentiator : public DiscreteTransferFunction
{
public:
    /**
     * @brief Construct a new Differentiator object
     * 
     * @param omega 折れ点周波数[rad/s]
     * @param dt サンプリング周期
     */
	Differentiator(double omega, double dt): 
        omega_(omega)
    {
        set_continuous({omega, 0}, {1, omega}, dt);
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