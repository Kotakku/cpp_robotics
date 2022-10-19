---
title: cpp_robotics::ActiveSetMethod::Problem

---

# cpp_robotics::ActiveSetMethod::Problem






`#include <active_set_method.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Problem](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Problem/#function-problem)**() =default |
| | **[Problem](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Problem/#function-problem)**(size_t x_size_) |
| void | **[add_inequality_constraint](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Problem/#function-add-inequality-constraint)**(const Eigen::MatrixXd & An, Eigen::VectorXd bn) |
| void | **[add_equality_constraint](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Problem/#function-add-equality-constraint)**(const Eigen::MatrixXd & An, Eigen::VectorXd bn) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| Eigen::MatrixXd | **[Q](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Problem/#variable-q)**  |
| Eigen::VectorXd | **[c](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Problem/#variable-c)**  |
| Eigen::MatrixXd | **[A](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Problem/#variable-a)**  |
| Eigen::VectorXd | **[b](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Problem/#variable-b)**  |
| size_t | **[max_iter](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Problem/#variable-max-iter)**  |
| size_t | **[max_iter_get_initial_feasible_x](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Problem/#variable-max-iter-get-initial-feasible-x)**  |
| size_t | **[x_size](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Problem/#variable-x-size)**  |
| size_t | **[constraint_size](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Problem/#variable-constraint-size)**  |
| double | **[alpha](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Problem/#variable-alpha)**  |

## Public Functions Documentation

### function Problem

```cpp
Problem() =default
```


### function Problem

```cpp
inline Problem(
    size_t x_size_
)
```


### function add_inequality_constraint

```cpp
inline void add_inequality_constraint(
    const Eigen::MatrixXd & An,
    Eigen::VectorXd bn
)
```


### function add_equality_constraint

```cpp
inline void add_equality_constraint(
    const Eigen::MatrixXd & An,
    Eigen::VectorXd bn
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


### variable A

```cpp
Eigen::MatrixXd A;
```


### variable b

```cpp
Eigen::VectorXd b;
```


### variable max_iter

```cpp
size_t max_iter = 1000;
```


### variable max_iter_get_initial_feasible_x

```cpp
size_t max_iter_get_initial_feasible_x = 1000;
```


### variable x_size

```cpp
size_t x_size = 0;
```


### variable constraint_size

```cpp
size_t constraint_size = 0;
```


### variable alpha

```cpp
double alpha = 1.1;
```


-------------------------------

Updated on 2022-10-19 at 13:20:53 +0900