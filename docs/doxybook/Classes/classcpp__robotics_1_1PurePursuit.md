---
title: cpp_robotics::PurePursuit
summary: Pure pursuit制御器 

---

# cpp_robotics::PurePursuit



Pure pursuit制御器 


`#include <pure_pursuit.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[PurePursuit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PurePursuit/#function-purepursuit)**(double K) |
| void | **[set_K](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PurePursuit/#function-set-k)**(double K) |
| std::tuple< bool, double > | **[control](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1PurePursuit/#function-control)**(std::function< [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d)(double)> traj_ref, double traj_progress, [Vector2d](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-vector2d) pos_present, double vel, double angle_present) |

## Public Functions Documentation

### function PurePursuit

```cpp
inline PurePursuit(
    double K
)
```


### function set_K

```cpp
inline void set_K(
    double K
)
```


### function control

```cpp
inline std::tuple< bool, double > control(
    std::function< Vector2d(double)> traj_ref,
    double traj_progress,
    Vector2d pos_present,
    double vel,
    double angle_present
)
```


**Parameters**: 

  * **traj_ref** 始点からの長さによる経路の関数 
  * **traj_progress** 現在の経路上の長さ位置 
  * **pos_present** 現在の座標 
  * **target_angle_offset** traj_refから目標座標を取ってきた時に位置誤差から角度を出した時に加えるオフセット 
  * **vel** 現在の進行方向の速度 
  * **angle_present** 現在のロボットのYaw角度 


**Return**: std::tuple<bool, double> [Pure Pursuitが有効な出力を返すか, 出力値] 

-------------------------------

Updated on 2022-10-05 at 16:05:00 +0900