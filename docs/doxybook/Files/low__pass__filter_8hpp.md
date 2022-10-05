---
title: include/cpp_robotics/filter/low_pass_filter.hpp

---

# include/cpp_robotics/filter/low_pass_filter.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::LowPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LowPassFilter/)** <br>ローパスフィルター  |




## Source code

```cpp
#pragma once

#include <cmath>

namespace cpp_robotics
{

// G(s) = Ts / (Ts + 1)
// 双一次変換で離散化したもの
class LowPassFilter
{
public:
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
```


-------------------------------

Updated on 2022-10-05 at 16:05:00 +0900
