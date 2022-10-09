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

// G(s) = omega / (s + omega)
class LowPassFilter : public DiscreteTransferFunction
{
public:
    LowPassFilter(double omega, double dt):
        omega_(omega)
    {
        set_continuous({omega}, {1, omega}, dt);
    }

    double filtering(double u) { return responce(u); } 

    double omega() const { return omega_; }
private:
    const double omega_;
};

}
```


-------------------------------

Updated on 2022-10-10 at 00:51:40 +0900
