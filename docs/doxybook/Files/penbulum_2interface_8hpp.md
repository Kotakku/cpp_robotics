---
title: include/cpp_robotics/robots/penbulum/interface.hpp

---

# include/cpp_robotics/robots/penbulum/interface.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::PendulumInterface](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PendulumInterface/)**  |
| struct | **[cpp_robotics::PendulumInterface::State](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PendulumInterface_1_1State/)**  |
| struct | **[cpp_robotics::PendulumInterface::Input](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PendulumInterface_1_1Input/)**  |




## Source code

```cpp
#pragma once

#include "../robot_utils/robot_utils.hpp"

namespace cpp_robotics
{

// StateとInputはここで定義するんじゃなくてユーザー側で定義できるべき?
class PendulumInterface
{
public:
    PendulumInterface() = default;

    struct State
    {
        double angle;
        double omega;
        double domega;
        
        double pos;
        double vel;
        double acc;

        std::shared_ptr<void> arg;
    };
    

    struct Input
    {
        double input;

        std::shared_ptr<void> arg;
    };

    virtual State get_state() = 0;
    virtual void control(const Input &input) = 0;
};

}
```


-------------------------------

Updated on 2022-09-26 at 11:58:18 +0900
