---
title: include/cpp_robotics/geometry/geometry_stream.hpp

---

# include/cpp_robotics/geometry/geometry_stream.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |




## Source code

```cpp
#pragma once
#include <iostream>
#include "../vector/vector2.hpp"
#include "../vector/vector3.hpp"
#include "../vector/vector4.hpp"
#include "../vector/transform.hpp"

namespace cpp_robotics
{

std::ostream& operator << (std::ostream& os, const Vector2d& v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

std::ostream& operator << (std::ostream& os, const Vector3d& v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

std::ostream& operator << (std::ostream& os, const Vector4d& v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
    return os;
}

std::ostream& operator << (std::ostream& os, const Transformd& v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.theta << ")";
    return os;
}

}
```


-------------------------------

Updated on 2022-09-25 at 23:20:38 +0900
