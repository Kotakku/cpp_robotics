---
title: cpp_robotics::NctfController
summary: NCTF制御器 

---

# cpp_robotics::NctfController



NCTF制御器 


`#include <nctf.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| std::function< double(double)> | **[make_simple_nct](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NctfController/#function-make-simple-nct)**(double max_velocity, double slope) |
| | **[NctfController](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NctfController/#function-nctfcontroller)**(double max_velocity, double nct_slope, [PIDController::pid_param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PIDController_1_1pid__param__t/) pid_param, double dt) |
| | **[NctfController](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NctfController/#function-nctfcontroller)**(std::function< double(double)> nct, [PIDController::pid_param_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1PIDController_1_1pid__param__t/) pid_param, double dt) |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NctfController/#function-reset)**() |
| double | **[control](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NctfController/#function-control)**(double target, double state) |
| double | **[control](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NctfController/#function-control)**(double e) |
| std::function< double(double)> | **[nct](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NctfController/#function-nct)**() const |

## Public Functions Documentation

### function make_simple_nct

```cpp
static inline std::function< double(double)> make_simple_nct(
    double max_velocity,
    double slope
)
```


### function NctfController

```cpp
inline NctfController(
    double max_velocity,
    double nct_slope,
    PIDController::pid_param_t pid_param,
    double dt
)
```


### function NctfController

```cpp
inline NctfController(
    std::function< double(double)> nct,
    PIDController::pid_param_t pid_param,
    double dt
)
```


### function reset

```cpp
inline void reset()
```


### function control

```cpp
inline double control(
    double target,
    double state
)
```


### function control

```cpp
inline double control(
    double e
)
```


### function nct

```cpp
inline std::function< double(double)> nct() const
```


-------------------------------

Updated on 2022-10-05 at 01:02:06 +0900