---
title: cpp_robotics::Line
summary: 直線クラス 

---

# cpp_robotics::Line



直線クラス 


`#include <shape.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/#function-line)**() =default |
| constexpr | **[Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/#function-line)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p0, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p1) |
| void | **[set](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/#function-set)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p0_, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p1_) |
| constexpr float | **[length](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/#function-length)**() const |
| constexpr float | **[angle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/#function-angle)**() const |
| constexpr [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[lerp](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/#function-lerp)**(const float t) const |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[p0](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/#variable-p0)**  |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[p1](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/#variable-p1)**  |

## Public Functions Documentation

### function Line

```cpp
Line() =default
```


### function Line

```cpp
inline constexpr Line(
    const Vector2d & p0,
    const Vector2d & p1
)
```


### function set

```cpp
inline void set(
    const Vector2d & p0_,
    const Vector2d & p1_
)
```


### function length

```cpp
inline constexpr float length() const
```


### function angle

```cpp
inline constexpr float angle() const
```


### function lerp

```cpp
inline constexpr Vector2d lerp(
    const float t
) const
```


## Public Attributes Documentation

### variable p0

```cpp
Vector2d p0;
```


### variable p1

```cpp
Vector2d p1;
```


-------------------------------

Updated on 2022-09-25 at 23:20:38 +0900