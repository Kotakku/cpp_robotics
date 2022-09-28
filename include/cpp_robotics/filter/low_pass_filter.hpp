#pragma once

#include <cmath>

namespace cpp_robotics
{

/// ローパスフィルター
// G(s) = Ts / (Ts + 1)
// 双一次変換で離散化したもの
class LowPassFilter
{
public:
    /**
     * @brief Construct a new Low Pass Filter object
     * 
     * @param w 折れ点周波数[rad/s]
     * @param dt サンプリング周期
     */
    LowPassFilter(double w, double dt):
        w_(w), T_(1/w), dt_(dt)
    {

    }

    void reset(double val = 0)
    {
        y1_ = val;
        u1_ = val;
    }
    
    double filtering(double u)
    {
        double y = ( (2*T_-dt_)*y1_ + dt_*(u+u1_) ) /(2*T_ + dt_);

        y1_ = y;
        u1_ = u;
        return y;
    }

    double w() const { return w_; }
    double dt() const {return dt_; }
private:
    const double w_;
    const double T_;
    const double dt_;
    double y1_, u1_ = 0;
};

}