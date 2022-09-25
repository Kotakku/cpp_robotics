---
title: matplotlibcpp::detail::is_callable

---

# matplotlibcpp::detail::is_callable



 [More...](#detailed-description)


`#include <matplotlibcpp.h>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| typedef [is_callable_impl](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1is__callable__impl/)< std::is_class< T >::value, T >::[type](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1is__callable/#typedef-type) | **[type](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1is__callable/#typedef-type)**  |

## Detailed Description

```cpp
template <typename T >
struct matplotlibcpp::detail::is_callable;
```

## Public Types Documentation

### typedef type

```cpp
typedef is_callable_impl<std::is_class<T>::value, T>::type matplotlibcpp::detail::is_callable< T >::type;
```


-------------------------------

Updated on 2022-09-25 at 23:10:54 +0900