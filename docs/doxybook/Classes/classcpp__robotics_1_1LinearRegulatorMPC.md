---
title: cpp_robotics::LinearRegulatorMPC

---

# cpp_robotics::LinearRegulatorMPC






`#include <linear_regulator_mpc.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[LinearRegulatorMPC](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearRegulatorMPC/#function-linearregulatormpc)**(const Eigen::MatrixXd & Ad, const Eigen::MatrixXd & Bd, const Eigen::MatrixXd & Q, const Eigen::MatrixXd & R, const Eigen::MatrixXd & Qf, const size_t N, std::optional< std::pair< Eigen::VectorXd, Eigen::VectorXd >> u_limit =std::nullopt) |
| void | **[set_initial_input](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearRegulatorMPC/#function-set-initial-input)**(const std::vector< Eigen::VectorXd > & u0) |
| std::tuple< bool, Eigen::VectorXd > | **[control](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearRegulatorMPC/#function-control)**(const Eigen::VectorXd & x0, bool warm_start =true) |
| [QuadProg::Result](/cpp_robotics/doxybook/Classes/structcpp__robotics_1_1QuadProg_1_1Result/) | **[latest_qp_result](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearRegulatorMPC/#function-latest-qp-result)**() const |
| Eigen::MatrixXd | **[Ad](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearRegulatorMPC/#function-ad)**() const |
| Eigen::MatrixXd | **[Bd](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearRegulatorMPC/#function-bd)**() const |
| Eigen::MatrixXd | **[Q](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearRegulatorMPC/#function-q)**() const |
| Eigen::MatrixXd | **[R](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearRegulatorMPC/#function-r)**() const |
| Eigen::MatrixXd | **[Qf](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearRegulatorMPC/#function-qf)**() const |
| size_t | **[N](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1LinearRegulatorMPC/#function-n)**() const |

## Public Functions Documentation

### function LinearRegulatorMPC

```cpp
inline LinearRegulatorMPC(
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

Updated on 2022-10-22 at 22:05:50 +0900