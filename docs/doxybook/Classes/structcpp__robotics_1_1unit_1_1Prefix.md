---
title: cpp_robotics::unit::Prefix

---

# cpp_robotics::unit::Prefix



 [More...](#detailed-description)


`#include <unit_core.hpp>`

Inherits from [cpp_robotics::unit::PrefixBase](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1PrefixBase/)

## Public Types

|                | Name           |
| -------------- | -------------- |
| using [Prefix](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/)< N, D > | **[type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/#using-type)**  |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| constexpr uint32_t | **[num](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/#variable-num)**  |
| constexpr uint32_t | **[den](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/#variable-den)**  |

## Additional inherited members

**Public Functions inherited from [cpp_robotics::unit::PrefixBase](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1PrefixBase/)**

|                | Name           |
| -------------- | -------------- |
| | **[PrefixBase](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1PrefixBase/#function-prefixbase)**() =delete |


## Detailed Description

```cpp
template <uint32_t N,
uint32_t D>
struct cpp_robotics::unit::Prefix;
```

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

Updated on 2022-09-25 at 23:20:38 +0900