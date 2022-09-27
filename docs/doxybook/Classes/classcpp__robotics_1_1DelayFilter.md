---
title: cpp_robotics::DelayFilter
summary: 遅延フィルタ 

---

# cpp_robotics::DelayFilter



遅延フィルタ  [More...](#detailed-description)


`#include <delay_filter.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[DelayFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DelayFilter/#function-delayfilter)**(double delay_time, double Ts) |
| virtual void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DelayFilter/#function-reset)**() |
| virtual double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DelayFilter/#function-filtering)**(double u) |

## Detailed Description

```cpp
class cpp_robotics::DelayFilter;
```

遅延フィルタ 

G(s) = e^(-T*s) 遅延時間はサンプリング時間の整数倍のみ 

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

Updated on 2022-09-28 at 01:12:56 +0900