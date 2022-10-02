---
title: cpp_robotics::unit::unit_dimention

---

# cpp_robotics::unit::unit_dimention



## Types

|                | Name           |
| -------------- | -------------- |
| using [UnitType](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1UnitType/)< 0, 0, 0, 0, 0, 0, 0 > | **[no_dimention](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-no-dimention)**  |
| using [UnitType](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1UnitType/)< 1, 0, 0, 0, 0, 0, 0 > | **[metere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-metere)**  |
| using [UnitType](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1UnitType/)< 0, 1, 0, 0, 0, 0, 0 > | **[kilogram](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-kilogram)**  |
| using [UnitType](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1UnitType/)< 0, 0, 1, 0, 0, 0, 0 > | **[second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-second)**  |
| using [UnitType](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1UnitType/)< 0, 0, 0, 1, 0, 0, 0 > | **[ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-ampere)**  |
| using [UnitType](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1UnitType/)< 0, 0, 0, 0, 1, 0, 0 > | **[kelvin](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-kelvin)**  |
| using [UnitType](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1UnitType/)< 0, 0, 0, 0, 0, 1, 0 > | **[mole](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-mole)**  |
| using [UnitType](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1unit_1_1UnitType/)< 0, 0, 0, 0, 0, 0, 1 > | **[candela](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-candela)**  |
| using udim_pow< [metere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-metere), 2 >::unit | **[area](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-area)**  |
| using udim_pow< [metere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-metere), 3 >::unit | **[volume](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-volume)**  |
| using udim_div< [metere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-metere), [second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-second) >::unit | **[velocity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-velocity)**  |
| using udim_div< [velocity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-velocity), [second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-second) >::unit | **[acceleration](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-acceleration)**  |
| using udim_div< [kilogram](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-kilogram), [volume](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-volume) >::unit | **[dencity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-dencity)**  |
| using udim_div< [metere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-metere), [metere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-metere) >::unit | **[angle](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-angle)**  |
| using udim_inv< [second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-second) >::unit | **[hertz](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-hertz)**  |
| using udim_div< udim_mul< [metere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-metere), [kilogram](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-kilogram) >::unit, udim_pow< [second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-second), 2 >::unit >::unit | **[newton](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-newton)**  |
| using udim_div< [newton](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-newton), [area](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-area) >::unit | **[pascal](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-pascal)**  |
| using udim_mul< [pascal](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-pascal), [second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-second) >::unit | **[viscosity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-viscosity)**  |
| using udim_mul< [newton](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-newton), [metere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-metere) >::unit | **[joule](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-joule)**  |
| using udim_div< [joule](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-joule), [second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-second) >::unit | **[watt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-watt)**  |
| using udim_div< [watt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-watt), [ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-ampere) >::unit | **[volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-volt)**  |
| using udim_mul< [second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-second), [ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-ampere) >::unit | **[coulomb](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-coulomb)**  |
| using udim_div< [coulomb](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-coulomb), [volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-volt) >::unit | **[farad](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-farad)**  |
| using udim_div< [volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-volt), [ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-ampere) >::unit | **[ohm](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-ohm)**  |
| using udim_mul< [volt](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-volt), [second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-second) >::unit | **[weber](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-weber)**  |
| using udim_div< [weber](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-weber), [ampere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-ampere) >::unit | **[henry](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-henry)**  |
| using udim_mul< [newton](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-newton), [metere](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-metere) >::unit | **[torque](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-torque)**  |
| using udim_mul< [kilogram](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-kilogram), [area](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-area) >::unit | **[inertia](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-inertia)**  |
| using udim_div< [angle](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-angle), [second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-second) >::unit | **[angular_velocity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-angular-velocity)**  |
| using udim_div< [angular_velocity](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-angular-velocity), [second](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-second) >::unit | **[angular_acceleration](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics_1_1unit_1_1unit__dimention/#using-angular-acceleration)**  |

## Types Documentation

### using no_dimention

```cpp
using cpp_robotics::unit::unit_dimention::no_dimention = typedef UnitType<0, 0, 0, 0, 0, 0, 0>;
```


### using metere

```cpp
using cpp_robotics::unit::unit_dimention::metere = typedef UnitType<1, 0, 0, 0, 0, 0, 0>;
```


### using kilogram

```cpp
using cpp_robotics::unit::unit_dimention::kilogram = typedef UnitType<0, 1, 0, 0, 0, 0, 0>;
```


### using second

```cpp
using cpp_robotics::unit::unit_dimention::second = typedef UnitType<0, 0, 1, 0, 0, 0, 0>;
```


### using ampere

```cpp
using cpp_robotics::unit::unit_dimention::ampere = typedef UnitType<0, 0, 0, 1, 0, 0, 0>;
```


### using kelvin

```cpp
using cpp_robotics::unit::unit_dimention::kelvin = typedef UnitType<0, 0, 0, 0, 1, 0, 0>;
```


### using mole

```cpp
using cpp_robotics::unit::unit_dimention::mole = typedef UnitType<0, 0, 0, 0, 0, 1, 0>;
```


### using candela

```cpp
using cpp_robotics::unit::unit_dimention::candela = typedef UnitType<0, 0, 0, 0, 0, 0, 1>;
```


### using area

```cpp
using cpp_robotics::unit::unit_dimention::area = typedef udim_pow<metere, 2>::unit;
```


### using volume

```cpp
using cpp_robotics::unit::unit_dimention::volume = typedef udim_pow<metere, 3>::unit;
```


### using velocity

```cpp
using cpp_robotics::unit::unit_dimention::velocity = typedef udim_div<metere, second>::unit;
```


### using acceleration

```cpp
using cpp_robotics::unit::unit_dimention::acceleration = typedef udim_div<velocity, second>::unit;
```


### using dencity

```cpp
using cpp_robotics::unit::unit_dimention::dencity = typedef udim_div<kilogram, volume>::unit;
```


### using angle

```cpp
using cpp_robotics::unit::unit_dimention::angle = typedef udim_div<metere, metere>::unit;
```


### using hertz

```cpp
using cpp_robotics::unit::unit_dimention::hertz = typedef udim_inv<second>::unit;
```


### using newton

```cpp
using cpp_robotics::unit::unit_dimention::newton = typedef udim_div<udim_mul<metere, kilogram>::unit, udim_pow<second, 2>::unit>::unit;
```


### using pascal

```cpp
using cpp_robotics::unit::unit_dimention::pascal = typedef udim_div<newton, area>::unit;
```


### using viscosity

```cpp
using cpp_robotics::unit::unit_dimention::viscosity = typedef udim_mul<pascal, second>::unit;
```


### using joule

```cpp
using cpp_robotics::unit::unit_dimention::joule = typedef udim_mul<newton, metere>::unit;
```


### using watt

```cpp
using cpp_robotics::unit::unit_dimention::watt = typedef udim_div<joule, second>::unit;
```


### using volt

```cpp
using cpp_robotics::unit::unit_dimention::volt = typedef udim_div<watt, ampere>::unit;
```


### using coulomb

```cpp
using cpp_robotics::unit::unit_dimention::coulomb = typedef udim_mul<second, ampere>::unit;
```


### using farad

```cpp
using cpp_robotics::unit::unit_dimention::farad = typedef udim_div<coulomb, volt>::unit;
```


### using ohm

```cpp
using cpp_robotics::unit::unit_dimention::ohm = typedef udim_div<volt, ampere>::unit;
```


### using weber

```cpp
using cpp_robotics::unit::unit_dimention::weber = typedef udim_mul<volt, second>::unit;
```


### using henry

```cpp
using cpp_robotics::unit::unit_dimention::henry = typedef udim_div<weber, ampere>::unit;
```


### using torque

```cpp
using cpp_robotics::unit::unit_dimention::torque = typedef udim_mul<newton, metere>::unit;
```


### using inertia

```cpp
using cpp_robotics::unit::unit_dimention::inertia = typedef udim_mul<kilogram, area>::unit;
```


### using angular_velocity

```cpp
using cpp_robotics::unit::unit_dimention::angular_velocity = typedef udim_div<angle, second>::unit;
```


### using angular_acceleration

```cpp
using cpp_robotics::unit::unit_dimention::angular_acceleration = typedef udim_div<angular_velocity, second>::unit;
```







-------------------------------

Updated on 2022-10-02 at 13:22:12 +0900