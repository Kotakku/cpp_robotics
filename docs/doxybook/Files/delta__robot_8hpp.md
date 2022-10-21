---
title: include/cpp_robotics/arm_ik/delta_robot.hpp

---

# include/cpp_robotics/arm_ik/delta_robot.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::DeltaRobotIk](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DeltaRobotIk/)** <br>デルタロボットの逆運動学  |




## Source code

```cpp
#pragma once

namespace cpp_robotics
{

class DeltaRobotIk
{
public:
    enum IkSolveMethod : uint8_t
    {
        Analytical,
        Numerical
    };
    DeltaRobotIk(double wb, double wp, double l1, double l2, IkSolveMethod method = IkSolveMethod::Analytical):
        method_(method), kinematics_functor_(wb, wp, l1, l2), ad_(kinematics_functor_){}

    Eigen::Vector3d solve_fk(Eigen::Vector3d joint_angles)
    {

    }

    Eigen::Vector3d solve_ik(Eigen::Vector3d pos, Eigen::Vector3d joint_angles0 = Eigen::Vector3d::Zero())
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
        Kinematics(double wb, double wp, double l1, double l2):
            wb(wb), wp(wp), l1(l1), l2(l2) {}
        
        // 順運動学
        template<typename T>
        Eigen::Matrix<T,3,1> solve_fk(const Eigen::Matrix<T,3,1>& angles)
        {
            Eigen::Matrix<T,3,1> pos;
            // Todo
            return pos;
        } 

        // 逆運動学
        Eigen::Vector3d solve_ik_analytical(Eigen::Vector3d pos)
        {
            Eigen::Vector3d angles;
            // Todo
            return angles;
        }

        // 逆運動学を数値的に求める時の評価関数
        template<typename T>
        void eval_func(const Eigen::Matrix<T,3,1>& x, Eigen::Matrix<T,1,1>& y)
        {
            Eigen::Matrix<T,3,1> diff = target_pos - solve_fk(x);
            y[0] = diff.dot(diff);
        }

        Eigen::Vector3d target_pos;
        
        const double wb;
        const double wp;
        const double l1;
        const double l2;
    };

    IkSolveMethod method_;
    Kinematics kinematics_functor_;
    AutoDiffAdaptor<Kinematics, Eigen::VectorXd, double, 3, 1> ad_;
};

}
```


-------------------------------

Updated on 2022-10-21 at 10:30:14 +0900
