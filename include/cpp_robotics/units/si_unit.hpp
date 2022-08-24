#pragma once

#include "./unit_core.hpp"

namespace cpp_robotics
{

inline namespace unit
{
namespace unit_dimention
{
    using no_dimention = UnitType<0, 0, 0, 0, 0, 0, 0>;

    // 基本単位
    using metere   = UnitType<1, 0, 0, 0, 0, 0, 0>;
    using kilogram = UnitType<0, 1, 0, 0, 0, 0, 0>;
    using second   = UnitType<0, 0, 1, 0, 0, 0, 0>;
    using ampere   = UnitType<0, 0, 0, 1, 0, 0, 0>;
    using kelvin   = UnitType<0, 0, 0, 0, 1, 0, 0>;
    using mole     = UnitType<0, 0, 0, 0, 0, 1, 0>;
    using candela  = UnitType<0, 0, 0, 0, 0, 0, 1>;

    using namespace unit_dim_assem;
    // 組立単位
    using area          = udim_pow<metere, 2>::unit;
    using volume        = udim_pow<metere, 3>::unit;
    using velocity      = udim_div<metere, second>::unit;
    using acceleration  = udim_div<velocity, second>::unit;
    using dencity       = udim_div<kilogram, volume>::unit;
    using angle         = udim_div<metere, metere>::unit;
    using hertz         = udim_inv<second>::unit;
    using newton        = udim_div<udim_mul<metere, kilogram>::unit, udim_pow<second, 2>::unit>::unit;
    using pascal        = udim_div<newton, area>::unit;
    using viscosity     = udim_mul<pascal, second>::unit;
    using joule         = udim_mul<newton, metere>::unit;
    using watt          = udim_div<joule, second>::unit;
    using volt          = udim_div<watt, ampere>::unit;
    using coulomb       = udim_mul<second, ampere>::unit;
    using farad         = udim_div<coulomb, volt>::unit;
    using ohm           = udim_div<volt, ampere>::unit;
    using weber         = udim_mul<volt, second>::unit;
    using henry         = udim_div<weber, ampere>::unit;
    using torque        = udim_mul<newton, metere>::unit;
    using inertia       = udim_mul<kilogram, area>::unit;
    using angular_velocity = udim_div<angle, second>::unit;
    using angular_acceleration = udim_div<angular_velocity, second>::unit;
    
}

using Second = Unit<double, unit_dimention::second, prefix::none>;
using MilliSecond = Unit<double, unit_dimention::second, prefix::milli>;
using MicroSecond = Unit<double, unit_dimention::second, prefix::micro>;
using Meter = Unit<double, unit_dimention::metere, prefix::none>;
using MilliMeter = Unit<double, unit_dimention::metere, prefix::milli>;
using MicroMeter = Unit<double, unit_dimention::metere, prefix::micro>;
using CentiMeter = Unit<double, unit_dimention::metere, prefix::centi>;
using KiloGram = Unit<double, unit_dimention::kilogram, prefix::none>;
using Gram = Unit<double, unit_dimention::kilogram, prefix::milli>;

using Watt = Unit<double, unit_dimention::watt, prefix::none>;
using KiloWatt = Unit<double, unit_dimention::watt, prefix::kilo>;
using Newton = Unit<double, unit_dimention::newton, prefix::none>;
using KiloNewton = Unit<double, unit_dimention::newton, prefix::kilo>;
using Pascal = Unit<double, unit_dimention::pascal, prefix::none>;
using KiloPascal = Unit<double, unit_dimention::pascal, prefix::kilo>;
using Hertz = Unit<double, unit_dimention::hertz, prefix::none>;

// 
using Area = Unit<double, unit_dimention::area, prefix::none>;
using Volume = Unit<double, unit_dimention::volume, prefix::none>;
using Velocity = Unit<double, unit_dimention::velocity, prefix::none>;
using Acceleration = Unit<double, unit_dimention::acceleration, prefix::none>;
using Dencity = Unit<double, unit_dimention::dencity, prefix::none>;
using Torque = Unit<double, unit_dimention::torque, prefix::none>;
using Inertia = Unit<double, unit_dimention::inertia, prefix::none>;

// 電気系
using Ampere = Unit<double, unit_dimention::ampere, prefix::none>;
using MilliAmpere = Unit<double, unit_dimention::ampere, prefix::milli>;
using Volt = Unit<double, unit_dimention::volt, prefix::none>;
using MilliVolt = Unit<double, unit_dimention::volt, prefix::milli>;
using Ohm = Unit<double, unit_dimention::ohm, prefix::none>;
using MilliOhm = Unit<double, unit_dimention::ohm, prefix::milli>;
using Henry = Unit<double, unit_dimention::henry, prefix::none>;
using MilliHenry = Unit<double, unit_dimention::henry, prefix::milli>;
using Farad = Unit<double, unit_dimention::farad, prefix::none>;
using MilliFarad = Unit<double, unit_dimention::farad, prefix::milli>;
using MicroFarad = Unit<double, unit_dimention::farad, prefix::micro>;
using NanoFarad = Unit<double, unit_dimention::farad, prefix::nano>;

// 角度、角速度
using Radian = Unit<double, unit_dimention::angle, prefix::none, tag::angle::radian>;
using Degree = Unit<double, unit_dimention::angle, prefix::none, tag::angle::degree>;
using AngularVelocity = Unit<double, unit_dimention::angular_velocity, prefix::none, tag::angular_vel::rad_per_sec>;
using Rps = Unit<double, unit_dimention::angular_velocity, prefix::none, tag::angular_vel::rps>;
using Rpm = Unit<double, unit_dimention::angular_velocity, prefix::none, tag::angular_vel::rpm>;

using AngularAcceleration = Unit<double, unit_dimention::angular_acceleration, prefix::none>;

GENERATE_CONV_FACTOR(unit_dimention::angle, tag::angle::radian, tag::angle::degree, 180.0f/M_PI)
GENERATE_CONV_FACTOR(unit_dimention::angle, tag::angle::degree, tag::angle::radian, M_PI/180.0f)

GENERATE_CONV_FACTOR(unit_dimention::angular_velocity, tag::angular_vel::rad_per_sec, tag::angular_vel::rps, 1.0f/(2*M_PI))
GENERATE_CONV_FACTOR(unit_dimention::angular_velocity, tag::angular_vel::rad_per_sec, tag::angular_vel::rpm, 30.0f/M_PI)
GENERATE_CONV_FACTOR(unit_dimention::angular_velocity, tag::angular_vel::rps, tag::angular_vel::rad_per_sec, (2*M_PI))
GENERATE_CONV_FACTOR(unit_dimention::angular_velocity, tag::angular_vel::rps, tag::angular_vel::rpm, 60.0f)
GENERATE_CONV_FACTOR(unit_dimention::angular_velocity, tag::angular_vel::rpm, tag::angular_vel::rps, 1/60.0f)
GENERATE_CONV_FACTOR(unit_dimention::angular_velocity, tag::angular_vel::rpm, tag::angular_vel::rad_per_sec, M_PI/30.0f)
}
}

