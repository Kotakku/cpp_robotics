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
#include <cpp_robotics/system/discrete_transfer_function.hpp>

namespace cpp_robotics
{

// G(s) = 1 / s
// 双一次変換で離散化したもの
class Integrator : public DiscreteTransferFunction
{
public:
    Integrator(double dt)
    {
        set_continuous({1}, {1, 0}, dt);
    }

    double filtering(double u) { return responce(u); } 
};

}
```


-------------------------------

Updated on 2022-10-10 at 00:51:40 +0900
