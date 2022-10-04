---
title: cpp_robotics::KalmanFilter
summary: カルマンフィルタ 

---

# cpp_robotics::KalmanFilter



カルマンフィルタ  [More...](#detailed-description)


`#include <kalman_filter.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using FLOATING_TYPE | **[value_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-value-type)**  |
| using Eigen::Matrix< [value_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-value-type), [state_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-state-size), 1 > | **[x_vec_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-x-vec-t)**  |
| using Eigen::Matrix< [value_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-value-type), [input_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-input-size), 1 > | **[u_vec_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-u-vec-t)**  |
| using Eigen::Matrix< [value_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-value-type), [observe_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-observe-size), 1 > | **[z_vec_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-z-vec-t)**  |
| using Eigen::Matrix< [value_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-value-type), [state_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-state-size), [state_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-state-size) > | **[f_mat_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-f-mat-t)**  |
| using Eigen::Matrix< [value_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-value-type), [state_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-state-size), [input_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-input-size) > | **[g_mat_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-g-mat-t)**  |
| using Eigen::Matrix< [value_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-value-type), [observe_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-observe-size), [state_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-state-size) > | **[h_mat_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-h-mat-t)**  |
| using Eigen::Matrix< [value_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-value-type), [state_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-state-size), [state_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-state-size) > | **[q_mat_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-q-mat-t)**  |
| using Eigen::Matrix< [value_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-value-type), [observe_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-observe-size), [observe_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-observe-size) > | **[r_mat_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-r-mat-t)**  |
| using Eigen::Matrix< [value_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-value-type), [state_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-state-size), [state_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-state-size) > | **[p_mat_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-p-mat-t)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[KalmanFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#function-kalmanfilter)**() =default |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#function-reset)**([x_vec_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-x-vec-t) x, [p_mat_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-p-mat-t) P) |
| [x_vec_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-x-vec-t) | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#function-filtering)**([u_vec_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-u-vec-t) u, [z_vec_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-z-vec-t) z) |
| [x_vec_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-x-vec-t) | **[get_x](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#function-get-x)**() |
| [p_mat_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-p-mat-t) | **[get_P](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#function-get-p)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| constexpr size_t | **[state_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-state-size)**  |
| constexpr size_t | **[input_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-input-size)**  |
| constexpr size_t | **[observe_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-observe-size)**  |
| [f_mat_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-f-mat-t) | **[F](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-f)**  |
| [g_mat_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-g-mat-t) | **[G](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-g)**  |
| [h_mat_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-h-mat-t) | **[H](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-h)**  |
| [q_mat_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-q-mat-t) | **[Q](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-q)**  |
| [r_mat_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#using-r-mat-t) | **[R](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KalmanFilter/#variable-r)**  |

## Detailed Description

```cpp
template <typename FLOATING_TYPE ,
size_t STATE_SIZE,
size_t INPUT_SIZE,
size_t OBSERVE_SIZE>
class cpp_robotics::KalmanFilter;
```

カルマンフィルタ 

**Template Parameters**: 

  * **FLOATING_TYPE** 浮動小数点型 
  * **STATE_SIZE** 状態量のサイズ 
  * **INPUT_SIZE** 入力量のサイズ 
  * **OBSERVE_SIZE** 観測量のサイズ 

## Public Types Documentation

### using value_type

```cpp
using cpp_robotics::KalmanFilter< FLOATING_TYPE, STATE_SIZE, INPUT_SIZE, OBSERVE_SIZE >::value_type =  FLOATING_TYPE;
```


### using x_vec_t

```cpp
using cpp_robotics::KalmanFilter< FLOATING_TYPE, STATE_SIZE, INPUT_SIZE, OBSERVE_SIZE >::x_vec_t =  Eigen::Matrix<value_type, state_size, 1>;
```


### using u_vec_t

```cpp
using cpp_robotics::KalmanFilter< FLOATING_TYPE, STATE_SIZE, INPUT_SIZE, OBSERVE_SIZE >::u_vec_t =  Eigen::Matrix<value_type, input_size, 1>;
```


### using z_vec_t

```cpp
using cpp_robotics::KalmanFilter< FLOATING_TYPE, STATE_SIZE, INPUT_SIZE, OBSERVE_SIZE >::z_vec_t =  Eigen::Matrix<value_type, observe_size, 1>;
```


### using f_mat_t

```cpp
using cpp_robotics::KalmanFilter< FLOATING_TYPE, STATE_SIZE, INPUT_SIZE, OBSERVE_SIZE >::f_mat_t =  Eigen::Matrix<value_type, state_size, state_size>;
```


### using g_mat_t

```cpp
using cpp_robotics::KalmanFilter< FLOATING_TYPE, STATE_SIZE, INPUT_SIZE, OBSERVE_SIZE >::g_mat_t =  Eigen::Matrix<value_type, state_size, input_size>;
```


### using h_mat_t

```cpp
using cpp_robotics::KalmanFilter< FLOATING_TYPE, STATE_SIZE, INPUT_SIZE, OBSERVE_SIZE >::h_mat_t =  Eigen::Matrix<value_type, observe_size, state_size>;
```


### using q_mat_t

```cpp
using cpp_robotics::KalmanFilter< FLOATING_TYPE, STATE_SIZE, INPUT_SIZE, OBSERVE_SIZE >::q_mat_t =  Eigen::Matrix<value_type, state_size, state_size>;
```


### using r_mat_t

```cpp
using cpp_robotics::KalmanFilter< FLOATING_TYPE, STATE_SIZE, INPUT_SIZE, OBSERVE_SIZE >::r_mat_t =  Eigen::Matrix<value_type, observe_size, observe_size>;
```


### using p_mat_t

```cpp
using cpp_robotics::KalmanFilter< FLOATING_TYPE, STATE_SIZE, INPUT_SIZE, OBSERVE_SIZE >::p_mat_t =  Eigen::Matrix<value_type, state_size, state_size>;
```


## Public Functions Documentation

### function KalmanFilter

```cpp
KalmanFilter() =default
```


### function reset

```cpp
inline void reset(
    x_vec_t x,
    p_mat_t P
)
```


### function filtering

```cpp
inline x_vec_t filtering(
    u_vec_t u,
    z_vec_t z
)
```


### function get_x

```cpp
inline x_vec_t get_x()
```


### function get_P

```cpp
inline p_mat_t get_P()
```


## Public Attributes Documentation

### variable state_size

```cpp
static constexpr size_t state_size = STATE_SIZE;
```


### variable input_size

```cpp
static constexpr size_t input_size = INPUT_SIZE;
```


### variable observe_size

```cpp
static constexpr size_t observe_size = OBSERVE_SIZE;
```


### variable F

```cpp
f_mat_t F;
```


### variable G

```cpp
g_mat_t G;
```


### variable H

```cpp
h_mat_t H;
```


### variable Q

```cpp
q_mat_t Q;
```


### variable R

```cpp
r_mat_t R;
```


-------------------------------

Updated on 2022-10-05 at 01:02:06 +0900