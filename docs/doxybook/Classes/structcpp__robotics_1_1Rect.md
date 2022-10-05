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
| constexpr | **[Rect](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-rect)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & pos, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & size) |
| void | **[set](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-set)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & pos_, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & size_) |
| void | **[set_center](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-set-center)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & pos_, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & size_) |
| constexpr [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[center](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-center)**() const |
| constexpr bool | **[has_area](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-has-area)**() const |
| constexpr float | **[area](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-area)**() const |
| constexpr std::array< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d), 4 > | **[vertex](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-vertex)**() const |
| constexpr std::array< [Line](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Line/), 4 > | **[outline](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-outline)**() const |
| constexpr [Quad](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/) | **[as_quad](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-as-quad)**() const |
| constexpr [Quad](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quad/) | **[get_rotated](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-get-rotated)**(float angle) const |
| constexpr [Rect](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/) | **[gen_center](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#function-gen-center)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & center_pos, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & size) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[pos](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#variable-pos)**  |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[size](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Rect/#variable-size)**  |

## Public Functions Documentation

### function Rect

```cpp
Rect() =default
```


### function Rect

```cpp
inline constexpr Rect(
    const Vector2d & pos,
    const Vector2d & size
)
```


### function set

```cpp
inline void set(
    const Vector2d & pos_,
    const Vector2d & size_
)
```


### function set_center

```cpp
inline void set_center(
    const Vector2d & pos_,
    const Vector2d & size_
)
```


### function center

```cpp
inline constexpr Vector2d center() const
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


### function as_quad

```cpp
constexpr Quad as_quad() const
```


### function get_rotated

```cpp
constexpr Quad get_rotated(
    float angle
) const
```


### function gen_center

```cpp
static inline constexpr Rect gen_center(
    const Vector2d & center_pos,
    const Vector2d & size
)
```


## Public Attributes Documentation

### variable pos

```cpp
Vector2d pos;
```


### variable size

```cpp
Vector2d size;
```


-------------------------------

Updated on 2022-10-05 at 16:05:00 +0900