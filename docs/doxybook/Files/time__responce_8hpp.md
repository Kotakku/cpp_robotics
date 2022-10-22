---
title: include/cpp_robotics/system/time_responce.hpp

---

# include/cpp_robotics/system/time_responce.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |




## Source code

```cpp
#pragma once

#include <tuple>
#include <type_traits>
#include "../utility/space.hpp"
#include "./transfer_function.hpp"

namespace cpp_robotics
{

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

static std::tuple<std::vector<double>, std::vector<double>> lsim(const std::function<double(double)> &sys, double dt, const std::vector<double> &input)
{
    std::vector<double> t = linspace(0, dt*input.size(), input.size());
    std::vector<double> res(t.size());
    for(size_t i = 0; i < res.size(); i++)
    {
        res[i] = sys(input[i]);
    }
    return {t, res};
}

template<class SysType, typename std::enable_if<internal::is_system_class<SysType>::value>::type* = nullptr>
static std::tuple<std::vector<double>, std::vector<double>> lsim(SysType &sys, std::vector<double> input)
{
    return lsim([&](double u){ return sys.responce(u); }, sys.Ts(), input);
}

template<class SysType, typename std::enable_if<internal::is_pure_filter_class<SysType>::value>::type* = nullptr>
static std::tuple<std::vector<double>, std::vector<double>> lsim(SysType &sys, std::vector<double> input)
{
    return lsim([&](double u){ return sys.filtering(u); }, sys.Ts(), input);
}


}
```


-------------------------------

Updated on 2022-10-22 at 22:05:50 +0900
