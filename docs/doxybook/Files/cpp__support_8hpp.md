---
title: include/cpp_robotics/utility/cpp_support.hpp

---

# include/cpp_robotics/utility/cpp_support.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |




## Source code

```cpp
#pragma once

#include <string>
#include <cstdio>
#include <vector>
#include <iostream>

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

#ifdef CPP_ROBOTICS_CPP20_OR_GREATER
#include <format>
#endif

namespace cpp_robotics
{

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

template <typename... Args>
void print(const std::string &format, Args const&... args)
{
    std::cout << c_format(format, args...);
}

}
```


-------------------------------

Updated on 2022-10-08 at 23:36:07 +0900
