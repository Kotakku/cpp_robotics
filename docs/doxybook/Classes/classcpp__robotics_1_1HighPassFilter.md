---
title: cpp_robotics::HighPassFilter
summary: ハイパスフィルタ 

---

# cpp_robotics::HighPassFilter



ハイパスフィルタ 


`#include <high_pass_filter.hpp>`

Inherits from [cpp_robotics::DiscreteTransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[HighPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1HighPassFilter/#function-highpassfilter)**(double omega, double dt)<br>Construct a new High Pass Filter object.  |
| double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1HighPassFilter/#function-filtering)**(double u)<br>フィルタリングする  |
| double | **[omega](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1HighPassFilter/#function-omega)**() const<br>時定数の取得  |

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

### function HighPassFilter

```cpp
inline HighPassFilter(
    double omega,
    double dt
)
```

Construct a new High Pass Filter object. 

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

時定数の取得 

**Return**: double 

-------------------------------

Updated on 2022-10-10 at 00:51:39 +0900