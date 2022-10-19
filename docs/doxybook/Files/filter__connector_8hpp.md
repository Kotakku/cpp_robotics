---
title: include/cpp_robotics/filter/filter_connector.hpp

---

# include/cpp_robotics/filter/filter_connector.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::FilterConnector](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1FilterConnector/)**  |




## Source code

```cpp
#pragma once

#include <cmath>
#include <array>
#include <variant>

namespace cpp_robotics
{

template<class ...FILTER_TYPE>
class FilterConnector
{
public:
    static constexpr size_t filter_count = sizeof...(FILTER_TYPE);
    using variant_type = std::variant<FILTER_TYPE...>;

    FilterConnector()
    {
        
    }

private:
    std::array<variant_type, filter_count> filters_;
};

}
```


-------------------------------

Updated on 2022-10-19 at 13:20:53 +0900
