#pragma once

#include <cmath>
#include <optional>
#include <utility>
#include <algorithm>

namespace cpp_robotics
{

/**
 * @brief PID制御器
 * 
 */
class PID
{
public:
    struct pid_param_t
    {
        double Ts;
        double gpd;
        double Kp, Ki, Kd;
        std::optional<std::pair<double, double>> output_limit;
    };

    PID(pid_param_t param)
    {
        set_param(param);
        reset();
    }

    void set_param(pid_param_t param)
    {
        param_ = param;
    }

    void reset()
    {
        u1_ = 0;
        u2_ = 0;
        e1_ = 0;
        e2_ = 0;
    }

    double calculate(double error)
    {
        auto &[Ts, gpd, Kp, Ki, Kd, output_limit] = param_;
        
        double u = ( 2.0*Ts*(Ki+Kp*gpd)*(error-e2_) + Ki*gpd*Ts*Ts*(error+2.0*e1_+e2_) +
                    4.0*(Kd*gpd+Kp)*(error-2.0*e1_+e2_) - (4.0-2.0*gpd*Ts)*u2_ + 8.0*u1_) / (4.0+2.0*gpd*Ts);
                    
        e2_ = e1_;
        e1_ = error;
        
        u2_ = u1_;
        u1_ = u;

        if(output_limit)
        {
            u = std::clamp(u, output_limit.value().first, output_limit.value().second);
        }
        
        return u;
    }

private:
    pid_param_t param_;
    double u1_, u2_;
    double e1_, e2_;
};


}