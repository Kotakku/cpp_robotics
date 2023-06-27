#pragma once

#include <cmath>
#include <optional>
#include <utility>
#include <algorithm>

namespace cpp_robotics
{

/**
 * @brief 2自由度PID制御器
 * 
 */
class PID2
{
public:
    struct pid_param_t
    {
        double Ts;
        double gpd;
        double Kp, Ki, Kd;
        double b, c;
        std::optional<std::pair<double, double>> output_limit;
    };

    static PID2 create_PI_D(double Ts, double gpd, double Kp, double Ki, double Kd, std::optional<std::pair<double, double>> output_limit = std::nullopt)
    {
        pid_param_t param = 
        {
            .Ts = Ts,
            .gpd = gpd,
            .Kp = Kp,
            .Ki = Ki,
            .Kd = Kd,
            .b = 1,
            .c = 0,
            .output_limit = output_limit
        };

        return PID2(param);
    }

    static PID2 create_I_PD(double Ts, double gpd, double Kp, double Ki, double Kd, std::optional<std::pair<double, double>> output_limit = std::nullopt)
    {
        pid_param_t param = 
        {
            .Ts = Ts,
            .gpd = gpd,
            .Kp = Kp,
            .Ki = Ki,
            .Kd = Kd,
            .b = 0,
            .c = 0,
            .output_limit = output_limit
        };

        return PID2(param);
    }

    static PID2 create_feed_foward_pid2(double Ts, double gpd, double Kpff, double Kdff, double Kpfb, double Kifb, double Kdfb, std::optional<std::pair<double, double>> output_limit = std::nullopt)
    {
        pid_param_t param = 
        {
            .Ts = Ts,
            .gpd = gpd,
            .Kp = Kpfb,
            .Ki = Kifb,
            .Kd = Kdfb,
            .b = (Kpff+Kpfb)/Kpfb,
            .c = (Kdff+Kdfb)/Kdfb,
            .output_limit = output_limit
        };

        return PID2(param);
    }

    PID2(pid_param_t param)
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
        r1_ = 0;
        r2_ = 0;
        y1_ = 0;
        y2_ = 0;
    }

    double calculate(double target, double present)
    {
        double &r = target;
        double &y = present;
        auto &[Ts, gpd, Kp, Ki, Kd, b, c, output_limit] = param_;
        
        double u = ( Kp*( (4.0+2.0*gpd*Ts)*(b*r-y) - 8.0*(b*r1_-y1_) + (4.0-2.0*gpd*Ts)*(b*r2_-y2_) )
                    +Ki*Ts*( (2.0+gpd*Ts)*(r-y) +2.0*gpd*Ts*(r1_-y1_) - (2.0-gpd*Ts)*(r2_-y2_) ) 
                    +4.0*Kd*gpd*( (c*r-y) - 2.0*(c*r1_-y1_) + (c*r2_-y2_) ) 
                    + 8.0*u1_ -(4.0-2.0*gpd*Ts)*u2_) / (4.0+2.0*gpd*Ts);

        if(output_limit)
        {
            u = std::clamp(u, output_limit.value().first, output_limit.value().second);
        }

        r2_ = r1_;
        r1_ = r;
        y2_ = y1_;
        y1_ = y;
        
        u2_ = u1_;
        u1_ = u;
        
        return u;
    }

private:
    pid_param_t param_;
    double u1_, u2_;
    double r1_, r2_;
    double y1_, y2_;
};

}