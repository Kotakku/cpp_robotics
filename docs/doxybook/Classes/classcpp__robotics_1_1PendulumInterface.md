---
title: cpp_robotics::PendulumInterface

---

# cpp_robotics::PendulumInterface






`#include <interface.hpp>`

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[Input](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PendulumInterface_1_1Input/)**  |
| struct | **[State](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PendulumInterface_1_1State/)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[PendulumInterface](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PendulumInterface/#function-penduluminterface)**() =default |
| virtual [State](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PendulumInterface_1_1State/) | **[get_state](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PendulumInterface/#function-get-state)**() =0 |
| virtual void | **[control](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PendulumInterface/#function-control)**(const [Input](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PendulumInterface_1_1Input/) & input) =0 |

## Public Functions Documentation

### function PendulumInterface

```cpp
PendulumInterface() =default
```


### function get_state

```cpp
virtual State get_state() =0
```


### function control

```cpp
virtual void control(
    const Input & input
) =0
```


-------------------------------

Updated on 2022-09-25 at 23:29:48 +0900