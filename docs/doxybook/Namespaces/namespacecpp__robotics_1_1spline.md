---
title: cpp_robotics::spline
summary: スプライン曲線用関数郡 

---

# cpp_robotics::spline

スプライン曲線用関数郡 

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[cpp_robotics::spline::spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/)**  |

## Functions

|                | Name           |
| -------------- | -------------- |
| [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) | **[bezier_spline](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-bezier-spline)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p0, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p1, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p2, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p3) |
| [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) | **[hermite_spline](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-hermite-spline)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p0, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p1, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & v0, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & v1) |
| [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) | **[catumull_spline](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-catumull-spline)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p0, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p1, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p2, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & p3) |
| [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) | **[cubic_function_to_bezier](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-cubic-function-to-bezier)**(const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & a, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & b, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & c, const [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) & d) |
| [Vector4d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector4d) | **[bezier_weight](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-bezier-weight)**(const double t) |
| [Vector4d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector4d) | **[bezier_weight](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-bezier-weight)**(const [Vector4d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector4d) t) |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[evaluate](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-evaluate)**(const [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) & spline, const [Vector4d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector4d) & w) |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[position](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-position)**(const [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) & spline, double t) |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[velocity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-velocity)**(const [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) & spline, double t) |
| [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) | **[acceleration](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-acceleration)**(const [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) & spline, double t) |
| void | **[split](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-split)**(const [Vector4d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector4d) & spline, [Vector4d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector4d) & spline0, [Vector4d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector4d) & spline1, double t) |
| void | **[split](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-split)**(const [Vector4d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector4d) & spline, [Vector4d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector4d) & spline0, [Vector4d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector4d) & spline1) |
| void | **[split](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-split)**(const [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) & spline, [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) & spline0, [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) & spline1) |
| void | **[split](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-split)**(const [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) & spline, [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) & spline0, [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) & spline1, double t) |
| double | **[length_estimate](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-length-estimate)**(const [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) & s, double * error) |
| double | **[length](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-length)**(const [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) & s, double maxError) |
| double | **[length](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-length)**(const [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) & s, double t0, double t1, double maxError) |
| double | **[curvature](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1spline/#function-curvature)**(const [spline_c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1spline_1_1spline__c/) & spline, double t) |


## Functions Documentation

### function bezier_spline

```cpp
spline_c bezier_spline(
    const Vector2d & p0,
    const Vector2d & p1,
    const Vector2d & p2,
    const Vector2d & p3
)
```


### function hermite_spline

```cpp
spline_c hermite_spline(
    const Vector2d & p0,
    const Vector2d & p1,
    const Vector2d & v0,
    const Vector2d & v1
)
```


### function catumull_spline

```cpp
spline_c catumull_spline(
    const Vector2d & p0,
    const Vector2d & p1,
    const Vector2d & p2,
    const Vector2d & p3
)
```


### function cubic_function_to_bezier

```cpp
spline_c cubic_function_to_bezier(
    const Vector2d & a,
    const Vector2d & b,
    const Vector2d & c,
    const Vector2d & d
)
```


### function bezier_weight

```cpp
Vector4d bezier_weight(
    const double t
)
```


### function bezier_weight

```cpp
Vector4d bezier_weight(
    const Vector4d t
)
```


### function evaluate

```cpp
inline Vector2d evaluate(
    const spline_c & spline,
    const Vector4d & w
)
```


### function position

```cpp
Vector2d position(
    const spline_c & spline,
    double t
)
```


### function velocity

```cpp
Vector2d velocity(
    const spline_c & spline,
    double t
)
```


### function acceleration

```cpp
Vector2d acceleration(
    const spline_c & spline,
    double t
)
```


### function split

```cpp
inline void split(
    const Vector4d & spline,
    Vector4d & spline0,
    Vector4d & spline1,
    double t
)
```


### function split

```cpp
inline void split(
    const Vector4d & spline,
    Vector4d & spline0,
    Vector4d & spline1
)
```


### function split

```cpp
void split(
    const spline_c & spline,
    spline_c & spline0,
    spline_c & spline1
)
```


### function split

```cpp
void split(
    const spline_c & spline,
    spline_c & spline0,
    spline_c & spline1,
    double t
)
```


### function length_estimate

```cpp
double length_estimate(
    const spline_c & s,
    double * error
)
```


### function length

```cpp
double length(
    const spline_c & s,
    double maxError
)
```


### function length

```cpp
double length(
    const spline_c & s,
    double t0,
    double t1,
    double maxError
)
```


### function curvature

```cpp
double curvature(
    const spline_c & spline,
    double t
)
```






-------------------------------

Updated on 2022-10-10 at 00:51:40 +0900