---
title: matplotlibcpp::detail

---

# matplotlibcpp::detail



## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[matplotlibcpp::detail::_interpreter](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1__interpreter/)**  |
| struct | **[matplotlibcpp::detail::is_callable](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1is__callable/)**  |
| struct | **[matplotlibcpp::detail::is_callable_impl](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1is__callable__impl/)**  |
| struct | **[matplotlibcpp::detail::is_callable_impl< false, T >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1is__callable__impl_3_01false_00_01T_01_4/)**  |
| struct | **[matplotlibcpp::detail::is_callable_impl< true, T >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1is__callable__impl_3_01true_00_01T_01_4/)**  |
| struct | **[matplotlibcpp::detail::plot_impl](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1plot__impl/)**  |
| struct | **[matplotlibcpp::detail::plot_impl< std::false_type >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1plot__impl_3_01std_1_1false__type_01_4/)**  |
| struct | **[matplotlibcpp::detail::plot_impl< std::true_type >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1plot__impl_3_01std_1_1true__type_01_4/)**  |
| struct | **[matplotlibcpp::detail::select_npy_type](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1select__npy__type/)**  |
| struct | **[matplotlibcpp::detail::select_npy_type< bool >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1select__npy__type_3_01bool_01_4/)**  |
| struct | **[matplotlibcpp::detail::select_npy_type< double >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1select__npy__type_3_01double_01_4/)**  |
| struct | **[matplotlibcpp::detail::select_npy_type< float >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1select__npy__type_3_01float_01_4/)**  |
| struct | **[matplotlibcpp::detail::select_npy_type< int16_t >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1select__npy__type_3_01int16__t_01_4/)**  |
| struct | **[matplotlibcpp::detail::select_npy_type< int32_t >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1select__npy__type_3_01int32__t_01_4/)**  |
| struct | **[matplotlibcpp::detail::select_npy_type< int64_t >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1select__npy__type_3_01int64__t_01_4/)**  |
| struct | **[matplotlibcpp::detail::select_npy_type< int8_t >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1select__npy__type_3_01int8__t_01_4/)**  |
| struct | **[matplotlibcpp::detail::select_npy_type< long long >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1select__npy__type_3_01long_01long_01_4/)**  |
| struct | **[matplotlibcpp::detail::select_npy_type< uint16_t >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1select__npy__type_3_01uint16__t_01_4/)**  |
| struct | **[matplotlibcpp::detail::select_npy_type< uint32_t >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1select__npy__type_3_01uint32__t_01_4/)**  |
| struct | **[matplotlibcpp::detail::select_npy_type< uint64_t >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1select__npy__type_3_01uint64__t_01_4/)**  |
| struct | **[matplotlibcpp::detail::select_npy_type< uint8_t >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1select__npy__type_3_01uint8__t_01_4/)**  |
| struct | **[matplotlibcpp::detail::select_npy_type< unsigned long long >](/cpp_robotics_core/doxybook/Classes/structmatplotlibcpp_1_1detail_1_1select__npy__type_3_01unsigned_01long_01long_01_4/)**  |

## Types

|                | Name           |
| -------------- | -------------- |
| template <typename T \> <br>using typename std::is_function< std::remove_pointer< std::remove_reference< T > >>::type | **[is_function](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp_1_1detail/#using-is-function)**  |

## Functions

|                | Name           |
| -------------- | -------------- |
| template <typename Numeric \> <br>PyObject * | **[get_array](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp_1_1detail/#function-get-array)**(const std::vector< Numeric > & v) |
| template <typename Numeric \> <br>PyObject * | **[get_2darray](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp_1_1detail/#function-get-2darray)**(const std::vector<::std::vector< Numeric >> & v) |
| PyObject * | **[get_array](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp_1_1detail/#function-get-array)**(const std::vector< std::string > & strings) |
| template <typename Numeric \> <br>PyObject * | **[get_listlist](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp_1_1detail/#function-get-listlist)**(const std::vector< std::vector< Numeric >> & ll) |
| void | **[imshow](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp_1_1detail/#function-imshow)**(void * ptr, const NPY_TYPES type, const int rows, const int columns, const int colors, const std::map< std::string, std::string > & keywords, PyObject ** out) |

## Attributes

|                | Name           |
| -------------- | -------------- |
| std::string | **[s_backend](/cpp_robotics_core/doxybook/Namespaces/namespacematplotlibcpp_1_1detail/#variable-s-backend)**  |

## Types Documentation

### using is_function

```cpp
template <typename T >
using matplotlibcpp::detail::is_function = typedef typename std::is_function<std::remove_pointer<std::remove_reference<T> >>::type;
```



## Functions Documentation

### function get_array

```cpp
template <typename Numeric >
PyObject * get_array(
    const std::vector< Numeric > & v
)
```


### function get_2darray

```cpp
template <typename Numeric >
PyObject * get_2darray(
    const std::vector<::std::vector< Numeric >> & v
)
```


### function get_array

```cpp
inline PyObject * get_array(
    const std::vector< std::string > & strings
)
```


### function get_listlist

```cpp
template <typename Numeric >
PyObject * get_listlist(
    const std::vector< std::vector< Numeric >> & ll
)
```


### function imshow

```cpp
inline void imshow(
    void * ptr,
    const NPY_TYPES type,
    const int rows,
    const int columns,
    const int colors,
    const std::map< std::string, std::string > & keywords,
    PyObject ** out
)
```



## Attributes Documentation

### variable s_backend

```cpp
static std::string s_backend;
```





-------------------------------

Updated on 2022-09-25 at 23:10:54 +0900