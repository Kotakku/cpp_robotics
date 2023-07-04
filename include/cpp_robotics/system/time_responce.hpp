#pragma once

#include <tuple>
#include <type_traits>
#include "../utility/space.hpp"
#include "./transfer_function.hpp"
#include "./siso_system.hpp"

namespace cpp_robotics
{

/// @cond
namespace internal
{
template <class T>
class is_system_class
{
    template <class U>
    static auto check(U&& x)->decltype(x.Ts(), x.responce(0.0), std::true_type{});

    template <class U>
    static auto check(...)->std::false_type;

public:
    static constexpr bool value = decltype(check<T>(std::declval<T>()))::value;
};

template <class T>
class is_filter_class
{
    template <class U>
    static auto check(U&& x)->decltype(x.Ts(), x.filtering(0.0), std::true_type{});

    template <class U>
    static auto check(...)->std::false_type;

public:
    static constexpr bool value = decltype(check<T>(std::declval<T>()))::value;
};

template <class T>
struct is_pure_filter_class
{
    static constexpr bool value = not is_system_class<T>::value && is_filter_class<T>::value;
};

}
/// @endcond

/**
 * @brief インパルス応答を求める
 * 
 * @param sys 
 * @param dt
 * @param time 
 * @return std::tuple<std::vector<double>, std::vector<double>> 
 */
static std::tuple<std::vector<double>, std::vector<double>> impulse(const std::function<double(double)> &sys, double dt, double time)
{
    std::vector<double> t = arrange(0, time, dt);
    std::vector<double> res(t.size());
    for(size_t i = 0; i < res.size(); i++)
    {
        res[i] = sys( i == 0 ? 1.0/dt : 0.0);
    }
    return {t, res};
}

template<class SysType, typename std::enable_if<internal::is_system_class<SysType>::value>::type* = nullptr>
static std::tuple<std::vector<double>, std::vector<double>> impulse(SysType &sys, double time)
{
    return impulse([&](double u){ return sys.responce(u); }, sys.Ts(), time);
}

template<class SysType, typename std::enable_if<internal::is_pure_filter_class<SysType>::value>::type* = nullptr>
static std::tuple<std::vector<double>, std::vector<double>> impulse(SysType &sys, double time)
{
    return impulse([&](double u){ return sys.filtering(u); }, sys.Ts(), time);
}

/**
 * @brief ステップ応答を求める
 * 
 * @param sys 
 * @param dt 
 * @param time 
 * @param gain 
 * @return std::tuple<std::vector<double>, std::vector<double>> 
 */
static std::tuple<std::vector<double>, std::vector<double>> step(const std::function<double(double)> &sys, double dt, double time, const double gain = 1.0)
{
    std::vector<double> t = arrange(0, time, dt);
    std::vector<double> res(t.size());

    for(size_t i = 0; i < res.size(); i++)
    {
        res[i] = sys(gain);
    }

    return {t, res};
}

template<class SysType, typename std::enable_if<internal::is_system_class<SysType>::value>::type* = nullptr>
static std::tuple<std::vector<double>, std::vector<double>> step(SysType &sys, double time, const double gain = 1.0)
{
    return step([&](double u){ return sys.responce(u); }, sys.Ts(), time, gain);
}

template<class FilterType, typename std::enable_if<internal::is_pure_filter_class<FilterType>::value>::type* = nullptr>
static std::tuple<std::vector<double>, std::vector<double>> step(FilterType &filter, double time, const double gain = 1.0)
{
    return step([&](double u){ return filter.filtering(u); }, filter.Ts(), time, gain);
}

/**
 * @brief 任意の入力による応答を求める
 * 
 * @tparam DataIterativeType 
 * @param sys 
 * @param dt 
 * @param input 
 * @return std::tuple<DataIterativeType, DataIterativeType> 
 */
template<class DataIterativeType>
static std::tuple<DataIterativeType, DataIterativeType> lsim(const std::function<double(double)> &sys, double dt, const DataIterativeType &input)
{
    DataIterativeType t = linspace<DataIterativeType>(0, dt*input.size(), input.size());
    DataIterativeType res(t.size());
    for(decltype(res.size()) i = 0; i < res.size(); i++)
    {
        res[i] = sys(input[i]);
    }
    return {t, res};
}

template<class DataIterativeType, class SysType, typename std::enable_if<internal::is_system_class<SysType>::value>::type* = nullptr>
static std::tuple<DataIterativeType, DataIterativeType> lsim(SysType sys, const DataIterativeType &input, bool skip_reset = false)
{
    if(not skip_reset)
        sys.reset();
    return lsim([&](double u){ return sys.responce(u); }, sys.Ts(), input);
}

template<class DataIterativeType, class SysType, typename std::enable_if<internal::is_pure_filter_class<SysType>::value>::type* = nullptr>
static std::tuple<DataIterativeType, DataIterativeType> lsim(SysType sys, const DataIterativeType &input, bool skip_reset = false)
{
    if(not skip_reset)
        sys.reset();
    return lsim([&](double u){ return sys.filtering(u); }, sys.Ts(), input);
}

template<class DataIterativeType>
static std::tuple<DataIterativeType, DataIterativeType> lsim(TransferFunction::tf_t sys_config, const DataIterativeType &input)
{
    TransferFunction sys(sys_config);
    return lsim([&](double u){ return sys.responce(u); }, sys.Ts(), input);
}

template<class DataIterativeType>
static std::tuple<DataIterativeType, DataIterativeType, DataIterativeType> lsim(SisoFeedbackSystem sys, const DataIterativeType &input, bool skip_reset = false)
{
    if(not skip_reset)
        sys.reset();
    DataIterativeType t = linspace<DataIterativeType>(0, sys.Ts()*input.size(), input.size());
    DataIterativeType u(t.size());
    DataIterativeType res(t.size());
    for(decltype(res.size()) i = 0; i < res.size(); i++)
    {
        std::tie(u[i], res[i]) = sys.responce_uy(input[i]);
    }
    return {t, u, res};
}

template<class DataIterativeType>
static DataIterativeType lsim_y(const std::function<double(double)> &sys, double dt, const DataIterativeType &input)
{
    auto [t, res] = lsim(sys, dt, input);
    return res;
}

template<class DataIterativeType, class SysType, typename std::enable_if<internal::is_system_class<SysType>::value>::type* = nullptr>
static DataIterativeType lsim_y(SysType sys, const DataIterativeType &input, bool skip_reset = false)
{
    if(not skip_reset)
        sys.reset();
    return lsim_y([&](double u){ return sys.responce(u); }, sys.Ts(), input);
}

template<class DataIterativeType, class SysType, typename std::enable_if<internal::is_pure_filter_class<SysType>::value>::type* = nullptr>
static DataIterativeType lsim_y(SysType sys, const DataIterativeType &input, bool skip_reset = false)
{
    if(not skip_reset)
        sys.reset();
    return lsim_y([&](double u){ return sys.filtering(u); }, sys.Ts(), input);
}

template<class DataIterativeType>
static DataIterativeType lsim_y(TransferFunction::tf_t sys_config, const DataIterativeType &input)
{
    TransferFunction sys(sys_config);
    return lsim_y([&](double u){ return sys.responce(u); }, sys.Ts(), input);
}

template<class DataIterativeType>
static std::tuple<DataIterativeType, DataIterativeType> lsim_uy(SisoFeedbackSystem sys, const DataIterativeType &input, bool skip_reset = false)
{
    auto [t, u, res] = lsim(sys, input, skip_reset);
    return {u, res};
}

template<class DataIterativeType>
static DataIterativeType lsim_y(SisoFeedbackSystem sys, const DataIterativeType &input, bool skip_reset = false)
{
    auto [t, u, res] = lsim(sys, input, skip_reset);
    return res;
}

}