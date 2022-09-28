---
title: cpp_robotics::HighPassFilter
summary: ハイパスフィルタ 

---

# cpp_robotics::HighPassFilter



ハイパスフィルタ 


`#include <high_pass_filter.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[HighPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1HighPassFilter/#function-highpassfilter)**(double w, double dt)<br>Construct a new High Pass Filter object.  |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1HighPassFilter/#function-reset)**(double val =0) |
| double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1HighPassFilter/#function-filtering)**(double u) |
| double | **[w](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1HighPassFilter/#function-w)**() const |
| double | **[dt](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1HighPassFilter/#function-dt)**() const |

## Public Functions Documentation

### function HighPassFilter

```cpp
inline HighPassFilter(
    double w,
    double dt
)
```

Construct a new High Pass Filter object. 

**Parameters**: 

  * **w** 折れ点周波数[rad/s] 
  * **dt** 


### function reset

```cpp
inline void reset(
    double val =0
)
```


### function filtering

```cpp
inline double filtering(
    double u
)
```


### function w

```cpp
inline double w() const
```


### function dt

```cpp
inline double dt() const
```


-------------------------------

Updated on 2022-09-28 at 23:12:43 +0900