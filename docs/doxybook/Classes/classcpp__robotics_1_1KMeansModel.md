---
title: cpp_robotics::KMeansModel
summary: K-means法 

---

# cpp_robotics::KMeansModel



K-means法  [More...](#detailed-description)


`#include <k_means_method.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using PointType | **[point_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KMeansModel/#using-point-t)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[KMeansModel](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KMeansModel/#function-kmeansmodel)**() =default |
| std::vector< size_t > | **[fit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KMeansModel/#function-fit)**(std::vector< [point_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KMeansModel/#using-point-t) > & data_set, size_t cluster_size, size_t max_iter =1000)<br>データセットを与えてクラスタを生成する  |
| size_t | **[predict](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KMeansModel/#function-predict)**(const [point_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KMeansModel/#using-point-t) & x)<br>点をクラスタリングする  |

## Detailed Description

```cpp
template <class PointType >
class cpp_robotics::KMeansModel;
```

K-means法 

**Template Parameters**: 

  * **PointType** データ型 

## Public Types Documentation

### using point_t

```cpp
using cpp_robotics::KMeansModel< PointType >::point_t =  PointType;
```


## Public Functions Documentation

### function KMeansModel

```cpp
KMeansModel() =default
```


### function fit

```cpp
inline std::vector< size_t > fit(
    std::vector< point_t > & data_set,
    size_t cluster_size,
    size_t max_iter =1000
)
```

データセットを与えてクラスタを生成する 

**Parameters**: 

  * **data_set** 点群 
  * **cluster_size** 生成するクラスタのサイズ 
  * **max_iter** 最大反復回数 


**Return**: std::vector<size_t> data_setのクラスタリング結果 

### function predict

```cpp
inline size_t predict(
    const point_t & x
)
```

点をクラスタリングする 

**Parameters**: 

  * **x** 点 


**Return**: size_t クラスタリング結果 

-------------------------------

Updated on 2022-09-28 at 23:12:43 +0900