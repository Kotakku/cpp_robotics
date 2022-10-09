---
title: cpp_robotics::NotchFilter
summary: ノッチフィルタ 

---

# cpp_robotics::NotchFilter



ノッチフィルタ 


`#include <notch_filter.hpp>`

Inherits from [cpp_robotics::DiscreteTransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1DiscreteTransferFunction/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[NotchFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-notchfilter)**(double omega, double zeta, double d, double dt)<br>Construct a new Notch Filter object.  |
| double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-filtering)**(double u)<br>フィルタリングする  |
| double | **[omega](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-omega)**() const<br>中心周波数[rad/s]  |
| double | **[zeta](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-zeta)**() const<br>鋭さ  |
| double | **[d](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-d)**() const<br>深さ  |

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

### function NotchFilter

```cpp
inline NotchFilter(
    double omega,
    double zeta,
    double d,
    double dt
)
```

Construct a new Notch Filter object. 

**Parameters**: 

  * **omega** 中心周波数[rad/s] 
  * **zeta** 鋭さ 
  * **d** 深さ(0.0で一番深く、1.0に近づけるほどフィルタの効果が弱くなる) 
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

中心周波数[rad/s] 

**Return**: double 

### function zeta

```cpp
inline double zeta() const
```

鋭さ 

**Return**: double 

### function d

```cpp
inline double d() const
```

深さ 

**Return**: double 

-------------------------------

Updated on 2022-10-10 at 00:51:39 +0900