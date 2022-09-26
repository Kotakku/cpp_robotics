---
title: cpp_robotics::PIDController

---

# cpp_robotics::PIDController






`#include <pid.hpp>`

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[pid_param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PIDController_1_1pid__param__t/)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[PIDController](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PIDController/#function-pidcontroller)**([pid_param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PIDController_1_1pid__param__t/) param) |
| void | **[set_param](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PIDController/#function-set-param)**([pid_param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PIDController_1_1pid__param__t/) param) |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PIDController/#function-reset)**() |
| double | **[calculate](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PIDController/#function-calculate)**(double error) |

## Public Functions Documentation

### function PIDController

```cpp
inline PIDController(
    pid_param_t param
)
```


### function set_param

```cpp
inline void set_param(
    pid_param_t param
)
```


### function reset

```cpp
inline void reset()
```


### function calculate

```cpp
inline double calculate(
    double error
)
```


-------------------------------

Updated on 2022-09-26 at 11:58:17 +0900