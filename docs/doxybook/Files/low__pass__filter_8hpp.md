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
#include <cpp_robotics/system/transfer_function.hpp>

namespace cpp_robotics
{

// G(s) = omega / (s + omega)
class LowPassFilter : public TransferFunction
{
public:
    LowPassFilter(double omega, double dt):
        omega_(omega)
    {
        TransferFunction::set_continuous({omega_}, {1, omega_}, dt);
    }

    double filtering(double u) { return responce(u); } 

    double omega() const { return omega_; }
private:
    const double omega_;
};

}
```


-------------------------------

Updated on 2022-10-21 at 10:30:14 +0900
