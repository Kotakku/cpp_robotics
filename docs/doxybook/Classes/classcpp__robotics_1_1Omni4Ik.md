---
title: cpp_robotics::Omni4Ik
summary: 4輪オムニの逆運動学モデル 

---

# cpp_robotics::Omni4Ik



4輪オムニの逆運動学モデル 


`#include <omni_ik.hpp>`

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[Config](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Omni4Ik_1_1Config/)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Omni4Ik](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Omni4Ik/#function-omni4ik)**(double radius, double first_wheel_angle =M_PI/4) |
| | **[Omni4Ik](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Omni4Ik/#function-omni4ik)**([Config](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Omni4Ik_1_1Config/) config) |
| std::array< double, 4 > | **[calculate](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Omni4Ik/#function-calculate)**([Transformd](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-transformd) velocity) |
| [Config](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Omni4Ik_1_1Config/) | **[config](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Omni4Ik/#function-config)**() const |

## Public Functions Documentation

### function Omni4Ik

```cpp
inline Omni4Ik(
    double radius,
    double first_wheel_angle =M_PI/4
)
```


### function Omni4Ik

```cpp
inline Omni4Ik(
    Config config
)
```


### function calculate

```cpp
inline std::array< double, 4 > calculate(
    Transformd velocity
)
```


### function config

```cpp
inline Config config() const
```


-------------------------------

Updated on 2022-10-05 at 16:05:00 +0900