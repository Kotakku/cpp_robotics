---
title: cpp_robotics::Discret

---

# cpp_robotics::Discret






`#include <discret.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| template <typename Derived \> <br>auto | **[discretize_a](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Discret/#function-discretize-a)**(const Eigen::MatrixBase< Derived > & A, const float Ts) |
| template <typename Derived1 ,typename Derived2 \> <br>auto | **[discretize_b](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Discret/#function-discretize-b)**(const Eigen::MatrixBase< Derived1 > & A, const Eigen::MatrixBase< Derived2 > & B, const float & Ts, size_t hdiv =1000) |
| template <typename Derived1 ,typename Derived2 \> <br>auto | **[discritize](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Discret/#function-discritize)**(const Eigen::MatrixBase< Derived1 > & A, const Eigen::MatrixBase< Derived2 > & B, const float & Ts, size_t hdiv =1000) |

## Public Functions Documentation

### function discretize_a

```cpp
template <typename Derived >
static inline auto discretize_a(
    const Eigen::MatrixBase< Derived > & A,
    const float Ts
)
```


### function discretize_b

```cpp
template <typename Derived1 ,
typename Derived2 >
static inline auto discretize_b(
    const Eigen::MatrixBase< Derived1 > & A,
    const Eigen::MatrixBase< Derived2 > & B,
    const float & Ts,
    size_t hdiv =1000
)
```


### function discritize

```cpp
template <typename Derived1 ,
typename Derived2 >
static inline auto discritize(
    const Eigen::MatrixBase< Derived1 > & A,
    const Eigen::MatrixBase< Derived2 > & B,
    const float & Ts,
    size_t hdiv =1000
)
```


-------------------------------

Updated on 2022-09-27 at 01:12:56 +0900