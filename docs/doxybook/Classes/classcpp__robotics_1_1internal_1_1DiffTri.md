---
title: cpp_robotics::internal::DiffTri

---

# cpp_robotics::internal::DiffTri






`#include <acceleration_limit_filter.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[DiffTri](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1internal_1_1DiffTri/#function-difftri)**(double Ts, double gpd) |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1internal_1_1DiffTri/#function-reset)**() |
| std::tuple< double, double, double > | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1internal_1_1DiffTri/#function-filtering)**(double u) |

## Public Functions Documentation

### function DiffTri

```cpp
inline DiffTri(
    double Ts,
    double gpd
)
```


### function reset

```cpp
inline void reset()
```


### function filtering

```cpp
inline std::tuple< double, double, double > filtering(
    double u
)
```


-------------------------------

Updated on 2022-09-25 at 23:20:38 +0900