---
title: cpp_robotics::PID
summary: PID制御器 

---

# cpp_robotics::PID



PID制御器 


`#include <pid.hpp>`

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[pid_param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PID_1_1pid__param__t/)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[PID](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PID/#function-pid)**([pid_param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PID_1_1pid__param__t/) param) |
| void | **[set_param](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PID/#function-set-param)**([pid_param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PID_1_1pid__param__t/) param) |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PID/#function-reset)**() |
| double | **[calculate](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PID/#function-calculate)**(double error) |

## Public Functions Documentation

### function PID

```cpp
inline PID(
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

Updated on 2022-10-22 at 22:05:50 +0900