// suffix

GENERATE_UNIT_SUFFIX(cpp_robotics::Second, s)
GENERATE_UNIT_SUFFIX(cpp_robotics::MilliSecond, ms)
GENERATE_UNIT_SUFFIX(cpp_robotics::MicroSecond, us)
GENERATE_UNIT_PFX_SUFFIX(cpp_robotics::Meter, prefix::kilo, km)
GENERATE_UNIT_SUFFIX(cpp_robotics::Meter, m)
GENERATE_UNIT_SUFFIX(cpp_robotics::CentiMeter, cm)
GENERATE_UNIT_SUFFIX(cpp_robotics::MilliMeter, mm)
GENERATE_UNIT_SUFFIX(cpp_robotics::KiloGram, kg)
GENERATE_UNIT_SUFFIX(cpp_robotics::Gram, g)

//
GENERATE_UNIT_SUFFIX(cpp_robotics::Watt, W)
GENERATE_UNIT_SUFFIX(cpp_robotics::KiloWatt, kW)

#ifdef UNIT_NEWTON_ENABLE 
// "_N"って名前のマクロが定義されてるのでそのままだと使えない
#undef _N
GENERATE_UNIT_SUFFIX(cpp_robotics::Newton, N) 
#endif // UNIT_NEWTON_ENABLE

GENERATE_UNIT_SUFFIX(cpp_robotics::KiloNewton, kN)
GENERATE_UNIT_SUFFIX(cpp_robotics::Pascal, Pa)
GENERATE_UNIT_SUFFIX(cpp_robotics::KiloPascal, kPa)
GENERATE_UNIT_SUFFIX(cpp_robotics::Torque, Nm)
GENERATE_UNIT_PFX_SUFFIX(cpp_robotics::Torque, prefix::milli, mmNm)

// 回路
GENERATE_UNIT_SUFFIX(cpp_robotics::Ampere, A)
GENERATE_UNIT_SUFFIX(cpp_robotics::MilliAmpere, mA)
GENERATE_UNIT_SUFFIX(cpp_robotics::Volt, V)
GENERATE_UNIT_SUFFIX(cpp_robotics::MilliVolt, mV)
GENERATE_UNIT_SUFFIX(cpp_robotics::Ohm, ohm)
GENERATE_UNIT_SUFFIX(cpp_robotics::MilliOhm, mohm)
GENERATE_UNIT_SUFFIX(cpp_robotics::Henry, H)
GENERATE_UNIT_SUFFIX(cpp_robotics::MilliHenry, mH)
GENERATE_UNIT_SUFFIX(cpp_robotics::Farad, F)
GENERATE_UNIT_SUFFIX(cpp_robotics::MilliFarad, mF)
GENERATE_UNIT_SUFFIX(cpp_robotics::MicroFarad, uF)
GENERATE_UNIT_SUFFIX(cpp_robotics::NanoFarad, nF)

// 角度、角速度
GENERATE_UNIT_SUFFIX(cpp_robotics::Radian, rad)
GENERATE_UNIT_SUFFIX(cpp_robotics::Degree, deg)
GENERATE_UNIT_SUFFIX(cpp_robotics::AngularVelocity, rad_per_sec)
GENERATE_UNIT_SUFFIX(cpp_robotics::Rpm, rpm)
GENERATE_UNIT_SUFFIX(cpp_robotics::Rps, rps)
