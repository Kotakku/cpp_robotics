---
title: cpp_robotics::PSMC

---

# cpp_robotics::PSMC






`#include <psmc.hpp>`

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PSMC_1_1param__t/)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[PSMC](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PSMC/#function-psmc)**() |
| | **[PSMC](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PSMC/#function-psmc)**([param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PSMC_1_1param__t/) param) |
| | **[PSMC](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PSMC/#function-psmc)**(double p, double d, double Hs, double dt) |
| | **[PSMC](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PSMC/#function-psmc)**(double p, double d, double Hs, double min_output, double max_output, double dt) |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PSMC/#function-reset)**() |
| void | **[set_param](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PSMC/#function-set-param)**([param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PSMC_1_1param__t/) param) |
| double | **[calculate](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PSMC/#function-calculate)**(double target_val, double now_val) |
| double | **[calculate](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PSMC/#function-calculate)**(double target_val, double now_val, double target_velocity, double now_velocity) |
| double & | **[Kp](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PSMC/#function-kp)**() |
| double & | **[Kd](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PSMC/#function-kd)**() |
| double & | **[Hs](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PSMC/#function-hs)**() |

## Public Functions Documentation

### function PSMC

```cpp
inline PSMC()
```


### function PSMC

```cpp
inline PSMC(
    param_t param
)
```


### function PSMC

```cpp
inline PSMC(
    double p,
    double d,
    double Hs,
    double dt
)
```


### function PSMC

```cpp
inline PSMC(
    double p,
    double d,
    double Hs,
    double min_output,
    double max_output,
    double dt
)
```


### function reset

```cpp
inline void reset()
```


### function set_param

```cpp
inline void set_param(
    param_t param
)
```


### function calculate

```cpp
inline double calculate(
    double target_val,
    double now_val
)
```


### function calculate

```cpp
inline double calculate(
    double target_val,
    double now_val,
    double target_velocity,
    double now_velocity
)
```


### function Kp

```cpp
inline double & Kp()
```


### function Kd

```cpp
inline double & Kd()
```


### function Hs

```cpp
inline double & Hs()
```


-------------------------------

Updated on 2022-10-19 at 13:20:53 +0900