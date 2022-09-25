---
title: cpp_robotics::QuadProg

---

# cpp_robotics::QuadProg






`#include <quadprog.hpp>`

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[Param](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1QuadProg_1_1Param/)**  |
| struct | **[Result](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1QuadProg_1_1Result/)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[set_problem_size](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1QuadProg/#function-set-problem-size)**(const size_t valiable_size, const size_t ineq_constraint_size, const size_t eq_constraint_size) |
| void | **[debug_prog](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1QuadProg/#function-debug-prog)**() |
| [Result](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1QuadProg_1_1Result/) | **[solve](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1QuadProg/#function-solve)**(Eigen::VectorXd x_init) |
| double | **[evaluate](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1QuadProg/#function-evaluate)**(const Eigen::VectorXd & x) |
| double | **[evaluate_merit](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1QuadProg/#function-evaluate-merit)**(const Eigen::VectorXd & x, const Eigen::VectorXd & s, const double rho, const double eta) |
| Eigen::VectorXd | **[grad_lagrange](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1QuadProg/#function-grad-lagrange)**(const Eigen::VectorXd & x, const Eigen::VectorXd & u, const Eigen::VectorXd & v) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| Eigen::MatrixXd | **[Q](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1QuadProg/#variable-q)**  |
| Eigen::VectorXd | **[c](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1QuadProg/#variable-c)**  |
| Eigen::MatrixXd | **[Aeq](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1QuadProg/#variable-aeq)**  |
| Eigen::VectorXd | **[beq](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1QuadProg/#variable-beq)**  |
| Eigen::MatrixXd | **[A](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1QuadProg/#variable-a)**  |
| Eigen::VectorXd | **[b](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1QuadProg/#variable-b)**  |
| [Param](/cpp_robotics_core/doxybook/Classes/structcpp__robotics_1_1QuadProg_1_1Param/) | **[param](/cpp_robotics_core/doxybook/Classes/classcpp__robotics_1_1QuadProg/#variable-param)**  |

## Public Functions Documentation

### function set_problem_size

```cpp
inline void set_problem_size(
    const size_t valiable_size,
    const size_t ineq_constraint_size,
    const size_t eq_constraint_size
)
```


### function debug_prog

```cpp
inline void debug_prog()
```


### function solve

```cpp
inline Result solve(
    Eigen::VectorXd x_init
)
```


### function evaluate

```cpp
inline double evaluate(
    const Eigen::VectorXd & x
)
```


### function evaluate_merit

```cpp
inline double evaluate_merit(
    const Eigen::VectorXd & x,
    const Eigen::VectorXd & s,
    const double rho,
    const double eta
)
```


### function grad_lagrange

```cpp
inline Eigen::VectorXd grad_lagrange(
    const Eigen::VectorXd & x,
    const Eigen::VectorXd & u,
    const Eigen::VectorXd & v
)
```


## Public Attributes Documentation

### variable Q

```cpp
Eigen::MatrixXd Q;
```


### variable c

```cpp
Eigen::VectorXd c;
```


### variable Aeq

```cpp
Eigen::MatrixXd Aeq;
```


### variable beq

```cpp
Eigen::VectorXd beq;
```


### variable A

```cpp
Eigen::MatrixXd A;
```


### variable b

```cpp
Eigen::VectorXd b;
```


### variable param

```cpp
Param param;
```


-------------------------------

Updated on 2022-09-25 at 23:11:52 +0900