---
title: cpp_robotics::AccelerationLimitFilter

---

# cpp_robotics::AccelerationLimitFilter






`#include <acceleration_limit_filter.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[AccelerationLimitFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AccelerationLimitFilter/#function-accelerationlimitfilter)**(double acc_max, double Ts, double gpd, double Kx, double Kv, std::optional< std::pair< double, double >> limit =std::nullopt) |
| | **[AccelerationLimitFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AccelerationLimitFilter/#function-accelerationlimitfilter)**(double acc_max, double Ts, std::optional< std::pair< double, double >> limit =std::nullopt) |
| virtual void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AccelerationLimitFilter/#function-reset)**() |
| virtual double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AccelerationLimitFilter/#function-filtering)**(double u) |

## Public Functions Documentation

### function AccelerationLimitFilter

```cpp
inline AccelerationLimitFilter(
    double acc_max,
    double Ts,
    double gpd,
    double Kx,
    double Kv,
    std::optional< std::pair< double, double >> limit =std::nullopt
)
```


### function AccelerationLimitFilter

```cpp
inline AccelerationLimitFilter(
    double acc_max,
    double Ts,
    std::optional< std::pair< double, double >> limit =std::nullopt
)
```


### function reset

```cpp
inline virtual void reset()
```


### function filtering

```cpp
inline virtual double filtering(
    double u
)
```


-------------------------------

Updated on 2022-09-26 at 11:58:17 +0900