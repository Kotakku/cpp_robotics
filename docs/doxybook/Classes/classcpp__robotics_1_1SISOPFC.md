---
title: cpp_robotics::SISOPFC

---

# cpp_robotics::SISOPFC






`#include <pfc.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[SISOPFC](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SISOPFC/#function-sisopfc)**(const Eigen::MatrixXd & Ad, const Eigen::VectorXd & Bd, const Eigen::VectorXd & Cd, const double delay, const double target_responce_time, const double dt)<br>Construct a new [SISOPFC](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SISOPFC/) object.  |
| double | **[calculate](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SISOPFC/#function-calculate)**(std::function< double(double)> ref_target, double now_state) |
| double | **[calculate](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SISOPFC/#function-calculate)**(std::function< double(double)> ref_target, double now_state, double prev_input) |
| double | **[prev_input](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SISOPFC/#function-prev-input)**() const |

## Public Functions Documentation

### function SISOPFC

```cpp
inline SISOPFC(
    const Eigen::MatrixXd & Ad,
    const Eigen::VectorXd & Bd,
    const Eigen::VectorXd & Cd,
    const double delay,
    const double target_responce_time,
    const double dt
)
```

Construct a new [SISOPFC](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SISOPFC/) object. 

**Parameters**: 

  * **Ad** 
  * **Bd** 
  * **Cd** 
  * **delay** 
  * **target_responce_time** 
  * **dt** 


### function calculate

```cpp
inline double calculate(
    std::function< double(double)> ref_target,
    double now_state
)
```


### function calculate

```cpp
inline double calculate(
    std::function< double(double)> ref_target,
    double now_state,
    double prev_input
)
```


### function prev_input

```cpp
inline double prev_input() const
```


-------------------------------

Updated on 2022-10-21 at 10:30:14 +0900