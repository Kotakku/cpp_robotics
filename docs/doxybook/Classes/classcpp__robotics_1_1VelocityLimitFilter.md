---
title: cpp_robotics::VelocityLimitFilter
summary: 速度制限フィルタ 

---

# cpp_robotics::VelocityLimitFilter



速度制限フィルタ 


`#include <velocity_limit_filter.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[VelocityLimitFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1VelocityLimitFilter/#function-velocitylimitfilter)**(double v_max_, double Ts_) |
| | **[VelocityLimitFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1VelocityLimitFilter/#function-velocitylimitfilter)**(double v_max_, double Ts_, std::pair< double, double > limit) |
| | **[VelocityLimitFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1VelocityLimitFilter/#function-velocitylimitfilter)**(double v_max_, double Ts_, double gpd_, double fb_gain, std::optional< std::pair< double, double >> limit =std::nullopt) |
| virtual void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1VelocityLimitFilter/#function-reset)**() |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1VelocityLimitFilter/#function-reset)**(double u) |
| virtual double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1VelocityLimitFilter/#function-filtering)**(double u) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| double | **[prev_v_](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1VelocityLimitFilter/#variable-prev-v-)**  |

## Public Functions Documentation

### function VelocityLimitFilter

```cpp
inline VelocityLimitFilter(
    double v_max_,
    double Ts_
)
```


### function VelocityLimitFilter

```cpp
inline VelocityLimitFilter(
    double v_max_,
    double Ts_,
    std::pair< double, double > limit
)
```


### function VelocityLimitFilter

```cpp
inline VelocityLimitFilter(
    double v_max_,
    double Ts_,
    double gpd_,
    double fb_gain,
    std::optional< std::pair< double, double >> limit =std::nullopt
)
```


### function reset

```cpp
inline virtual void reset()
```


### function reset

```cpp
inline void reset(
    double u
)
```


### function filtering

```cpp
inline virtual double filtering(
    double u
)
```


## Public Attributes Documentation

### variable prev_v_

```cpp
double prev_v_;
```


-------------------------------

Updated on 2022-10-02 at 13:22:12 +0900