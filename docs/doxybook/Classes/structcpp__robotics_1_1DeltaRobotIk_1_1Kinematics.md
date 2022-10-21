---
title: cpp_robotics::DeltaRobotIk::Kinematics

---

# cpp_robotics::DeltaRobotIk::Kinematics





## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Kinematics](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DeltaRobotIk_1_1Kinematics/#function-kinematics)**(double wb, double wp, double l1, double l2) |
| template <typename T \> <br>Eigen::Matrix< T, 3, 1 > | **[solve_fk](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DeltaRobotIk_1_1Kinematics/#function-solve-fk)**(const Eigen::Matrix< T, 3, 1 > & angles) |
| Eigen::Vector3d | **[solve_ik_analytical](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DeltaRobotIk_1_1Kinematics/#function-solve-ik-analytical)**(Eigen::Vector3d pos) |
| template <typename T \> <br>void | **[eval_func](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DeltaRobotIk_1_1Kinematics/#function-eval-func)**(const Eigen::Matrix< T, 3, 1 > & x, Eigen::Matrix< T, 1, 1 > & y) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| Eigen::Vector3d | **[target_pos](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DeltaRobotIk_1_1Kinematics/#variable-target-pos)**  |
| const double | **[wb](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DeltaRobotIk_1_1Kinematics/#variable-wb)**  |
| const double | **[wp](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DeltaRobotIk_1_1Kinematics/#variable-wp)**  |
| const double | **[l1](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DeltaRobotIk_1_1Kinematics/#variable-l1)**  |
| const double | **[l2](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DeltaRobotIk_1_1Kinematics/#variable-l2)**  |

## Public Functions Documentation

### function Kinematics

```cpp
inline Kinematics(
    double wb,
    double wp,
    double l1,
    double l2
)
```


### function solve_fk

```cpp
template <typename T >
inline Eigen::Matrix< T, 3, 1 > solve_fk(
    const Eigen::Matrix< T, 3, 1 > & angles
)
```


### function solve_ik_analytical

```cpp
inline Eigen::Vector3d solve_ik_analytical(
    Eigen::Vector3d pos
)
```


### function eval_func

```cpp
template <typename T >
inline void eval_func(
    const Eigen::Matrix< T, 3, 1 > & x,
    Eigen::Matrix< T, 1, 1 > & y
)
```


## Public Attributes Documentation

### variable target_pos

```cpp
Eigen::Vector3d target_pos;
```


### variable wb

```cpp
const double wb;
```


### variable wp

```cpp
const double wp;
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

Updated on 2022-10-21 at 10:30:14 +0900