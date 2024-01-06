#pragma once

#include "cpp_robotics/arm_kinematics/arm_kinematics.hpp"

namespace cpp_robotics
{

class XY2LinkRobot : public ArmForwardKinematics<XY2LinkRobot>
{
public:
    XY2LinkRobot(double l1, double l2):
        ArmForwardKinematics<XY2LinkRobot>(2, 2), l1(l1), l2(l2) {}

    template<typename Vector>
    void forward_kinematics(const Vector& q, Vector& x)
    {
        x[0] = l1*cos(q[0]) + l2*cos(q[0]+q[1]);
        x[1] = l1*sin(q[0]) + l2*sin(q[0]+q[1]);
    } 

private:
    const double l1;
    const double l2;
};

}