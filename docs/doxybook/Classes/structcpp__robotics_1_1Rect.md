---
title: cpp_robotics::Rect
summary: 長方形クラス(回転は考えない) 

---

# cpp_robotics::Rect



長方形クラス(回転は考えない) 


`#include <shape.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Rect](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-rect)**() =default |
| constexpr | **[Rect](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-rect)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & center, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & size) |
| void | **[set](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-set)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & center_, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & size_) |
| constexpr bool | **[has_area](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-has-area)**() const |
| constexpr double | **[area](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-area)**() const |
| constexpr std::array< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d), 4 > | **[vertex](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-vertex)**() const |
| constexpr std::array< [Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/), 4 > | **[outline](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-outline)**() const |
| constexpr [Quad](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/) | **[as_quad](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-as-quad)**() const |
| constexpr [Quad](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/) | **[get_rotated](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-get-rotated)**(double angle) const |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[center](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#variable-center)**  |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[size](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#variable-size)**  |

## Public Functions Documentation

### function Rect

```cpp
Rect() =default
```


### function Rect

```cpp
inline constexpr Rect(
    const Vector2d & center,
    const Vector2d & size
)
```


### function set

```cpp
inline void set(
    const Vector2d & center_,
    const Vector2d & size_
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
inline constexpr std::array< Vector2d, 4 > vertex() const
```


### function outline

```cpp
inline constexpr std::array< Line, 4 > outline() const
```


### function as_quad

```cpp
inline constexpr Quad as_quad() const
```


### function get_rotated

```cpp
inline constexpr Quad get_rotated(
    double angle
) const
```


## Public Attributes Documentation

### variable center

```cpp
Vector2d center;
```


### variable size

```cpp
Vector2d size;
```


-------------------------------

Updated on 2022-10-10 at 00:51:39 +0900