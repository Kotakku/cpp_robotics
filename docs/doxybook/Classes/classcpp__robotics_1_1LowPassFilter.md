---
title: cpp_robotics::LowPassFilter
summary: ローパスフィルター 

---

# cpp_robotics::LowPassFilter



ローパスフィルター 


`#include <low_pass_filter.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[LowPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LowPassFilter/#function-lowpassfilter)**(double w, double dt)<br>Construct a new Low Pass Filter object.  |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LowPassFilter/#function-reset)**(double val =0) |
| double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LowPassFilter/#function-filtering)**(double u) |
| double | **[w](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LowPassFilter/#function-w)**() const |
| double | **[dt](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LowPassFilter/#function-dt)**() const |

## Public Functions Documentation

### function LowPassFilter

```cpp
inline LowPassFilter(
    double w,
    double dt
)
```

Construct a new Low Pass Filter object. 

**Parameters**: 

  * **w** 折れ点周波数[rad/s] 
  * **dt** サンプリング周期 


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

Updated on 2022-09-28 at 19:28:33 +0900