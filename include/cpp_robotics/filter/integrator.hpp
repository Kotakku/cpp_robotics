#pragma once

#include <cmath>
#include <cpp_robotics/system/discrete_transfer_function.hpp>

namespace cpp_robotics
{

/// 積分器
// G(s) = 1 / s
// 双一次変換で離散化したもの
class Integrator : public DiscreteTransferFunction
{
public:
    /**
     * @brief Construct a new Integrator object
     * 
     * @param dt サンプリング周期
     */
    Integrator(double dt)
    {
        set_continuous({1}, {1, 0}, dt);
    }

    /**
     * @brief フィルタリングする
     * 
     * @param u 
     * @return double 
     */
    double filtering(double u) { return responce(u); } 
};

}