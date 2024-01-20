#include <iostream>
#include <iomanip>
#include <Eigen/Dense>
#include <cpp_robotics/optimize/quadprog.hpp>

int main()
{
    using namespace cpp_robotics;

    QuadProgProblem problem;

    // 変数のサイズ      : 2
    // 不等式制約のサイズ : 0
    // 等式制約のサイズ   : 0
    // box制約          : true
    problem.set_problem_size(2, 0, 0, true); 

    // この問題における制約なしの時の大域的最適解
    // x = (3, 1)
    problem.Q << 
        1,0,
        0,1;

    problem.c << 
        -3,-1;

    // s.t.
    problem.lb << 0,0;
    problem.ub << 10, 10;

    Eigen::VectorXd x0(2);
    x0 << 1, 0;

    auto result = quadprog(problem, x0);

    std::cout << std::fixed << std::setprecision(3);

    std::cout << "is_solved: " << (result.is_solved ? "true" : "false") << std::endl;
    std::cout << "optx     : " << result.x.transpose() << std::endl;
    std::cout << "itr      : " << result.iter_cnt << std::endl;
}