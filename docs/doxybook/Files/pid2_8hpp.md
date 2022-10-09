---
title: include/cpp_robotics/controller/pid2.hpp

---

# include/cpp_robotics/controller/pid2.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::PID2Controller](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PID2Controller/)** <br>2自由度PID制御器  |
| struct | **[cpp_robotics::PID2Controller::pid_param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PID2Controller_1_1pid__param__t/)**  |




## Source code

```cpp
#pragma once

namespace cpp_robotics
{

class PID2Controller
{
public:
    struct pid_param_t
    {
        double Ts;
        double gpd;
        double Kp, Ki, Kd;
        double b, c;
    };

    PID2Controller(pid_param_t param)
    {
        set_param(param);
        reset();
    }

    void setParam(pid_param_t param)
    {
        set_param(param);
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

    double calculate(double target, double present, double dt)
    {
        (void) dt;
        return calculate(target, present);
    }   

    double calculate(double target, double present)
    {
        double &r = target;
        double &y = present;
        auto [Ts, gpd, Kp, Ki, Kd, b, c] = param_;
        
        double u = ( Kp*( (4.0+2.0*gpd*Ts)*(b*r-y) - 8.0*(b*r1_-y1_) + (4.0-2.0*gpd*Ts)*(b*r2_-y2_) )
                    +Ki*Ts*( (2.0+gpd*Ts)*(r-y) +2.0*gpd*Ts*(r1_-y1_) - (2.0-gpd*Ts)*(r2_-y2_) ) 
                    +4.0*Kd*gpd*( (c*r-y) - 2.0*(c*r1_-y1_) + (c*r2_-y2_) ) 
                    + 8.0*u1_ -(4.0-2.0*gpd*Ts)*u2_) / (4.0+2.0*gpd*Ts);
                    
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
```


-------------------------------

Updated on 2022-10-10 at 00:51:40 +0900
