---
title: cpp_robotics::SQP::Problem

---

# cpp_robotics::SQP::Problem






`#include <sqp.hpp>`

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [func_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SQP/#using-func-type) | **[func](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SQP_1_1Problem/#variable-func)**  |
| std::optional< [grad_func_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SQP/#using-grad-func-type) > | **[grad](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SQP_1_1Problem/#variable-grad)**  |
| [ConstraintArray](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ConstraintArray/) | **[con](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SQP_1_1Problem/#variable-con)**  |
| double | **[tol_step](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SQP_1_1Problem/#variable-tol-step)**  |
| double | **[tol_con](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SQP_1_1Problem/#variable-tol-con)**  |
| size_t | **[max_iter](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SQP_1_1Problem/#variable-max-iter)**  |

## Public Attributes Documentation

### variable func

```cpp
func_type func;
```


### variable grad

```cpp
std::optional< grad_func_type > grad;
```


### variable con

```cpp
ConstraintArray con;
```


### variable tol_step

```cpp
double tol_step = 1e-6;
```


### variable tol_con

```cpp
double tol_con = 1e-6;
```


### variable max_iter

```cpp
size_t max_iter = 100;
```


-------------------------------

Updated on 2022-10-08 at 23:36:07 +0900