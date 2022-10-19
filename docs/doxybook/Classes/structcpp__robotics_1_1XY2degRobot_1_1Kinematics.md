---
title: cpp_robotics::XY2degRobot::Kinematics

---

# cpp_robotics::XY2degRobot::Kinematics





## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Kinematics](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1XY2degRobot_1_1Kinematics/#function-kinematics)**(double l1, double l2) |
| template <typename T \> <br>Eigen::Matrix< T, 2, 1 > | **[solve_fk](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1XY2degRobot_1_1Kinematics/#function-solve-fk)**(const Eigen::Matrix< T, 2, 1 > & x) |
| Eigen::Vector2d | **[solve_ik_analytical](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1XY2degRobot_1_1Kinematics/#function-solve-ik-analytical)**(Eigen::Vector2d pos) |
| template <typename T \> <br>void | **[eval_func](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1XY2degRobot_1_1Kinematics/#function-eval-func)**(const Eigen::Matrix< T, 2, 1 > & x, Eigen::Matrix< T, 1, 1 > & y) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| Eigen::Vector2d | **[target_pos](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1XY2degRobot_1_1Kinematics/#variable-target-pos)**  |
| const double | **[l1](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1XY2degRobot_1_1Kinematics/#variable-l1)**  |
| const double | **[l2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1XY2degRobot_1_1Kinematics/#variable-l2)**  |

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
inline Eigen::Matrix< T, 2, 1 > solve_fk(
    const Eigen::Matrix< T, 2, 1 > & x
)
```


### function solve_ik_analytical

```cpp
inline Eigen::Vector2d solve_ik_analytical(
    Eigen::Vector2d pos
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
const double l1;
```


### variable l2

```cpp
const double l2;
```


-------------------------------

Updated on 2022-10-19 at 13:20:53 +0900