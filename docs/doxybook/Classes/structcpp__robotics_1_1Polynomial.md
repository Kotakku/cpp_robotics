---
title: cpp_robotics::Polynomial
summary: 多項式 

---

# cpp_robotics::Polynomial



多項式 


`#include <polynomial.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-polynomial)**(std::initializer_list< double > coeff) |
| | **[Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-polynomial)**(const std::vector< double > & coeff) |
| template <class IteratorType \> <br>| **[Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-polynomial)**(IteratorType begin, IteratorType end) |
| void | **[set_degree](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-set-degree)**(size_t deg) |
| size_t | **[size](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-size)**() const |
| size_t | **[degree](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-degree)**() const |
| std::vector< double > | **[coeff](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-coeff)**() const |
| double & | **[at](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-at)**(size_t i) |
| double | **[at](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-at)**(size_t i) const |
| double & | **[at_degree](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-at-degree)**(size_t i) |
| double | **[at_degree](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-at-degree)**(size_t i) const |
| double & | **[operator[]](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-operator[])**(size_t i) |
| double | **[operator[]](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-operator[])**(size_t i) const |
| void | **[check_degree](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-check-degree)**() |
| double | **[evalute](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-evalute)**(double x) const |
| [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) | **[polyder](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-polyder)**(size_t i) const |
| [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) | **[polyint](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-polyint)**(double C =0) const |
| void | **[swap](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-swap)**([Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) & poly) |
| double | **[operator()](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-operator())**(double x) const |
| [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) | **[operator+](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-operator+)**() const |
| [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) | **[operator-](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-operator-)**() const |
| [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) | **[operator+](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-operator+)**(double s) const |
| [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) | **[operator-](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-operator-)**(double s) const |
| [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) | **[operator*](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-operator*)**(double s) const |
| [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) | **[operator/](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-operator/)**(double s) const |
| [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) | **[operator*](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-operator*)**(const [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) & p) const |
| [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) | **[expand](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#function-expand)**(std::vector< double > roots) |

## Friends

|                | Name           |
| -------------- | -------------- |
| [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) | **[operator*](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#friend-operator*)**(double s, const [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) & poly)  |
| bool | **[operator==](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#friend-operator==)**(const [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) & lhs, const [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) & rhs)  |
| bool | **[operator!=](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/#friend-operator!=)**(const [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) & lhs, const [Polynomial](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Polynomial/) & rhs)  |

## Public Functions Documentation

### function Polynomial

```cpp
inline Polynomial(
    std::initializer_list< double > coeff
)
```


### function Polynomial

```cpp
inline Polynomial(
    const std::vector< double > & coeff
)
```


### function Polynomial

```cpp
template <class IteratorType >
inline Polynomial(
    IteratorType begin,
    IteratorType end
)
```


### function set_degree

```cpp
inline void set_degree(
    size_t deg
)
```


### function size

```cpp
inline size_t size() const
```


### function degree

```cpp
inline size_t degree() const
```


### function coeff

```cpp
inline std::vector< double > coeff() const
```


### function at

```cpp
inline double & at(
    size_t i
)
```


### function at

```cpp
inline double at(
    size_t i
) const
```


### function at_degree

```cpp
inline double & at_degree(
    size_t i
)
```


### function at_degree

```cpp
inline double at_degree(
    size_t i
) const
```


### function operator[]

```cpp
inline double & operator[](
    size_t i
)
```


### function operator[]

```cpp
inline double operator[](
    size_t i
) const
```


### function check_degree

```cpp
inline void check_degree()
```


### function evalute

```cpp
inline double evalute(
    double x
) const
```


### function polyder

```cpp
inline Polynomial polyder(
    size_t i
) const
```


### function polyint

```cpp
inline Polynomial polyint(
    double C =0
) const
```


### function swap

```cpp
inline void swap(
    Polynomial & poly
)
```


### function operator()

```cpp
inline double operator()(
    double x
) const
```


### function operator+

```cpp
inline Polynomial operator+() const
```


### function operator-

```cpp
inline Polynomial operator-() const
```


### function operator+

```cpp
inline Polynomial operator+(
    double s
) const
```


### function operator-

```cpp
inline Polynomial operator-(
    double s
) const
```


### function operator*

```cpp
inline Polynomial operator*(
    double s
) const
```


### function operator/

```cpp
inline Polynomial operator/(
    double s
) const
```


### function operator*

```cpp
inline Polynomial operator*(
    const Polynomial & p
) const
```


### function expand

```cpp
static inline Polynomial expand(
    std::vector< double > roots
)
```


## Friends

### friend operator*

```cpp
friend Polynomial operator*(
    double s,

    const Polynomial & poly
);
```


### friend operator==

```cpp
friend bool operator==(
    const Polynomial & lhs,

    const Polynomial & rhs
);
```


### friend operator!=

```cpp
friend bool operator!=(
    const Polynomial & lhs,

    const Polynomial & rhs
);
```


-------------------------------

Updated on 2022-10-02 at 13:22:12 +0900