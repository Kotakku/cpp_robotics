---
title: include/cpp_robotics/robots/penbulum/pendulum.hpp

---

# include/cpp_robotics/robots/penbulum/pendulum.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::PendulumController](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PendulumController/)**  |




## Source code

```cpp
#pragma once

#include "./interface.hpp"

namespace cpp_robotics
{

template<class Interface>
class PendulumController
{
public:
    static_assert(is_base_of_robot_if_v<PendulumInterface, Interface>, "");
    PendulumController() = default;

    void control()
    {

    }
};

}
```


-------------------------------

Updated on 2022-09-25 at 23:20:39 +0900
