---
title: cpp_robotics::DCMotorParam
summary: DCモーターモデル 

---

# cpp_robotics::DCMotorParam



DCモーターモデル 


`#include <dc_motor_param.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| constexpr | **[DCMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#function-dcmotorparam)**([Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt) nominal_voltage, [Rpm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-rpm) free_speed, [Ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-ampere) free_current, [Ohm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-ohm) Rm, [Henry](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-henry) Lm, [TorqueConstant](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-torqueconstant) Kt, [BackEmfConstant](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-backemfconstant) Ke, [Inertia](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-inertia) Im, [Second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-second) curr_set_time =0.1f) |
| constexpr | **[DCMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#function-dcmotorparam)**(const [DCMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/) & ) =default |
| constexpr void | **[set_current_setting_time](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#function-set-current-setting-time)**([Second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-second) Tc) |
| constexpr [Rpm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-rpm) | **[calcu_steady_free_velocity](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#function-calcu-steady-free-velocity)**([Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt) v) const |
| constexpr [Ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-ampere) | **[calcu_stall_current](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#function-calcu-stall-current)**([Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt) v) const |
| constexpr [Torque](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-torque) | **[calcu_stall_torque](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#function-calcu-stall-torque)**([Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt) v) const |
| constexpr [AngularAcceleration](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-angularacceleration) | **[calcu_max_free_angular_acceleration](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#function-calcu-max-free-angular-acceleration)**([Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt) v) const |
| constexpr [Second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-second) | **[get_Tm](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#function-get-tm)**() const |
| constexpr [AngularVelocity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-angularvelocity) | **[get_Wi](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#function-get-wi)**() const |
| constexpr double | **[get_Kip](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#function-get-kip)**([Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt) volt) const |
| constexpr double | **[get_Kii](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#function-get-kii)**([Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt) volt) const |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| const [Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt) | **[nominal_voltage](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#variable-nominal-voltage)**  |
| const [Rpm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-rpm) | **[free_speed](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#variable-free-speed)**  |
| const [Ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-ampere) | **[free_current](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#variable-free-current)**  |
| const [Ohm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-ohm) | **[resistance](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#variable-resistance)**  |
| const [Henry](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-henry) | **[inductance](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#variable-inductance)**  |
| const [TorqueConstant](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-torqueconstant) | **[torque_constant](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#variable-torque-constant)**  |
| const [BackEmfConstant](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-backemfconstant) | **[back_emf_constance](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#variable-back-emf-constance)**  |
| const [FrictionConstant](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-frictionconstant) | **[friction_constant](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#variable-friction-constant)**  |
| const [Inertia](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-inertia) | **[rotor_inertia](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#variable-rotor-inertia)**  |
| const [Second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-second) | **[time_constant](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/#variable-time-constant)**  |

## Public Functions Documentation

### function DCMotorParam

```cpp
inline constexpr DCMotorParam(
    Volt nominal_voltage,
    Rpm free_speed,
    Ampere free_current,
    Ohm Rm,
    Henry Lm,
    TorqueConstant Kt,
    BackEmfConstant Ke,
    Inertia Im,
    Second curr_set_time =0.1f
)
```


### function DCMotorParam

```cpp
constexpr DCMotorParam(
    const DCMotorParam & 
) =default
```


### function set_current_setting_time

```cpp
inline constexpr void set_current_setting_time(
    Second Tc
)
```


### function calcu_steady_free_velocity

```cpp
inline constexpr Rpm calcu_steady_free_velocity(
    Volt v
) const
```


### function calcu_stall_current

```cpp
inline constexpr Ampere calcu_stall_current(
    Volt v
) const
```


### function calcu_stall_torque

```cpp
inline constexpr Torque calcu_stall_torque(
    Volt v
) const
```


### function calcu_max_free_angular_acceleration

```cpp
inline constexpr AngularAcceleration calcu_max_free_angular_acceleration(
    Volt v
) const
```


### function get_Tm

```cpp
inline constexpr Second get_Tm() const
```


### function get_Wi

```cpp
inline constexpr AngularVelocity get_Wi() const
```


### function get_Kip

```cpp
inline constexpr double get_Kip(
    Volt volt
) const
```


### function get_Kii

```cpp
inline constexpr double get_Kii(
    Volt volt
) const
```


## Public Attributes Documentation

### variable nominal_voltage

```cpp
const Volt nominal_voltage;
```


### variable free_speed

```cpp
const Rpm free_speed;
```


### variable free_current

```cpp
const Ampere free_current;
```


### variable resistance

```cpp
const Ohm resistance;
```


### variable inductance

```cpp
const Henry inductance;
```


### variable torque_constant

```cpp
const TorqueConstant torque_constant;
```


### variable back_emf_constance

```cpp
const BackEmfConstant back_emf_constance;
```


### variable friction_constant

```cpp
const FrictionConstant friction_constant;
```


### variable rotor_inertia

```cpp
const Inertia rotor_inertia;
```


### variable time_constant

```cpp
const Second time_constant;
```


-------------------------------

Updated on 2022-10-22 at 22:05:49 +0900