#pragma once

#include "cpp_robotics/unit.hpp"
#include <cmath>

namespace cpp_robotics
{

inline namespace unit
{
using TorqueConstant = unit_assem::unit_div<Torque, Ampere>::unit;
using BackEmfConstant = unit_assem::unit_div<Volt, AngularVelocity>::unit;
using FrictionConstant = unit_assem::unit_mul<Torque, Second>::unit;
}

GENERATE_UNIT_SUFFIX(cpp_robotics::TorqueConstant, Nm_per_A)
GENERATE_UNIT_SUFFIX(cpp_robotics::BackEmfConstant, Vs_per_rad)
GENERATE_UNIT_SUFFIX(cpp_robotics::FrictionConstant, Nms)

/**
 * @brief DCモーターモデル
 * 
 */
struct DCMotorParam
{
    const Volt nominal_voltage;               // 公称電圧[V]
    const Rpm free_speed;                     // 無負荷時回転数[rpm]
    const Ampere free_current;                // 無負荷時電流[A]
    const Ohm resistance;                     // 電機子抵抗[ohm]             (公称電圧 / ストール電流)
    const Henry inductance;                   // 電機子インダクタンス[H]
    const TorqueConstant torque_constant;     // トルク定数[Nm/A]            (ストールトルク)/(ストール電流 - 無負荷電流)
    const BackEmfConstant back_emf_constance; // 逆気電力定数[V/(rad/s)]      (公称電圧 - 抵抗*無負荷電流)/無負荷回転数[rad/s]
    const FrictionConstant friction_constant; // 粘性係数[Nms]               (トルク損失/無負荷回転数[rad/s]) トルク損失 = 無負荷時電流*トルク定数
    const Inertia rotor_inertia;              // ロータ慣性モーメント[kgm^2]
    const Second time_constant;               // 電気的時定数[s]             (インダクタンス/抵抗)

    constexpr DCMotorParam(Volt nominal_voltage, Rpm free_speed, Ampere free_current, Ohm Rm, Henry Lm, TorqueConstant Kt, BackEmfConstant Ke, Inertia Im, Second curr_set_time = 0.1f):
        nominal_voltage(nominal_voltage),
        free_speed(free_speed),
        free_current(free_current),
        resistance(Rm),
        inductance(Lm),
        torque_constant(Kt),
        back_emf_constance(Ke),
        friction_constant((free_current*torque_constant) / (AngularVelocity)(free_speed)),
        rotor_inertia(Im),
        time_constant(inductance/resistance)
    {
        set_current_setting_time(curr_set_time);
    }
    constexpr DCMotorParam(const DCMotorParam&) = default;

    constexpr void set_current_setting_time(Second Tc)
    {
        if((double)Tc > 0.0f)
            current_setting_time_ = Tc;
        corner_frequency_ = 3.0f / current_setting_time_;
        current_p_gain_base_ = (inductance*corner_frequency_).value();
        current_i_gain_base_ = (resistance*corner_frequency_).value();
    }

    constexpr Rpm calcu_steady_free_velocity(Volt v) const
    {
        return free_speed * ((double)v / (double)nominal_voltage);
    }

    constexpr Ampere calcu_stall_current(Volt v) const
    {
        return v / resistance;
    }

    constexpr Torque calcu_stall_torque(Volt v) const
    {
        return calcu_stall_current(v) * torque_constant;
    }

    constexpr AngularAcceleration calcu_max_free_angular_acceleration(Volt v) const
    {
        return calcu_stall_torque(v) / rotor_inertia;
    }

    constexpr Second get_Tm() const { return time_constant; }
    constexpr AngularVelocity get_Wi() const { return corner_frequency_; }
    constexpr double get_Kip(Volt volt) const { return current_p_gain_base_ / volt.value(); }
    constexpr double get_Kii(Volt volt) const { return current_i_gain_base_ / volt.value(); }

private:
    Second current_setting_time_ = 0.1_s;
    AngularVelocity corner_frequency_ = 0;
    double current_p_gain_base_ = 0;
    double current_i_gain_base_ = 0;
};

/**
 * @brief ギアヘッドモデル
 * 
 */
struct GearHeadParam
{
    const double ratio;
    const double efficiency;
    constexpr GearHeadParam(double ratio_, double efficiency_):
        ratio(ratio_), efficiency(efficiency_) {}
};

/**
 * @brief ギアヘッド付きDCモーターモデル
 * 
 */
struct DCGearedMotorParam
{
    constexpr DCGearedMotorParam(Volt voltage_, DCMotorParam motor_, GearHeadParam gear_head_, const double optional_gear_ratio_ = 1):
        voltage(voltage_),
        motor(motor_),
        gear_head(gear_head_),
        optional_gear_ratio(optional_gear_ratio_)
    {

    }

    constexpr Rpm calcu_gear_head_steady_free_velocity(Volt v) const
    {
        return motor.calcu_steady_free_velocity(v) * gear_head.ratio;
    }

    constexpr Rpm calcu_endpoint_steady_free_velocity(Volt v) const
    {
        return calcu_gear_head_steady_free_velocity(v) * optional_gear_ratio;
    }
    
    /**
     * ギアヘッド(+追加のギア)の軸先が発生させられる最大の角加速度を計算する
     * 
     * optional_inertina: ギアヘッド(+追加のギア)の軸先の慣性モーメント
     **/
    constexpr AngularAcceleration calcu_endpoint_max_angular_accleleration(Inertia optional_inertina = 0) const
    {
        return motor.calcu_stall_torque(voltage) / (motor.rotor_inertia + (optional_inertina * std::pow(gear_head.ratio*optional_gear_ratio, 2))) * gear_head.ratio;
    }

    const Volt voltage;
    const DCMotorParam motor;
    const GearHeadParam gear_head;
    const double optional_gear_ratio;
};

inline constexpr DCMotorParam generate_mabuchi_motor_param(
    Volt nominal_voltage,  // 公称電圧[V]
    Rpm free_speed,        // 無負荷時回転数[rpm]
    Ampere free_current,   // 無負荷時電流[A]
    Torque stall_torque,   // ストールトルク[Nm]
    Ampere stall_current,  // ストール電流[A]
    Henry inductance,      // 電機子インダクタンス[H] (計測する)
    Inertia rotor_inertia  // ロータ慣性モーメント[kgm^2] (計測する)
)
{
    const auto R = nominal_voltage/stall_current;
    return DCMotorParam(
        nominal_voltage,
        free_speed,
        free_current,
        R,
        inductance,
        stall_torque / (stall_current - free_current),
        (nominal_voltage - R*free_current) / (AngularVelocity)(free_speed),
        rotor_inertia
    );
}

inline constexpr DCMotorParam generate_maxon_brush_motor_param(
    Volt nominal_voltage,  // 公称電圧[V]
    Rpm free_speed,        // 無負荷時回転数[rpm]
    Ampere free_current,   // 無負荷時電流[A]
    Ohm resistance,        // 電機子抵抗[ohm]
    Henry inductance,      // 電機子インダクタンス[H]
    TorqueConstant Kt,     // トルク定数[Nm/A]
    Inertia rotor_inertia  // ロータ慣性モーメント[kgm^2] (計測する)
)
{
    return DCMotorParam(
        nominal_voltage,
        free_speed,
        free_current,
        resistance,
        inductance,
        Kt,
        (nominal_voltage - resistance*free_current) / (AngularVelocity)(free_speed),
        rotor_inertia
    );
}

}
