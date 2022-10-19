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
#include <cpp_robotics/system/transfer_function.hpp>

namespace cpp_robotics
{

// G(s) = 1 / s
// 双一次変換で離散化したもの
class Integrator : public TransferFunction
{
public:
    Integrator(double dt)
    {
        TransferFunction::set_continuous({1}, {1, 0}, dt);
    }

    double filtering(double u) { return responce(u); } 
};

}
```


-------------------------------

Updated on 2022-10-19 at 13:20:53 +0900
