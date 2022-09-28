---
title: include/cpp_robotics/utility/singleton.hpp

---

# include/cpp_robotics/utility/singleton.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::Singleton](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Singleton/)** <br>シングルトンなオブジェクトを生成する  |




## Source code

```cpp
#pragma once

#include <memory>

namespace cpp_robotics
{

template<class T>
class Singleton
{
private:
    Singleton() = default;

public:
    using class_t = T;
    using shared_t = std::shared_ptr<class_t>;

    static shared_t get_shared_instance()
    {
        static shared_t instance = std::make_shared<class_t>();
        return instance;
    }
};

}
```


-------------------------------

Updated on 2022-09-28 at 23:12:44 +0900
