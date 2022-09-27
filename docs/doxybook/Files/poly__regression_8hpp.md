---
title: include/cpp_robotics/algorithm/poly_regression.hpp

---

# include/cpp_robotics/algorithm/poly_regression.hpp






## Source code

```cpp
// #pragma once

// #include <array>
// #include <Eigen/Dense>

// namespace cpp_robotics
// {
// // 回帰曲線
// Eigen::VectorXd poly_regression(Container x, Container y, const size_t degree)
// {
//     MyMatrix<typename Container::value_type, Dynamic, Dynamic> XT, Y;

//     assert(x.size() == y.size());
//     const size_t data_num = x.size();
//     XT.resize(degree + 1, data_num);
//     Y.resize(data_num, 1);

//     for (size_t j = 0; j < x.size(); j++)
//     {
//         XT(0, j) = 1;
//         for (size_t i = 0; i < degree; i++)
//         {
//             XT(i + 1, j) = XT(i, j) * x[j];
//         }
//     }

//     for (size_t i = 0; i < y.size(); i++)
//     {
//         Y(i) = y[i];
//     }

//     auto coeff_mat_1d = inverse(XT * transpose(XT)) * (XT * Y);

//     std::vector<typename Container::value_type> coeff(degree + 1);
//     for (size_t i = 0; i < degree + 1; i++)
//     {
//         //coeff[i] = coeff_mat_1d(degree - i);
//         coeff[i] = coeff_mat_1d(i);
//     }

//     return Polynomial(coeff);
// }

// }
```


-------------------------------

Updated on 2022-09-28 at 01:12:56 +0900
