---
title: cpp_robotics::ButterworthFilter
summary: バターワースフィルタ 

---

# cpp_robotics::ButterworthFilter



バターワースフィルタ 


`#include <butterworth_filter.hpp>`

Inherits from [cpp_robotics::DiscreteTransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[ButterworthFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ButterworthFilter/#function-butterworthfilter)**(double omega, size_t n, double dt)<br>Construct a new Butterworth Filter object.  |
| double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ButterworthFilter/#function-filtering)**(double u)<br>フィルタリングする  |
| double | **[omega](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ButterworthFilter/#function-omega)**() const<br>時定数の取得  |
| size_t | **[n](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ButterworthFilter/#function-n)**() const<br>フィルタの次数  |

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

### function ButterworthFilter

```cpp
inline ButterworthFilter(
    double omega,
    size_t n,
    double dt
)
```

Construct a new Butterworth Filter object. 

**Parameters**: 

  * **omega** 折れ点周波数[rad/s] 
  * **n** フィルタの次数 
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

### function n

```cpp
inline size_t n() const
```

フィルタの次数 

**Return**: size_t 

-------------------------------

Updated on 2022-10-10 at 00:51:39 +0900