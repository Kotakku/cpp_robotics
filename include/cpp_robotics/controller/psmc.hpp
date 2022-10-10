#pragma once

#include <cmath>
#include <optional>
#include <array>
#include <utility>
#include <cpp_robotics/utility/cpp_support.hpp>

namespace cpp_robotics
{

class PSMC
{
public:
    struct param_t
    {
        double Ts;
        double Kp, Kd;
        double Hs;
        std::optional<std::pair<double, double>> output_limit;
    };
    
    PSMC()
    {
        reset();
    }

    PSMC(param_t param):
        param_(param)
    {
        reset();
    }
    
    PSMC(double p, double d, double Hs, double dt)
    {
        param_.Kp = p;
        param_.Kd = d;
        param_.Hs = Hs;
        param_.Ts = dt;
        reset();
    }

    PSMC(double p, double d, double Hs, double min_output, double max_output, double dt)
    {
        param_.Kp = p;
        param_.Kd = d;
        param_.Hs = Hs;
        param_.output_limit = std::pair(min_output, max_output);
        param_.Ts = dt;
        reset();
    }
    
    void reset()
    {
        for(size_t i = 0; i < 2; i++)
        {
            target_val_[i] = now_val_[i] = error_[i] = 0.0;
        }
    }

    void set_param(param_t param)
    {
        param_ = param;
    }

    double calculate(double target_val, double now_val)
    {
        double target_velocity, now_velocity;
    
        target_velocity = (target_val - target_val_[0])/param_.Ts;
        now_velocity =  (now_val - now_val_[0])/param_.Ts;
        
        return calculate(target_val, now_val, target_velocity, now_velocity);
    }

    double calculate(double target_val, double now_val, double target_velocity, double now_velocity)
    {
        double s, u, f, e;
        
        // coeff
        double ua, ub;
        double ea;
        
        shift_right(target_val_.begin(), target_val_.begin(), 1);
        target_val_[0] = target_val;
        shift_right(now_val_.begin(), now_val_.begin(), 1);
        now_val_[0] = now_val;
        
        s = (target_val_[0] - now_val_[0]) + param_.Hs*(target_velocity - now_velocity);
        
        ua = (param_.Kd + param_.Kp*param_.Ts)/(param_.Hs + param_.Ts);
        ub = (param_.Kp*param_.Hs - param_.Kd)/(param_.Hs + param_.Ts);
        u = ua*s + ub*error_[0];
        
        if(param_.output_limit)
            f = std::clamp(u, param_.output_limit.value().first, param_.output_limit.value().second);
        else
            f = u;
        
        ea = param_.Kd + param_.Kp*param_.Ts;
        e = (param_.Kd * error_[0] + param_.Ts*f) / ea;
        
        shift_right(error_.begin(), error_.begin(), 1);
        error_[0] = e;
        
        return f;
    }
    
    double &Kp() { return param_.Kp; }
    double &Kd() { return param_.Kd; }
    double &Hs() { return param_.Hs; }

private:
    param_t param_;
    
    std::array<double, 2> target_val_;
    std::array<double, 2> now_val_;
    std::array<double, 2> error_;
};
}