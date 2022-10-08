---
title: cpp_robotics::Constraint
summary: 数理最適問題に使用する制約クラス 

---

# cpp_robotics::Constraint



数理最適問題に使用する制約クラス 


`#include <constraint.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| enum uint8_t | **[Type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#enum-type)** { Eq, Ineq} |
| using std::function< double(Eigen::VectorXd)> | **[func_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#using-func-type)**  |
| using std::function< Eigen::VectorXd(Eigen::VectorXd)> | **[grad_func_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#using-grad-func-type)**  |
| using std::function< Eigen::MatrixXd(Eigen::VectorXd)> | **[hessian_func_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#using-hessian-func-type)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Constraint](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#function-constraint)**([Type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#enum-type) type_, [func_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#using-func-type) con_) |
| double | **[eval](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#function-eval)**(const Eigen::VectorXd & x) const |
| bool | **[satisfy](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#function-satisfy)**(const Eigen::VectorXd & x, const double tol) const |
| Eigen::VectorXd | **[grad](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#function-grad)**(Eigen::VectorXd x) |
| Eigen::MatrixXd | **[hessian](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#function-hessian)**(Eigen::VectorXd x) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [Type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#enum-type) | **[type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#variable-type)**  |
| [func_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#using-func-type) | **[con_f](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#variable-con-f)**  |
| std::optional< [grad_func_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#using-grad-func-type) > | **[con_grad_f](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#variable-con-grad-f)**  |
| std::optional< [hessian_func_type](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#using-hessian-func-type) > | **[con_hessian_f](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/#variable-con-hessian-f)**  |

## Public Types Documentation

### enum Type

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| Eq | |   |
| Ineq | |   |




### using func_type

```cpp
using cpp_robotics::Constraint::func_type =  std::function<double(Eigen::VectorXd)>;
```


### using grad_func_type

```cpp
using cpp_robotics::Constraint::grad_func_type =  std::function<Eigen::VectorXd(Eigen::VectorXd)>;
```


### using hessian_func_type

```cpp
using cpp_robotics::Constraint::hessian_func_type =  std::function<Eigen::MatrixXd(Eigen::VectorXd)>;
```


## Public Functions Documentation

### function Constraint

```cpp
inline Constraint(
    Type type_,
    func_type con_
)
```


### function eval

```cpp
inline double eval(
    const Eigen::VectorXd & x
) const
```


### function satisfy

```cpp
inline bool satisfy(
    const Eigen::VectorXd & x,
    const double tol
) const
```


### function grad

```cpp
inline Eigen::VectorXd grad(
    Eigen::VectorXd x
)
```


### function hessian

```cpp
inline Eigen::MatrixXd hessian(
    Eigen::VectorXd x
)
```


## Public Attributes Documentation

### variable type

```cpp
Type type;
```


### variable con_f

```cpp
func_type con_f;
```


### variable con_grad_f

```cpp
std::optional< grad_func_type > con_grad_f;
```


### variable con_hessian_f

```cpp
std::optional< hessian_func_type > con_hessian_f;
```


-------------------------------

Updated on 2022-10-08 at 23:36:07 +0900