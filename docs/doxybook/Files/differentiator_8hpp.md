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
| class | **[cpp_robotics::Differentiator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Differentiator/)** <br>疑似微分器  |




## Source code

```cpp
#pragma once

#include <cmath>
#include <cpp_robotics/system/transfer_function.hpp>

namespace cpp_robotics
{

class Differentiator : public TransferFunction
{
public:
    Differentiator(double omega, double dt): 
        omega_(omega)
    {
        TransferFunction::set_continuous({omega_, 0}, {1, omega_}, dt);
    }

    double filtering(double u) { return responce(u); } 

    double omega() const { return omega_; }
private:
    const double omega_;
};

}
```


-------------------------------

Updated on 2022-10-19 at 13:20:53 +0900
