---
title: cpp_robotics::PID2
summary: 2自由度PID制御器 

---

# cpp_robotics::PID2



2自由度PID制御器 


`#include <pid2.hpp>`

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[pid_param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PID2_1_1pid__param__t/)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[PID2](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PID2/#function-pid2)**([pid_param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PID2_1_1pid__param__t/) param) |
| void | **[set_param](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PID2/#function-set-param)**([pid_param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PID2_1_1pid__param__t/) param) |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PID2/#function-reset)**() |
| double | **[calculate](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PID2/#function-calculate)**(double target, double present) |

## Public Functions Documentation

### function PID2

```cpp
inline PID2(
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
    double target,
    double present
)
```


-------------------------------

Updated on 2022-10-22 at 22:05:50 +0900