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
| class | **[cpp_robotics::Singleton](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1Singleton/)**  |




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
    static std::shared_ptr<T> get_instance()
    {
        static std::shared_ptr<T> instance = std::make_shared<T>();
        return instance;
    }
};

}
```


-------------------------------

Updated on 2022-09-25 at 23:50:01 +0900
