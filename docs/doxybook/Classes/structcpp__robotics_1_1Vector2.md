---
title: cpp_robotics::Vector2
summary: 2次元のベクトル 

---

# cpp_robotics::Vector2



2次元のベクトル  [More...](#detailed-description)


`#include <vector2.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using FLOATING_TYPE | **[value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-vector2)**() =default<br>Construct a new Vector 2 object.  |
| constexpr | **[Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-vector2)**([value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) vx, [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) vy)<br>Construct a new Vector 2 object.  |
| constexpr | **[Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-vector2)**(const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & ) =default<br>Construct a new Vector 2 object.  |
| constexpr void | **[set](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-set)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) vx, const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) vy)<br>値の代入  |
| void | **[set_polar](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-set-polar)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) radius, const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) theta)<br>極形式での値の代入  |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) | **[dot](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-dot)**(const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & v) const |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) | **[cross](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-cross)**(const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & v) const |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) | **[norm_sq](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-norm-sq)**() const |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) | **[norm](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-norm)**() const<br>ベクトルの大きさを返す  |
| void | **[normalize](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-normalize)**()<br>単位ベクトル化  |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) | **[angle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-angle)**() const<br>ベクトルの角度を返す  |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[get_normalized](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-get-normalized)**()<br>単位ベクトル化したベクトルを返す  |
| void | **[rotate](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-rotate)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) theta)<br>原点中心に回転  |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[get_rotated](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-get-rotated)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) theta) const<br>原点中心に回転させたベクトルを返す  |
| constexpr bool | **[is_zero](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-is-zero)**() const |
| constexpr bool | **[has_nan](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-has-nan)**() const |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[yx](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-yx)**() const |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[nyx](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-nyx)**() const |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[ynx](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-ynx)**() const |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[nxy](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-nxy)**() const |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[xny](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-xny)**() const |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[lerp](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-lerp)**(const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & b, const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) t) const |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[operator+](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-operator+)**() const |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[operator-](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-operator-)**() const |
| constexpr bool | **[operator==](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-operator==)**(const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & v) const |
| constexpr bool | **[operator!=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-operator!=)**(const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & v) const |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[operator+](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-operator+)**(const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & v) const |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[operator-](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-operator-)**(const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & v) const |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & | **[operator+=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-operator+=)**(const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & v) |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & | **[operator-=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-operator-=)**(const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & v) |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & | **[operator*=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-operator*=)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) value) |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & | **[operator/=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-operator/=)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) value) |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) & | **[operator[]](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-operator[])**(const size_t index) |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) | **[operator[]](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-operator[])**(const size_t index) const |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) | **[dot](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-dot)**(const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & a, const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & b) |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) | **[angle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-angle)**(const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & a, const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & b) |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) | **[distance](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-distance)**(const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & a, const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & b) |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[lerp](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-lerp)**(const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & a, const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & b, const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) t) |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[zero](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-zero)**() |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[up](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-up)**() |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[down](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-down)**() |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[right](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-right)**() |
| constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[left](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#function-left)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) | **[x](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#variable-x)**  |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) | **[y](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#variable-y)**  |

## Friends

|                | Name           |
| -------------- | -------------- |
| constexpr friend [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[operator/](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#friend-operator/)**(const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & v, const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#using-value-type) value)  |
| constexpr friend [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[operator*](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#friend-operator*)**(const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & v, const Scaler s)  |
| constexpr friend [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) | **[operator*](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/#friend-operator*)**(const Scaler s, const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/) & v)  |

## Detailed Description

```cpp
template <typename FLOATING_TYPE >
struct cpp_robotics::Vector2;
```

2次元のベクトル 
## Public Types Documentation

### using value_type

```cpp
using cpp_robotics::Vector2< FLOATING_TYPE >::value_type =  FLOATING_TYPE;
```


## Public Functions Documentation

### function Vector2

```cpp
Vector2() =default
```

Construct a new Vector 2 object. 

### function Vector2

```cpp
inline constexpr Vector2(
    value_type vx,
    value_type vy
)
```

Construct a new Vector 2 object. 

**Parameters**: 

  * **vx** 
  * **vy** 


### function Vector2

```cpp
constexpr Vector2(
    const Vector2 & 
) =default
```

Construct a new Vector 2 object. 

**Parameters**: 

  * **v** 


### function set

```cpp
inline constexpr void set(
    const value_type vx,
    const value_type vy
)
```

値の代入 

**Parameters**: 

  * **vx** value_type 
  * **vy** 


### function set_polar

```cpp
inline void set_polar(
    const value_type radius,
    const value_type theta
)
```

極形式での値の代入 

**Parameters**: 

  * **radius** 半径 
  * **theta** 角度[rad] 


### function dot

```cpp
inline constexpr value_type dot(
    const Vector2 & v
) const
```


**Parameters**: 

  * **v** 


**Return**: constexpr value_type 

### function cross

```cpp
inline constexpr value_type cross(
    const Vector2 & v
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
inline constexpr value_type norm() const
```

ベクトルの大きさを返す 

**Return**: value_type 

### function normalize

```cpp
inline void normalize()
```

単位ベクトル化 

### function angle

```cpp
inline constexpr value_type angle() const
```

ベクトルの角度を返す 

**Return**: value_type 

### function get_normalized

```cpp
inline constexpr Vector2 get_normalized()
```

単位ベクトル化したベクトルを返す 

**Return**: [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

### function rotate

```cpp
inline void rotate(
    const value_type theta
)
```

原点中心に回転 

**Parameters**: 

  * **theta** [rad] 


### function get_rotated

```cpp
inline constexpr Vector2 get_rotated(
    const value_type theta
) const
```

原点中心に回転させたベクトルを返す 

**Parameters**: 

  * **theta** 


**Return**: [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

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


### function yx

```cpp
inline constexpr Vector2 yx() const
```


**Return**: constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

### function nyx

```cpp
inline constexpr Vector2 nyx() const
```


**Return**: constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

### function ynx

```cpp
inline constexpr Vector2 ynx() const
```


**Return**: constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

### function nxy

```cpp
inline constexpr Vector2 nxy() const
```


### function xny

```cpp
inline constexpr Vector2 xny() const
```


### function lerp

```cpp
inline constexpr Vector2 lerp(
    const Vector2 & b,
    const value_type t
) const
```


**Parameters**: 

  * **b** 
  * **t** 


**Return**: constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

### function operator+

```cpp
inline constexpr Vector2 operator+() const
```


**Return**: constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

### function operator-

```cpp
inline constexpr Vector2 operator-() const
```


**Return**: constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

### function operator==

```cpp
inline constexpr bool operator==(
    const Vector2 & v
) const
```


**Parameters**: 

  * **v** 


**Return**: 

  * true 
  * false 


### function operator!=

```cpp
inline constexpr bool operator!=(
    const Vector2 & v
) const
```


**Parameters**: 

  * **v** 


**Return**: 

  * true 
  * false 


### function operator+

```cpp
inline constexpr Vector2 operator+(
    const Vector2 & v
) const
```


**Parameters**: 

  * **v** 


**Return**: [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

### function operator-

```cpp
inline constexpr Vector2 operator-(
    const Vector2 & v
) const
```


**Parameters**: 

  * **v** 


**Return**: [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

### function operator+=

```cpp
inline constexpr Vector2 & operator+=(
    const Vector2 & v
)
```


**Parameters**: 

  * **v** 


**Return**: [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)& 

### function operator-=

```cpp
inline constexpr Vector2 & operator-=(
    const Vector2 & v
)
```


**Parameters**: 

  * **v** 


**Return**: [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)& 

### function operator*=

```cpp
inline constexpr Vector2 & operator*=(
    const value_type value
)
```


**Parameters**: 

  * **value** 


**Return**: [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)& 

### function operator/=

```cpp
inline constexpr Vector2 & operator/=(
    const value_type value
)
```


**Parameters**: 

  * **value** 


**Return**: [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)& 

### function operator[]

```cpp
inline value_type & operator[](
    const size_t index
)
```


**Parameters**: 

  * **index** 


**Return**: value_type& 

### function operator[]

```cpp
inline constexpr value_type operator[](
    const size_t index
) const
```


**Parameters**: 

  * **index** 


**Return**: constexpr value_type 

### function dot

```cpp
static inline constexpr value_type dot(
    const Vector2 & a,
    const Vector2 & b
)
```


**Parameters**: 

  * **a** 
  * **b** 


**Return**: constexpr value_type 

### function angle

```cpp
static inline constexpr value_type angle(
    const Vector2 & a,
    const Vector2 & b
)
```


**Parameters**: 

  * **a** 
  * **b** 


**Return**: value_type 

### function distance

```cpp
static inline constexpr value_type distance(
    const Vector2 & a,
    const Vector2 & b
)
```


**Parameters**: 

  * **a** 
  * **b** 


**Return**: value_type 

### function lerp

```cpp
static inline constexpr Vector2 lerp(
    const Vector2 & a,
    const Vector2 & b,
    const value_type t
)
```


**Parameters**: 

  * **a** 
  * **b** 
  * **t** 


**Return**: constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

### function zero

```cpp
static inline constexpr Vector2 zero()
```


**Return**: const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

### function up

```cpp
static inline constexpr Vector2 up()
```


**Return**: const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

### function down

```cpp
static inline constexpr Vector2 down()
```


**Return**: const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

### function right

```cpp
static inline constexpr Vector2 right()
```


**Return**: const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

### function left

```cpp
static inline constexpr Vector2 left()
```


**Return**: const [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

## Public Attributes Documentation

### variable x

```cpp
value_type x;
```


### variable y

```cpp
value_type y;
```


## Friends

### friend operator/

```cpp
friend constexpr friend Vector2 operator/(
    const Vector2 & v,

    const value_type value
);
```


**Parameters**: 

  * **value** 


**Return**: [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

### friend operator*

```cpp
friend constexpr friend Vector2 operator*(
    const Vector2 & v,

    const Scaler s
);
```


**Parameters**: 

  * **v** 
  * **s** 


**Template Parameters**: 

  * **Scaler** 


**Return**: constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

### friend operator*

```cpp
friend constexpr friend Vector2 operator*(
    const Scaler s,

    const Vector2 & v
);
```


**Parameters**: 

  * **s** 
  * **v** 


**Template Parameters**: 

  * **Scaler** 


**Return**: constexpr [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)

-------------------------------

Updated on 2022-09-28 at 23:12:43 +0900