---
title: cpp_robotics::BandPassFilter
summary: バンドパスフィルタ 

---

# cpp_robotics::BandPassFilter



バンドパスフィルタ 


`#include <band_pass_filter.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[BandPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1BandPassFilter/#function-bandpassfilter)**(double w, double zeta, double dt)<br>Construct a new Notch Filter object.  |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1BandPassFilter/#function-reset)**() |
| double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1BandPassFilter/#function-filtering)**(double u) |
| double | **[w](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1BandPassFilter/#function-w)**() const |
| double | **[zeta](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1BandPassFilter/#function-zeta)**() const |
| double | **[dt](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1BandPassFilter/#function-dt)**() const |

## Public Functions Documentation

### function BandPassFilter

```cpp
inline BandPassFilter(
    double w,
    double zeta,
    double dt
)
```

Construct a new Notch Filter object. 

**Parameters**: 

  * **w** 中心周波数[rad/s] 
  * **zeta** 鋭さ 
  * **dt** サンプリング周期 


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


### function w

```cpp
inline double w() const
```


### function zeta

```cpp
inline double zeta() const
```


### function dt

```cpp
inline double dt() const
```


-------------------------------

Updated on 2022-10-08 at 23:36:07 +0900