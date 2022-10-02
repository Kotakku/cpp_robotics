---
title: cpp_robotics::CubicSpline
summary: 3次スプライン曲線 

---

# cpp_robotics::CubicSpline



3次スプライン曲線 


`#include <spline.hpp>`

Inherits from [cpp_robotics::Spline2D](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[CubicSpline](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1CubicSpline/#function-cubicspline)**(std::vector< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) > & points, const double error =0.1) |

## Additional inherited members

**Protected Classes inherited from [cpp_robotics::Spline2D](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/)**

|                | Name           |
| -------------- | -------------- |
| struct | **[segment_info_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Spline2D_1_1segment__info__t/)**  |
| struct | **[segment_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Spline2D_1_1segment__t/)**  |

**Public Functions inherited from [cpp_robotics::Spline2D](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/)**

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

**Protected Functions inherited from [cpp_robotics::Spline2D](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/)**

|                | Name           |
| -------------- | -------------- |
| [segment_info_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Spline2D_1_1segment__info__t/) | **[get_segmet_idx](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#function-get-segmet-idx)**(const double t) |

**Protected Attributes inherited from [cpp_robotics::Spline2D](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/)**

|                | Name           |
| -------------- | -------------- |
| std::vector< [segment_t](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Spline2D_1_1segment__t/) > | **[_spline](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#variable--spline)**  |
| bool | **[_is_empty](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#variable--is-empty)**  |
| size_t | **[_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#variable--size)**  |
| double | **[_all_length](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Spline2D/#variable--all-length)**  |


## Public Functions Documentation

### function CubicSpline

```cpp
inline CubicSpline(
    std::vector< Vector2d > & points,
    const double error =0.1
)
```


-------------------------------

Updated on 2022-10-02 at 13:22:12 +0900