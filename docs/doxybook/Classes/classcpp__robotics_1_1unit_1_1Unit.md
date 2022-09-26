---
title: cpp_robotics::unit::Unit
summary: 単位クラス 

---

# cpp_robotics::unit::Unit



単位クラス  [More...](#detailed-description)


`#include <unit_core.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using T | **[value_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-value-type)**  |
| using UnitDimType | **[unit_dimention_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-unit-dimention-type)**  |
| using P | **[prefix_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-prefix-type)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T, UnitDimType, P > | **[unit_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-unit-type)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#function-unit)**() =default |
| constexpr | **[Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#function-unit)**(T val) |
| constexpr T | **[value](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#function-value)**() const |
| constexpr T | **[raw_value](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#function-raw-value)**() const |
| constexpr [unit_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-unit-type) | **[operator+](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#function-operator+)**() const |
| constexpr [unit_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-unit-type) | **[operator-](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#function-operator-)**() const |
| constexpr [unit_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-unit-type) | **[operator+](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#function-operator+)**(const [unit_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-unit-type) & rhl) const |
| constexpr [unit_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-unit-type) | **[operator-](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#function-operator-)**(const [unit_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-unit-type) & rhl) const |
| constexpr auto | **[operator*](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#function-operator*)**(const [unit_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-unit-type) & rhl) const |
| constexpr [unit_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-unit-type) & | **[operator+=](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#function-operator+=)**(const [unit_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-unit-type) & rhl) |
| constexpr [unit_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-unit-type) & | **[operator-=](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#function-operator-=)**(const [unit_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-unit-type) & rhl) |
| template <int R_Tag\> <br>constexpr | **[operator Unit< value_type, unit_dimention_type, prefix_type, R_Tag >](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#function-operator-unit<-value-type,-unit-dimention-type,-prefix-type,-r-tag->)**() const |
| template <class R_P \> <br>constexpr | **[operator Unit< value_type, unit_dimention_type, R_P, tag >](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#function-operator-unit<-value-type,-unit-dimention-type,-r-p,-tag->)**() const |
| constexpr | **[operator value_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#function-operator-value-type)**() const |
| constexpr bool | **[operator==](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#function-operator==)**(const [unit_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-unit-type) & r_value) |
| constexpr bool | **[operator!=](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#function-operator!=)**(const [unit_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#using-unit-type) & r_value) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| constexpr int | **[tag](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/#variable-tag)**  |

## Detailed Description

```cpp
template <class T ,
class UnitDimType ,
class P ,
int Tag =-1>
class cpp_robotics::unit::Unit;
```

単位クラス 

**Template Parameters**: 

  * **T** 浮動小数点数型 
  * **UnitDimType** 次元 
  * **P** 接頭辞 
  * **Tag** 同次元の単位系を区別するタグ 

## Public Types Documentation

### using value_type

```cpp
using cpp_robotics::unit::Unit< T, UnitDimType, P, Tag >::value_type =  T;
```


### using unit_dimention_type

```cpp
using cpp_robotics::unit::Unit< T, UnitDimType, P, Tag >::unit_dimention_type =  UnitDimType;
```


### using prefix_type

```cpp
using cpp_robotics::unit::Unit< T, UnitDimType, P, Tag >::prefix_type =  P;
```


### using unit_type

```cpp
using cpp_robotics::unit::Unit< T, UnitDimType, P, Tag >::unit_type =  Unit<T, UnitDimType, P>;
```


## Public Functions Documentation

### function Unit

```cpp
Unit() =default
```


### function Unit

```cpp
inline constexpr Unit(
    T val
)
```


### function value

```cpp
inline constexpr T value() const
```


### function raw_value

```cpp
inline constexpr T raw_value() const
```


### function operator+

```cpp
inline constexpr unit_type operator+() const
```


### function operator-

```cpp
inline constexpr unit_type operator-() const
```


### function operator+

```cpp
inline constexpr unit_type operator+(
    const unit_type & rhl
) const
```


### function operator-

```cpp
inline constexpr unit_type operator-(
    const unit_type & rhl
) const
```


### function operator*

```cpp
inline constexpr auto operator*(
    const unit_type & rhl
) const
```


### function operator+=

```cpp
inline constexpr unit_type & operator+=(
    const unit_type & rhl
)
```


### function operator-=

```cpp
inline constexpr unit_type & operator-=(
    const unit_type & rhl
)
```


### function operator Unit< value_type, unit_dimention_type, prefix_type, R_Tag >

```cpp
template <int R_Tag>
inline constexpr operator Unit< value_type, unit_dimention_type, prefix_type, R_Tag >() const
```


### function operator Unit< value_type, unit_dimention_type, R_P, tag >

```cpp
template <class R_P >
inline constexpr operator Unit< value_type, unit_dimention_type, R_P, tag >() const
```


### function operator value_type

```cpp
inline constexpr operator value_type() const
```


### function operator==

```cpp
inline constexpr bool operator==(
    const unit_type & r_value
)
```


### function operator!=

```cpp
inline constexpr bool operator!=(
    const unit_type & r_value
)
```


## Public Attributes Documentation

### variable tag

```cpp
static constexpr int tag = Tag;
```


-------------------------------

Updated on 2022-09-27 at 01:12:56 +0900