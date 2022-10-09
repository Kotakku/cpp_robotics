---
title: cpp_robotics::LowPassFilter
summary: ローパスフィルター 

---

# cpp_robotics::LowPassFilter



ローパスフィルター 


`#include <low_pass_filter.hpp>`

Inherits from [cpp_robotics::DiscreteTransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[LowPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LowPassFilter/#function-lowpassfilter)**(double omega, double dt)<br>Construct a new Low Pass Filter object.  |
| double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LowPassFilter/#function-filtering)**(double u)<br>フィルタリングする  |
| double | **[omega](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LowPassFilter/#function-omega)**() const<br>折れ点周波数[rad/s]の取得  |

## Additional inherited members

**Public Functions inherited from [cpp_robotics::DiscreteTransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/)**

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

### function LowPassFilter

```cpp
inline LowPassFilter(
    double omega,
    double dt
)
```

Construct a new Low Pass Filter object. 

**Parameters**: 

  * **omega** 折れ点周波数[rad/s] 
  * **dt** サンプリング周期 


### function filtering

```cpp
inline double filtering(
    double u
)
```

フィルタリングする 

**Parameters**: 

  * **u** 


**Return**: double 

### function omega

```cpp
inline double omega() const
```

折れ点周波数[rad/s]の取得 

**Return**: double 

-------------------------------

Updated on 2022-10-10 at 00:51:39 +0900