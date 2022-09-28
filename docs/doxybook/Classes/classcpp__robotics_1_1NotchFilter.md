---
title: cpp_robotics::NotchFilter
summary: ノッチフィルタ 

---

# cpp_robotics::NotchFilter



ノッチフィルタ 


`#include <notch_filter.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[NotchFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-notchfilter)**(double w, double zeta, double d, double dt)<br>Construct a new Notch Filter object.  |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-reset)**() |
| double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-filtering)**(double u) |
| double | **[w](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-w)**() const |
| double | **[zeta](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-zeta)**() const |
| double | **[d](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-d)**() const |
| double | **[dt](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-dt)**() const |

## Public Functions Documentation

### function NotchFilter

```cpp
inline NotchFilter(
    double w,
    double zeta,
    double d,
    double dt
)
```

Construct a new Notch Filter object. 

**Parameters**: 

  * **w** 中心周波数[rad/s] 
  * **zeta** 鋭さ 
  * **d** 深さ(0.0で一番深く、1.0に近づけるほどフィルタの効果が弱くなる) 
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


### function d

```cpp
inline double d() const
```


### function dt

```cpp
inline double dt() const
```


-------------------------------

Updated on 2022-09-28 at 23:12:43 +0900