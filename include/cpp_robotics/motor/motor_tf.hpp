#pragma once

#include "./dc_motor_param.hpp"
#include "../system/transfer_function.hpp"

namespace cpp_robotics
{

static TransferFunction<0, 2> make_motor_vel_tf(const DCMotorParam &motor, const double dt)
{
    return TransferFunction<0, 2>({motor.torque_constant}, {motor.inductance*motor.rotor_inertia, motor.resistance*motor.rotor_inertia, motor.torque_constant*motor.back_emf_constance}, dt);
}

static TransferFunction<0, 3> make_motor_pos_tf(const DCMotorParam &motor, const double dt)
{
    auto vel_tf = make_motor_vel_tf(motor, dt);
    return TransferFunction<0, 3>(vel_tf.num_array, std::array{vel_tf.den_array[0], vel_tf.den_array[1], vel_tf.den_array[2], 0.0}, dt);
}

static TransferFunction<0, 2> make_geared_motor_vel_tf(const DCGearedMotorParam &geared_motor, const double dt)
{
    auto &motor = geared_motor.motor;
    auto &gear_head = geared_motor.gear_head;
    return TransferFunction<0, 2>({motor.torque_constant * gear_head.ratio }, {motor.inductance*motor.rotor_inertia, motor.resistance*motor.rotor_inertia, motor.torque_constant*motor.back_emf_constance}, dt);
}

static TransferFunction<0, 3> make_geared_motor_pos_tf(const DCGearedMotorParam &geared_motor, const double dt)
{
    auto vel_tf = make_geared_motor_vel_tf(geared_motor, dt);
    return TransferFunction<0, 3>(vel_tf.num_array, std::array{vel_tf.den_array[0], vel_tf.den_array[1], vel_tf.den_array[2], 0.0}, dt);
}

}