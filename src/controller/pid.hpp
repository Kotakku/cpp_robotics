#pragma once

namespace cpp_robotics
{

class PIDController
{
public:
    struct pid_param_t
    {
        double Ts;
        double gpd;
        double Kp, Ki, Kd;
    };

    PIDController(pid_param_t param)
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

    double calculate(double target, double present)
    {
        double e = target - present;
        auto [Ts, gpd, Kp, Ki, Kd] = param_;
        
        double u = ( 2.0*Ts*(Ki+Kp*gpd)*(e-e2_) + Ki*gpd*Ts*Ts*(e+2.0*e1_+e2_) +
                    4.0*(Kd*gpd+Kp)*(e-2.0*e1_+e2_) - (4.0-2.0*gpd*Ts)*u2_ + 8.0*u1_) / (4.0+2.0*gpd*Ts);
                    
        e2_ = e1_;
        e1_ = e;
        
        u2_ = u1_;
        u1_ = u;
        
        return u;
    }

private:
    pid_param_t param_;
    double u1_, u2_;
    double e1_, e2_;
};


}