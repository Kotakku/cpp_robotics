---
title: matplotlibcpp::Plot

---

# matplotlibcpp::Plot






`#include <matplotlibcpp.h>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| template <typename Numeric \> <br>| **[Plot](/cpp_robotics_core/doxybook/Classes/classmatplotlibcpp_1_1Plot/#function-plot)**(const std::string & name, const std::vector< Numeric > & x, const std::vector< Numeric > & y, const std::string & format ="") |
| | **[Plot](/cpp_robotics_core/doxybook/Classes/classmatplotlibcpp_1_1Plot/#function-plot)**(const std::string & name ="", const std::string & format ="") |
| template <typename Numeric \> <br>bool | **[update](/cpp_robotics_core/doxybook/Classes/classmatplotlibcpp_1_1Plot/#function-update)**(const std::vector< Numeric > & x, const std::vector< Numeric > & y) |
| bool | **[clear](/cpp_robotics_core/doxybook/Classes/classmatplotlibcpp_1_1Plot/#function-clear)**() |
| void | **[remove](/cpp_robotics_core/doxybook/Classes/classmatplotlibcpp_1_1Plot/#function-remove)**() |
| | **[~Plot](/cpp_robotics_core/doxybook/Classes/classmatplotlibcpp_1_1Plot/#function-~plot)**() |

## Public Functions Documentation

### function Plot

```cpp
template <typename Numeric >
inline Plot(
    const std::string & name,
    const std::vector< Numeric > & x,
    const std::vector< Numeric > & y,
    const std::string & format =""
)
```


### function Plot

```cpp
inline Plot(
    const std::string & name ="",
    const std::string & format =""
)
```


### function update

```cpp
template <typename Numeric >
inline bool update(
    const std::vector< Numeric > & x,
    const std::vector< Numeric > & y
)
```


### function clear

```cpp
inline bool clear()
```


### function remove

```cpp
inline void remove()
```


### function ~Plot

```cpp
inline ~Plot()
```


-------------------------------

Updated on 2022-09-25 at 23:10:54 +0900