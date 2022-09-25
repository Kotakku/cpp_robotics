---
title: cpp_robotics::Vector3
summary: 3次元のベクトル 

---

# cpp_robotics::Vector3



3次元のベクトル  [More...](#detailed-description)


`#include <vector3.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using FLOATING_TYPE | **[value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-vector3)**() =default<br>Construct a new Vector 3 object.  |
| constexpr | **[Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-vector3)**([value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) vx, [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) vy, [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) vz)<br>Construct a new Vector 3 object.  |
| | **[Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-vector3)**(const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & v) =default<br>Construct a new Vector 3 object.  |
| void | **[set](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-set)**([value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) vx, [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) vy, [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) vz) |
| constexpr [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) | **[dot](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-dot)**(const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & v) const |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[cross](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-cross)**(const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & v) const |
| constexpr [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) | **[norm_sq](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-norm-sq)**() const |
| [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) | **[norm](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-norm)**()<br>Get the Magnitude object.  |
| void | **[normalize](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-normalize)**()<br>単位ベクトル化  |
| [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[get_normalized](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-get-normalized)**()<br>Get the Normalized object.  |
| constexpr bool | **[is_zero](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-is-zero)**() const |
| constexpr bool | **[has_nan](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-has-nan)**() const |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[lerp](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-lerp)**(const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & b, const [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) t) const |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[operator+](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-operator+)**() const |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[operator-](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-operator-)**() const |
| bool | **[operator==](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-operator==)**(const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & v) const |
| bool | **[operator!=](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-operator!=)**(const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & v) const |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[operator+](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-operator+)**(const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & v) const |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[operator-](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-operator-)**(const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & v) const |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & | **[operator+=](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-operator+=)**(const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & v) |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & | **[operator-=](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-operator-=)**(const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & v) |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & | **[operator*=](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-operator*=)**(const [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) value) |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & | **[operator/=](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-operator/=)**(const [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) value) |
| [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) & | **[operator[]](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-operator[])**(const int index) |
| constexpr [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) | **[operator[]](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-operator[])**(const int index) const |
| constexpr [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) | **[dot](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-dot)**(const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & a, const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & b) |
| [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) | **[distance](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-distance)**(const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & a, const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & b) |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[lerp](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-lerp)**(const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & a, const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & b, const [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) t) |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[zero](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-zero)**() |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[forward](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-forward)**() |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[back](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-back)**() |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[up](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-up)**() |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[down](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-down)**() |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[right](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-right)**() |
| constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[left](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#function-left)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) | **[x](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#variable-x)**  |
| [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) | **[y](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#variable-y)**  |
| [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) | **[z](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#variable-z)**  |

## Friends

|                | Name           |
| -------------- | -------------- |
| constexpr friend [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[operator/](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#friend-operator/)**(const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & v, const [value_type](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#using-value-type) value)  |
| constexpr friend [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[operator*](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#friend-operator*)**(const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & v, const Scaler s)  |
| constexpr friend [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) | **[operator*](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/#friend-operator*)**(const Scaler s, const [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/) & v)  |

## Detailed Description

```cpp
template <typename FLOATING_TYPE >
struct cpp_robotics::Vector3;
```

3次元のベクトル 
## Public Types Documentation

### using value_type

```cpp
using cpp_robotics::Vector3< FLOATING_TYPE >::value_type =  FLOATING_TYPE;
```


## Public Functions Documentation

### function Vector3

```cpp
Vector3() =default
```

Construct a new Vector 3 object. 

### function Vector3

```cpp
inline constexpr Vector3(
    value_type vx,
    value_type vy,
    value_type vz
)
```

Construct a new Vector 3 object. 

**Parameters**: 

  * **vx** 
  * **vy** 
  * **vz** 


### function Vector3

```cpp
Vector3(
    const Vector3 & v
) =default
```

Construct a new Vector 3 object. 

**Parameters**: 

  * **v** 


### function set

```cpp
inline void set(
    value_type vx,
    value_type vy,
    value_type vz
)
```


**Parameters**: 

  * **vx** 
  * **vy** 
  * **vz** 


### function dot

```cpp
inline constexpr value_type dot(
    const Vector3 & v
) const
```


**Parameters**: 

  * **v** 


**Return**: constexpr value_type 

### function cross

```cpp
inline constexpr Vector3 cross(
    const Vector3 & v
) const
```


**Parameters**: 

  * **v** 


**Return**: constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

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
inline Vector3 get_normalized()
```

Get the Normalized object. 

**Return**: [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

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
inline constexpr Vector3 lerp(
    const Vector3 & b,
    const value_type t
) const
```


**Parameters**: 

  * **b** 
  * **t** 


**Return**: constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

### function operator+

```cpp
inline constexpr Vector3 operator+() const
```


**Return**: constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

### function operator-

```cpp
inline constexpr Vector3 operator-() const
```


**Return**: constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

### function operator==

```cpp
inline bool operator==(
    const Vector3 & v
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
    const Vector3 & v
) const
```


**Parameters**: 

  * **v** 


**Return**: 

  * true 
  * false 


### function operator+

```cpp
inline constexpr Vector3 operator+(
    const Vector3 & v
) const
```


**Parameters**: 

  * **v** 


**Return**: [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

### function operator-

```cpp
inline constexpr Vector3 operator-(
    const Vector3 & v
) const
```


**Parameters**: 

  * **v** 


**Return**: [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

### function operator+=

```cpp
inline constexpr Vector3 & operator+=(
    const Vector3 & v
)
```


**Parameters**: 

  * **v** 


**Return**: [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)& 

### function operator-=

```cpp
inline constexpr Vector3 & operator-=(
    const Vector3 & v
)
```


**Parameters**: 

  * **v** 


**Return**: [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)& 

### function operator*=

```cpp
inline constexpr Vector3 & operator*=(
    const value_type value
)
```


**Parameters**: 

  * **value** 


**Return**: [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)& 

### function operator/=

```cpp
inline constexpr Vector3 & operator/=(
    const value_type value
)
```


**Parameters**: 

  * **value** 


**Return**: [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)& 

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
    const Vector3 & a,
    const Vector3 & b
)
```


**Parameters**: 

  * **a** 
  * **b** 


**Return**: constexpr value_type 

### function distance

```cpp
static inline value_type distance(
    const Vector3 & a,
    const Vector3 & b
)
```


**Parameters**: 

  * **a** 
  * **b** 


**Return**: value_type 

### function lerp

```cpp
static inline constexpr Vector3 lerp(
    const Vector3 & a,
    const Vector3 & b,
    const value_type t
)
```


**Parameters**: 

  * **a** 
  * **b** 
  * **t** 


**Return**: constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

### function zero

```cpp
static inline constexpr Vector3 zero()
```


**Return**: [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

### function forward

```cpp
static inline constexpr Vector3 forward()
```


**Return**: [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

### function back

```cpp
static inline constexpr Vector3 back()
```


**Return**: [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

### function up

```cpp
static inline constexpr Vector3 up()
```


**Return**: [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

### function down

```cpp
static inline constexpr Vector3 down()
```


**Return**: [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

### function right

```cpp
static inline constexpr Vector3 right()
```


**Return**: [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

### function left

```cpp
static inline constexpr Vector3 left()
```


**Return**: [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

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


## Friends

### friend operator/

```cpp
friend constexpr friend Vector3 operator/(
    const Vector3 & v,

    const value_type value
);
```


**Parameters**: 

  * **value** 


**Return**: [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

### friend operator*

```cpp
friend constexpr friend Vector3 operator*(
    const Vector3 & v,

    const Scaler s
);
```


**Parameters**: 

  * **v** 
  * **s** 


**Template Parameters**: 

  * **Scaler** 


**Return**: constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

### friend operator*

```cpp
friend constexpr friend Vector3 operator*(
    const Scaler s,

    const Vector3 & v
);
```


**Parameters**: 

  * **s** 
  * **v** 


**Template Parameters**: 

  * **Scaler** 


**Return**: constexpr [Vector3](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1Vector3/)

-------------------------------

Updated on 2022-09-25 at 23:11:52 +0900