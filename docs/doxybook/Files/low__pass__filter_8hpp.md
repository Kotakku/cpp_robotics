---
title: include/cpp_robotics/filter/low_pass_filter.hpp

---

# include/cpp_robotics/filter/low_pass_filter.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics_core/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::LowPassFilter](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1LowPassFilter/)**  |




## Source code

```cpp
#pragma once

#include <cmath>

namespace cpp_robotics
{

// ローパスフィルター
// G(s) = Ts / (Ts + 1)
// 双一次変換で離散化したもの
class LowPassFilter
{
public:
    LowPassFilter(double T, double dt):
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
        double y = ( (2*T_-dt_)*y1_ + dt_*(u+u1_) ) /(2*T_ + dt_);

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
```


-------------------------------

Updated on 2022-09-25 at 23:11:52 +0900
