---
title: cpp_robotics::XY2degRobot

---

# cpp_robotics::XY2degRobot






`#include <xy_2deg_robot.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| enum uint8_t | **[IkSolveMethod](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1XY2degRobot/#enum-iksolvemethod)** { Analytical, Numerical} |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[XY2degRobot](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1XY2degRobot/#function-xy2degrobot)**(double l1, double l2, [IkSolveMethod](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1XY2degRobot/#enum-iksolvemethod) method =IkSolveMethod::Analytical) |
| Eigen::Vector2d | **[solve_fk](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1XY2degRobot/#function-solve-fk)**(double joint_angle1, double joint_angle2) |
| Eigen::Vector2d | **[solve_fk](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1XY2degRobot/#function-solve-fk)**(Eigen::Vector2d joint_angles) |
| Eigen::Vector2d | **[solve_ik](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1XY2degRobot/#function-solve-ik)**(Eigen::Vector2d pos, Eigen::Vector2d joint_angles0 =Eigen::Vector2d::Zero()) |

## Public Types Documentation

### enum IkSolveMethod

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| Analytical | |   |
| Numerical | |   |




## Public Functions Documentation

### function XY2degRobot

```cpp
inline XY2degRobot(
    double l1,
    double l2,
    IkSolveMethod method =IkSolveMethod::Analytical
)
```


### function solve_fk

```cpp
inline Eigen::Vector2d solve_fk(
    double joint_angle1,
    double joint_angle2
)
```


### function solve_fk

```cpp
inline Eigen::Vector2d solve_fk(
    Eigen::Vector2d joint_angles
)
```


### function solve_ik

```cpp
inline Eigen::Vector2d solve_ik(
    Eigen::Vector2d pos,
    Eigen::Vector2d joint_angles0 =Eigen::Vector2d::Zero()
)
```


-------------------------------

Updated on 2022-10-10 at 00:51:39 +0900