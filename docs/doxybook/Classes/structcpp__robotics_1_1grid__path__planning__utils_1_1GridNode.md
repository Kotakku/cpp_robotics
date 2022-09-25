---
title: cpp_robotics::grid_path_planning_utils::GridNode

---

# cpp_robotics::grid_path_planning_utils::GridNode






`#include <grid_path_planning_utils.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| bool | **[operator==](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1grid__path__planning__utils_1_1GridNode/#function-operator==)**(const [GridNode](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1grid__path__planning__utils_1_1GridNode/) & o) |
| bool | **[operator==](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1grid__path__planning__utils_1_1GridNode/#function-operator==)**(const Eigen::Vector2i & o) |
| bool | **[operator<](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1grid__path__planning__utils_1_1GridNode/#function-operator<)**(const [GridNode](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1grid__path__planning__utils_1_1GridNode/) & o) |
| int | **[score](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1grid__path__planning__utils_1_1GridNode/#function-score)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| Eigen::Vector2i | **[pos](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1grid__path__planning__utils_1_1GridNode/#variable-pos)**  |
| Eigen::Vector2i | **[parent](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1grid__path__planning__utils_1_1GridNode/#variable-parent)**  |
| int | **[cost](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1grid__path__planning__utils_1_1GridNode/#variable-cost)**  |
| int | **[hcost](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1grid__path__planning__utils_1_1GridNode/#variable-hcost)**  |

## Public Functions Documentation

### function operator==

```cpp
inline bool operator==(
    const GridNode & o
)
```


### function operator==

```cpp
inline bool operator==(
    const Eigen::Vector2i & o
)
```


### function operator<

```cpp
inline bool operator<(
    const GridNode & o
)
```


### function score

```cpp
inline int score()
```


## Public Attributes Documentation

### variable pos

```cpp
Eigen::Vector2i pos;
```


### variable parent

```cpp
Eigen::Vector2i parent;
```


### variable cost

```cpp
int cost;
```


### variable hcost

```cpp
int hcost;
```


-------------------------------

Updated on 2022-09-25 at 23:11:52 +0900