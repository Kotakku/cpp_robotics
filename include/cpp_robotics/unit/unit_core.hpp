#pragma once

#include <cstdint>
#include <cstdlib>
#include <type_traits>
#include <numeric>
#include <cmath>

namespace cpp_robotics
{

/**
 * @brief 単位系
 * 
 */
inline namespace unit
{
enum UnitIndex
{
    MetereIdx,
    KiloGramIdx,
    SecondIdx,
    AmpereIdx,
    KelvinIdx,
    MoleIdx,
    CandelaIdx
};

/**
 * @brief SI単位系次元定義クラス
 */
template<int DIM1, int DIM2, int DIM3, int DIM4, int DIM5, int DIM6, int DIM7>
struct UnitType{
    /**
     * @brief メートル(m)
     * 
     */
    static constexpr int dim1 = DIM1;

    /**
     * @brief キログラム(kg)
     * 
     */
    static constexpr int dim2 = DIM2;

    /**
     * @brief 秒(s)
     * 
     */
    static constexpr int dim3 = DIM3;

    /**
     * @brief アンペア(A)
     * 
     */
    static constexpr int dim4 = DIM4;

    /**
     * @brief ケルビン(K)
     * 
     */
    static constexpr int dim5 = DIM5;

    /**
     * @brief モル(mol)
     * 
     */
    static constexpr int dim6 = DIM6;

    /**
     * @brief カンデラ(cd)
     * 
     */
    static constexpr int dim7 = DIM7;
};

/// @cond
namespace unit_dim_assem
{
    template<class U1, class U2>
    struct udim_mul
    {
        using unit = UnitType<
            U1::dim1 + U2::dim1,
            U1::dim2 + U2::dim2,
            U1::dim3 + U2::dim3,
            U1::dim4 + U2::dim4,
            U1::dim5 + U2::dim5,
            U1::dim6 + U2::dim6,
            U1::dim7 + U2::dim7>;
    };

    template<class U1, class U2>
    struct udim_div
    {
        using unit = UnitType<
            U1::dim1 - U2::dim1,
            U1::dim2 - U2::dim2,
            U1::dim3 - U2::dim3,
            U1::dim4 - U2::dim4,
            U1::dim5 - U2::dim5,
            U1::dim6 - U2::dim6,
            U1::dim7 - U2::dim7>;
    };

    template<class U1, int N>
    struct udim_pow
    {
        using unit = UnitType<
            U1::dim1 * N,
            U1::dim2 * N,
            U1::dim3 * N,
            U1::dim4 * N,
            U1::dim5 * N,
            U1::dim6 * N,
            U1::dim7 * N>;
    };

    template<class U1>
    struct udim_inv
    {
        using unit = UnitType<
            -U1::dim1,
            -U1::dim2,
            -U1::dim3,
            -U1::dim4,
            -U1::dim5,
            -U1::dim6,
            -U1::dim7>;
    };
}
/// @endcond

/// @cond
struct PrefixBase 
{
    PrefixBase() = delete;
};
/// @endcond

/**
 * @brief 単位系接頭辞クラス
 * 
 * @tparam N 
 * @tparam D 
 */
template<uint32_t N, uint32_t D>
struct Prefix : public PrefixBase
{
    using type = Prefix<N, D>;
    static constexpr uint32_t num = N / std::gcd(N, D);
    static constexpr uint32_t den = D / std::gcd(N, D);
};

namespace prefix
{
    using nano  = Prefix<1, 1000000000>;
    using micro = Prefix<1,    1000000>;
    using milli = Prefix<1,       1000>;
    using centi = Prefix<1,        100>;
    using deci  = Prefix<1,         10>;
    using none  = Prefix<1,          1>;
    using deca  = Prefix<        10, 1>;
    using hecto = Prefix<       100, 1>;
    using kilo  = Prefix<      1000, 1>;
    using mega  = Prefix<   1000000, 1>;
    using giga  = Prefix<1000000000, 1>;

    template<class P1, class P2>
    struct pfx_mul
    {
        static constexpr uint32_t raw_num = P2::num * P1::num;
        static constexpr uint32_t raw_den = P2::den * P1::den;
        using prefix = Prefix<raw_num, raw_den>;
    };

    template<class P1, class P2>
    struct pfx_div
    {
        static constexpr uint32_t raw_num = P1::num * P2::den;
        static constexpr uint32_t raw_den = P1::den * P2::num;
        using prefix = Prefix<raw_num, raw_den>;
    };

    template<class P>
    struct pfx_inv
    {
        using prefix = Prefix<P::den, P::num>;
    };

    template<class P1, class P2>
    struct pfx_min
    {
        static constexpr uint32_t raw_num = std::min(P1::num * P2::den, P2::num * P1::den);
        static constexpr uint32_t raw_den = P1::den * P2::den;
        using prefix = Prefix<raw_num, raw_den>;
    };
}

namespace tag
{
    enum angle
    {
        radian = 0,
        degree
    };

    enum angular_vel
    {
        rad_per_sec = 0,
        rps,
        rpm
    };

    template <int Tag>
    struct is_normal_tag : std::false_type{};

    template<>
    struct is_normal_tag<-1> : std::true_type{};
    template<>
    struct is_normal_tag<0> : std::true_type{};
}

template<class UnitDimType, int FromTag, int ToTag, bool IsNormalTag = tag::is_normal_tag<FromTag>::value && tag::is_normal_tag<ToTag>::value>
constexpr double conv_factor()
{
    static_assert(IsNormalTag == true, "conv_factor is not defined");
    return 1;
}

/**
 * @brief 単位クラス
 * 
 * @tparam T 浮動小数点数型
 * @tparam UnitDimType 次元
 * @tparam P 接頭辞
 * @tparam Tag 同次元の単位系を区別するタグ
 */
template<class T, class UnitDimType, class P, int Tag = -1>
class Unit
{
    static_assert(std::is_arithmetic_v<T>, "T is not arithmetic.");
    static_assert(std::is_base_of_v<PrefixBase, P> && !std::is_same_v<PrefixBase, P>, "");

public:
    using value_type = T;
    using unit_dimention_type = UnitDimType;
    using prefix_type = P;
    using unit_type = Unit<T, UnitDimType, P>;
    static constexpr int tag = Tag;

    Unit() = default;
    constexpr Unit(T val): val_(val){}
    constexpr T value() const { return val_; }
    constexpr T raw_value() const { return val_ * P::num / P::den; }
    
    //////////////////// 符号 ////////////////////
    constexpr unit_type operator +() const
    {
        return val_;
    }

    constexpr unit_type operator -() const
    {
        return -val_;
    }

    //////////////////// 同一単位同士 ////////////////////
    constexpr unit_type operator +(const unit_type& rhl) const
    {
        return {val_ + rhl.value()};
    }

    constexpr unit_type operator -(const unit_type& rhl) const
    {
        return {val_ - rhl.value()};
    }

    constexpr auto operator *(const unit_type& rhl) const
    {
        using ret_dim_type = typename unit_dim_assem::udim_mul<unit_dimention_type, unit_dimention_type>::unit;
        using ret_type = Unit<value_type, ret_dim_type, prefix::none>;

        return ret_type{raw_value() * rhl.raw_value()};
    }

    //////////////////// 自己演算 ////////////////////
    constexpr unit_type& operator +=(const unit_type& rhl)
    {
        val_ += rhl.value();
        return *this;
    }

    constexpr unit_type& operator -=(const unit_type& rhl)
    {
        val_ -= rhl.value();
        return *this;
    }

    //////////////////// キャスト演算 ////////////////////
    // タグの変換
    template<int R_Tag>
    constexpr operator Unit<value_type, unit_dimention_type, prefix_type, R_Tag>() const
    {

        using ret_type = Unit<T, UnitDimType, prefix_type, R_Tag>;
        if constexpr (tag == -1 && R_Tag == 0)
        {
            ret_type{value()};
        }
        return ret_type{value() * conv_factor<unit_dimention_type, tag, R_Tag>()};
    }

    // 接頭語の変換
    template<class R_P>
    constexpr operator Unit<value_type, unit_dimention_type, R_P, tag>() const
    {
        using ret_type = Unit<T, UnitDimType, R_P>;
        using scale_prefix = typename prefix::pfx_div<R_P, prefix_type>::prefix;
        return ret_type{value() * scale_prefix::den / scale_prefix::num};
    }
    
    // 数値型に変換
    constexpr operator value_type() const
    {
        return static_cast<value_type>(val_);
    }

    //////////////////// 比較演算 ////////////////////
    constexpr bool operator ==(const unit_type &r_value)
    {
        return val_ == r_value.value();
    }

    constexpr bool operator !=(const unit_type &r_value)
    {
        return !(val_ == r_value);
    }
    
private:
    T val_;
};

/// @cond
namespace unit_assem
{
    template<class Unit1, class Unit2>
    struct unit_mul
    {
        static_assert(std::is_same_v<typename Unit1::value_type, typename Unit2::value_type>, "");
        // static_assert(Unit1::tag == 0 && Unit2::tag == 0, "");
        using dim = typename unit_dim_assem::udim_mul<typename Unit1::unit_dimention_type, typename Unit2::unit_dimention_type>::unit;
        using pfx = typename prefix::pfx_mul<typename Unit1::prefix_type, typename Unit2::prefix_type>::prefix;
        using unit = Unit<typename Unit1::value_type, dim, pfx>;
    };

    template<class Unit1, class Unit2>
    struct unit_div
    {
        static_assert(std::is_same_v<typename Unit1::value_type, typename Unit2::value_type>, "");
        // static_assert(Unit1::tag == 0 && Unit2::tag == 0, "");
        using dim = typename unit_dim_assem::udim_div<typename Unit1::unit_dimention_type, typename Unit2::unit_dimention_type>::unit;
        using pfx = typename prefix::pfx_div<typename Unit1::prefix_type, typename Unit2::prefix_type>::prefix;
        using unit = Unit<typename Unit1::value_type, dim, pfx>;
    };

    template<class UnitType>
    struct unit_inv
    {
        using dim = typename unit_dim_assem::udim_inv<typename UnitType::unit_dimention_type>::unit;
        using pfx = typename prefix::pfx_inv<typename UnitType::prefix_type>::prefix;
        using unit = Unit<typename UnitType::value_type, dim, pfx, 0>;
    };

    template<class UnitType, class PrefixType>
    struct unit_pfx_scaled
    {
        using unit = Unit<typename UnitType::value_type, 
            typename UnitType::unit_dimention_type, 
            typename prefix::pfx_mul<typename UnitType::prefix_type, PrefixType>::prefix,
            UnitType::tag>;
    };
}
/// @endcond

// template <class UnitType, typename T>
// constexpr auto operator <=>(const UnitType &l_value, const T &r_value)
// {
//     return static_cast<typename UnitType::value_type>(l_value) <=> r_value;
// }

// 単位*数値
template <typename T1, typename T2, class UnitDim, class Prefix, int Tag>
constexpr auto operator *(const Unit<T1, UnitDim, Prefix, Tag> &l_value, const T2 &r_value)
{
    static_assert(std::is_arithmetic_v<T1> && std::is_arithmetic_v<T2>, "Type is not arithmetic");
    using unit_type = Unit<T1, UnitDim, Prefix, Tag>;
    return unit_type(l_value.value() * r_value);
}

// 数値*単位
template <typename T1, typename T2, class UnitDim, class Prefix, int Tag>
constexpr auto operator *(const T1 &l_value, const Unit<T2, UnitDim, Prefix, Tag> &r_value)
{
    static_assert(std::is_arithmetic_v<T1> && std::is_arithmetic_v<T2>, "Type is not arithmetic");
    using unit_type = Unit<T2, UnitDim, Prefix, Tag>;
    return unit_type(l_value * r_value.value());
}

// 数値/単位
template <typename T1, typename T2, class UnitDim, class Prefix, int Tag>
constexpr auto operator /(const T1 &l_value, const Unit<T2, UnitDim, Prefix, Tag> &r_value)
{
    static_assert(std::is_arithmetic_v<T1> && std::is_arithmetic_v<T2>, "Type is not arithmetic");
    using unit_type = Unit<T2, UnitDim, Prefix, Tag>;
    return typename unit_assem::unit_inv<unit_type>::unit(l_value / r_value.value());
}

// 単位/数値
template <typename T1, typename T2, class UnitDim, class Prefix, int Tag>
constexpr auto operator /(const Unit<T1, UnitDim, Prefix, Tag> &l_value, const T2 &r_value)
{
    static_assert(std::is_arithmetic_v<T1> && std::is_arithmetic_v<T2>, "Type is not arithmetic");
    using unit_type = Unit<T1, UnitDim, Prefix, Tag>;
    return unit_type(l_value.value() / r_value);
}

// 単位*単位
template<typename T1, class UnitDim1, class Prefix1, int Tag1, typename T2, class UnitDim2, class Prefix2, int Tag2>
constexpr auto operator *(const Unit<T1, UnitDim1, Prefix1, Tag1>& lhl, const Unit<T2, UnitDim2, Prefix2, Tag2> &rhl)
{
    // static_assert(std::is_base_of_v<Unit, R_UnitDimType> && std::is_base_of_v<Unit, L_UnityDimType>, "test");
    static_assert(tag::is_normal_tag<Tag1>::value && tag::is_normal_tag<Tag2>::value, "Type has not normal tag");
    // static_assert(R_UnitDimType)
    // static_assert(R_P)
    using ret_dim_type = typename unit_dim_assem::udim_mul<UnitDim1, UnitDim2>::unit;
    using ret_type = Unit<T1, ret_dim_type, prefix::none>;
    return ret_type{lhl.raw_value() * rhl.raw_value()};
}

// 単位/単位
template<typename T1, class UnitDim1, class Prefix1, int Tag1, typename T2, class UnitDim2, class Prefix2, int Tag2>
constexpr auto operator /(const Unit<T1, UnitDim1, Prefix1, Tag1>& lhl, const Unit<T2, UnitDim2, Prefix2, Tag2> &rhl)
{
    static_assert(tag::is_normal_tag<Tag1>::value && tag::is_normal_tag<Tag2>::value, "Type has not normal tag");
    // static_assert(R_UnitDimType)
    // static_assert(R_P)
    static_assert(tag::is_normal_tag<Tag2>::value, "R_Tag is imcorrect");
    using ret_dim_type = typename unit_dim_assem::udim_div<UnitDim1, UnitDim2>::unit;
    using ret_type = Unit<T1, ret_dim_type, prefix::none>;
    return ret_type{lhl.raw_value() / rhl.raw_value()};
}

// 単位+単位(prefix違い)
// prefixが小さい方で返す
template<typename T, class UnitDim, class Prefix1, class Prefix2, int Tag>
constexpr auto operator +(const Unit<T, UnitDim, Prefix1, Tag>& lhl, const Unit<T, UnitDim, Prefix2, Tag> &rhl)
{
    using min_prefix = typename prefix::pfx_min<Prefix1, Prefix2>::prefix;

    
    using lpfx = typename prefix::pfx_div<Prefix1, min_prefix>::prefix;
    T lhl_scaled_val = lhl.value() * lpfx::num / lpfx::den;
    
    using rpfx = typename prefix::pfx_div<Prefix2, min_prefix>::prefix;
    T rhl_scaled_val = rhl.value() * rpfx::num / rpfx::den;

    using ret_type = Unit<T, UnitDim, min_prefix, Tag>;
    return ret_type{lhl_scaled_val + rhl_scaled_val};
}

template<typename T, class UnitDim, class Prefix1, class Prefix2, int Tag>
constexpr auto operator -(const Unit<T, UnitDim, Prefix1, Tag>& lhl, const Unit<T, UnitDim, Prefix2, Tag> &rhl)
{
    using min_prefix = typename prefix::pfx_min<Prefix1, Prefix2>::prefix;

    using lpfx = typename prefix::pfx_div<Prefix1, min_prefix>::prefix;
    T lhl_scaled_val = lhl.value() * lpfx::num / lpfx::den;
    
    using rpfx = typename prefix::pfx_div<Prefix2, min_prefix>::prefix;
    T rhl_scaled_val = rhl.value() * rpfx::num / rpfx::den;

    using ret_type = Unit<T, UnitDim, min_prefix, Tag>;
    return ret_type{lhl_scaled_val - rhl_scaled_val};
}

#define GENERATE_CONV_FACTOR(unit_dim, from_tag, to_tag, factor)\
template<>\
constexpr double conv_factor<unit_dim, from_tag, to_tag>()\
{\
    return (factor);\
}

#define GENERATE_UNIT_SUFFIX(unit, suffix)\
constexpr unit operator"" _## suffix(unsigned long long val)\
{\
    return unit{static_cast<double>(val)};\
}\
constexpr unit operator"" _## suffix(long double val)\
{\
    return unit{static_cast<double>(val)};\
}

#define GENERATE_UNIT_PFX_SUFFIX(unit_type, prefix, suffix)\
constexpr auto operator"" _## suffix(unsigned long long val)\
{\
    using namespace cpp_robotics::unit;\
    return unit_assem::unit_pfx_scaled<unit_type, prefix>::unit{static_cast<double>(val)};\
}\
constexpr auto operator"" _## suffix(long double val)\
{\
    using namespace cpp_robotics::unit;\
    return unit_assem::unit_pfx_scaled<unit_type, prefix>::unit{static_cast<double>(val)};\
}

}
}
