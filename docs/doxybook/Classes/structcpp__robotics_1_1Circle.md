---
title: cpp_robotics::Circle
summary: 円クラス 

---

# cpp_robotics::Circle



円クラス 


`#include <shape.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Circle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Circle/#function-circle)**() =default |
| constexpr | **[Circle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Circle/#function-circle)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & center, const double r) |
| constexpr bool | **[has_area](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Circle/#function-has-area)**() const |
| constexpr double | **[area](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Circle/#function-area)**() const |
| constexpr [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[angle_pos](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Circle/#function-angle-pos)**(const double theta) const |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[center](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Circle/#variable-center)**  |
| double | **[r](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Circle/#variable-r)**  |

## Public Functions Documentation

### function Circle

```cpp
Circle() =default
```


### function Circle

```cpp
inline constexpr Circle(
    const Vector2d & center,
    const double r
)
```


### function has_area

```cpp
inline constexpr bool has_area() const
```


### function area

```cpp
inline constexpr double area() const
```


### function angle_pos

```cpp
inline constexpr Vector2d angle_pos(
    const double theta
) const
```


## Public Attributes Documentation

### variable center

```cpp
Vector2d center;
```


### variable r

```cpp
double r;
```


-------------------------------

Updated on 2022-10-22 at 22:05:49 +0900