#include <iostream>
#include <cpp_robotics/algorithm/algorithm.hpp>
#include <cpp_robotics/optimize/sqp.hpp>

using namespace cpp_robotics;

int main()
{
    SQP solver;
    SQP::Problem prob;

    //////////////////// 問題設定 ////////////////////
    prob.func = [](Eigen::VectorXd x)
    {
        return std::pow(x(0)-3, 2) + std::pow(x(1)-3,2);
    };

    prob.con.push_back({
        Constraint::Ineq,
        [](Eigen::VectorXd x)
        {
            return (x.squaredNorm() - 1);
        },
    });
    // prob.con.push_back({
    //     Constraint::Ineq,
    //     [](Eigen::VectorXd x)
    //     {
    //         x(0) -= 1.5;
    //         return x.squaredNorm() - 1;
    //     },
    // });

    prob.max_iter = 3;

    Eigen::VectorXd x0(2);
    x0 << 1.0, 0;

    //////////////////// 解く ////////////////////
    auto result = solver.solve(prob, x0);

    std::cout << "min (x(0)-3)^2 + x(1)^2" << std::endl;
    std::cout << "s.t. x(0)^2 + x(1)^2 <= 1" << std::endl;

    if(result.is_solved)
    {
        std::cout << "解けた" << std::endl;
    }
    else
    {
        std::cout << "解けなかった" << std::endl;
    }

    std::cout << "x_opt =" << std::endl;
    std::cout << result.x_opt << std::endl;
    std::cout << "lambda_opt =" << std::endl;
    std::cout << result.lambda_opt << std::endl;

    std::cout << "iter: " << result.iter_cnt << std::endl;

}