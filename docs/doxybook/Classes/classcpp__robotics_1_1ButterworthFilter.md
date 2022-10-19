---
title: cpp_robotics::ButterworthFilter
summary: バターワースフィルタ 

---

# cpp_robotics::ButterworthFilter



バターワースフィルタ 


`#include <butterworth_filter.hpp>`

Inherits from [cpp_robotics::TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[ButterworthFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ButterworthFilter/#function-butterworthfilter)**(double omega, size_t n, double dt)<br>Construct a new Butterworth Filter object.  |
| double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ButterworthFilter/#function-filtering)**(double u)<br>フィルタリングする  |
| double | **[omega](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ButterworthFilter/#function-omega)**() const<br>時定数の取得  |
| size_t | **[n](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ButterworthFilter/#function-n)**() const<br>フィルタの次数  |

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

Updated on 2022-10-19 at 13:20:53 +0900