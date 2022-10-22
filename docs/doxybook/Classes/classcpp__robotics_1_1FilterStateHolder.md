---
title: cpp_robotics::FilterStateHolder
summary: フィルタの入力と計算を非同期にして最後の入力と出力を保持しておけるようにするクラス 

---

# cpp_robotics::FilterStateHolder



フィルタの入力と計算を非同期にして最後の入力と出力を保持しておけるようにするクラス  [More...](#detailed-description)


`#include <filter_state_holder.hpp>`

Inherits from BASE_FILTER_TYPE

## Public Functions

|                | Name           |
| -------------- | -------------- |
| void | **[set_input](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1FilterStateHolder/#function-set-input)**(double u) |
| double | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1FilterStateHolder/#function-filtering)**() |
| double | **[u](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1FilterStateHolder/#function-u)**() const |
| double | **[y](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1FilterStateHolder/#function-y)**() const |

## Detailed Description

```cpp
template <class BASE_FILTER_TYPE >
class cpp_robotics::FilterStateHolder;
```

フィルタの入力と計算を非同期にして最後の入力と出力を保持しておけるようにするクラス 

**Template Parameters**: 

  * **BASE_FILTER_TYPE** 

## Public Functions Documentation

### function set_input

```cpp
inline void set_input(
    double u
)
```


### function filtering

```cpp
inline double filtering()
```


### function u

```cpp
inline double u() const
```


### function y

```cpp
inline double y() const
```


-------------------------------

Updated on 2022-10-22 at 22:05:49 +0900