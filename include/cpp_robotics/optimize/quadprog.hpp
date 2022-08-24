// #pragma once

// #include <tuple>
// #include <functional>
// #include <Eigen/Dense>
// #include <cassert>
// #include "constraint.hpp"
// #include "derivative.hpp"

// namespace cpp_robotics
// {

// // 2次計画法
// // min 1/2 x^T Q x + c^T x
// // s.t. 
// class QuadProgSolver
// {
//     Eigen::MatrixXd Q;
//     Eigen::VectorXd c;
//     ConstraintArray con;
    
//     std::tuple<bool, Eigen::VectorXd, size_t> solve(Eigen::VectorXd x_init, const double tol = 1e-6, const size_t max_iter = 1000)
//     {
//         assert(Q.rows() == Q.cols());
//         assert(c.cols() == Q.rows());
//         assert(x_init.cols() == Q.rows());
        
//         eq_con_func_ = con.gen_eq_constraint_list();
//         ineq_con_func_ = con.gen_ineq_constraint_list();
        

//         size_t l = ineq_con_func_.size();
//         size_t m = eq_con_func_.size();
//         size_t n = x_init.cols();

//         Eigen::VectorXd x(n);

//         double rho = 1;
//         Eigen::VectorXd s = Eigen::VectorXd::Ones(l);
//         Eigen::VectorXd u = s; //rho / s;
//         Eigen::VectorXd v = Eigen::VectorXd::Zero(m);
        
//         for(size_t i = 0; i < max_iter; i++)
//         {
//             // if(rho < tol)
//             //     return {true, x, i};
            
//             // auto H = Q;
//             // auto d = Q*x + c;

//             // auto Jg = Eigen::MatrixXd::Zero(l,n);
//             // auto g = Eigen::VectorXd::Zero(l);
//             // // g(x) <= 0
//             // for(auto &g_func : ineq_con_func_)
//             // {
//             //     H += g_func.hessian(x) * u(i);
//             //     // Jg[i, :] = g_func.grad(x);
//             //     // d += Jg[i, :] * u[i];
//             //     g(i) = g_func.con_f(x);
//             // }

//             // auto Jh = Eigen::MatrixXd::Zero(m,n);
//             // auto h = Eigen::VectorXd::Zero(m);
//             // // h(x) = 0
//             // for(auto &h_func : eq_con_func_)
//             // {
                
//             // }

//             // auto Du = u.diagonal();
//             // auto Ds = s.diagonal();

//             // Eigen::MatrixXd P = Eigen::MatrixXd::Zeros(n + 2 * l + m, n + 2 * l + m);
//             // // P.block(0,0, 2,2) = a;

//             // Eigen::MatrixXd r;
//             // r << -d,
//             //     rho - s * u,
//             //     -(g+s),
//             //     -h;

//             // // 連立一次方程式を解く



//         }

//         return {false, x, max_iter};
//     }

// private:
//     std::vector<Constraint> eq_con_func_; // h(x) = 0
//     std::vector<Constraint> ineq_con_func_; // g(x) <= 0
// };

// }