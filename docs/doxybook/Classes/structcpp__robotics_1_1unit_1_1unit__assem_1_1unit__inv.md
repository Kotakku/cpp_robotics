---
title: cpp_robotics::unit::unit_assem::unit_inv

---

# cpp_robotics::unit::unit_assem::unit_inv



 [More...](#detailed-description)


`#include <unit_core.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using typename [unit_dim_assem::udim_inv](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1unit__dim__assem_1_1udim__inv/)< typename UnitType::unit_dimention_type >::[unit](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1unit__assem_1_1unit__inv/#using-unit) | **[dim](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1unit__assem_1_1unit__inv/#using-dim)**  |
| using typename [prefix::pfx_inv](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1prefix_1_1pfx__inv/)< typename UnitType::prefix_type >::prefix | **[pfx](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1unit__assem_1_1unit__inv/#using-pfx)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< typename UnitType::value_type, [dim](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1unit__assem_1_1unit__inv/#using-dim), [pfx](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1unit__assem_1_1unit__inv/#using-pfx), 0 > | **[unit](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1unit__assem_1_1unit__inv/#using-unit)**  |

## Detailed Description

```cpp
template <class UnitType >
struct cpp_robotics::unit::unit_assem::unit_inv;
```

## Public Types Documentation

### using dim

```cpp
using cpp_robotics::unit::unit_assem::unit_inv< UnitType >::dim =  typename unit_dim_assem::udim_inv<typename UnitType::unit_dimention_type>::unit;
```


### using pfx

```cpp
using cpp_robotics::unit::unit_assem::unit_inv< UnitType >::pfx =  typename prefix::pfx_inv<typename UnitType::prefix_type>::prefix;
```


### using unit

```cpp
using cpp_robotics::unit::unit_assem::unit_inv< UnitType >::unit =  Unit<typename UnitType::value_type, dim, pfx, 0>;
```


-------------------------------

Updated on 2022-09-25 at 23:20:38 +0900