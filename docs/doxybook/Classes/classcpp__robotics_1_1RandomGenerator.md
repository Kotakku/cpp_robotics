---
title: cpp_robotics::RandomGenerator
summary: 乱数生成器 stdの標準乱数生成器をラップしてこのクラス一つだけ実体化すれば乱数を生成できるようにした 

---

# cpp_robotics::RandomGenerator



乱数生成器 stdの標準乱数生成器をラップしてこのクラス一つだけ実体化すれば乱数を生成できるようにした  [More...](#detailed-description)


`#include <random.hpp>`

Inherits from Distribution

## Public Types

|                | Name           |
| -------------- | -------------- |
| using Distribution | **[distribution_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/#using-distribution-t)**  |
| using EngineMethod | **[engine_method_t](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/#using-engine-method-t)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| template <typename ... Arg\> <br>| **[RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/#function-randomgenerator)**(Arg ... arg)<br>コンストラクタ引数はDistributionに従う  |
| distribution_t::result_type | **[value](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/#function-value)**()<br>乱数を取得する, 戻り値の型はDistributionに従う  |

## Detailed Description

```cpp
template <class Distribution ,
class EngineMethod  =std::mt19937>
class cpp_robotics::RandomGenerator;
```

乱数生成器 stdの標準乱数生成器をラップしてこのクラス一つだけ実体化すれば乱数を生成できるようにした 

**Template Parameters**: 

  * **Distribution** 乱数の分布, std::normal_distribution<double>等 
  * **EngineMethod** 疑似乱数生成法, std::mt19937等 

## Public Types Documentation

### using distribution_t

```cpp
using cpp_robotics::RandomGenerator< Distribution, EngineMethod >::distribution_t =  Distribution;
```


### using engine_method_t

```cpp
using cpp_robotics::RandomGenerator< Distribution, EngineMethod >::engine_method_t =  EngineMethod;
```


## Public Functions Documentation

### function RandomGenerator

```cpp
template <typename ... Arg>
inline RandomGenerator(
    Arg ... arg
)
```

コンストラクタ引数はDistributionに従う 

**Parameters**: 

  * **arg** 


**Template Parameters**: 

  * **Arg** 


### function value

```cpp
inline distribution_t::result_type value()
```

乱数を取得する, 戻り値の型はDistributionに従う 

**Return**: distribution_t::result_type 

-------------------------------

Updated on 2022-09-27 at 01:12:56 +0900