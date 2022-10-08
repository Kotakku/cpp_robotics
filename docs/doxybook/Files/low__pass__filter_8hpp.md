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
#include <cpp_robotics/system/discrete_transfer_function.hpp>

namespace cpp_robotics
{

// G(s) = 1 / (Ts + 1)
class LowPassFilter : public DiscreteTransferFunction
{
public:
    LowPassFilter(double tau, double dt):
        tau_(tau)
    {
        set_continuous({1}, {tau_, 1}, dt);
    }

    double filtering(double u) { return responce(u); } 

    double tau() const { return tau_; }
private:
    const double tau_;
};

}
```


-------------------------------

Updated on 2022-10-08 at 23:36:07 +0900
