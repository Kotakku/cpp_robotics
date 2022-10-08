---
title: cpp_robotics::Spline2D
summary: 2次元のスプライン曲線のインターフェイスクラス 

---

# cpp_robotics::Spline2D



2次元のスプライン曲線のインターフェイスクラス 


`#include <spline.hpp>`

Inherited by [cpp_robotics::CatumullRom2D](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1CatumullRom2D/), [cpp_robotics::CubicSpline](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1CubicSpline/)

## Protected Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[segment_info_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Spline2D_1_1segment__info__t/)**  |
| struct | **[segment_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Spline2D_1_1segment__t/)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Spline2D](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#function-spline2d)**() =default |
| bool | **[is_empty](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#function-is-empty)**() |
| size_t | **[size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#function-size)**() |
| size_t | **[point_num](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#function-point-num)**() |
| double | **[length](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#function-length)**() |
| double | **[length](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#function-length)**(size_t i) |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[position](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#function-position)**(double t) |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[velocity](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#function-velocity)**(double t) |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[acceleration](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#function-acceleration)**(double t) |

## Protected Functions

|                | Name           |
| -------------- | -------------- |
| [segment_info_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Spline2D_1_1segment__info__t/) | **[get_segmet_idx](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#function-get-segmet-idx)**(const double t) |

## Protected Attributes

|                | Name           |
| -------------- | -------------- |
| std::vector< [segment_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Spline2D_1_1segment__t/) > | **[_spline](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#variable--spline)**  |
| bool | **[_is_empty](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#variable--is-empty)**  |
| size_t | **[_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#variable--size)**  |
| double | **[_all_length](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#variable--all-length)**  |

## Public Functions Documentation

### function Spline2D

```cpp
Spline2D() =default
```


### function is_empty

```cpp
inline bool is_empty()
```


### function size

```cpp
inline size_t size()
```


### function point_num

```cpp
inline size_t point_num()
```


### function length

```cpp
inline double length()
```


### function length

```cpp
inline double length(
    size_t i
)
```


### function position

```cpp
inline Vector2d position(
    double t
)
```


### function velocity

```cpp
inline Vector2d velocity(
    double t
)
```


### function acceleration

```cpp
inline Vector2d acceleration(
    double t
)
```


## Protected Functions Documentation

### function get_segmet_idx

```cpp
inline segment_info_t get_segmet_idx(
    const double t
)
```


## Protected Attributes Documentation

### variable _spline

```cpp
std::vector< segment_t > _spline;
```


### variable _is_empty

```cpp
bool _is_empty;
```


### variable _size

```cpp
size_t _size;
```


### variable _all_length

```cpp
double _all_length;
```


-------------------------------

Updated on 2022-10-08 at 23:36:07 +0900