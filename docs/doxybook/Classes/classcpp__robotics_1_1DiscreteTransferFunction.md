---
title: cpp_robotics::DiscreteTransferFunction
summary: z空間の伝達関数 

---

# cpp_robotics::DiscreteTransferFunction



z空間の伝達関数 


`#include <discrete_transfer_function.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[DiscreteTransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/#function-discretetransferfunction)**() =default |
| | **[DiscreteTransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/#function-discretetransferfunction)**(std::vector< double > num_disc, std::vector< double > den_disc, const double dt) |
| void | **[set_discrite](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/#function-set-discrite)**(std::vector< double > num_disc, std::vector< double > den_disc, const double dt) |
| double | **[Ts](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/#function-ts)**() const |
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

Updated on 2022-10-05 at 01:02:06 +0900