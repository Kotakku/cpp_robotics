---
title: include/cpp_robotics/filter/band_pass_filter.hpp

---

# include/cpp_robotics/filter/band_pass_filter.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::BandPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1BandPassFilter/)** <br>バンドパスフィルタ  |




## Source code

```cpp
#pragma once

#include <cpp_robotics/system/transfer_function.hpp>

namespace cpp_robotics
{

//               2*zeta*omega*s
// G(s) = ------------------------------ を双一次変換
//         s^2 + 2*zeta*omega*s + omega^2
class BandPassFilter : public TransferFunction
{
public:
    BandPassFilter(double omega, double zeta, double dt):
        omega_(omega), zeta_(zeta)
    {
        TransferFunction::set_continuous({(2*zeta_*omega_),0}, {1,(2*zeta_*omega_),(omega*omega)}, dt);
    }

    double filtering(double u) { return responce(u); } 

    double omega() const { return omega_; }

    double zeta() const { return zeta_; }
private:
    const double omega_;
    const double zeta_;
};

}
```


-------------------------------

Updated on 2022-10-22 at 22:05:50 +0900
