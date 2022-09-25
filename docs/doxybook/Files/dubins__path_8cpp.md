---
title: example/path_planning/dubins_path.cpp

---

# example/path_planning/dubins_path.cpp



## Functions

|                | Name           |
| -------------- | -------------- |
| int | **[main](/cpp_robotics/doxybook/Files/dubins__path_8cpp/#function-main)**() |


## Functions Documentation

### function main

```cpp
int main()
```




## Source code

```cpp
#include <iostream>
#include "cpp_robotics/cpp_robotics.hpp"

int main()
{
    using namespace cpp_robotics;
    namespace plt = matplotlibcpp;

    const Transformd start(4.0, 3.0, radians(-45));
    const Transformd end(1.0, 1.0, radians(45));
    const double cavature = 1;
    DubinsPath dpath(start, end, cavature);

    std::cout << dpath.path_type() << std::endl;

    for(size_t i = 0; i < 3; i++)
        std::cout << dpath.segment_length(i) << std::endl;

    auto l = linspace(0, dpath.length());

    std::vector<double> x(l.size()), y(l.size());

    for(size_t i = 0; i < l.size(); i++)
    {
        auto pos = dpath.position(l[i]);
        x[i] = pos.x;
        y[i] = pos.y;
    }
    
    plt::plot(x, y);
    plt::set_aspect(1.0);
    plt::show();
}
```


-------------------------------

Updated on 2022-09-25 at 23:20:39 +0900
