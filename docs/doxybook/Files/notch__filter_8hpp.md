---
title: include/cpp_robotics/filter/notch_filter.hpp

---

# include/cpp_robotics/filter/notch_filter.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::NotchFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/)** <br>ノッチフィルタ  |




## Source code

```cpp
#pragma once

#include <cpp_robotics/system/transfer_function.hpp>

namespace cpp_robotics
{

//         s^2 + d*2*zeta*omega*s + omega^2
// G(s) = -------------------------------- を双一次変換
//          s^2 + 2*zeta*omega*s + omega^2
class NotchFilter : public TransferFunction
{
public:
    NotchFilter(double omega, double zeta, double d, double dt):
        omega_(omega), zeta_(zeta), d_(d)
    {
        TransferFunction::set_continuous({1, (d_*2*zeta_*omega_), (omega_*omega_)}, {1, (2*zeta_*omega_), (omega_*omega_)}, dt);
    }

    double filtering(double u) { return responce(u); } 

    double omega() const { return omega_; }

    double zeta() const { return zeta_; }

    double d() const { return d_; }
private:
    const double omega_;
    const double zeta_;
    const double d_;
};

}
```


-------------------------------

Updated on 2022-10-21 at 10:30:14 +0900
