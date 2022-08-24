// #pragma once

// #include <tuple>
// #include <functional>
// #include <Eigen/Dense>

// namespace cpp_robotics
// {

// // 線形計画法
// // min f^T x
// // sub A x < b
// //     (Aeq x = beq)
// //     (l <= x <= u)
// class LinProgSolver
// {
//     Eigen::MatrixXd f;
//     Eigen::MatrixXd A;
//     Eigen::VectorXd b;
    
//     std::tuple<bool, Eigen::VectorXd, size_t> solve(Eigen::VectorXd x_init, const double tol = 1e-6, const size_t max_iter = 1000)
//     {

//     }
// };

// }