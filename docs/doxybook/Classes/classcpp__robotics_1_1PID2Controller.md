---
title: cpp_robotics::PID2Controller
summary: 2自由度PID制御器 

---

# cpp_robotics::PID2Controller



2自由度PID制御器 


`#include <pid2.hpp>`

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[pid_param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PID2Controller_1_1pid__param__t/)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[PID2Controller](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PID2Controller/#function-pid2controller)**([pid_param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PID2Controller_1_1pid__param__t/) param) |
| void | **[setParam](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PID2Controller/#function-setparam)**([pid_param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PID2Controller_1_1pid__param__t/) param) |
| void | **[set_param](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PID2Controller/#function-set-param)**([pid_param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PID2Controller_1_1pid__param__t/) param) |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PID2Controller/#function-reset)**() |
| double | **[calculate](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PID2Controller/#function-calculate)**(double target, double present, double dt) |
| double | **[calculate](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PID2Controller/#function-calculate)**(double target, double present) |

## Public Functions Documentation

### function PID2Controller

```cpp
inline PID2Controller(
    pid_param_t param
)
```


### function setParam

```cpp
inline void setParam(
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
    double present,
    double dt
)
```


### function calculate

```cpp
inline double calculate(
    double target,
    double present
)
```


-------------------------------

Updated on 2022-10-05 at 16:05:00 +0900