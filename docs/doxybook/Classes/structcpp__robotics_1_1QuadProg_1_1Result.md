---
title: cpp_robotics::QuadProg::Result

---

# cpp_robotics::QuadProg::Result






`#include <quadprog.hpp>`

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| bool | **[is_solved](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1QuadProg_1_1Result/#variable-is-solved)**  |
| Eigen::VectorXd | **[x](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1QuadProg_1_1Result/#variable-x)**  |
| Eigen::VectorXd | **[lambda_ineq](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1QuadProg_1_1Result/#variable-lambda-ineq)**  |
| Eigen::VectorXd | **[lambda_eq](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1QuadProg_1_1Result/#variable-lambda-eq)**  |
| size_t | **[iter_cnt](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1QuadProg_1_1Result/#variable-iter-cnt)**  |

## Public Attributes Documentation

### variable is_solved

```cpp
bool is_solved = false;
```


### variable x

```cpp
Eigen::VectorXd x;
```


### variable lambda_ineq

```cpp
Eigen::VectorXd lambda_ineq;
```


### variable lambda_eq

```cpp
Eigen::VectorXd lambda_eq;
```


### variable iter_cnt

```cpp
size_t iter_cnt = 0;
```


-------------------------------

Updated on 2022-10-08 at 23:36:07 +0900