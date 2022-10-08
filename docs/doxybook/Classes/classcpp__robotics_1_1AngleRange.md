---
title: cpp_robotics::AngleRange
summary: 角度[rad]に対して範囲を指定する 複数の角度の範囲の合成をしたり逆を取ったりできる 

---

# cpp_robotics::AngleRange



角度[rad]に対して範囲を指定する 複数の角度の範囲の合成をしたり逆を取ったりできる 


`#include <angle_range.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using std::pair< double, double > | **[range_pair_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AngleRange/#using-range-pair-t)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[AngleRange](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AngleRange/#function-anglerange)**() =default |
| void | **[add_range](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AngleRange/#function-add-range)**(const [AngleRange](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AngleRange/) & range) |
| void | **[add_range](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AngleRange/#function-add-range)**(double start, double end) |
| size_t | **[size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AngleRange/#function-size)**() const |
| [AngleRange](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AngleRange/) | **[invert](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AngleRange/#function-invert)**() const |
| double | **[most_near_by](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AngleRange/#function-most-near-by)**(double angle) |
| bool | **[in_range_part](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AngleRange/#function-in-range-part)**([range_pair_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AngleRange/#using-range-pair-t) & range, double angle) |
| bool | **[in_range](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AngleRange/#function-in-range)**(double angle) |
| std::vector< [range_pair_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AngleRange/#using-range-pair-t) > | **[ranges](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AngleRange/#function-ranges)**() const |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| constexpr static double | **[PI](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AngleRange/#variable-pi)**  |

## Public Types Documentation

### using range_pair_t

```cpp
using cpp_robotics::AngleRange::range_pair_t =  std::pair<double, double>;
```


## Public Functions Documentation

### function AngleRange

```cpp
AngleRange() =default
```


### function add_range

```cpp
inline void add_range(
    const AngleRange & range
)
```


### function add_range

```cpp
inline void add_range(
    double start,
    double end
)
```


### function size

```cpp
inline size_t size() const
```


### function invert

```cpp
inline AngleRange invert() const
```


### function most_near_by

```cpp
inline double most_near_by(
    double angle
)
```


### function in_range_part

```cpp
inline bool in_range_part(
    range_pair_t & range,
    double angle
)
```


### function in_range

```cpp
inline bool in_range(
    double angle
)
```


### function ranges

```cpp
inline std::vector< range_pair_t > ranges() const
```


## Public Attributes Documentation

### variable PI

```cpp
static constexpr static double PI = M_PI;
```


-------------------------------

Updated on 2022-10-08 at 23:36:07 +0900