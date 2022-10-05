---
title: cpp_robotics::XY2degRobot::Kinematics

---

# cpp_robotics::XY2degRobot::Kinematics





## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Kinematics](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1XY2degRobot_1_1Kinematics/#function-kinematics)**(double l1, double l2) |
| template <typename T \> <br>void | **[solve_fk](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1XY2degRobot_1_1Kinematics/#function-solve-fk)**(const Eigen::Matrix< T, 2, 1 > & x, Eigen::Matrix< T, 2, 1 > & y) |
| template <typename T \> <br>void | **[eval_func](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1XY2degRobot_1_1Kinematics/#function-eval-func)**(const Eigen::Matrix< T, 2, 1 > & x, Eigen::Matrix< T, 1, 1 > & y) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| Eigen::Vector2d | **[target_pos](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1XY2degRobot_1_1Kinematics/#variable-target-pos)**  |
| double | **[l1](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1XY2degRobot_1_1Kinematics/#variable-l1)**  |
| double | **[l2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1XY2degRobot_1_1Kinematics/#variable-l2)**  |

## Public Functions Documentation

### function Kinematics

```cpp
inline Kinematics(
    double l1,
    double l2
)
```


### function solve_fk

```cpp
template <typename T >
inline void solve_fk(
    const Eigen::Matrix< T, 2, 1 > & x,
    Eigen::Matrix< T, 2, 1 > & y
)
```


### function eval_func

```cpp
template <typename T >
inline void eval_func(
    const Eigen::Matrix< T, 2, 1 > & x,
    Eigen::Matrix< T, 1, 1 > & y
)
```


## Public Attributes Documentation

### variable target_pos

```cpp
Eigen::Vector2d target_pos;
```


### variable l1

```cpp
double l1;
```


### variable l2

```cpp
double l2;
```


-------------------------------

Updated on 2022-10-05 at 16:05:00 +0900