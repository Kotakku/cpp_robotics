---
title: cpp_robotics::unit::unit_assem::unit_pfx_scaled

---

# cpp_robotics::unit::unit_assem::unit_pfx_scaled



 [More...](#detailed-description)


`#include <unit_core.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< typename UnitType::value_type, typename UnitType::unit_dimention_type, typename [prefix::pfx_mul](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1prefix_1_1pfx__mul/)< typename UnitType::prefix_type, PrefixType >::prefix, UnitType::tag > | **[unit](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1unit__assem_1_1unit__pfx__scaled/#using-unit)**  |

## Detailed Description

```cpp
template <class UnitType ,
class PrefixType >
struct cpp_robotics::unit::unit_assem::unit_pfx_scaled;
```

## Public Types Documentation

### using unit

```cpp
using cpp_robotics::unit::unit_assem::unit_pfx_scaled< UnitType, PrefixType >::unit =  Unit<typename UnitType::value_type, typename UnitType::unit_dimention_type, typename prefix::pfx_mul<typename UnitType::prefix_type, PrefixType>::prefix, UnitType::tag>;
```


-------------------------------

Updated on 2022-09-25 at 23:29:49 +0900