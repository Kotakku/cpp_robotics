---
title: cpp_robotics::DiscreteTransferFunction
summary: z空間の伝達関数 

---

# cpp_robotics::DiscreteTransferFunction



z空間の伝達関数 


`#include <discrete_transfer_function.hpp>`

Inherited by [cpp_robotics::BandPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1BandPassFilter/), [cpp_robotics::ButterworthFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ButterworthFilter/), [cpp_robotics::Differentiator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Differentiator/), [cpp_robotics::HighPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1HighPassFilter/), [cpp_robotics::Integrator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Integrator/), [cpp_robotics::LowPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LowPassFilter/), [cpp_robotics::NotchFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[DiscreteTransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/#function-discretetransferfunction)**() =default |
| | **[DiscreteTransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/#function-discretetransferfunction)**(std::vector< double > num_disc, std::vector< double > den_disc, const double dt) |
| void | **[set_continuous](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/#function-set-continuous)**(std::vector< double > num, std::vector< double > den, const double dt) |
| void | **[set_discrite](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/#function-set-discrite)**(std::vector< double > num_disc, std::vector< double > den_disc, const double dt) |
| double | **[Ts](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/#function-ts)**() const<br>サンプリング周期  |
| virtual void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/#function-reset)**(double state =0) |
| double | **[responce](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/#function-responce)**(double u) |

## Public Functions Documentation

### function DiscreteTransferFunction

```cpp
DiscreteTransferFunction() =default
```


### function DiscreteTransferFunction

```cpp
inline DiscreteTransferFunction(
    std::vector< double > num_disc,
    std::vector< double > den_disc,
    const double dt
)
```


### function set_continuous

```cpp
inline void set_continuous(
    std::vector< double > num,
    std::vector< double > den,
    const double dt
)
```


### function set_discrite

```cpp
inline void set_discrite(
    std::vector< double > num_disc,
    std::vector< double > den_disc,
    const double dt
)
```


### function Ts

```cpp
inline double Ts() const
```

サンプリング周期 

**Return**: double 

### function reset

```cpp
inline virtual void reset(
    double state =0
)
```


### function responce

```cpp
inline double responce(
    double u
)
```


-------------------------------

Updated on 2022-10-10 at 00:51:39 +0900