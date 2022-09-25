---
title: matplotlibcpp::detail::is_callable_impl< true, T >

---

# matplotlibcpp::detail::is_callable_impl< true, T >



 [More...](#detailed-description)


`#include <matplotlibcpp.h>`

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[Check](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1is__callable__impl_3_01true_00_01T_01_4_1_1Check/)**  |
| struct | **[Derived](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1is__callable__impl_3_01true_00_01T_01_4_1_1Derived/)**  |
| struct | **[Fallback](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1is__callable__impl_3_01true_00_01T_01_4_1_1Fallback/)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| template <typename U \> <br>std::true_type | **[test](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1is__callable__impl_3_01true_00_01T_01_4/#function-test)**(... ) |
| template <typename U \> <br>std::false_type | **[test](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1is__callable__impl_3_01true_00_01T_01_4/#function-test)**(Check< void(Fallback::*)(), &U::operator()> * ) |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| decltype([test](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1is__callable__impl_3_01true_00_01T_01_4/#function-test)< Derived >(nullptr)) typedef | **[type](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1is__callable__impl_3_01true_00_01T_01_4/#variable-type)**  |
| decltype(&Fallback::operator()) typedef | **[dtype](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1is__callable__impl_3_01true_00_01T_01_4/#variable-dtype)**  |
| constexpr bool | **[value](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1is__callable__impl_3_01true_00_01T_01_4/#variable-value)**  |

## Detailed Description

```cpp
template <typename T >
struct matplotlibcpp::detail::is_callable_impl< true, T >;
```

## Public Functions Documentation

### function test

```cpp
template <typename U >
static std::true_type test(
    ... 
)
```


### function test

```cpp
template <typename U >
static std::false_type test(
    Check< void(Fallback::*)(), &U::operator()> * 
)
```


## Public Attributes Documentation

### variable type

```cpp
decltype(test< Derived >(nullptr)) typedef type;
```


### variable dtype

```cpp
decltype(&Fallback::operator()) typedef dtype;
```


### variable value

```cpp
static constexpr bool value = type::value;
```


-------------------------------

Updated on 2022-09-25 at 23:10:54 +0900