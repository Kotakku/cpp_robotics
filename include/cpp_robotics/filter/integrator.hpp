#pragma once

#include <cmath>

namespace cpp_robotics
{

// 積分器
// G(s) = 1 / s
// 双一次変換で離散化したもの
class Integrator
{
public:
    Integrator(double Ts):
        Ts_(Ts)
    {

    }

    void reset(double val = 0)
    {
        val_ = val;
        u1_ = val;
    }
    
    double filtering(double u)
    {
        val_ += (u1_+u)*Ts_*0.5;
        u1_ = u;
        return val_;
    }

private:
    double Ts_;
    double val_, u1_ = 0;
};

}