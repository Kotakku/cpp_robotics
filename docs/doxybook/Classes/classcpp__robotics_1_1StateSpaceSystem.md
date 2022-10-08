---
title: cpp_robotics::StateSpaceSystem
summary: 状態空間モデル 

---

# cpp_robotics::StateSpaceSystem



状態空間モデル 


`#include <state_space_system.hpp>`

Inherited by [cpp_robotics::TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[StateSpaceSystem](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-statespacesystem)**() =default |
| template <typename DerivedA ,typename DerivedB ,typename DerivedC \> <br>| **[StateSpaceSystem](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-statespacesystem)**(const Eigen::MatrixBase< DerivedA > & A, const Eigen::MatrixBase< DerivedB > & B, const Eigen::MatrixBase< DerivedC > & C, const double Ts) |
| template <typename DerivedA ,typename DerivedB ,typename DerivedC ,typename DerivedD \> <br>| **[StateSpaceSystem](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-statespacesystem)**(const Eigen::MatrixBase< DerivedA > & A, const Eigen::MatrixBase< DerivedB > & B, const Eigen::MatrixBase< DerivedC > & C, const Eigen::MatrixBase< DerivedD > & D, const double Ts) |
| template <typename DerivedA ,typename DerivedB ,typename DerivedC \> <br>void | **[set_continuous](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-set-continuous)**(const Eigen::MatrixBase< DerivedA > & A, const Eigen::MatrixBase< DerivedB > & B, const Eigen::MatrixBase< DerivedC > & C, const double Ts, const bool skip_state_reset =false) |
| template <typename DerivedA ,typename DerivedB ,typename DerivedC ,typename DerivedD \> <br>void | **[set_continuous](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-set-continuous)**(const Eigen::MatrixBase< DerivedA > & A, const Eigen::MatrixBase< DerivedB > & B, const Eigen::MatrixBase< DerivedC > & C, const Eigen::MatrixBase< DerivedD > & D, const double Ts, const bool skip_state_reset =false) |
| template <typename DerivedA ,typename DerivedB ,typename DerivedC \> <br>void | **[set_discrite](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-set-discrite)**(const Eigen::MatrixBase< DerivedA > & Ad, const Eigen::MatrixBase< DerivedB > & Bd, const Eigen::MatrixBase< DerivedC > & Cd, const double Ts, const bool skip_state_reset =false) |
| template <typename DerivedA ,typename DerivedB ,typename DerivedC ,typename DerivedD \> <br>void | **[set_discrite](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-set-discrite)**(const Eigen::MatrixBase< DerivedA > & Ad, const Eigen::MatrixBase< DerivedB > & Bd, const Eigen::MatrixBase< DerivedC > & Cd, const Eigen::MatrixBase< DerivedD > & Dd, const double Ts, const bool skip_state_reset =false) |
| size_t | **[state_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-state-size)**() const |
| size_t | **[input_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-input-size)**() const |
| size_t | **[output_size](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-output-size)**() const |
| bool | **[is_siso_model](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-is-siso-model)**() const |
| void | **[set_state_zero](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-set-state-zero)**() |
| void | **[set_state](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-set-state)**(const Eigen::VectorXd & x) |
| void | **[set_state](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-set-state)**(const double & x) |
| auto | **[responce](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-responce)**(const Eigen::VectorXd & u) |
| double | **[responce](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-responce)**(double u) |
| std::optional< Eigen::MatrixXd > | **[A](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-a)**() const |
| std::optional< Eigen::MatrixXd > | **[B](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-b)**() const |
| double | **[Ts](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-ts)**() const |
| Eigen::MatrixXd | **[Ad](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-ad)**() const |
| Eigen::MatrixXd | **[Bd](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-bd)**() const |
| Eigen::MatrixXd | **[C](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-c)**() const |
| Eigen::MatrixXd | **[Cd](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-cd)**() const |
| Eigen::MatrixXd | **[D](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-d)**() const |
| Eigen::MatrixXd | **[Dd](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-dd)**() const |
| Eigen::VectorXd | **[x](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-x)**() const |
| Eigen::VectorXd | **[y](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/#function-y)**() const |

## Public Functions Documentation

### function StateSpaceSystem

```cpp
StateSpaceSystem() =default
```


### function StateSpaceSystem

```cpp
template <typename DerivedA ,
typename DerivedB ,
typename DerivedC >
inline StateSpaceSystem(
    const Eigen::MatrixBase< DerivedA > & A,
    const Eigen::MatrixBase< DerivedB > & B,
    const Eigen::MatrixBase< DerivedC > & C,
    const double Ts
)
```


### function StateSpaceSystem

```cpp
template <typename DerivedA ,
typename DerivedB ,
typename DerivedC ,
typename DerivedD >
inline StateSpaceSystem(
    const Eigen::MatrixBase< DerivedA > & A,
    const Eigen::MatrixBase< DerivedB > & B,
    const Eigen::MatrixBase< DerivedC > & C,
    const Eigen::MatrixBase< DerivedD > & D,
    const double Ts
)
```


### function set_continuous

```cpp
template <typename DerivedA ,
typename DerivedB ,
typename DerivedC >
inline void set_continuous(
    const Eigen::MatrixBase< DerivedA > & A,
    const Eigen::MatrixBase< DerivedB > & B,
    const Eigen::MatrixBase< DerivedC > & C,
    const double Ts,
    const bool skip_state_reset =false
)
```


### function set_continuous

```cpp
template <typename DerivedA ,
typename DerivedB ,
typename DerivedC ,
typename DerivedD >
inline void set_continuous(
    const Eigen::MatrixBase< DerivedA > & A,
    const Eigen::MatrixBase< DerivedB > & B,
    const Eigen::MatrixBase< DerivedC > & C,
    const Eigen::MatrixBase< DerivedD > & D,
    const double Ts,
    const bool skip_state_reset =false
)
```


### function set_discrite

```cpp
template <typename DerivedA ,
typename DerivedB ,
typename DerivedC >
inline void set_discrite(
    const Eigen::MatrixBase< DerivedA > & Ad,
    const Eigen::MatrixBase< DerivedB > & Bd,
    const Eigen::MatrixBase< DerivedC > & Cd,
    const double Ts,
    const bool skip_state_reset =false
)
```


### function set_discrite

```cpp
template <typename DerivedA ,
typename DerivedB ,
typename DerivedC ,
typename DerivedD >
inline void set_discrite(
    const Eigen::MatrixBase< DerivedA > & Ad,
    const Eigen::MatrixBase< DerivedB > & Bd,
    const Eigen::MatrixBase< DerivedC > & Cd,
    const Eigen::MatrixBase< DerivedD > & Dd,
    const double Ts,
    const bool skip_state_reset =false
)
```


### function state_size

```cpp
inline size_t state_size() const
```


### function input_size

```cpp
inline size_t input_size() const
```


### function output_size

```cpp
inline size_t output_size() const
```


### function is_siso_model

```cpp
inline bool is_siso_model() const
```


### function set_state_zero

```cpp
inline void set_state_zero()
```


### function set_state

```cpp
inline void set_state(
    const Eigen::VectorXd & x
)
```


### function set_state

```cpp
inline void set_state(
    const double & x
)
```


### function responce

```cpp
inline auto responce(
    const Eigen::VectorXd & u
)
```


### function responce

```cpp
inline double responce(
    double u
)
```


### function A

```cpp
inline std::optional< Eigen::MatrixXd > A() const
```


### function B

```cpp
inline std::optional< Eigen::MatrixXd > B() const
```


### function Ts

```cpp
inline double Ts() const
```


### function Ad

```cpp
inline Eigen::MatrixXd Ad() const
```


### function Bd

```cpp
inline Eigen::MatrixXd Bd() const
```


### function C

```cpp
inline Eigen::MatrixXd C() const
```


### function Cd

```cpp
inline Eigen::MatrixXd Cd() const
```


### function D

```cpp
inline Eigen::MatrixXd D() const
```


### function Dd

```cpp
inline Eigen::MatrixXd Dd() const
```


### function x

```cpp
inline Eigen::VectorXd x() const
```


### function y

```cpp
inline Eigen::VectorXd y() const
```


-------------------------------

Updated on 2022-10-08 at 23:36:07 +0900