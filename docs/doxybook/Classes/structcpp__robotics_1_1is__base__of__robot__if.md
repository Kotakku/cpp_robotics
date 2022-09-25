---
title: cpp_robotics::is_base_of_robot_if

---

# cpp_robotics::is_base_of_robot_if



 [More...](#detailed-description)


`#include <robot_utils.hpp>`

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| constexpr bool | **[value](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1is__base__of__robot__if/#variable-value)**  |

## Detailed Description

```cpp
template <class Interface ,
class UserInterface >
struct cpp_robotics::is_base_of_robot_if;
```

## Public Attributes Documentation

### variable value

```cpp
static constexpr bool value = std::is_base_of<Interface, UserInterface>::value;
```


-------------------------------

Updated on 2022-09-25 at 23:20:38 +0900