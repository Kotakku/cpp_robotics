---
title: cpp_robotics::Quad
summary: 四角形 

---

# cpp_robotics::Quad



四角形 


`#include <shape.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Quad](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/#function-quad)**() =default |
| constexpr | **[Quad](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/#function-quad)**(const std::array< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d), 4 > & points) |
| constexpr | **[Quad](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/#function-quad)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p0, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p1, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p2, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p3) |
| void | **[set](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/#function-set)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p0_, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p1_, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p2_, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p3_) |
| constexpr bool | **[has_area](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/#function-has-area)**() const |
| constexpr float | **[area](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/#function-area)**() const |
| constexpr std::array< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d), 4 > | **[vertex](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/#function-vertex)**() const |
| constexpr std::array< [Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/), 4 > | **[outline](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/#function-outline)**() const |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[p0](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/#variable-p0)**  |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[p1](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/#variable-p1)**  |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[p2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/#variable-p2)**  |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[p3](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/#variable-p3)**  |

## Public Functions Documentation

### function Quad

```cpp
Quad() =default
```


### function Quad

```cpp
inline constexpr Quad(
    const std::array< Vector2d, 4 > & points
)
```


### function Quad

```cpp
inline constexpr Quad(
    const Vector2d & p0,
    const Vector2d & p1,
    const Vector2d & p2,
    const Vector2d & p3
)
```


### function set

```cpp
inline void set(
    const Vector2d & p0_,
    const Vector2d & p1_,
    const Vector2d & p2_,
    const Vector2d & p3_
)
```


### function has_area

```cpp
inline constexpr bool has_area() const
```


### function area

```cpp
inline constexpr float area() const
```


### function vertex

```cpp
inline constexpr std::array< Vector2d, 4 > vertex() const
```


### function outline

```cpp
inline constexpr std::array< Line, 4 > outline() const
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


### variable p2

```cpp
Vector2d p2;
```


### variable p3

```cpp
Vector2d p3;
```


-------------------------------

Updated on 2022-09-25 at 23:50:01 +0900