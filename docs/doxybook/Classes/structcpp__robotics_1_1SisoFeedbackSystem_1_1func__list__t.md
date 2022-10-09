---
title: cpp_robotics::SisoFeedbackSystem::func_list_t

---

# cpp_robotics::SisoFeedbackSystem::func_list_t






`#include <siso_system.hpp>`

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| std::function< void(void)> | **[controller_reset](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SisoFeedbackSystem_1_1func__list__t/#variable-controller-reset)**  |
| std::function< double(double)> | **[controller](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SisoFeedbackSystem_1_1func__list__t/#variable-controller)**  |
| std::function< void(void)> | **[system_reset](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SisoFeedbackSystem_1_1func__list__t/#variable-system-reset)**  |
| std::function< double(double)> | **[system](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SisoFeedbackSystem_1_1func__list__t/#variable-system)**  |

## Public Attributes Documentation

### variable controller_reset

```cpp
std::function< void(void)> controller_reset;
```


### variable controller

```cpp
std::function< double(double)> controller;
```


### variable system_reset

```cpp
std::function< void(void)> system_reset;
```


### variable system

```cpp
std::function< double(double)> system;
```


-------------------------------

Updated on 2022-10-10 at 00:51:39 +0900