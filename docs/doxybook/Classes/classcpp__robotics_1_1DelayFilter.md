---
title: cpp_robotics::DelayFilter

---

# cpp_robotics::DelayFilter






`#include <delay_filter.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[DelayFilter](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1DelayFilter/#function-delayfilter)**(double delay_time, double Ts) |
| virtual void | **[reset](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1DelayFilter/#function-reset)**() |
| virtual double | **[filtering](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1DelayFilter/#function-filtering)**(double u) |

## Public Functions Documentation

### function DelayFilter

```cpp
inline DelayFilter(
    double delay_time,
    double Ts
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

Updated on 2022-09-25 at 23:11:52 +0900