---
title: cpp_robotics::Transform
summary: 2次元のロボットの座標を扱うクラス 

---

# cpp_robotics::Transform



2次元のロボットの座標を扱うクラス  [More...](#detailed-description)


`#include <transform.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using FLOATING_TYPE | **[value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type)**  |
| using [Vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Vector2/)< [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) > | **[vector_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-vector-type)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-transform)**() =default<br>Construct a new Field Vector 2 object.  |
| constexpr | **[Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-transform)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) _x, const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) _y, const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) _theta)<br>Construct a new Field Vector 2 object.  |
| constexpr | **[Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-transform)**(const [vector_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-vector-type) & _xy, const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) _theta)<br>Construct a new Field Vector 2 object.  |
| constexpr | **[Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-transform)**(const [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & ) =default<br>Construct a new Field Vector 2 object.  |
| constexpr [vector_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-vector-type) | **[make_vector2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-make-vector2)**() const<br>xy成分のVector2を生成  |
| constexpr void | **[set](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-set)**([value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) vx, [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) vy, [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) vtheta) |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) | **[distance](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-distance)**() const<br>原点からxy座標までの距離を返す  |
| void | **[rotate](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-rotate)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) theta)<br>原点中心に回転  |
| void | **[rotate](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-rotate)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) rotX, const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) rotY, const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) theta)<br>指定座標中心に回転  |
| void | **[rotate](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-rotate)**([vector_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-vector-type) rotPos, const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) theta)<br>指定座標中心に回転  |
| void | **[set_polar](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-set-polar)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) radius, const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) angle, const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) robotTheta)<br>極座標指定  |
| bool | **[is_zero](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-is-zero)**() const |
| bool | **[is_zero_pos](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-is-zero-pos)**() const |
| bool | **[is_zero_angle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-is-zero-angle)**() const |
| bool | **[has_nan](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-has-nan)**() const |
| constexpr bool | **[operator==](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator==)**(const [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) v) const |
| constexpr bool | **[operator!=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator!=)**(const [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & v) const |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) | **[operator+](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator+)**(const [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & v) const |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) | **[operator-](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator-)**(const [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & v) const |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & | **[operator+=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator+=)**(const [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & v) |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & | **[operator-=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator-=)**(const [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & v) |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) | **[operator+](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator+)**(const [vector_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-vector-type) & v) const |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) | **[operator-](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator-)**(const [vector_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-vector-type) & v) const |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) | **[operator+](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator+)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) angle) const |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) | **[operator-](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator-)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) angle) const |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & | **[operator+=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator+=)**(const [vector_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-vector-type) & v) |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & | **[operator-=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator-=)**(const [vector_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-vector-type) & v) |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & | **[operator+=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator+=)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) angle) |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & | **[operator-=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator-=)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) angle) |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) | **[operator*](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator*)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) value) const |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) | **[operator/](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator/)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) value) const |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & | **[operator*=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator*=)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) value) |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & | **[operator/=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator/=)**(const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) value) |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) & | **[operator[]](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator[])**(const int index) |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) | **[operator[]](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-operator[])**(const int index) const |
| constexpr [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) | **[get_angle](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-get-angle)**([Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & a, [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & b)<br>Get the Angle object.  |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) | **[get_distance](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-get-distance)**([Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & a, [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & b)<br>Get the Distance object.  |
| [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) | **[get_lerp](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-get-lerp)**([Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & a, [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) & b, const [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) t)<br>lerp function  |
| constexpr [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/) | **[origin](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#function-origin)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) | **[x](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#variable-x)**  |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) | **[y](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#variable-y)**  |
| [value_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#using-value-type) | **[theta](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/#variable-theta)**  |

## Detailed Description

```cpp
template <typename FLOATING_TYPE >
struct cpp_robotics::Transform;
```

2次元のロボットの座標を扱うクラス 
## Public Types Documentation

### using value_type

```cpp
using cpp_robotics::Transform< FLOATING_TYPE >::value_type =  FLOATING_TYPE;
```


### using vector_type

```cpp
using cpp_robotics::Transform< FLOATING_TYPE >::vector_type =  Vector2<value_type>;
```


## Public Functions Documentation

### function Transform

```cpp
Transform() =default
```

Construct a new Field Vector 2 object. 

### function Transform

```cpp
inline constexpr Transform(
    const value_type _x,
    const value_type _y,
    const value_type _theta
)
```

Construct a new Field Vector 2 object. 

**Parameters**: 

  * **x** 
  * **y** 
  * **theta** 


### function Transform

```cpp
inline constexpr Transform(
    const vector_type & _xy,
    const value_type _theta
)
```

Construct a new Field Vector 2 object. 

### function Transform

```cpp
constexpr Transform(
    const Transform & 
) =default
```

Construct a new Field Vector 2 object. 

**Parameters**: 

  * **v** 


### function make_vector2

```cpp
inline constexpr vector_type make_vector2() const
```

xy成分のVector2を生成 

### function set

```cpp
inline constexpr void set(
    value_type vx,
    value_type vy,
    value_type vtheta
)
```


**Parameters**: 

  * **vx** 
  * **vy** 
  * **vtheta** 


### function distance

```cpp
inline value_type distance() const
```

原点からxy座標までの距離を返す 

**Return**: value_type 

### function rotate

```cpp
inline void rotate(
    const value_type theta
)
```

原点中心に回転 

**Parameters**: 

  * **theta** 


### function rotate

```cpp
inline void rotate(
    const value_type rotX,
    const value_type rotY,
    const value_type theta
)
```

指定座標中心に回転 

**Parameters**: 

  * **rotX** 
  * **rotY** 
  * **theta** 


### function rotate

```cpp
inline void rotate(
    vector_type rotPos,
    const value_type theta
)
```

指定座標中心に回転 

**Parameters**: 

  * **rotPos** 
  * **theta** 


### function set_polar

```cpp
inline void set_polar(
    const value_type radius,
    const value_type angle,
    const value_type robotTheta
)
```

極座標指定 

**Parameters**: 

  * **radius** 
  * **angle** 
  * **robotTheta** 


### function is_zero

```cpp
inline bool is_zero() const
```


**Return**: 

  * true 
  * false 


### function is_zero_pos

```cpp
inline bool is_zero_pos() const
```


**Return**: 

  * true 
  * false 


### function is_zero_angle

```cpp
inline bool is_zero_angle() const
```


**Return**: 

  * true 
  * false 


### function has_nan

```cpp
inline bool has_nan() const
```


**Return**: 

  * true 
  * false 


### function operator==

```cpp
inline constexpr bool operator==(
    const Transform v
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
    const Transform & v
) const
```


**Parameters**: 

  * **v** 


**Return**: 

  * true 
  * false 


### function operator+

```cpp
inline constexpr Transform operator+(
    const Transform & v
) const
```


**Parameters**: 

  * **v** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)

### function operator-

```cpp
inline constexpr Transform operator-(
    const Transform & v
) const
```


**Parameters**: 

  * **v** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)

### function operator+=

```cpp
inline constexpr Transform & operator+=(
    const Transform & v
)
```


**Parameters**: 

  * **v** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)& 

### function operator-=

```cpp
inline constexpr Transform & operator-=(
    const Transform & v
)
```


**Parameters**: 

  * **v** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)& 

### function operator+

```cpp
inline constexpr Transform operator+(
    const vector_type & v
) const
```


**Parameters**: 

  * **v** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)

### function operator-

```cpp
inline constexpr Transform operator-(
    const vector_type & v
) const
```


**Parameters**: 

  * **v** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)

### function operator+

```cpp
inline constexpr Transform operator+(
    const value_type angle
) const
```


**Parameters**: 

  * **angle** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)

### function operator-

```cpp
inline constexpr Transform operator-(
    const value_type angle
) const
```


**Parameters**: 

  * **angle** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)

### function operator+=

```cpp
inline constexpr Transform & operator+=(
    const vector_type & v
)
```


**Parameters**: 

  * **v** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)& 

### function operator-=

```cpp
inline constexpr Transform & operator-=(
    const vector_type & v
)
```


**Parameters**: 

  * **v** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)& 

### function operator+=

```cpp
inline constexpr Transform & operator+=(
    const value_type angle
)
```


**Parameters**: 

  * **angle** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)& 

### function operator-=

```cpp
inline constexpr Transform & operator-=(
    const value_type angle
)
```


**Parameters**: 

  * **angle** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)& 

### function operator*

```cpp
inline constexpr Transform operator*(
    const value_type value
) const
```


**Parameters**: 

  * **value** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)

### function operator/

```cpp
inline constexpr Transform operator/(
    const value_type value
) const
```


**Parameters**: 

  * **value** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)

### function operator*=

```cpp
inline constexpr Transform & operator*=(
    const value_type value
)
```


**Parameters**: 

  * **value** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)& 

### function operator/=

```cpp
inline constexpr Transform & operator/=(
    const value_type value
)
```


**Parameters**: 

  * **value** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)& 

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

### function get_angle

```cpp
static inline constexpr value_type get_angle(
    Transform & a,
    Transform & b
)
```

Get the Angle object. 

**Parameters**: 

  * **a** 
  * **b** 


**Return**: value_type 

### function get_distance

```cpp
static inline value_type get_distance(
    Transform & a,
    Transform & b
)
```

Get the Distance object. 

**Parameters**: 

  * **a** 
  * **b** 


**Return**: value_type 

### function get_lerp

```cpp
static inline Transform get_lerp(
    Transform & a,
    Transform & b,
    const value_type t
)
```

lerp function 

**Parameters**: 

  * **a** 
  * **b** 
  * **t** 


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)

### function origin

```cpp
static inline constexpr Transform origin()
```


**Return**: [Transform](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Transform/)

## Public Attributes Documentation

### variable x

```cpp
value_type x;
```


### variable y

```cpp
value_type y;
```


### variable theta

```cpp
value_type theta;
```


-------------------------------

Updated on 2022-10-10 at 00:51:39 +0900