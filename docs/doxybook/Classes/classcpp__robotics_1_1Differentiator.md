---
title: cpp_robotics::Differentiator
summary: 疑似微分器 

---

# cpp_robotics::Differentiator



疑似微分器  [More...](#detailed-description)


`#include <differentiator.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Differentiator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Differentiator/#function-differentiator)**(double bandwidth, double sample_time) |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Differentiator/#function-reset)**() |
| double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Differentiator/#function-filtering)**(double u) |

## Detailed Description

```cpp
class cpp_robotics::Differentiator;
```

疑似微分器 

G(s) = s / (Ts + 1) 双一次変換で離散化したもの 

## Public Functions Documentation

### function Differentiator

```cpp
inline Differentiator(
    double bandwidth,
    double sample_time
)
```


### function reset

```cpp
inline void reset()
```


### function filtering

```cpp
inline double filtering(
    double u
)
```


-------------------------------

Updated on 2022-09-28 at 23:34:45 +0900