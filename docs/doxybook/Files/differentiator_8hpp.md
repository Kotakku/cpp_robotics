---
title: include/cpp_robotics/filter/differentiator.hpp

---

# include/cpp_robotics/filter/differentiator.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::Differentiator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Differentiator/)**  |




## Source code

```cpp
#pragma once

#include <cmath>

namespace cpp_robotics
{

// 疑似微分器
// G(s) = s / (Ts + 1)
// 双一次変換で離散化したもの
class Differentiator
{
public:
    // bandwidth[rad/s]
    // sample_time[s]
    Differentiator(double bandwidth, double sample_time): 
        Ts_(sample_time),
        gpd_(bandwidth)
    {
        
    }

    void reset()
    {
        u1_ = y1_ = 0;
    }

    double filtering(double u)
    {
        double y;
        y = ( 2.0*gpd_*(u-u1_) + (2.0-Ts_*gpd_)*y1_ )/(2.0+Ts_*gpd_);
        u1_=u;
        y1_=y;        
        return y;
    }

private:
    double Ts_;
    double gpd_;
    double u1_;
    double y1_;
};

}
```


-------------------------------

Updated on 2022-09-25 at 23:20:38 +0900
