---
title: cpp_robotics::MecanumIk
summary: メカナムの逆運動学モデル 

---

# cpp_robotics::MecanumIk



メカナムの逆運動学モデル 


`#include <mecanum_ik.hpp>`

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[Config](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1MecanumIk_1_1Config/)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[MecanumIk](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1MecanumIk/#function-mecanumik)**(double width, double length) |
| | **[MecanumIk](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1MecanumIk/#function-mecanumik)**([Config](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1MecanumIk_1_1Config/) config) |
| std::array< double, 4 > | **[calculate](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1MecanumIk/#function-calculate)**([Transformd](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/#using-transformd) velocity) |
| [Config](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1MecanumIk_1_1Config/) | **[config](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1MecanumIk/#function-config)**() const |

## Public Functions Documentation

### function MecanumIk

```cpp
inline MecanumIk(
    double width,
    double length
)
```


### function MecanumIk

```cpp
inline MecanumIk(
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

Updated on 2022-10-19 at 13:20:53 +0900