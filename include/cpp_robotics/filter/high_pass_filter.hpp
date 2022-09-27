#pragma once

#include <cmath>

namespace cpp_robotics
{

/**
 * @brief ハイパスフィルタ
 * 
 */
// G(s) = 1 / (Ts + 1)
// 双一次変換で離散化したもの
class HighPassFilter
{
public:
    HighPassFilter(double T, double dt):
        T_(T), dt_(dt)
    {

    }

    void reset(double val = 0)
    {
        y1_ = val;
        u1_ = val;
    }
    
    double filtering(double u)
    {
        double y = ( (2*T_-dt_)*y1_ + 2*T_*(u-u1_) ) /(2*T_ + dt_);

        y1_ = y;
        u1_ = u;
        return y;
    }

private:
    double T_;
    double dt_;
    double y1_, u1_ = 0;
};

}