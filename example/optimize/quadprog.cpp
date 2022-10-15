#include <iostream>
#include <iomanip>
#include <Eigen/Dense>
#include <cpp_robotics/optimize/quadprog.hpp>

int main()
{
    using namespace cpp_robotics;

    QuadProg qp;

    // 変数のサイズ      : 2
    // 不等式制約のサイズ : 2
    // 等式制約のサイズ   : 0
    qp.param.tol_con = 1e-3;
    qp.param.tol_step = 1e-3;
    
    qp.set_problem_size(2, 4, 1); 

    // min 0.5*(x1^2 + x2^2) - 3*x1
    // qp.Q << 1, 0, 
    //         0, 1;
    // qp.c << -3, 1;

    qp.Q << 
        1.55356e+14, 6.74972e+13,
        6.74972e+13, 2.93254e+13;

    qp.Q << 
        1.55356e0, 6.74972e0,
        6.74972e0, 2.93254e0;

    qp.c <<
        -0.928814,
        1.89986;
    // s.t. x1 <= 4
    //      -x2 <= -1 (x2 >= 1)
    qp.A << 
        1, 0,
        0, 1,
        -1, 0,
        0, -1;
    qp.b << 
        0.1, 0.1, 0.1, 0.1;

    // qp.Aeq << 
    //     1, 1;
    // qp.beq << 
    //     1;
    qp.Aeq << 1, 1;
    qp.beq << 0.05;
    // A, bに変数の上下限をいれると解けないので解法をl<x<uで設定する

    // この問題における最適解
    // x = (3, 1)

    Eigen::VectorXd x0(2);
    x0 << 1, 0;

    // std::cout << qp.evaluate_merit(Eigen::Vector2d(0, 0), Eigen::Vector2d(0, 0), 0, 0) << std::endl;
    // std::cout << qp.evaluate_merit(Eigen::Vector2d(3, 0), Eigen::Vector2d(0, 0), 0, 0) << std::endl;
    auto result = qp.solve(x0);

    std::cout << std::fixed << std::setprecision(3);

    // std::cout << "is_solved: " << result.is_solved<< std::endl;
    std::cout << "is_solved: " << (result.is_solved ? "true" : "false") << std::endl;
    std::cout << "optx     : " << result.x.transpose() << std::endl;
    std::cout << "itr      : " << result.iter_cnt << std::endl;
    std::cout << "satisfy  : " << qp.satisfy(result.x) << std::endl;

    std::cout << "(Ax-b < 0)? :" << std::endl;
    std::cout << qp.A*result.x - qp.b << std::endl;

    std::cout << "(Aeqx-beq = 0)? :" << std::endl;
    std::cout << qp.Aeq*result.x - qp.beq << std::endl;
}