---
title: include/cpp_robotics/algorithm/random.hpp

---

# include/cpp_robotics/algorithm/random.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::RandomGenerator](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1RandomGenerator/)** <br>stdの乱数生成をラップしてこのクラス一つだけ実体化すればいいようにした乱数生成器  |




## Source code

```cpp
# pragma once

#include <cmath>
#include <random>
#include "../utility/singleton.hpp"

namespace cpp_robotics
{

namespace internal
{
template<class Method>
class RandomEngineWrapper
{
public:
    using engine_method_t = Method;

    RandomEngineWrapper():
        engine_((*Singleton<std::random_device>::get_shared_instance())()){}

    engine_method_t& get_engine()
    {
        return engine_;
    }

private:
    engine_method_t engine_;
};
}

template<class Distribution, class EngineMethod = std::mt19937>
class RandomGenerator : public Distribution
{
public:
    using distribution_t = Distribution;
    using engine_method_t = EngineMethod;

    template<typename ...Arg>
    RandomGenerator(Arg ...arg):
        distribution_t(arg...)
    {
        engine_wrapper_ = Singleton<engine_t>::get_shared_instance();
    }

    typename distribution_t::result_type value()
    {
        auto &dist = *(distribution_t*)(this);
        return dist(engine_wrapper_->get_engine());
    }

private:
    using engine_t = internal::RandomEngineWrapper<engine_method_t>;
    typename Singleton<engine_t>::shared_t engine_wrapper_;
};

using UniformIntRandomEngine = RandomGenerator<std::uniform_int_distribution<>>;
using UniformRealRandomEngine = RandomGenerator<std::uniform_real_distribution<>>;

using BernoulliRandomEngine = RandomGenerator<std::bernoulli_distribution>;
using BinomialRandomEngine = RandomGenerator<std::binomial_distribution<>>;
using GeometricRandomEngine = RandomGenerator<std::geometric_distribution<>>;
using NegativeBinomialRandomEngine = RandomGenerator<std::negative_binomial_distribution<>>;


using PoissonRandomEngine = RandomGenerator<std::poisson_distribution<>>;
using ExponentialRandomEngine = RandomGenerator<std::exponential_distribution<>>;
using GammaRandomEngine = RandomGenerator<std::gamma_distribution<>>;
using WeibullRandomEngine = RandomGenerator<std::weibull_distribution<>>;
using ExtremeValueRandomEngine = RandomGenerator<std::extreme_value_distribution<>>;



using NormalRandomEngine = RandomGenerator<std::normal_distribution<>>;

using LognormalRandomEngine = RandomGenerator<std::lognormal_distribution<>>;
using ChiSquaredRandomEngine = RandomGenerator<std::chi_squared_distribution<>>;
using CauchyRandomEngine = RandomGenerator<std::cauchy_distribution<>>;
using FisherFRandomEngine = RandomGenerator<std::fisher_f_distribution<>>;
using StudentTRandomEngine = RandomGenerator<std::student_t_distribution<>>;

using DiscreteRandomEngine = RandomGenerator<std::discrete_distribution<>>;
using PiecewiseConstantRandomEngine = RandomGenerator<std::piecewise_constant_distribution<>>;
using PiecewiseLinearRandomEngine = RandomGenerator<std::piecewise_linear_distribution<>>;

template<typename Real = double>
static Real gererate_random()
{
    using engine_t = internal::RandomEngineWrapper<std::mt19937>;
    auto engine_wrapper = Singleton<engine_t>::get_shared_instance();
    constexpr std::size_t bits = std::numeric_limits<Real>::digits;
    return std::generate_canonical<Real, bits>(engine_wrapper->get_engine());
}

}
```


-------------------------------

Updated on 2022-10-02 at 13:22:12 +0900
