---
title: cpp_robotics::AutoDiffAdaptor
summary: 自動微分でヤコビアンを求めるクラス 

---

# cpp_robotics::AutoDiffAdaptor



自動微分でヤコビアンを求めるクラス  [More...](#detailed-description)


`#include <auto_diff.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| enum| **[@0](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#enum-@0)** { InputsAtCompileTime = NX, ValuesAtCompileTime = NY} |
| using Eigen::Matrix< Scalar, NX, 1 > | **[InputVector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-inputvector)**  |
| using Eigen::Matrix< Scalar, NY, 1 > | **[ValueVector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-valuevector)**  |
| using Eigen::Matrix< Scalar, NY, NX > | **[JacobianMatrix](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-jacobianmatrix)**  |
| using Eigen::Matrix< Scalar, NX, NX > | **[HessianMatrix](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-hessianmatrix)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[AutoDiffAdaptor](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#function-autodiffadaptor)**(Functor & functor)<br>引数/戻り値が静的サイズのベクトルである場合のコンストラクタ  |
| | **[AutoDiffAdaptor](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#function-autodiffadaptor)**(Functor & functor, const size_t input_size, const size_t value_size)<br>引数/戻り値が動的サイズのベクトルである場合のコンストラクタ  |
| void | **[evalute](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#function-evalute)**(const [InputVector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-inputvector) & x, [ValueVector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-valuevector) & y)<br>関数の評価  |
| [ValueVector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-valuevector) | **[evalute](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#function-evalute)**(const [InputVector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-inputvector) & x)<br>関数の評価  |
| std::function< [ValueVector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-valuevector)([InputVector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-inputvector))> | **[evalute_func](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#function-evalute-func)**() |
| std::function< double([InputVector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-inputvector))> | **[evalute_func_scalar](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#function-evalute-func-scalar)**() |
| void | **[jacobian](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#function-jacobian)**(const [InputVector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-inputvector) & x, [JacobianMatrix](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-jacobianmatrix) & jac)<br>ヤコビアンの評価  |
| [JacobianMatrix](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-jacobianmatrix) | **[jacobian](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#function-jacobian)**(const [InputVector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-inputvector) & x)<br>ヤコビアンの評価  |
| std::function< [JacobianMatrix](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-jacobianmatrix)([InputVector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-inputvector))> | **[jacobian_func](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#function-jacobian-func)**() |
| std::function< Eigen::Matrix< Scalar, NX, 1 >[InputVector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#using-inputvector))> | **[jacobian_func_row_vector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1AutoDiffAdaptor/#function-jacobian-func-row-vector)**() |

## Detailed Description

```cpp
template <class Functor ,
class DerType  =Eigen::VectorXd,
typename Scalar  =double,
int NX =Eigen::Dynamic,
int NY =Eigen::Dynamic>
class cpp_robotics::AutoDiffAdaptor;
```

自動微分でヤコビアンを求めるクラス 

**Template Parameters**: 

  * **Functor** 関数のクラス, template<typename T> static void eval_func(const Eigen::Matrix<T,Eigen::Dynamic,1>& x, Eigen::Matrix<T,Eigen::Dynamic,1>& y)を持つ必要がある 
  * **DerType** 
  * **Scalar** 
  * **NX** 
  * **NY** 

## Public Types Documentation

### enum @0

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| InputsAtCompileTime | NX|   |
| ValuesAtCompileTime | NY|   |




### using InputVector

```cpp
using cpp_robotics::AutoDiffAdaptor< Functor, DerType, Scalar, NX, NY >::InputVector =  Eigen::Matrix<Scalar, NX, 1>;
```


### using ValueVector

```cpp
using cpp_robotics::AutoDiffAdaptor< Functor, DerType, Scalar, NX, NY >::ValueVector =  Eigen::Matrix<Scalar, NY, 1>;
```


### using JacobianMatrix

```cpp
using cpp_robotics::AutoDiffAdaptor< Functor, DerType, Scalar, NX, NY >::JacobianMatrix =  Eigen::Matrix<Scalar, NY, NX>;
```


### using HessianMatrix

```cpp
using cpp_robotics::AutoDiffAdaptor< Functor, DerType, Scalar, NX, NY >::HessianMatrix =  Eigen::Matrix<Scalar, NX, NX>;
```


## Public Functions Documentation

### function AutoDiffAdaptor

```cpp
inline AutoDiffAdaptor(
    Functor & functor
)
```

引数/戻り値が静的サイズのベクトルである場合のコンストラクタ 

**Parameters**: 

  * **functor** 


### function AutoDiffAdaptor

```cpp
inline AutoDiffAdaptor(
    Functor & functor,
    const size_t input_size,
    const size_t value_size
)
```

引数/戻り値が動的サイズのベクトルである場合のコンストラクタ 

**Parameters**: 

  * **functor** 
  * **input_size** 関数の引数の次元 
  * **value_size** 関数の戻り値の次元 


### function evalute

```cpp
inline void evalute(
    const InputVector & x,
    ValueVector & y
)
```

関数の評価 

**Parameters**: 

  * **x** 
  * **y** 


### function evalute

```cpp
inline ValueVector evalute(
    const InputVector & x
)
```

関数の評価 

**Parameters**: 

  * **x** 


**Return**: ValueVector 

### function evalute_func

```cpp
inline std::function< ValueVector(InputVector)> evalute_func()
```


### function evalute_func_scalar

```cpp
inline std::function< double(InputVector)> evalute_func_scalar()
```


### function jacobian

```cpp
inline void jacobian(
    const InputVector & x,
    JacobianMatrix & jac
)
```

ヤコビアンの評価 

**Parameters**: 

  * **x** 
  * **jac** 


### function jacobian

```cpp
inline JacobianMatrix jacobian(
    const InputVector & x
)
```

ヤコビアンの評価 

**Parameters**: 

  * **x** 


**Return**: JacobianMatrix 

### function jacobian_func

```cpp
inline std::function< JacobianMatrix(InputVector)> jacobian_func()
```


### function jacobian_func_row_vector

```cpp
inline std::function< Eigen::Matrix< Scalar, NX, 1 >InputVector)> jacobian_func_row_vector()
```


-------------------------------

Updated on 2022-10-08 at 23:36:07 +0900