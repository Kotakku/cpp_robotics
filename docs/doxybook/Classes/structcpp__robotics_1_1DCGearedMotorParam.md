---
title: cpp_robotics::DCGearedMotorParam

---

# cpp_robotics::DCGearedMotorParam






`#include <dc_motor_param.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| constexpr | **[DCGearedMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCGearedMotorParam/#function-dcgearedmotorparam)**([Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt) voltage_, [DCMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/) motor_, [GearHeadParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1GearHeadParam/) gear_head_, const double optional_gear_ratio_ =1) |
| constexpr [Rpm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-rpm) | **[calcu_gear_head_steady_free_velocity](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCGearedMotorParam/#function-calcu-gear-head-steady-free-velocity)**([Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt) v) const |
| constexpr [Rpm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-rpm) | **[calcu_endpoint_steady_free_velocity](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCGearedMotorParam/#function-calcu-endpoint-steady-free-velocity)**([Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt) v) const |
| constexpr [AngularAcceleration](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-angularacceleration) | **[calcu_endpoint_max_angular_accleleration](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCGearedMotorParam/#function-calcu-endpoint-max-angular-accleleration)**([Inertia](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-inertia) optional_inertina =0) const |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| const [Volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-volt) | **[voltage](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCGearedMotorParam/#variable-voltage)**  |
| const [DCMotorParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCMotorParam/) | **[motor](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCGearedMotorParam/#variable-motor)**  |
| const [GearHeadParam](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1GearHeadParam/) | **[gear_head](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCGearedMotorParam/#variable-gear-head)**  |
| const double | **[optional_gear_ratio](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1DCGearedMotorParam/#variable-optional-gear-ratio)**  |

## Public Functions Documentation

### function DCGearedMotorParam

```cpp
inline constexpr DCGearedMotorParam(
    Volt voltage_,
    DCMotorParam motor_,
    GearHeadParam gear_head_,
    const double optional_gear_ratio_ =1
)
```


### function calcu_gear_head_steady_free_velocity

```cpp
inline constexpr Rpm calcu_gear_head_steady_free_velocity(
    Volt v
) const
```


### function calcu_endpoint_steady_free_velocity

```cpp
inline constexpr Rpm calcu_endpoint_steady_free_velocity(
    Volt v
) const
```


### function calcu_endpoint_max_angular_accleleration

```cpp
inline constexpr AngularAcceleration calcu_endpoint_max_angular_accleleration(
    Inertia optional_inertina =0
) const
```


ギアヘッド(+追加のギア)の軸先が発生させられる最大の角加速度を計算する

optional_inertina: ギアヘッド(+追加のギア)の軸先の慣性モーメント 


## Public Attributes Documentation

### variable voltage

```cpp
const Volt voltage;
```


### variable motor

```cpp
const DCMotorParam motor;
```


### variable gear_head

```cpp
const GearHeadParam gear_head;
```


### variable optional_gear_ratio

```cpp
const double optional_gear_ratio;
```


-------------------------------

Updated on 2022-09-25 at 23:50:00 +0900