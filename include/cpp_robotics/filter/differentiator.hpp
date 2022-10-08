#pragma once

#include <cmath>
#include <cpp_robotics/system/discrete_transfer_function.hpp>

namespace cpp_robotics
{

/**
 * @brief 疑似微分器
 * 
 */
/// G(s) = s / (Ts + 1)
/// 双一次変換で離散化したもの
class Differentiator : public DiscreteTransferFunction
{
public:
    /**
     * @brief Construct a new Differentiator object
     * 
     * @param tau 時定数
     * @param dt サンプリング周期
     */
	Differentiator(double tau, double dt): 
        tau_(tau)
    {
        set_continuous({1, 0}, {tau_, 1}, dt);
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
    double tau() const { return tau_; }
private:
    const double tau_;
};

}