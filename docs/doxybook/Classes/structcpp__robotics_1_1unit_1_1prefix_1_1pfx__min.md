---
title: cpp_robotics::unit::prefix::pfx_min

---

# cpp_robotics::unit::prefix::pfx_min



 [More...](#detailed-description)


`#include <unit_core.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using [Prefix](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/)< [raw_num](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1prefix_1_1pfx__min/#variable-raw-num), [raw_den](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1prefix_1_1pfx__min/#variable-raw-den) > | **[prefix](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1prefix_1_1pfx__min/#using-prefix)**  |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| constexpr uint32_t | **[raw_num](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1prefix_1_1pfx__min/#variable-raw-num)**  |
| constexpr uint32_t | **[raw_den](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1prefix_1_1pfx__min/#variable-raw-den)**  |

## Detailed Description

```cpp
template <class P1 ,
class P2 >
struct cpp_robotics::unit::prefix::pfx_min;
```

## Public Types Documentation

### using prefix

```cpp
using cpp_robotics::unit::prefix::pfx_min< P1, P2 >::prefix =  Prefix<raw_num, raw_den>;
```


## Public Attributes Documentation

### variable raw_num

```cpp
static constexpr uint32_t raw_num = std::min(P1::num * P2::den, P2::num * P1::den);
```


### variable raw_den

```cpp
static constexpr uint32_t raw_den = P1::den * P2::den;
```


-------------------------------

Updated on 2022-09-25 at 23:50:01 +0900