---
title: cpp_robotics::LinearMPC

---

# cpp_robotics::LinearMPC






`#include <linear_mpc.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[LinearMPC](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearMPC/#function-linearmpc)**(const Eigen::MatrixXd & Ad, const Eigen::MatrixXd & Bd, const Eigen::MatrixXd & Q, const Eigen::MatrixXd & R, const Eigen::MatrixXd & Qf, const size_t N, std::optional< std::pair< Eigen::VectorXd, Eigen::VectorXd >> u_limit =std::nullopt) |
| void | **[set_initial_input](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearMPC/#function-set-initial-input)**(const std::vector< Eigen::VectorXd > & u0) |
| std::tuple< bool, Eigen::VectorXd > | **[control](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearMPC/#function-control)**(const Eigen::VectorXd & x0, const std::vector< Eigen::VectorXd > & x_ref, bool warm_start =true) |
| std::tuple< bool, Eigen::VectorXd > | **[control](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearMPC/#function-control)**(const Eigen::VectorXd & x0, const Eigen::VectorXd & x_ref, bool warm_start =true) |
| [QuadProg::Result](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1QuadProg_1_1Result/) | **[latest_qp_result](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearMPC/#function-latest-qp-result)**() const |
| Eigen::MatrixXd | **[Ad](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearMPC/#function-ad)**() const |
| Eigen::MatrixXd | **[Bd](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearMPC/#function-bd)**() const |
| Eigen::MatrixXd | **[Q](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearMPC/#function-q)**() const |
| Eigen::MatrixXd | **[R](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearMPC/#function-r)**() const |
| Eigen::MatrixXd | **[Qf](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearMPC/#function-qf)**() const |
| size_t | **[N](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearMPC/#function-n)**() const |

## Public Functions Documentation

### function LinearMPC

```cpp
inline LinearMPC(
    const Eigen::MatrixXd & Ad,
    const Eigen::MatrixXd & Bd,
    const Eigen::MatrixXd & Q,
    const Eigen::MatrixXd & R,
    const Eigen::MatrixXd & Qf,
    const size_t N,
    std::optional< std::pair< Eigen::VectorXd, Eigen::VectorXd >> u_limit =std::nullopt
)
```


### function set_initial_input

```cpp
inline void set_initial_input(
    const std::vector< Eigen::VectorXd > & u0
)
```


### function control

```cpp
inline std::tuple< bool, Eigen::VectorXd > control(
    const Eigen::VectorXd & x0,
    const std::vector< Eigen::VectorXd > & x_ref,
    bool warm_start =true
)
```


### function control

```cpp
inline std::tuple< bool, Eigen::VectorXd > control(
    const Eigen::VectorXd & x0,
    const Eigen::VectorXd & x_ref,
    bool warm_start =true
)
```


### function latest_qp_result

```cpp
inline QuadProg::Result latest_qp_result() const
```


### function Ad

```cpp
inline Eigen::MatrixXd Ad() const
```


### function Bd

```cpp
inline Eigen::MatrixXd Bd() const
```


### function Q

```cpp
inline Eigen::MatrixXd Q() const
```


### function R

```cpp
inline Eigen::MatrixXd R() const
```


### function Qf

```cpp
inline Eigen::MatrixXd Qf() const
```


### function N

```cpp
inline size_t N() const
```


-------------------------------

Updated on 2022-10-21 at 10:30:14 +0900