---
title: cpp_robotics::unit
summary: 単位系 

---

# cpp_robotics::unit

単位系 

## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics::unit::prefix](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/)**  |
| **[cpp_robotics::unit::tag](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1tag/)**  |
| **[cpp_robotics::unit::unit_dimention](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[cpp_robotics::unit::Prefix](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/)** <br>単位系接頭辞クラス  |
| class | **[cpp_robotics::unit::Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)** <br>単位クラス  |
| struct | **[cpp_robotics::unit::UnitType](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1UnitType/)** <br>SI単位系次元定義クラス  |

## Types

|                | Name           |
| -------------- | -------------- |
| enum| **[UnitIndex](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#enum-unitindex)** { MetereIdx, KiloGramIdx, SecondIdx, AmpereIdx, KelvinIdx, MoleIdx, CandelaIdx} |
| using unit_assem::unit_div< [Torque](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-torque), [Ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-ampere) >::unit | **[TorqueConstant](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-torqueconstant)**  |
| using unit_assem::unit_div< [Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt), [AngularVelocity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-angularvelocity) >::unit | **[BackEmfConstant](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-backemfconstant)**  |
| using unit_assem::unit_mul< [Torque](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-torque), [Second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-second) >::unit | **[FrictionConstant](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-frictionconstant)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-second), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-second)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-second), [prefix::milli](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-milli) > | **[MilliSecond](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-millisecond)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-second), [prefix::micro](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-micro) > | **[MicroSecond](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-microsecond)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::metere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-metere), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Meter](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-meter)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::metere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-metere), [prefix::milli](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-milli) > | **[MilliMeter](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-millimeter)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::metere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-metere), [prefix::micro](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-micro) > | **[MicroMeter](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-micrometer)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::metere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-metere), [prefix::centi](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-centi) > | **[CentiMeter](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-centimeter)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::kilogram](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-kilogram), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[KiloGram](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-kilogram)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::kilogram](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-kilogram), [prefix::milli](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-milli) > | **[Gram](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-gram)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::watt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-watt), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Watt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-watt)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::watt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-watt), [prefix::kilo](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-kilo) > | **[KiloWatt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-kilowatt)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::newton](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-newton), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Newton](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-newton)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::newton](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-newton), [prefix::kilo](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-kilo) > | **[KiloNewton](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-kilonewton)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::pascal](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-pascal), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Pascal](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-pascal)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::pascal](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-pascal), [prefix::kilo](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-kilo) > | **[KiloPascal](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-kilopascal)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::hertz](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-hertz), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Hertz](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-hertz)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::area](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-area), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Area](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-area)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::volume](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-volume), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Volume](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-volume)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::velocity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-velocity), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Velocity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-velocity)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::acceleration](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-acceleration), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Acceleration](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-acceleration)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::dencity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-dencity), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Dencity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-dencity)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::torque](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-torque), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Torque](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-torque)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::inertia](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-inertia), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Inertia](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-inertia)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-ampere), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-ampere)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-ampere), [prefix::milli](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-milli) > | **[MilliAmpere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-milliampere)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-volt), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-volt)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-volt), [prefix::milli](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-milli) > | **[MilliVolt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-millivolt)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::ohm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-ohm), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Ohm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-ohm)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::ohm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-ohm), [prefix::milli](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-milli) > | **[MilliOhm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-milliohm)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::henry](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-henry), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Henry](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-henry)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::henry](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-henry), [prefix::milli](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-milli) > | **[MilliHenry](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-millihenry)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::farad](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-farad), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[Farad](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-farad)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::farad](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-farad), [prefix::milli](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-milli) > | **[MilliFarad](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-millifarad)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::farad](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-farad), [prefix::micro](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-micro) > | **[MicroFarad](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-microfarad)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::farad](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-farad), [prefix::nano](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-nano) > | **[NanoFarad](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-nanofarad)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::angle](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-angle), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none), tag::angle::radian > | **[Radian](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-radian)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::angle](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-angle), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none), tag::angle::degree > | **[Degree](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-degree)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::angular_velocity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-angular-velocity), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none), tag::angular_vel::rad_per_sec > | **[AngularVelocity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-angularvelocity)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::angular_velocity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-angular-velocity), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none), tag::angular_vel::rps > | **[Rps](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-rps)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::angular_velocity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-angular-velocity), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none), tag::angular_vel::rpm > | **[Rpm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-rpm)**  |
| using [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< double, [unit_dimention::angular_acceleration](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-angular-acceleration), [prefix::none](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1prefix/#using-none) > | **[AngularAcceleration](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#using-angularacceleration)**  |

## Functions

|                | Name           |
| -------------- | -------------- |
| template <class UnitDimType ,int FromTag,int ToTag,bool IsNormalTag =tag::is_normal_tag<FromTag>::value && tag::is_normal_tag<ToTag>::value\> <br>constexpr double | **[conv_factor](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#function-conv-factor)**() |
| template <typename T1 ,typename T2 ,class UnitDim ,class Prefix ,int Tag\> <br>constexpr auto | **[operator*](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#function-operator*)**(const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T1, UnitDim, [Prefix](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/), Tag > & l_value, const T2 & r_value) |
| template <typename T1 ,typename T2 ,class UnitDim ,class Prefix ,int Tag\> <br>constexpr auto | **[operator*](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#function-operator*)**(const T1 & l_value, const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T2, UnitDim, [Prefix](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/), Tag > & r_value) |
| template <typename T1 ,typename T2 ,class UnitDim ,class Prefix ,int Tag\> <br>constexpr auto | **[operator/](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#function-operator/)**(const T1 & l_value, const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T2, UnitDim, [Prefix](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/), Tag > & r_value) |
| template <typename T1 ,typename T2 ,class UnitDim ,class Prefix ,int Tag\> <br>constexpr auto | **[operator/](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#function-operator/)**(const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T1, UnitDim, [Prefix](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1Prefix/), Tag > & l_value, const T2 & r_value) |
| template <typename T1 ,class UnitDim1 ,class Prefix1 ,int Tag1,typename T2 ,class UnitDim2 ,class Prefix2 ,int Tag2\> <br>constexpr auto | **[operator*](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#function-operator*)**(const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T1, UnitDim1, Prefix1, Tag1 > & lhl, const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T2, UnitDim2, Prefix2, Tag2 > & rhl) |
| template <typename T1 ,class UnitDim1 ,class Prefix1 ,int Tag1,typename T2 ,class UnitDim2 ,class Prefix2 ,int Tag2\> <br>constexpr auto | **[operator/](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#function-operator/)**(const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T1, UnitDim1, Prefix1, Tag1 > & lhl, const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T2, UnitDim2, Prefix2, Tag2 > & rhl) |
| template <typename T ,class UnitDim ,class Prefix1 ,class Prefix2 ,int Tag\> <br>constexpr auto | **[operator+](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#function-operator+)**(const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T, UnitDim, Prefix1, Tag > & lhl, const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T, UnitDim, Prefix2, Tag > & rhl) |
| template <typename T ,class UnitDim ,class Prefix1 ,class Prefix2 ,int Tag\> <br>constexpr auto | **[operator-](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit/#function-operator-)**(const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T, UnitDim, Prefix1, Tag > & lhl, const [Unit](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1unit_1_1Unit/)< T, UnitDim, Prefix2, Tag > & rhl) |

## Types Documentation

### enum UnitIndex

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| MetereIdx | |   |
| KiloGramIdx | |   |
| SecondIdx | |   |
| AmpereIdx | |   |
| KelvinIdx | |   |
| MoleIdx | |   |
| CandelaIdx | |   |




### using TorqueConstant

```cpp
using cpp_robotics::unit::TorqueConstant = typedef unit_assem::unit_div<Torque, Ampere>::unit;
```


### using BackEmfConstant

```cpp
using cpp_robotics::unit::BackEmfConstant = typedef unit_assem::unit_div<Volt, AngularVelocity>::unit;
```


### using FrictionConstant

```cpp
using cpp_robotics::unit::FrictionConstant = typedef unit_assem::unit_mul<Torque, Second>::unit;
```


### using Second

```cpp
using cpp_robotics::unit::Second = typedef Unit<double, unit_dimention::second, prefix::none>;
```


### using MilliSecond

```cpp
using cpp_robotics::unit::MilliSecond = typedef Unit<double, unit_dimention::second, prefix::milli>;
```


### using MicroSecond

```cpp
using cpp_robotics::unit::MicroSecond = typedef Unit<double, unit_dimention::second, prefix::micro>;
```


### using Meter

```cpp
using cpp_robotics::unit::Meter = typedef Unit<double, unit_dimention::metere, prefix::none>;
```


### using MilliMeter

```cpp
using cpp_robotics::unit::MilliMeter = typedef Unit<double, unit_dimention::metere, prefix::milli>;
```


### using MicroMeter

```cpp
using cpp_robotics::unit::MicroMeter = typedef Unit<double, unit_dimention::metere, prefix::micro>;
```


### using CentiMeter

```cpp
using cpp_robotics::unit::CentiMeter = typedef Unit<double, unit_dimention::metere, prefix::centi>;
```


### using KiloGram

```cpp
using cpp_robotics::unit::KiloGram = typedef Unit<double, unit_dimention::kilogram, prefix::none>;
```


### using Gram

```cpp
using cpp_robotics::unit::Gram = typedef Unit<double, unit_dimention::kilogram, prefix::milli>;
```


### using Watt

```cpp
using cpp_robotics::unit::Watt = typedef Unit<double, unit_dimention::watt, prefix::none>;
```


### using KiloWatt

```cpp
using cpp_robotics::unit::KiloWatt = typedef Unit<double, unit_dimention::watt, prefix::kilo>;
```


### using Newton

```cpp
using cpp_robotics::unit::Newton = typedef Unit<double, unit_dimention::newton, prefix::none>;
```


### using KiloNewton

```cpp
using cpp_robotics::unit::KiloNewton = typedef Unit<double, unit_dimention::newton, prefix::kilo>;
```


### using Pascal

```cpp
using cpp_robotics::unit::Pascal = typedef Unit<double, unit_dimention::pascal, prefix::none>;
```


### using KiloPascal

```cpp
using cpp_robotics::unit::KiloPascal = typedef Unit<double, unit_dimention::pascal, prefix::kilo>;
```


### using Hertz

```cpp
using cpp_robotics::unit::Hertz = typedef Unit<double, unit_dimention::hertz, prefix::none>;
```


### using Area

```cpp
using cpp_robotics::unit::Area = typedef Unit<double, unit_dimention::area, prefix::none>;
```


### using Volume

```cpp
using cpp_robotics::unit::Volume = typedef Unit<double, unit_dimention::volume, prefix::none>;
```


### using Velocity

```cpp
using cpp_robotics::unit::Velocity = typedef Unit<double, unit_dimention::velocity, prefix::none>;
```


### using Acceleration

```cpp
using cpp_robotics::unit::Acceleration = typedef Unit<double, unit_dimention::acceleration, prefix::none>;
```


### using Dencity

```cpp
using cpp_robotics::unit::Dencity = typedef Unit<double, unit_dimention::dencity, prefix::none>;
```


### using Torque

```cpp
using cpp_robotics::unit::Torque = typedef Unit<double, unit_dimention::torque, prefix::none>;
```


### using Inertia

```cpp
using cpp_robotics::unit::Inertia = typedef Unit<double, unit_dimention::inertia, prefix::none>;
```


### using Ampere

```cpp
using cpp_robotics::unit::Ampere = typedef Unit<double, unit_dimention::ampere, prefix::none>;
```


### using MilliAmpere

```cpp
using cpp_robotics::unit::MilliAmpere = typedef Unit<double, unit_dimention::ampere, prefix::milli>;
```


### using Volt

```cpp
using cpp_robotics::unit::Volt = typedef Unit<double, unit_dimention::volt, prefix::none>;
```


### using MilliVolt

```cpp
using cpp_robotics::unit::MilliVolt = typedef Unit<double, unit_dimention::volt, prefix::milli>;
```


### using Ohm

```cpp
using cpp_robotics::unit::Ohm = typedef Unit<double, unit_dimention::ohm, prefix::none>;
```


### using MilliOhm

```cpp
using cpp_robotics::unit::MilliOhm = typedef Unit<double, unit_dimention::ohm, prefix::milli>;
```


### using Henry

```cpp
using cpp_robotics::unit::Henry = typedef Unit<double, unit_dimention::henry, prefix::none>;
```


### using MilliHenry

```cpp
using cpp_robotics::unit::MilliHenry = typedef Unit<double, unit_dimention::henry, prefix::milli>;
```


### using Farad

```cpp
using cpp_robotics::unit::Farad = typedef Unit<double, unit_dimention::farad, prefix::none>;
```


### using MilliFarad

```cpp
using cpp_robotics::unit::MilliFarad = typedef Unit<double, unit_dimention::farad, prefix::milli>;
```


### using MicroFarad

```cpp
using cpp_robotics::unit::MicroFarad = typedef Unit<double, unit_dimention::farad, prefix::micro>;
```


### using NanoFarad

```cpp
using cpp_robotics::unit::NanoFarad = typedef Unit<double, unit_dimention::farad, prefix::nano>;
```


### using Radian

```cpp
using cpp_robotics::unit::Radian = typedef Unit<double, unit_dimention::angle, prefix::none, tag::angle::radian>;
```


### using Degree

```cpp
using cpp_robotics::unit::Degree = typedef Unit<double, unit_dimention::angle, prefix::none, tag::angle::degree>;
```


### using AngularVelocity

```cpp
using cpp_robotics::unit::AngularVelocity = typedef Unit<double, unit_dimention::angular_velocity, prefix::none, tag::angular_vel::rad_per_sec>;
```


### using Rps

```cpp
using cpp_robotics::unit::Rps = typedef Unit<double, unit_dimention::angular_velocity, prefix::none, tag::angular_vel::rps>;
```


### using Rpm

```cpp
using cpp_robotics::unit::Rpm = typedef Unit<double, unit_dimention::angular_velocity, prefix::none, tag::angular_vel::rpm>;
```


### using AngularAcceleration

```cpp
using cpp_robotics::unit::AngularAcceleration = typedef Unit<double, unit_dimention::angular_acceleration, prefix::none>;
```



## Functions Documentation

### function conv_factor

```cpp
template <class UnitDimType ,
int FromTag,
int ToTag,
bool IsNormalTag =tag::is_normal_tag<FromTag>::value && tag::is_normal_tag<ToTag>::value>
constexpr double conv_factor()
```


### function operator*

```cpp
template <typename T1 ,
typename T2 ,
class UnitDim ,
class Prefix ,
int Tag>
constexpr auto operator*(
    const Unit< T1, UnitDim, Prefix, Tag > & l_value,
    const T2 & r_value
)
```


### function operator*

```cpp
template <typename T1 ,
typename T2 ,
class UnitDim ,
class Prefix ,
int Tag>
constexpr auto operator*(
    const T1 & l_value,
    const Unit< T2, UnitDim, Prefix, Tag > & r_value
)
```


### function operator/

```cpp
template <typename T1 ,
typename T2 ,
class UnitDim ,
class Prefix ,
int Tag>
constexpr auto operator/(
    const T1 & l_value,
    const Unit< T2, UnitDim, Prefix, Tag > & r_value
)
```


### function operator/

```cpp
template <typename T1 ,
typename T2 ,
class UnitDim ,
class Prefix ,
int Tag>
constexpr auto operator/(
    const Unit< T1, UnitDim, Prefix, Tag > & l_value,
    const T2 & r_value
)
```


### function operator*

```cpp
template <typename T1 ,
class UnitDim1 ,
class Prefix1 ,
int Tag1,
typename T2 ,
class UnitDim2 ,
class Prefix2 ,
int Tag2>
constexpr auto operator*(
    const Unit< T1, UnitDim1, Prefix1, Tag1 > & lhl,
    const Unit< T2, UnitDim2, Prefix2, Tag2 > & rhl
)
```


### function operator/

```cpp
template <typename T1 ,
class UnitDim1 ,
class Prefix1 ,
int Tag1,
typename T2 ,
class UnitDim2 ,
class Prefix2 ,
int Tag2>
constexpr auto operator/(
    const Unit< T1, UnitDim1, Prefix1, Tag1 > & lhl,
    const Unit< T2, UnitDim2, Prefix2, Tag2 > & rhl
)
```


### function operator+

```cpp
template <typename T ,
class UnitDim ,
class Prefix1 ,
class Prefix2 ,
int Tag>
constexpr auto operator+(
    const Unit< T, UnitDim, Prefix1, Tag > & lhl,
    const Unit< T, UnitDim, Prefix2, Tag > & rhl
)
```


### function operator-

```cpp
template <typename T ,
class UnitDim ,
class Prefix1 ,
class Prefix2 ,
int Tag>
constexpr auto operator-(
    const Unit< T, UnitDim, Prefix1, Tag > & lhl,
    const Unit< T, UnitDim, Prefix2, Tag > & rhl
)
```






-------------------------------

Updated on 2022-09-28 at 19:28:33 +0900