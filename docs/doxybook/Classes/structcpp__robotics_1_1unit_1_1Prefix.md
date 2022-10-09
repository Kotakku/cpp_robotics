---
title: cpp_robotics::unit::Prefix
summary: 単位系接頭辞クラス 

---

# cpp_robotics::unit::Prefix



単位系接頭辞クラス  [More...](#detailed-description)


`#include <unit_core.hpp>`

Inherits from PrefixBase

## Public Types

|                | Name           |
| -------------- | -------------- |
| using [Prefix](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/)< N, D > | **[type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/#using-type)**  |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| constexpr uint32_t | **[num](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/#variable-num)**  |
| constexpr uint32_t | **[den](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/#variable-den)**  |

## Detailed Description

```cpp
template <uint32_t N,
uint32_t D>
struct cpp_robotics::unit::Prefix;
```

単位系接頭辞クラス 

**Template Parameters**: 

  * **N** 
  * **D** 

## Public Types Documentation

### using type

```cpp
using cpp_robotics::unit::Prefix< N, D >::type =  Prefix<N, D>;
```


## Public Attributes Documentation

### variable num

```cpp
static constexpr uint32_t num = N / std::gcd(N, D);
```


### variable den

```cpp
static constexpr uint32_t den = D / std::gcd(N, D);
```


-------------------------------

Updated on 2022-10-10 at 00:51:40 +0900