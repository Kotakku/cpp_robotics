---
title: cpp_robotics::KDTree
summary: k-d木 

---

# cpp_robotics::KDTree



k-d木  [More...](#detailed-description)


`#include <kdtree.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using POINT_T | **[point_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#using-point-type)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[KDTree](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#function-kdtree)**() =default |
| | **[KDTree](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#function-kdtree)**(std::vector< [point_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#using-point-type) > point) |
| void | **[clear](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#function-clear)**() |
| void | **[build](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#function-build)**(std::vector< [point_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#using-point-type) > point) |
| size_t | **[nn_search](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#function-nn-search)**(const [point_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#using-point-type) & point) const |
| std::vector< size_t > | **[nn_search](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#function-nn-search)**(const std::vector< [point_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#using-point-type) > & point) const |
| std::vector< size_t > | **[knn_search](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#function-knn-search)**(const [point_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#using-point-type) & point, size_t k) const |
| std::vector< size_t > | **[radius_search](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#function-radius-search)**(const [point_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#using-point-type) & point, double radius) const |
| std::vector< [point_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#using-point-type) > | **[get_points](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#function-get-points)**(const std::vector< size_t > & idx) const |
| std::vector< [point_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#using-point-type) > | **[knn_search_points](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#function-knn-search-points)**(const [point_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#using-point-type) & point, size_t k) const |
| std::vector< [point_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#using-point-type) > | **[radius_search_points](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#function-radius-search-points)**(const [point_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#using-point-type) & point, double radius) const |
| void | **[debug_node](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#function-debug-node)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| constexpr size_t | **[dimention](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KDTree/#variable-dimention)**  |

## Detailed Description

```cpp
template <class POINT_T ,
int DIM>
class cpp_robotics::KDTree;
```

k-d木 

**Template Parameters**: 

  * **POINT_T** データ型 
  * **DIM** 次元サイズ 

## Public Types Documentation

### using point_type

```cpp
using cpp_robotics::KDTree< POINT_T, DIM >::point_type =  POINT_T;
```


## Public Functions Documentation

### function KDTree

```cpp
KDTree() =default
```


### function KDTree

```cpp
inline KDTree(
    std::vector< point_type > point
)
```


### function clear

```cpp
inline void clear()
```


### function build

```cpp
inline void build(
    std::vector< point_type > point
)
```


### function nn_search

```cpp
inline size_t nn_search(
    const point_type & point
) const
```


### function nn_search

```cpp
inline std::vector< size_t > nn_search(
    const std::vector< point_type > & point
) const
```


### function knn_search

```cpp
inline std::vector< size_t > knn_search(
    const point_type & point,
    size_t k
) const
```


### function radius_search

```cpp
inline std::vector< size_t > radius_search(
    const point_type & point,
    double radius
) const
```


### function get_points

```cpp
inline std::vector< point_type > get_points(
    const std::vector< size_t > & idx
) const
```


### function knn_search_points

```cpp
inline std::vector< point_type > knn_search_points(
    const point_type & point,
    size_t k
) const
```


### function radius_search_points

```cpp
inline std::vector< point_type > radius_search_points(
    const point_type & point,
    double radius
) const
```


### function debug_node

```cpp
inline void debug_node()
```


## Public Attributes Documentation

### variable dimention

```cpp
static constexpr size_t dimention = DIM;
```


-------------------------------

Updated on 2022-09-28 at 01:12:56 +0900