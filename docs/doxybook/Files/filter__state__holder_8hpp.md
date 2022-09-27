---
title: include/cpp_robotics/filter/filter_state_holder.hpp

---

# include/cpp_robotics/filter/filter_state_holder.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::FilterStateHolder](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1FilterStateHolder/)** <br>フィルタの入力と計算を非同期にして最後の入力と出力を保持しておけるようにするクラス  |




## Source code

```cpp
#pragma once

#include <tuple>
#include <optional>
#include <algorithm>

namespace cpp_robotics
{

template<class BASE_FILTER_TYPE>
class FilterStateHolder : public BASE_FILTER_TYPE
{
public:
    using BASE_FILTER_TYPE::BASE_FILTER_TYPE;
    void set_input(double u)
    {
        u_ = u;
    }

    double filtering()
    {
        y_ = BASE_FILTER_TYPE::filtering(u);
        return y_;
    }

    double u() const { return u_; }
    double y() const { return y_; }
private:
    double u_ = 0, y_ = 0;
};

}
```


-------------------------------

Updated on 2022-09-28 at 01:12:56 +0900
