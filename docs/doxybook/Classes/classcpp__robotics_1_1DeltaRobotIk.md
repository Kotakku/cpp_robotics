---
title: cpp_robotics::DeltaRobotIk
summary: デルタロボットの逆運動学 

---

# cpp_robotics::DeltaRobotIk



デルタロボットの逆運動学 


`#include <delta_robot.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| enum uint8_t | **[IkSolveMethod](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DeltaRobotIk/#enum-iksolvemethod)** { Analytical, Numerical} |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[DeltaRobotIk](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DeltaRobotIk/#function-deltarobotik)**(double wb, double wp, double l1, double l2, [IkSolveMethod](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DeltaRobotIk/#enum-iksolvemethod) method =IkSolveMethod::Analytical) |
| Eigen::Vector3d | **[solve_fk](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DeltaRobotIk/#function-solve-fk)**(Eigen::Vector3d joint_angles) |
| Eigen::Vector3d | **[solve_ik](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DeltaRobotIk/#function-solve-ik)**(Eigen::Vector3d pos, Eigen::Vector3d joint_angles0 =Eigen::Vector3d::Zero()) |

## Public Types Documentation

### enum IkSolveMethod

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| Analytical | |   |
| Numerical | |   |




## Public Functions Documentation

### function DeltaRobotIk

```cpp
inline DeltaRobotIk(
    double wb,
    double wp,
    double l1,
    double l2,
    IkSolveMethod method =IkSolveMethod::Analytical
)
```


### function solve_fk

```cpp
inline Eigen::Vector3d solve_fk(
    Eigen::Vector3d joint_angles
)
```


### function solve_ik

```cpp
inline Eigen::Vector3d solve_ik(
    Eigen::Vector3d pos,
    Eigen::Vector3d joint_angles0 =Eigen::Vector3d::Zero()
)
```


-------------------------------

Updated on 2022-10-10 at 00:51:39 +0900