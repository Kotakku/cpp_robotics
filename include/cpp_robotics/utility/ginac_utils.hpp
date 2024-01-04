// #pragma once

// #include <Eigen/Dense>
// #include <Eigen/Geometry>
// #include <ginac/ginac.h>

// namespace cpp_robotics
// {

// template<int ROWS, int COLS>
// void cout_exmat(const Eigen::Matrix<GiNaC::ex, ROWS, COLS>& mat, std::string name = "") {
//     if(name != "")
//         std::cout << name + ": " << std::endl;
//     for(int r = 0; r < mat.rows(); r++)
//     {
//         for(int c = 0; c < mat.cols(); c++)
//         {
//             std::cout << mat(r,c) << ", ";
//         }
//         std::cout << std::endl;
//     }
//     std::cout << std::endl;
// }

// template<int ROWS, int COLS>
// void simplify_indexed(Eigen::Matrix<GiNaC::ex, ROWS, COLS> &mat) {
//     for(int r = 0; r < mat.rows(); r++)
//     {
//         for(int c = 0; c < mat.cols(); c++)
//         {
//             mat(r,c) = mat(r,c).simplify_indexed();
//         }
//     }
// }

// template<int ROWS, int COLS>
// void expand(Eigen::Matrix<GiNaC::ex, ROWS, COLS> &mat) {
//     for(int r = 0; r < mat.rows(); r++)
//     {
//         for(int c = 0; c < mat.cols(); c++)
//         {
//             mat(r,c) = mat(r,c).expand();
//         }
//     }
// }

// template<int ROWS, int COLS>
// void subs(Eigen::Matrix<GiNaC::ex, ROWS, COLS> &mat, const GiNaC::lst exlst) {
//     for(int r = 0; r < mat.rows(); r++)
//     {
//         for(int c = 0; c < mat.cols(); c++)
//         {
//             mat(r,c) = mat(r,c).subs(exlst);
//         }
//     }
// }

// template<int IN_ROWS, int IN_COLS, int OUT_ROWS, int OUT_COLS>
// void to_double_matrix(Eigen::Matrix<GiNaC::ex, IN_ROWS, IN_COLS> &in_mat, Eigen::Matrix<double, OUT_ROWS, OUT_COLS> &out_mat) {
//     for(int r = 0; r < in_mat.rows(); r++)
//     {
//         for(int c = 0; c < in_mat.cols(); c++)
//         {
//             out_mat(r,c) = GiNaC::ex_to<GiNaC::numeric>(in_mat(r,c)).to_double();
//         }
//     }
// }

// }