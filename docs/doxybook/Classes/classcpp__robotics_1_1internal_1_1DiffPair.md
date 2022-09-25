---
title: cpp_robotics::internal::DiffPair

---

# cpp_robotics::internal::DiffPair






`#include <velocity_limit_filter.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[DiffPair](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1internal_1_1DiffPair/#function-diffpair)**(double Ts_, double gpd_) |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1internal_1_1DiffPair/#function-reset)**() |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1internal_1_1DiffPair/#function-reset)**(double u) |
| std::tuple< double, double > | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1internal_1_1DiffPair/#function-filtering)**(double u) |

## Public Functions Documentation

### function DiffPair

```cpp
inline DiffPair(
    double Ts_,
    double gpd_
)
```


### function reset

```cpp
inline void reset()
```


### function reset

```cpp
inline void reset(
    double u
)
```


### function filtering

```cpp
inline std::tuple< double, double > filtering(
    double u
)
```


-------------------------------

Updated on 2022-09-25 at 23:29:49 +0900