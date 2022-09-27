---
title: include/cpp_robotics/robots/robot_utils/robot_utils.hpp

---

# include/cpp_robotics/robots/robot_utils/robot_utils.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[cpp_robotics::is_base_of_robot_if](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1is__base__of__robot__if/)**  |




## Source code

```cpp
#pragma once

#include <type_traits>
#include <memory>

namespace cpp_robotics
{

template<class Interface, class UserInterface>
struct is_base_of_robot_if
{
    static constexpr bool value = std::is_base_of<Interface, UserInterface>::value;
};

template<class Interface, class UserInterface>
static constexpr bool is_base_of_robot_if_v = is_base_of_robot_if<Interface, UserInterface>::value;

}
```


-------------------------------

Updated on 2022-09-27 at 01:12:56 +0900