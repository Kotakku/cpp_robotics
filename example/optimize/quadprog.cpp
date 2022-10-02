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
    qp.set_problem_size(2, 2, 0); 

    // min 0.5*(x1^2 + x2^2) - 3*x1
    qp.Q << 1, 0, 
            0, 1;
    qp.c << -3, 0;

    // s.t. x1 <= 4
    //      -x2 <= -1 (x2 >= 1)
    qp.A << 1, 0,
            0, -1;
    qp.b << 4, -1;

    // この問題における最適解
    // x = (3, 1)

    Eigen::VectorXd x0(2);
    x0 << 4, 1;
    auto result = qp.solve(x0);

    // std::cout << std::fixed << std::setprecision(3);
    std::cout << "is_solved: " << (result.is_solved ? "true" : "false") << std::endl;
    std::cout << "optx     : " << result.x.transpose() << std::endl;
    std::cout << "itr      : " << result.iter_cnt << std::endl;
}