---
title: cpp_robotics::unit::unit_assem::unit_div

---

# cpp_robotics::unit::unit_assem::unit_div



 [More...](#detailed-description)


`#include <unit_core.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using typename [unit_dim_assem::udim_div](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1unit__dim__assem_1_1udim__div/)< typename Unit1::unit_dimention_type, typename Unit2::unit_dimention_type >::[unit](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1unit__assem_1_1unit__div/#using-unit) | **[dim](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1unit__assem_1_1unit__div/#using-dim)**  |
| using typename [prefix::pfx_div](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1prefix_1_1pfx__div/)< typename Unit1::prefix_type, typename Unit2::prefix_type >::prefix | **[pfx](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1unit__assem_1_1unit__div/#using-pfx)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< typename Unit1::value_type, [dim](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1unit__assem_1_1unit__div/#using-dim), [pfx](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1unit__assem_1_1unit__div/#using-pfx) > | **[unit](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1unit__assem_1_1unit__div/#using-unit)**  |

## Detailed Description

```cpp
template <class Unit1 ,
class Unit2 >
struct cpp_robotics::unit::unit_assem::unit_div;
```

## Public Types Documentation

### using dim

```cpp
using cpp_robotics::unit::unit_assem::unit_div< Unit1, Unit2 >::dim =  typename unit_dim_assem::udim_div<typename Unit1::unit_dimention_type, typename Unit2::unit_dimention_type>::unit;
```


### using pfx

```cpp
using cpp_robotics::unit::unit_assem::unit_div< Unit1, Unit2 >::pfx =  typename prefix::pfx_div<typename Unit1::prefix_type, typename Unit2::prefix_type>::prefix;
```


### using unit

```cpp
using cpp_robotics::unit::unit_assem::unit_div< Unit1, Unit2 >::unit =  Unit<typename Unit1::value_type, dim, pfx>;
```


-------------------------------

Updated on 2022-09-25 at 23:20:38 +0900