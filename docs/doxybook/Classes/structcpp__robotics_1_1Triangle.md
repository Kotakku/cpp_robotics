---
title: cpp_robotics::Triangle
summary: 三角形クラス 

---

# cpp_robotics::Triangle



三角形クラス 


`#include <shape.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Triangle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Triangle/#function-triangle)**() =default |
| constexpr | **[Triangle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Triangle/#function-triangle)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p0, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p1, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p2) |
| void | **[set](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Triangle/#function-set)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p0_, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p1_, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p2_) |
| constexpr bool | **[has_area](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Triangle/#function-has-area)**() const |
| constexpr double | **[area](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Triangle/#function-area)**() const |
| constexpr std::array< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d), 3 > | **[vertex](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Triangle/#function-vertex)**() const |
| constexpr std::array< [Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/), 3 > | **[outline](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Triangle/#function-outline)**() const |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[p0](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Triangle/#variable-p0)**  |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[p1](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Triangle/#variable-p1)**  |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[p2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Triangle/#variable-p2)**  |

## Public Functions Documentation

### function Triangle

```cpp
Triangle() =default
```


### function Triangle

```cpp
inline constexpr Triangle(
    const Vector2d & p0,
    const Vector2d & p1,
    const Vector2d & p2
)
```


### function set

```cpp
inline void set(
    const Vector2d & p0_,
    const Vector2d & p1_,
    const Vector2d & p2_
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


### function vertex

```cpp
inline constexpr std::array< Vector2d, 3 > vertex() const
```


### function outline

```cpp
inline constexpr std::array< Line, 3 > outline() const
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


-------------------------------

Updated on 2022-10-22 at 22:05:50 +0900