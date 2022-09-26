---
title: cpp_robotics::DubinsPath

---

# cpp_robotics::DubinsPath






`#include <dubins_path.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| enum class| **[Mode](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DubinsPath/#enum-mode)** { LRL, RLR, LSL, LSR, RSL, RSR, NONE} |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[DubinsPath](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DubinsPath/#function-dubinspath)**([Transformd](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-transformd) start, [Transformd](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-transformd) end, double cavature) |
| double | **[length](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DubinsPath/#function-length)**() const |
| double | **[segment_length](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DubinsPath/#function-segment-length)**(size_t i) const |
| [Transformd](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-transformd) | **[position](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DubinsPath/#function-position)**(double len) const |
| std::string | **[path_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DubinsPath/#function-path-type)**() const |

## Public Types Documentation

### enum Mode

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| LRL | |   |
| RLR | |   |
| LSL | |   |
| LSR | |   |
| RSL | |   |
| RSR | |   |
| NONE | |   |




## Public Functions Documentation

### function DubinsPath

```cpp
inline DubinsPath(
    Transformd start,
    Transformd end,
    double cavature
)
```


### function length

```cpp
inline double length() const
```


### function segment_length

```cpp
inline double segment_length(
    size_t i
) const
```


### function position

```cpp
inline Transformd position(
    double len
) const
```


### function path_type

```cpp
inline std::string path_type() const
```


-------------------------------

Updated on 2022-09-26 at 11:58:17 +0900