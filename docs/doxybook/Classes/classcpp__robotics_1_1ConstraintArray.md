---
title: cpp_robotics::ConstraintArray
summary: 数理最適化問題の制約の集合 

---

# cpp_robotics::ConstraintArray



数理最適化問題の制約の集合 


`#include <constraint.hpp>`

Inherits from std::vector< Constraint >

## Public Functions

|                | Name           |
| -------------- | -------------- |
| std::vector< double > | **[eval](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ConstraintArray/#function-eval)**(const Eigen::VectorXd & x) const |
| double | **[eval_sum](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ConstraintArray/#function-eval-sum)**(const Eigen::VectorXd & x) const |
| bool | **[all_satisfy](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ConstraintArray/#function-all-satisfy)**(const Eigen::VectorXd & x, const double tol) const |
| std::vector< [Constraint](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/) >::size_type | **[eq_constraint_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ConstraintArray/#function-eq-constraint-size)**() const |
| std::vector< [Constraint](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/) >::size_type | **[ineq_constraint_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ConstraintArray/#function-ineq-constraint-size)**() const |
| std::vector< [Constraint](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/) > | **[gen_eq_constraint_list](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ConstraintArray/#function-gen-eq-constraint-list)**() const |
| std::vector< [Constraint](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Constraint/) > | **[gen_ineq_constraint_list](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ConstraintArray/#function-gen-ineq-constraint-list)**() const |

## Public Functions Documentation

### function eval

```cpp
inline std::vector< double > eval(
    const Eigen::VectorXd & x
) const
```


### function eval_sum

```cpp
inline double eval_sum(
    const Eigen::VectorXd & x
) const
```


### function all_satisfy

```cpp
inline bool all_satisfy(
    const Eigen::VectorXd & x,
    const double tol
) const
```


### function eq_constraint_size

```cpp
inline std::vector< Constraint >::size_type eq_constraint_size() const
```


### function ineq_constraint_size

```cpp
inline std::vector< Constraint >::size_type ineq_constraint_size() const
```


### function gen_eq_constraint_list

```cpp
inline std::vector< Constraint > gen_eq_constraint_list() const
```


### function gen_ineq_constraint_list

```cpp
inline std::vector< Constraint > gen_ineq_constraint_list() const
```


-------------------------------

Updated on 2022-09-28 at 23:12:43 +0900