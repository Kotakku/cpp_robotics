---
title: cpp_robotics::grid_path_planning_utils
summary: グリッドパスプランニング用関数・クラス郡 

---

# cpp_robotics::grid_path_planning_utils

グリッドパスプランニング用関数・クラス郡 

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[cpp_robotics::grid_path_planning_utils::GridNode](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1grid__path__planning__utils_1_1GridNode/)**  |

## Functions

|                | Name           |
| -------------- | -------------- |
| bool | **[contain_in_map](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1grid__path__planning__utils/#function-contain-in-map)**(const Eigen::MatrixXi & map, const Eigen::Vector2i & p) |
| int | **[dist](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1grid__path__planning__utils/#function-dist)**(const Eigen::Vector2i & pos, const Eigen::Vector2i & end) |
| template <typename T \> <br>bool | **[in_range_open](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1grid__path__planning__utils/#function-in-range-open)**(T x, T min, T max) |
| bool | **[is_valid](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1grid__path__planning__utils/#function-is-valid)**(const Eigen::Vector2i & pos, size_t row, size_t col) |
| bool | **[is_wall](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1grid__path__planning__utils/#function-is-wall)**(const Eigen::Vector2i & pos, size_t row, size_t col) |
| bool | **[is_correct_step](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1grid__path__planning__utils/#function-is-correct-step)**(const Eigen::Vector2i & pos, const Eigen::MatrixXi & map) |
| bool | **[exist](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1grid__path__planning__utils/#function-exist)**(std::list< [GridNode](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1grid__path__planning__utils_1_1GridNode/) > & open, std::list< [GridNode](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1grid__path__planning__utils_1_1GridNode/) > & closed, const Eigen::Vector2i & p, int cost) |


## Functions Documentation

### function contain_in_map

```cpp
static bool contain_in_map(
    const Eigen::MatrixXi & map,
    const Eigen::Vector2i & p
)
```


### function dist

```cpp
static int dist(
    const Eigen::Vector2i & pos,
    const Eigen::Vector2i & end
)
```


### function in_range_open

```cpp
template <typename T >
bool in_range_open(
    T x,
    T min,
    T max
)
```


### function is_valid

```cpp
bool is_valid(
    const Eigen::Vector2i & pos,
    size_t row,
    size_t col
)
```


### function is_wall

```cpp
bool is_wall(
    const Eigen::Vector2i & pos,
    size_t row,
    size_t col
)
```


### function is_correct_step

```cpp
bool is_correct_step(
    const Eigen::Vector2i & pos,
    const Eigen::MatrixXi & map
)
```


### function exist

```cpp
bool exist(
    std::list< GridNode > & open,
    std::list< GridNode > & closed,
    const Eigen::Vector2i & p,
    int cost
)
```






-------------------------------

Updated on 2022-10-06 at 00:27:03 +0900