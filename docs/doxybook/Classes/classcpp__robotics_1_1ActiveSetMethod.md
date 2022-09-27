---
title: cpp_robotics::ActiveSetMethod
summary: 線形不等式制約を持つ2次計画法を解く有効制約法 

---

# cpp_robotics::ActiveSetMethod



線形不等式制約を持つ2次計画法を解く有効制約法 


`#include <active_set_method.hpp>`

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[Problem](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Problem/)**  |
| struct | **[Result](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Result/)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| [Result](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Result/) | **[solve](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ActiveSetMethod/#function-solve)**([Problem](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1ActiveSetMethod_1_1Problem/) prob, Eigen::VectorXd x) |

## Public Functions Documentation

### function solve

```cpp
inline Result solve(
    Problem prob,
    Eigen::VectorXd x
)
```


-------------------------------

Updated on 2022-09-28 at 01:12:56 +0900