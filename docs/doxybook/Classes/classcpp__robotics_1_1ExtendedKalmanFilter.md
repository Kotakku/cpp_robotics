---
title: cpp_robotics::ExtendedKalmanFilter

---

# cpp_robotics::ExtendedKalmanFilter






`#include <extended_kalman_filter.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[ExtendedKalmanFilter](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#function-extendedkalmanfilter)**(const double dt, size_t input_size, size_t state_size, size_t observe_size) |
| void | **[reset](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#function-reset)**(Eigen::VectorXd new_x, Eigen::MatrixXd new_P) |
| Eigen::VectorXd | **[filtering](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#function-filtering)**(Eigen::VectorXd u, Eigen::VectorXd z) |
| double | **[dt](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#function-dt)**() const |
| Eigen::VectorXd | **[get_x](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#function-get-x)**() const |
| Eigen::MatrixXd | **[get_P](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#function-get-p)**() const |
| virtual Eigen::VectorXd | **[system](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#function-system)**(Eigen::VectorXd x, Eigen::VectorXd u) =0<br>システム  |
| virtual Eigen::VectorXd | **[observe](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#function-observe)**(Eigen::VectorXd x) =0<br>観測  |
| virtual void | **[system_noise_conv](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#function-system-noise-conv)**(Eigen::MatrixXd & Q, Eigen::VectorXd x, Eigen::VectorXd u) =0<br>システムノイズ共分散行列  |
| virtual void | **[observe_noise_conv](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#function-observe-noise-conv)**(Eigen::MatrixXd & R, Eigen::VectorXd x, Eigen::VectorXd u) =0<br>観測ノイズの共分散行列  |
| virtual void | **[linearized_system_matrix](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#function-linearized-system-matrix)**(Eigen::MatrixXd & F, Eigen::VectorXd x, Eigen::VectorXd u)<br>システム線形化行列  |
| virtual void | **[linearized_observe_matrix](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#function-linearized-observe-matrix)**(Eigen::MatrixXd & H, Eigen::VectorXd x)<br>観測線形化行列  |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| Eigen::VectorXd | **[x](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#variable-x)** <br>状態量  |
| Eigen::MatrixXd | **[F](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#variable-f)** <br>遷移行列  |
| Eigen::MatrixXd | **[B](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#variable-b)** <br>制御行列  |
| Eigen::MatrixXd | **[H](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#variable-h)** <br>観測行列  |
| Eigen::MatrixXd | **[Q](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#variable-q)** <br>状態量ノイズ分散行列  |
| Eigen::MatrixXd | **[R](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#variable-r)** <br>観測量ノイズ分散行列  |
| Eigen::MatrixXd | **[P](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#variable-p)** <br>誤差共分散行列  |

## Protected Attributes

|                | Name           |
| -------------- | -------------- |
| const double | **[dt_](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#variable-dt-)**  |
| const size_t | **[input_size_](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#variable-input-size-)**  |
| const size_t | **[state_size_](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#variable-state-size-)**  |
| const size_t | **[observe_size_](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1ExtendedKalmanFilter/#variable-observe-size-)**  |

## Public Functions Documentation

### function ExtendedKalmanFilter

```cpp
inline ExtendedKalmanFilter(
    const double dt,
    size_t input_size,
    size_t state_size,
    size_t observe_size
)
```


### function reset

```cpp
inline void reset(
    Eigen::VectorXd new_x,
    Eigen::MatrixXd new_P
)
```


### function filtering

```cpp
inline Eigen::VectorXd filtering(
    Eigen::VectorXd u,
    Eigen::VectorXd z
)
```


### function dt

```cpp
inline double dt() const
```


### function get_x

```cpp
inline Eigen::VectorXd get_x() const
```


### function get_P

```cpp
inline Eigen::MatrixXd get_P() const
```


### function system

```cpp
virtual Eigen::VectorXd system(
    Eigen::VectorXd x,
    Eigen::VectorXd u
) =0
```

システム 

### function observe

```cpp
virtual Eigen::VectorXd observe(
    Eigen::VectorXd x
) =0
```

観測 

### function system_noise_conv

```cpp
virtual void system_noise_conv(
    Eigen::MatrixXd & Q,
    Eigen::VectorXd x,
    Eigen::VectorXd u
) =0
```

システムノイズ共分散行列 

### function observe_noise_conv

```cpp
virtual void observe_noise_conv(
    Eigen::MatrixXd & R,
    Eigen::VectorXd x,
    Eigen::VectorXd u
) =0
```

観測ノイズの共分散行列 

### function linearized_system_matrix

```cpp
inline virtual void linearized_system_matrix(
    Eigen::MatrixXd & F,
    Eigen::VectorXd x,
    Eigen::VectorXd u
)
```

システム線形化行列 

### function linearized_observe_matrix

```cpp
inline virtual void linearized_observe_matrix(
    Eigen::MatrixXd & H,
    Eigen::VectorXd x
)
```

観測線形化行列 

## Public Attributes Documentation

### variable x

```cpp
Eigen::VectorXd x;
```

状態量 

### variable F

```cpp
Eigen::MatrixXd F;
```

遷移行列 

### variable B

```cpp
Eigen::MatrixXd B;
```

制御行列 

### variable H

```cpp
Eigen::MatrixXd H;
```

観測行列 

### variable Q

```cpp
Eigen::MatrixXd Q;
```

状態量ノイズ分散行列 

### variable R

```cpp
Eigen::MatrixXd R;
```

観測量ノイズ分散行列 

### variable P

```cpp
Eigen::MatrixXd P;
```

誤差共分散行列 

## Protected Attributes Documentation

### variable dt_

```cpp
const double dt_;
```


### variable input_size_

```cpp
const size_t input_size_;
```


### variable state_size_

```cpp
const size_t state_size_;
```


### variable observe_size_

```cpp
const size_t observe_size_;
```


-------------------------------

Updated on 2022-09-28 at 23:12:43 +0900