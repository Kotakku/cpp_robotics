---
title: cpp_robotics::SQP

---

# cpp_robotics::SQP






`#include <sqp.hpp>`

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[Problem](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SQP_1_1Problem/)**  |
| struct | **[Result](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SQP_1_1Result/)**  |

## Public Types

|                | Name           |
| -------------- | -------------- |
| using std::function< double(Eigen::VectorXd)> | **[func_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SQP/#using-func-type)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| [Result](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SQP_1_1Result/) | **[solve](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SQP/#function-solve)**([Problem](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1SQP_1_1Problem/) prob, const Eigen::VectorXd & x0, std::optional< std::function< void(Eigen::VectorXd)>> callback) |

## Public Types Documentation

### using func_type

```cpp
using cpp_robotics::SQP::func_type =  std::function<double(Eigen::VectorXd)>;
```


## Public Functions Documentation

### function solve

```cpp
inline Result solve(
    Problem prob,
    const Eigen::VectorXd & x0,
    std::optional< std::function< void(Eigen::VectorXd)>> callback
)
```


-------------------------------

Updated on 2022-09-25 at 23:29:49 +0900