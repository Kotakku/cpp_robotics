---
title: include/cpp_robotics/filter/high_pass_filter.hpp

---

# include/cpp_robotics/filter/high_pass_filter.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::HighPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1HighPassFilter/)** <br>ハイパスフィルタ  |




## Source code

```cpp
#pragma once

#include <cmath>
#include <cpp_robotics/system/transfer_function.hpp>

namespace cpp_robotics
{

// G(s) = s / (s + omega)
// 双一次変換で離散化したもの
class HighPassFilter: public TransferFunction
{
public:
    HighPassFilter(double omega, double dt):
        omega_(omega)
    {
        TransferFunction::set_continuous({1, 0}, {1, omega_}, dt);
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
