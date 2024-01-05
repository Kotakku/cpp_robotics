#pragma once

#include <string>
#include <cstdio>
#include <vector>

// platform
#if defined(linux) || defined(__linux) || defined(__linux__)
#  define CPP_ROBOTICS_PLATFORM_LINUX

#elif defined(WIN32) || defined(__WIN32__) || defined(_WIN32) || defined(_MSC_VER) || defined(__MINGW32__)
#  define CPP_ROBOTICS_PLATFORM_WINDOWS
#endif

// C++ version
#ifdef __cplusplus

#  if (__cplusplus >= 201103L) || (defined(_MSVC_LANG) && _MSVC_LANG >= 201103L)
#    define CPP_ROBOTICS_CPP11_OR_GREATER
#  endif

#  if (__cplusplus >= 201402L) || (defined(_MSVC_LANG) && _MSVC_LANG >= 201402L)
#    define CPP_ROBOTICS_CPP14_OR_GREATER
#  endif

#  if (__cplusplus >= 201703L) || (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L)
#    define CPP_ROBOTICS_CPP17_OR_GREATER
#  endif

#  if (__cplusplus >= 202002L) || (defined(_MSVC_LANG) && _MSVC_LANG >= 202002L)
#    define CPP_ROBOTICS_CPP20_OR_GREATER
#  endif

#endif

#include <string_view>

// #ifdef CPP_ROBOTICS_CPP20_OR_GREATER
// #include <format>
// #endif

namespace cpp_robotics
{

/**
 * @brief Substitute shift_left function in C++20 alogorithm
 * 
 * @tparam ForwardIterator 
 * @param first 
 * @param last 
 * @param n 
 * @return constexpr ForwardIterator 
 */
template <class ForwardIterator>
constexpr ForwardIterator shift_left(ForwardIterator first,
                                        ForwardIterator last,
                                        typename std::iterator_traits<ForwardIterator>::difference_type n)
{
    if (n <= 0)
        return last;
    if (n >= last - first)
        return first;

    ForwardIterator it = first;
    ForwardIterator nlast = std::prev(last, n);
    while (it != nlast)
    {
        ForwardIterator nit = std::next(it, n);
        *it = *nit;
        it++;
    }
    return first + (last - first - n);
}

/**
 * @brief Substitute shift_right function in C++20 alogorithm
 * 
 * @tparam ForwardIterator 
 * @param first 
 * @param last 
 * @param n 
 * @return constexpr ForwardIterator 
 */
template <class ForwardIterator>
constexpr ForwardIterator shift_right(ForwardIterator first,
                                        ForwardIterator last,
                                        typename std::iterator_traits<ForwardIterator>::difference_type n)
{
    if (n <= 0)
        return first;
    if (n >= last - first)
        return last;

    ForwardIterator it = std::prev(last, n);
    ForwardIterator nfirst = std::prev(first, 1);
    while (it != nfirst)
    {
        ForwardIterator nit = std::next(it, n);
        *nit = *it;
        it--;
    }

    return first + n;
}

/**
 * @brief printfと同様の操作でstd::stringを得る
 * 
 * @tparam Args 
 * @param format 
 * @param args 
 * @return std::string 
 */
template <typename... Args>
std::string c_format(const std::string &format, Args const&... args)
{
#pragma GCC diagnostic ignored "-Wformat-security"
    size_t len = std::snprintf(nullptr, 0, format.c_str(), args...);
    std::vector<char> buf(len + 1);
    std::snprintf(&buf[0], len + 1, format.c_str(), args...);
    return std::string{&buf[0], &buf[0] + len};
#pragma GCC diagnostic warning "-Wformat-security"
}

}