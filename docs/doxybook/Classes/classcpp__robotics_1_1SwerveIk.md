---
title: cpp_robotics::SwerveIk
summary: メカナムの逆運動学モデル 

---

# cpp_robotics::SwerveIk



メカナムの逆運動学モデル 


`#include <swerve_ik.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using std::array< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d), 4 > | **[VecArray](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SwerveIk/#using-vecarray)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[SwerveIk](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SwerveIk/#function-swerveik)**(const double width, const double length) |
| | **[SwerveIk](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SwerveIk/#function-swerveik)**([VecArray](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SwerveIk/#using-vecarray) wheel_place) |
| [VecArray](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SwerveIk/#using-vecarray) | **[calculate](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SwerveIk/#function-calculate)**([Transformd](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-transformd) velocity) |
| [VecArray](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SwerveIk/#using-vecarray) | **[wheel_place](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SwerveIk/#function-wheel-place)**() const |

## Public Types Documentation

### using VecArray

```cpp
using cpp_robotics::SwerveIk::VecArray =  std::array<Vector2d, 4>;
```


## Public Functions Documentation

### function SwerveIk

```cpp
inline SwerveIk(
    const double width,
    const double length
)
```


### function SwerveIk

```cpp
inline SwerveIk(
    VecArray wheel_place
)
```


### function calculate

```cpp
inline VecArray calculate(
    Transformd velocity
)
```


### function wheel_place

```cpp
inline VecArray wheel_place() const
```


-------------------------------

Updated on 2022-10-05 at 01:02:06 +0900