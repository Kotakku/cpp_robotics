---
title: cpp_robotics::VelocityLimitFilter::DiffPair

---

# cpp_robotics::VelocityLimitFilter::DiffPair





## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[DiffPair](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1VelocityLimitFilter_1_1DiffPair/#function-diffpair)**(double gpd, double Ts) |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1VelocityLimitFilter_1_1DiffPair/#function-reset)**() |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1VelocityLimitFilter_1_1DiffPair/#function-reset)**(double u) |
| std::tuple< double, double > | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1VelocityLimitFilter_1_1DiffPair/#function-filtering)**(double u) |

## Public Functions Documentation

### function DiffPair

```cpp
inline DiffPair(
    double gpd,
    double Ts
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

Updated on 2022-10-22 at 22:05:50 +0900