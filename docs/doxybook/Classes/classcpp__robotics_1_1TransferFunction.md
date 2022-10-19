---
title: cpp_robotics::TransferFunction
summary: 伝達関数モデル 

---

# cpp_robotics::TransferFunction



伝達関数モデル 


`#include <transfer_function.hpp>`

Inherited by [cpp_robotics::BandPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1BandPassFilter/), [cpp_robotics::ButterworthFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ButterworthFilter/), [cpp_robotics::Differentiator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Differentiator/), [cpp_robotics::HighPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1HighPassFilter/), [cpp_robotics::Integrator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Integrator/), [cpp_robotics::LowPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LowPassFilter/), [cpp_robotics::NotchFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| [TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/) | **[make_first_order_system](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-make-first-order-system)**(const double T, const double Ts) |
| [TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/) | **[make_second_order_system](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-make-second-order-system)**(const double omega, const double zeta, const double Ts) |
| | **[TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-transferfunction)**() =default |
| | **[TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-transferfunction)**(std::vector< double > num, std::vector< double > den, const double Ts) |
| void | **[set_continuous](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-set-continuous)**(std::vector< double > num, std::vector< double > den, const double dt) |
| void | **[set_discrite](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-set-discrite)**(std::vector< double > num_disc, std::vector< double > den_disc, const double dt) |
| double | **[Ts](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-ts)**() const<br>サンプリング周期  |
| virtual void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-reset)**(double state =0) |
| double | **[responce](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-responce)**(double u) |
| size_t | **[num_deg](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-num-deg)**(size_t num_idx =0) const |
| size_t | **[den_deg](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-den-deg)**(size_t num_idx =0) const |
| std::vector< double > | **[num_array](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-num-array)**() const |
| std::vector< double > | **[den_array](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-den-array)**() const |

## Public Functions Documentation

### function make_first_order_system

```cpp
static inline TransferFunction make_first_order_system(
    const double T,
    const double Ts
)
```


### function make_second_order_system

```cpp
static inline TransferFunction make_second_order_system(
    const double omega,
    const double zeta,
    const double Ts
)
```


### function TransferFunction

```cpp
TransferFunction() =default
```


### function TransferFunction

```cpp
inline TransferFunction(
    std::vector< double > num,
    std::vector< double > den,
    const double Ts
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


### function num_deg

```cpp
inline size_t num_deg(
    size_t num_idx =0
) const
```


### function den_deg

```cpp
inline size_t den_deg(
    size_t num_idx =0
) const
```


### function num_array

```cpp
inline std::vector< double > num_array() const
```


### function den_array

```cpp
inline std::vector< double > den_array() const
```


-------------------------------

Updated on 2022-10-19 at 13:20:53 +0900