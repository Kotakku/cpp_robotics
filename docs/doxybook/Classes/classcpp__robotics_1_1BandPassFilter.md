---
title: cpp_robotics::BandPassFilter
summary: バンドパスフィルタ 

---

# cpp_robotics::BandPassFilter



バンドパスフィルタ 


`#include <band_pass_filter.hpp>`

Inherits from [cpp_robotics::DiscreteTransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[BandPassFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1BandPassFilter/#function-bandpassfilter)**(double omega, double zeta, double dt)<br>Construct a new Notch Filter object.  |
| double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1BandPassFilter/#function-filtering)**(double u)<br>フィルタリングする  |
| double | **[omega](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1BandPassFilter/#function-omega)**() const<br>中心周波数[rad/s]の取得  |
| double | **[zeta](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1BandPassFilter/#function-zeta)**() const<br>鋭さの取得  |

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

### function BandPassFilter

```cpp
inline BandPassFilter(
    double omega,
    double zeta,
    double dt
)
```

Construct a new Notch Filter object. 

**Parameters**: 

  * **omega** 中心周波数[rad/s] 
  * **zeta** 鋭さ 
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

中心周波数[rad/s]の取得 

**Return**: double 

### function zeta

```cpp
inline double zeta() const
```

鋭さの取得 

**Return**: double 

-------------------------------

Updated on 2022-10-10 at 00:51:39 +0900