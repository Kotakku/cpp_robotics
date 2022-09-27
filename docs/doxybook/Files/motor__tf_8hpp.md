---
title: include/cpp_robotics/motor/motor_tf.hpp

---

# include/cpp_robotics/motor/motor_tf.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |




## Source code

```cpp
#pragma once

#include "./dc_motor_param.hpp"
#include "../system/transfer_function.hpp"

namespace cpp_robotics
{

static TransferFunction make_motor_vel_tf(const DCMotorParam &motor, const double dt)
{
    return TransferFunction({motor.torque_constant}, {motor.inductance*motor.rotor_inertia, motor.resistance*motor.rotor_inertia, motor.torque_constant*motor.back_emf_constance}, dt);
}

static TransferFunction make_motor_pos_tf(const DCMotorParam &motor, const double dt)
{
    auto vel_tf = make_motor_vel_tf(motor, dt);
    auto new_den = vel_tf.den_array();
    new_den.push_back(0);
    return TransferFunction(vel_tf.num_array(), new_den, dt);
}

static TransferFunction make_geared_motor_vel_tf(const DCGearedMotorParam &geared_motor, const double dt)
{
    auto &motor = geared_motor.motor;
    auto &gear_head = geared_motor.gear_head;
    return TransferFunction({motor.torque_constant * gear_head.ratio }, {motor.inductance*motor.rotor_inertia, motor.resistance*motor.rotor_inertia, motor.torque_constant*motor.back_emf_constance}, dt);
}

static TransferFunction make_geared_motor_pos_tf(const DCGearedMotorParam &geared_motor, const double dt)
{
    auto vel_tf = make_geared_motor_vel_tf(geared_motor, dt);
    auto new_den = vel_tf.den_array();
    new_den.push_back(0);
    return TransferFunction(vel_tf.num_array(), new_den, dt);
}

}
```


-------------------------------

Updated on 2022-09-28 at 01:12:56 +0900
