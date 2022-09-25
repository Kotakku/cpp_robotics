---
title: example/system/bode_nyquist.cpp

---

# example/system/bode_nyquist.cpp



## Functions

|                | Name           |
| -------------- | -------------- |
| int | **[main](/cpp_robotics/doxybook/Files/bode__nyquist_8cpp/#function-main)**() |


## Functions Documentation

### function main

```cpp
int main()
```




## Source code

```cpp
#include <iostream>
#include <Eigen/Dense>
#include <cpp_robotics/system/system.hpp>

int main()
{
    namespace cr = cpp_robotics;

    // 伝達関数
    // tf(s) = 1 / (s + 1)
    cr::TransferFunction tf({1.0}, {1.0, 1.0}, 0.01);

    // ボード線図
    cr::bode_plot(tf);

    // ナイキスト線図
    cr::nyquist_plot(tf);
}
```


-------------------------------

Updated on 2022-09-25 at 23:20:39 +0900
