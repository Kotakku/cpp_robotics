---
title: cpp_robotics::NotchFilter
summary: ノッチフィルタ 

---

# cpp_robotics::NotchFilter



ノッチフィルタ 


`#include <notch_filter.hpp>`

Inherits from [cpp_robotics::TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[NotchFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-notchfilter)**(double omega, double zeta, double d, double dt)<br>Construct a new Notch Filter object.  |
| double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-filtering)**(double u)<br>フィルタリングする  |
| double | **[omega](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-omega)**() const<br>中心周波数[rad/s]  |
| double | **[zeta](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-zeta)**() const<br>鋭さ  |
| double | **[d](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1NotchFilter/#function-d)**() const<br>深さ  |

## Additional inherited members

**Public Functions inherited from [cpp_robotics::TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/)**

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

Updated on 2022-10-21 at 10:30:14 +0900