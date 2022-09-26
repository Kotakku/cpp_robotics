# pragma once

#include <cmath>
#include <random>
#include "../utility/singleton.hpp"

namespace cpp_robotics
{

/// @cond
namespace internal
{
template<class Method>
class RandomEngineWrapper
{
public:
    using engine_method_t = Method;

    RandomEngineWrapper():
        engine_((*Singleton<std::random_device>::get_instance())()){}

    engine_method_t& get_engine()
    {
        return engine_;
    }

private:
    engine_method_t engine_;
};
}
/// @endcond

/**
 * @brief 乱数生成器 stdの標準乱数生成器をラップしてこのクラス一つだけ実体化すれば乱数を生成できるようにした
 * 
 * @tparam Distribution 乱数の分布, std::normal_distribution<double>等
 * @tparam EngineMethod 疑似乱数生成法, std::mt19937等
 */
template<class Distribution, class EngineMethod = std::mt19937>
class RandomGenerator : public Distribution
{
public:
    using distribution_t = Distribution;
    using engine_method_t = EngineMethod;

    /**
     * @brief コンストラクタ引数はDistributionに従う
     * 
     * @tparam Arg 
     * @param arg 
     */
    template<typename ...Arg>
    RandomGenerator(Arg ...arg):
        distribution_t(arg...) {}

    /**
     * @brief 乱数を取得する, 戻り値の型はDistributionに従う
     * 
     * @return distribution_t::result_type 
     */
    typename distribution_t::result_type value()
    {
        using engine_t = internal::RandomEngineWrapper<engine_method_t>;
        auto &engine_wrapper = *Singleton<engine_t>::get_instance();
        auto &engine = engine_wrapper.get_engine();
        auto &dist = *(distribution_t*)(this);
        return dist(engine);
    }
};

/**
 * @brief 整数型一様分布乱数生成エンジン
 * 
 */
using UniformIntRandomEngine = RandomGenerator<std::uniform_int_distribution<>>;
/**
 * @brief 実数型一様分布乱数生成エンジン
 * 
 */
using UniformRealRandomEngine = RandomGenerator<std::uniform_real_distribution<>>;

/**
 * @brief ベルヌーイ分布乱数生成エンジン
 * 
 */
using BernoulliRandomEngine = RandomGenerator<std::bernoulli_distribution>;
/**
 * @brief 二項分布乱数生成エンジン
 * 
 */
using BinomialRandomEngine = RandomGenerator<std::binomial_distribution<>>;
/**
 * @brief 幾何学分布乱数生成エンジン
 * 
 */
using GeometricRandomEngine = RandomGenerator<std::geometric_distribution<>>;
/**
 * @brief 負の二項分布乱数生成エンジン
 * 
 */
using NegativeBinomialRandomEngine = RandomGenerator<std::negative_binomial_distribution<>>;


/**
 * @brief ポワソン分布乱数生成エンジン
 * 
 */
using PoissonRandomEngine = RandomGenerator<std::poisson_distribution<>>;
/**
 * @brief 指数分布乱数生成エンジン
 * 
 */
using ExponentialRandomEngine = RandomGenerator<std::exponential_distribution<>>;
/**
 * @brief ガンマ分布乱数生成エンジン
 * 
 */
using GammaRandomEngine = RandomGenerator<std::gamma_distribution<>>;
/**
 * @brief ワイブル分布乱数生成エンジン
 * 
 */
using WeibullRandomEngine = RandomGenerator<std::weibull_distribution<>>;
/**
 * @brief 極値分布乱数生成エンジン
 * 
 */
using ExtremeValueRandomEngine = RandomGenerator<std::extreme_value_distribution<>>;



/**
 * @brief 正規分布乱数生成エンジン
 * 
 */
using NormalRandomEngine = RandomGenerator<std::normal_distribution<>>;

/**
 * @brief 対数正規分布乱数生成エンジン
 * 
 */
using LognormalRandomEngine = RandomGenerator<std::lognormal_distribution<>>;
/**
 * @brief カイ二乗分布乱数生成エンジン
 * 
 */
using ChiSquaredRandomEngine = RandomGenerator<std::chi_squared_distribution<>>;
/**
 * @brief コーシー分布乱数生成エンジン
 * 
 */
using CauchyRandomEngine = RandomGenerator<std::cauchy_distribution<>>;
/**
 * @brief フィッシャーのF分布乱数生成エンジン
 * 
 */
using FisherFRandomEngine = RandomGenerator<std::fisher_f_distribution<>>;
/**
 * @brief ステューデントのt分布乱数生成エンジン
 * 
 */
using StudentTRandomEngine = RandomGenerator<std::student_t_distribution<>>;

/**
 * @brief 整数のインデックスごとに離散した確率分布の乱数生成エンジン
 * 
 */
using DiscreteRandomEngine = RandomGenerator<std::discrete_distribution<>>;
/**
 * @brief 区間ごとの重み付けを定数値とした分布の乱数生成エンジン
 * 
 */
using PiecewiseConstantRandomEngine = RandomGenerator<std::piecewise_constant_distribution<>>;
/**
 * @brief 区間ごとの重み付けを線形に接続した分布の乱数生成エンジン
 * 
 */
using PiecewiseLinearRandomEngine = RandomGenerator<std::piecewise_linear_distribution<>>;

/**
 * @brief 0.0〜1.0までの一様分布の乱数を生成する
 * 
 * @tparam Real 浮動小数点型
 * @return Real 乱数
 */
template<typename Real = double>
static Real gererate_random()
{
    using engine_t = internal::RandomEngineWrapper<std::mt19937>;
    auto &engine_wrapper = *Singleton<engine_t>::get_instance();
    auto &engine = engine_wrapper.get_engine();
    constexpr std::size_t bits = std::numeric_limits<Real>::digits;
    return std::generate_canonical<Real, bits>(engine);
}

}