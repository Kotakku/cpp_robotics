---
title: cpp_robotics::Quaternion
summary: クォータニオンクラス 

---

# cpp_robotics::Quaternion



クォータニオンクラス  [More...](#detailed-description)


`#include <quaternion.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using FLOATING_TYPE | **[value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#using-value-type)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| constexpr | **[Quaternion](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#function-quaternion)**() |
| constexpr | **[Quaternion](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#function-quaternion)**([value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#using-value-type) nx, [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#using-value-type) ny, [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#using-value-type) nz, [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#using-value-type) nw) |
| [Quaternion](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/) | **[get_product](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#function-get-product)**([Quaternion](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/) q) |
| constexpr [Quaternion](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/) | **[conjugate](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#function-conjugate)**() const |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#using-value-type) | **[norm](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#function-norm)**() const |
| constexpr void | **[normalize](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#function-normalize)**() |
| constexpr [Quaternion](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/) | **[get_normalized](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#function-get-normalized)**() const |
| constexpr void | **[set_rpy](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#function-set-rpy)**([value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#using-value-type) roll, [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#using-value-type) pitch, [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#using-value-type) yaw) |
| constexpr [Vector3d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector3d) | **[get_rpy](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#function-get-rpy)**() const |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#using-value-type) | **[operator[]](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#function-operator[])**(const int index) const |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#using-value-type) | **[x](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#variable-x)**  |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#using-value-type) | **[y](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#variable-y)**  |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#using-value-type) | **[z](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#variable-z)**  |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#using-value-type) | **[w](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Quaternion/#variable-w)**  |

## Detailed Description

```cpp
template <typename FLOATING_TYPE >
class cpp_robotics::Quaternion;
```

クォータニオンクラス 

**Template Parameters**: 

  * **FLOATING_TYPE** 

## Public Types Documentation

### using value_type

```cpp
using cpp_robotics::Quaternion< FLOATING_TYPE >::value_type =  FLOATING_TYPE;
```


## Public Functions Documentation

### function Quaternion

```cpp
inline constexpr Quaternion()
```


### function Quaternion

```cpp
inline constexpr Quaternion(
    value_type nx,
    value_type ny,
    value_type nz,
    value_type nw
)
```


### function get_product

```cpp
inline Quaternion get_product(
    Quaternion q
)
```


### function conjugate

```cpp
inline constexpr Quaternion conjugate() const
```


### function norm

```cpp
inline constexpr value_type norm() const
```


### function normalize

```cpp
inline constexpr void normalize()
```


### function get_normalized

```cpp
inline constexpr Quaternion get_normalized() const
```


### function set_rpy

```cpp
inline constexpr void set_rpy(
    value_type roll,
    value_type pitch,
    value_type yaw
)
```


### function get_rpy

```cpp
inline constexpr Vector3d get_rpy() const
```


### function operator[]

```cpp
inline constexpr value_type operator[](
    const int index
) const
```


**Parameters**: 

  * **index** 


**Return**: constexpr value_type 

## Public Attributes Documentation

### variable x

```cpp
value_type x;
```


### variable y

```cpp
value_type y;
```


### variable z

```cpp
value_type z;
```


### variable w

```cpp
value_type w;
```


-------------------------------

Updated on 2022-10-05 at 16:05:00 +0900