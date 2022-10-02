---
title: cpp_robotics::FilterConnector

---

# cpp_robotics::FilterConnector



 [More...](#detailed-description)


`#include <filter_connector.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| using std::variant< FILTER_TYPE... > | **[variant_type](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1FilterConnector/#using-variant-type)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[FilterConnector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1FilterConnector/#function-filterconnector)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| constexpr size_t | **[filter_count](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1FilterConnector/#variable-filter-count)**  |

## Detailed Description

```cpp
template <class ... FILTER_TYPE>
class cpp_robotics::FilterConnector;
```

## Public Types Documentation

### using variant_type

```cpp
using cpp_robotics::FilterConnector< FILTER_TYPE >::variant_type =  std::variant<FILTER_TYPE...>;
```


## Public Functions Documentation

### function FilterConnector

```cpp
inline FilterConnector()
```


## Public Attributes Documentation

### variable filter_count

```cpp
static constexpr size_t filter_count = sizeof...(FILTER_TYPE);
```


-------------------------------

Updated on 2022-10-02 at 13:22:12 +0900