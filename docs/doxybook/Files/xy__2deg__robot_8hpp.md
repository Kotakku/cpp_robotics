---
title: include/cpp_robotics/arm_ik/xy_2deg_robot.hpp

---

# include/cpp_robotics/arm_ik/xy_2deg_robot.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::XY2degRobot](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1XY2degRobot/)**  |




## Source code

```cpp
#pragma once

#include <Eigen/Dense>
#include "cpp_robotics/optimize/derivative.hpp"
#include "cpp_robotics/optimize/quasi_newton_method.hpp"
#include "cpp_robotics/algorithm/auto_diff.hpp"

namespace cpp_robotics
{

class XY2degRobot
{
public:
    enum IkSolveMethod : uint8_t
    {
        Analytical,
        Numerical
    };
    XY2degRobot(double l1, double l2, IkSolveMethod method = IkSolveMethod::Analytical):
        method_(method), kinematics_functor_(l1, l2), ad_(kinematics_functor_) {}

    Eigen::Vector2d solve_fk(double joint_angle1, double joint_angle2)
    {
        return solve_fk(Eigen::Vector2d(joint_angle1, joint_angle2));
    }

    Eigen::Vector2d solve_fk(Eigen::Vector2d joint_angles)
    {
        return kinematics_functor_.solve_fk(joint_angles);;
    }

    Eigen::Vector2d solve_ik(Eigen::Vector2d pos, Eigen::Vector2d joint_angles0 = Eigen::Vector2d::Zero())
    {
        if(method_ == IkSolveMethod::Analytical)
        {
            // 解析的に逆運動学を解く
            return kinematics_functor_.solve_ik_analytical(pos);
        }

        // 準ニュートン法を使用して数値的に解く
        kinematics_functor_.target_pos = pos;
        auto [ret, rx, rcnt] = quasi_newton_method(ad_.evalute_func_scalar(), ad_.jacobian_func_row_vector(), joint_angles0);
        return rx;
    }

private:
    struct Kinematics
    {
        Kinematics(double l1, double l2):
            l1(l1), l2(l2) {}
        
        // 順運動学
        template<typename T>
        Eigen::Matrix<T,2,1> solve_fk(const Eigen::Matrix<T,2,1>& x)
        {
            Eigen::Matrix<T,2,1> pos;
            pos[0] = l1*cos(x[0]) + l2*cos(x[0]+x[1]);
            pos[1] = l1*sin(x[0]) + l2*sin(x[0]+x[1]);
            return pos;
        } 

        // 逆運動学
        Eigen::Vector2d solve_ik_analytical(Eigen::Vector2d pos)
        {
            Eigen::Vector2d angles;
            if (l1 + l2 < pos.norm())
                pos *= (l1 + l2) / pos.norm();

            const double xxyyllll = pos.squaredNorm() + l1 * l1 - l2 * l2;
            const double pos_norm = pos.norm();
            angles[0] = std::acos(xxyyllll / (2 * l1 * pos_norm)) + std::atan(pos[1] / pos[0]);
            angles[1] = std::atan((pos[1] - l1 * std::sin(angles[0])) / (pos[0] - l1 * std::cos(angles[0]))) - angles[0];

            return angles;
        }

        // 逆運動学を数値的に求める時の評価関数
        template<typename T>
        void eval_func(const Eigen::Matrix<T,2,1>& x, Eigen::Matrix<T,1,1>& y)
        {
            Eigen::Matrix<T,2,1> diff = target_pos - solve_fk(x);
            y[0] = diff.dot(diff);
        }

        Eigen::Vector2d target_pos;

        const double l1;
        const double l2;
    };

    IkSolveMethod method_;
    Kinematics kinematics_functor_;
    AutoDiffAdaptor<Kinematics, Eigen::VectorXd, double, 2, 1> ad_;
};

}
```


-------------------------------

Updated on 2022-10-22 at 22:05:50 +0900
