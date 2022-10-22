---
title: cpp_robotics::Vector4
summary: 4次元のベクトル 

---

# cpp_robotics::Vector4



4次元のベクトル  [More...](#detailed-description)


`#include <vector4.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using FLOATING_TYPE | **[value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-vector4)**() =default<br>Construct a new Vector 4 object.  |
| constexpr | **[Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-vector4)**([value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) vx, [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) vy, [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) vz, [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) vw)<br>Construct a new Vector 4 object.  |
| | **[Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-vector4)**(const [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & v) =default<br>Construct a new Vector 4 object.  |
| void | **[set](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-set)**([value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) vx, [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) vy, [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) vz, [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) vw) |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) | **[dot](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-dot)**(const [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & v) const |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) | **[norm_sq](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-norm-sq)**() const |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) | **[norm](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-norm)**()<br>Get the Magnitude object.  |
| void | **[normalize](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-normalize)**()<br>単位ベクトル化  |
| [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) | **[get_normalized](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-get-normalized)**()<br>Get the Normalized object.  |
| constexpr bool | **[is_zero](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-is-zero)**() const |
| constexpr bool | **[has_nan](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-has-nan)**() const |
| constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) | **[lerp](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-lerp)**(const [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & b, const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) t) const |
| constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) | **[operator+](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-operator+)**() const |
| constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) | **[operator-](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-operator-)**() const |
| bool | **[operator==](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-operator==)**(const [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & v) const |
| bool | **[operator!=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-operator!=)**(const [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & v) const |
| constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) | **[operator+](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-operator+)**(const [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & v) const |
| constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) | **[operator-](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-operator-)**(const [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & v) const |
| constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) | **[operator*](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-operator*)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) value) const |
| constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) | **[operator/](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-operator/)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) value) const |
| constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & | **[operator+=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-operator+=)**(const [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & v) |
| constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & | **[operator-=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-operator-=)**(const [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & v) |
| constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & | **[operator*=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-operator*=)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) value) |
| constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & | **[operator/=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-operator/=)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) value) |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) & | **[operator[]](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-operator[])**(const int index) |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) | **[operator[]](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-operator[])**(const int index) const |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) | **[dot](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-dot)**(const [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & a, const [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & b) |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) | **[distance](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-distance)**(const [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & a, const [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & b) |
| constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) | **[lerp](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-lerp)**(const [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & a, const [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) & b, const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) t) |
| constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) | **[zero](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#function-zero)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) | **[x](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#variable-x)**  |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) | **[y](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#variable-y)**  |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) | **[z](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#variable-z)**  |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#using-value-type) | **[w](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#variable-w)**  |

## Friends

|                | Name           |
| -------------- | -------------- |
| constexpr friend [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) | **[operator*](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/#friend-operator*)**(Scaler s, [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/) v)  |

## Detailed Description

```cpp
template <typename FLOATING_TYPE >
struct cpp_robotics::Vector4;
```

4次元のベクトル 
## Public Types Documentation

### using value_type

```cpp
using cpp_robotics::Vector4< FLOATING_TYPE >::value_type =  FLOATING_TYPE;
```


## Public Functions Documentation

### function Vector4

```cpp
Vector4() =default
```

Construct a new Vector 4 object. 

### function Vector4

```cpp
inline constexpr Vector4(
    value_type vx,
    value_type vy,
    value_type vz,
    value_type vw
)
```

Construct a new Vector 4 object. 

**Parameters**: 

  * **vx** 
  * **vy** 
  * **vz** 
  * **vw** 


### function Vector4

```cpp
Vector4(
    const Vector4 & v
) =default
```

Construct a new Vector 4 object. 

**Parameters**: 

  * **v** 


### function set

```cpp
inline void set(
    value_type vx,
    value_type vy,
    value_type vz,
    value_type vw
)
```


**Parameters**: 

  * **vx** 
  * **vy** 
  * **vz** 
  * **vw** 


### function dot

```cpp
inline constexpr value_type dot(
    const Vector4 & v
) const
```


**Parameters**: 

  * **v** 


**Return**: constexpr value_type 

### function norm_sq

```cpp
inline constexpr value_type norm_sq() const
```


**Return**: constexpr value_type 

### function norm

```cpp
inline value_type norm()
```

Get the Magnitude object. 

**Return**: value_type 

### function normalize

```cpp
inline void normalize()
```

単位ベクトル化 

### function get_normalized

```cpp
inline Vector4 get_normalized()
```

Get the Normalized object. 

**Return**: [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)

### function is_zero

```cpp
inline constexpr bool is_zero() const
```


**Return**: 

  * true 
  * false 


### function has_nan

```cpp
inline constexpr bool has_nan() const
```


**Return**: 

  * true 
  * false 


### function lerp

```cpp
inline constexpr Vector4 lerp(
    const Vector4 & b,
    const value_type t
) const
```


**Parameters**: 

  * **b** 
  * **t** 


**Return**: constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)

### function operator+

```cpp
inline constexpr Vector4 operator+() const
```


**Return**: constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)

### function operator-

```cpp
inline constexpr Vector4 operator-() const
```


**Return**: constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)

### function operator==

```cpp
inline bool operator==(
    const Vector4 & v
) const
```


**Parameters**: 

  * **v** 


**Return**: 

  * true 
  * false 


### function operator!=

```cpp
inline bool operator!=(
    const Vector4 & v
) const
```


**Parameters**: 

  * **v** 


**Return**: 

  * true 
  * false 


### function operator+

```cpp
inline constexpr Vector4 operator+(
    const Vector4 & v
) const
```


**Parameters**: 

  * **v** 


**Return**: [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)

### function operator-

```cpp
inline constexpr Vector4 operator-(
    const Vector4 & v
) const
```


**Parameters**: 

  * **v** 


**Return**: [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)

### function operator*

```cpp
inline constexpr Vector4 operator*(
    const value_type value
) const
```


**Parameters**: 

  * **value** 


**Return**: [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)

### function operator/

```cpp
inline constexpr Vector4 operator/(
    const value_type value
) const
```


**Parameters**: 

  * **value** 


**Return**: [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)

### function operator+=

```cpp
inline constexpr Vector4 & operator+=(
    const Vector4 & v
)
```


**Parameters**: 

  * **v** 


**Return**: [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)& 

### function operator-=

```cpp
inline constexpr Vector4 & operator-=(
    const Vector4 & v
)
```


**Parameters**: 

  * **v** 


**Return**: [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)& 

### function operator*=

```cpp
inline constexpr Vector4 & operator*=(
    const value_type value
)
```


**Parameters**: 

  * **value** 


**Return**: [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)& 

### function operator/=

```cpp
inline constexpr Vector4 & operator/=(
    const value_type value
)
```


**Parameters**: 

  * **value** 


**Return**: [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)& 

### function operator[]

```cpp
inline value_type & operator[](
    const int index
)
```


**Parameters**: 

  * **index** 


**Return**: value_type& 

### function operator[]

```cpp
inline constexpr value_type operator[](
    const int index
) const
```


**Parameters**: 

  * **index** 


**Return**: constexpr value_type 

### function dot

```cpp
static inline constexpr value_type dot(
    const Vector4 & a,
    const Vector4 & b
)
```


**Parameters**: 

  * **a** 
  * **b** 


**Return**: constexpr value_type 

### function distance

```cpp
static inline value_type distance(
    const Vector4 & a,
    const Vector4 & b
)
```


**Parameters**: 

  * **a** 
  * **b** 


**Return**: value_type 

### function lerp

```cpp
static inline constexpr Vector4 lerp(
    const Vector4 & a,
    const Vector4 & b,
    const value_type t
)
```


**Parameters**: 

  * **a** 
  * **b** 
  * **t** 


**Return**: constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)

### function zero

```cpp
static inline constexpr Vector4 zero()
```


**Return**: [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)

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


## Friends

### friend operator*

```cpp
friend constexpr friend Vector4 operator*(
    Scaler s,

    Vector4 v
);
```


**Parameters**: 

  * **s** 
  * **v** 


**Template Parameters**: 

  * **Scaler** 


**Return**: constexpr [Vector4](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector4/)

-------------------------------

Updated on 2022-10-22 at 22:05:50 +0900