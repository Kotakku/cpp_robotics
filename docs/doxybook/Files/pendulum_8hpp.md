---
title: include/cpp_robotics/robots/penbulum/pendulum.hpp

---

# include/cpp_robotics/robots/penbulum/pendulum.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |




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

Updated on 2022-09-28 at 19:28:33 +0900
