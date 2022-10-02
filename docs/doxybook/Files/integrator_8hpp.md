---
title: include/cpp_robotics/filter/integrator.hpp

---

# include/cpp_robotics/filter/integrator.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::Integrator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Integrator/)** <br>積分器  |




## Source code

```cpp
#pragma once

#include <cmath>

namespace cpp_robotics
{

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
```


-------------------------------

Updated on 2022-10-02 at 13:22:12 +0900
