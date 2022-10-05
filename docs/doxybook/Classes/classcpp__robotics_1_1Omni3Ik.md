---
title: cpp_robotics::Omni3Ik
summary: 3輪オムニの逆運動学モデル 

---

# cpp_robotics::Omni3Ik



3輪オムニの逆運動学モデル 


`#include <omni_ik.hpp>`

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[Config](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Omni3Ik_1_1Config/)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[Omni3Ik](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Omni3Ik/#function-omni3ik)**(double radius, double first_wheel_angle =M_PI/6) |
| | **[Omni3Ik](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Omni3Ik/#function-omni3ik)**([Config](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Omni3Ik_1_1Config/) config) |
| std::array< double, 3 > | **[calculate](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Omni3Ik/#function-calculate)**([Transformd](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-transformd) velocity) |
| [Config](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1Omni3Ik_1_1Config/) | **[config](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Omni3Ik/#function-config)**() const |

## Public Functions Documentation

### function Omni3Ik

```cpp
inline Omni3Ik(
    double radius,
    double first_wheel_angle =M_PI/6
)
```


### function Omni3Ik

```cpp
inline Omni3Ik(
    Config config
)
```


### function calculate

```cpp
inline std::array< double, 3 > calculate(
    Transformd velocity
)
```


### function config

```cpp
inline Config config() const
```


-------------------------------

Updated on 2022-10-06 at 00:27:03 +0900