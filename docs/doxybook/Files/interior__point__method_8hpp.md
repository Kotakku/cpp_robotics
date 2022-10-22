---
title: include/cpp_robotics/optimize/interior_point_method.hpp

---

# include/cpp_robotics/optimize/interior_point_method.hpp






## Source code

```cpp
// #pragma once

// #include "./derivative.hpp"
// #include "./constraint.hpp"

// namespace cpp_robotics
// {

// // 内点法
// class InteriorPointMethod
// {
// public:
//     InteriorPointMethod() = default;

//     struct Problem
//     {
//         std::function<double(const Eigen::VectorXd &)> f;
//         ConstraintArray constraint;
//         Eigen::VectorXd x_init;
//         const double rho_tol = 1e-3;
//         const size_t max_iter = 1000;
//         const double constraint_merit_gain = 0.1;
//         double slack_gain_init = 1.0;
//     };

//     struct Result
//     {
//         bool is_solved;
//         Eigen::VectorXd x;
//         size_t iter_count;
//     };

//     Result solve(Problem prob)
//     {
//         auto [f, constraint, x_init, rho_tol, max_iter, eta, rho] = prob;

//         size_t x_dim = x_init.rows();
//         size_t eq_cnt = constraint.eq_constraint_size();
//         size_t ineq_cnt = constraint.ineq_constraint_size();
//         size_t con_cnt = constraint.size();

//         auto eq_con_func = constraint.gen_eq_constraint_list();
//         auto ineq_con_func = constraint.gen_ineq_constraint_list();
        
//         auto x = x_init;
//         auto s = Eigen::VectorXd::Ones(ineq_cnt).eval(); // 不等式制約のためのスラック変数
//         auto u = Eigen::VectorXd::Zero(con_cnt).eval();  // ラグランジュ定数
//         // Todo: 等式制約と不等式制約に分けて考え直す

//         // メリット関数
//         auto merit_func = [&](const Eigen::VectorXd &x, const Eigen::VectorXd &s, const Eigen::VectorXd &u)
//         {
//             double val = f(x);

//             for(size_t i = 0; i < ineq_cnt; i++)
//             {
//                 val += -rho * std::log(s(i));
//             }

//             for(size_t i = 0; i < ineq_cnt; i++)
//             {
//                 val += -eta * std::abs( ineq_con_func[i].eval(x) + s(i) );
//             }

//             for(size_t i = 0; i < eq_cnt; i++)
//             {
//                 val += -eta * std::abs( eq_con_func[i].eval(x) );
//             }

//             return val;
//         };

//         size_t i = 0;
//         for(; i < max_iter; i++)
//         {
//             // 終了条件チェック
//             if(std::abs(rho) < rho_tol)
//                 break;
            
//             // Todo: 連立方程式を立てて解き、それぞれの更新方向を求める
//             Eigen::MatrixXd A = Eigen::MatrixXd::Zero(4, x_dim + ineq_cnt + con_cnt);
//             Eigen::VectorXd b = Eigen::VectorXd::Zero(4, 1);

//             // A.block(0,0, x_dim, x_dim) = Eigen::MatrixXd::Zero(x_dim, x_dim);
//             // b(0) = 1;
//             // b(1) = 1;
//             // b(2) = 1;
//             // b(3) = 1;
            
//             auto dstate = A.partialPivLu().solve(b);

//             auto dx = dstate.segment(0, x_dim);
//             auto ds = dstate.segment(x_dim, ineq_cnt);
//             auto du = dstate.segment(x_dim+ineq_cnt, con_cnt);

//             // ステップ幅を求める
//             // メリット関数に対して探索方向を適応した時に評価値が最小になるようなステップを求める
//             double alpha = bracketing_serach([&](double v){ return merit_func(x+v*dx, s+v*ds, u+v*du); });

//             // 状態量を更新する
//             x += alpha * dx;
//             s += alpha * ds;
//             u += alpha * du;

//             // Todo: rhoを更新する
//             // rho = gamma * (1) / static_cast<double>(ineq_cnt);
//         }
//     }


// };

// }
```


-------------------------------

Updated on 2022-10-22 at 22:05:50 +0900
