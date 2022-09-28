---
title: cpp_robotics::AccelerationLimitFilter
summary: 加速度制限フィルタ(速度制限込み) 

---

# cpp_robotics::AccelerationLimitFilter



加速度制限フィルタ(速度制限込み)  [More...](#detailed-description)


`#include <acceleration_limit_filter.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[AccelerationLimitFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AccelerationLimitFilter/#function-accelerationlimitfilter)**(double acc_max, double Ts, double gpd, double Kx, double Kv, std::optional< std::pair< double, double >> limit =std::nullopt) |
| | **[AccelerationLimitFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AccelerationLimitFilter/#function-accelerationlimitfilter)**(double acc_max, double Ts, std::optional< std::pair< double, double >> limit =std::nullopt) |
| virtual void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AccelerationLimitFilter/#function-reset)**() |
| virtual double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AccelerationLimitFilter/#function-filtering)**(double u) |

## Detailed Description

```cpp
class cpp_robotics::AccelerationLimitFilter;
```

加速度制限フィルタ(速度制限込み) 

熊本大学の岡島研究室の文献を参考にした 

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

Updated on 2022-09-28 at 23:34:44 +0900