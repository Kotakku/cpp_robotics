---
title: cpp_robotics::TransferFunction
summary: 伝達関数モデル 

---

# cpp_robotics::TransferFunction



伝達関数モデル 


`#include <transfer_function.hpp>`

Inherits from [cpp_robotics::StateSpaceSystem](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| [TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/) | **[make_first_order_system](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-make-first-order-system)**(const double T, const double Ts) |
| [TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/) | **[make_second_order_system](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-make-second-order-system)**(const double omega, const double zeta, const double Ts) |
| | **[TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-transferfunction)**() |
| | **[TransferFunction](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-transferfunction)**(std::vector< double > num, std::vector< double > den, const double Ts) |
| size_t | **[num_deg](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-num-deg)**(size_t num_idx =0) const |
| size_t | **[den_deg](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-den-deg)**(size_t num_idx =0) const |
| std::vector< double > | **[num_array](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-num-array)**() const |
| std::vector< double > | **[den_array](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1TransferFunction/#function-den-array)**() const |

## Additional inherited members

**Public Functions inherited from [cpp_robotics::StateSpaceSystem](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1StateSpaceSystem/)**

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

### function make_first_order_system

```cpp
static inline TransferFunction make_first_order_system(
    const double T,
    const double Ts
)
```


### function make_second_order_system

```cpp
static inline TransferFunction make_second_order_system(
    const double omega,
    const double zeta,
    const double Ts
)
```


### function TransferFunction

```cpp
inline TransferFunction()
```


### function TransferFunction

```cpp
inline TransferFunction(
    std::vector< double > num,
    std::vector< double > den,
    const double Ts
)
```


### function num_deg

```cpp
inline size_t num_deg(
    size_t num_idx =0
) const
```


### function den_deg

```cpp
inline size_t den_deg(
    size_t num_idx =0
) const
```


### function num_array

```cpp
inline std::vector< double > num_array() const
```


### function den_array

```cpp
inline std::vector< double > den_array() const
```


-------------------------------

Updated on 2022-10-05 at 16:05:00 +0900