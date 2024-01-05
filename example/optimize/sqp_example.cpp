#define CR_USE_MATPLOTLIB
#include <iostream>
#include <cpp_robotics/optimize/sqp.hpp>
#include "cpp_robotics/third_party/matplotlib-cpp/matplotlibcpp.h"

using namespace cpp_robotics;

int main()
{
    SQP solver;
    SQP::Problem prob;

    //////////////////// 問題設定 ////////////////////
    // 極小値の時x = (3, -1)
    prob.func = [](Eigen::VectorXd x) -> double
    {
        Eigen::MatrixXd Q(2,2);
        Eigen::VectorXd c(2);
        Q << 1, 0, 
                0, 1;
        c << -3, 1;
        return 0.5*(x.transpose()*Q).dot(x) + c.dot(x);
    };

    // prob.con.push_back({
    //     Constraint::Ineq,
    //     [](Eigen::VectorXd x)
    //     {
    //         const double radius = 2.0;
    //         return (x.squaredNorm() - std::pow(radius, 2.0));
    //     },
    // });

    // 解けない NAN
    // prob.con.push_back({
    //     Constraint::Ineq,
    //     [](Eigen::VectorXd x)
    //     {
    //         const double radius = 1.0;
    //         return (x.squaredNorm() - std::pow(radius, 2.0));
    //     },
    // });

    // prob.con.push_back({
    //     Constraint::Ineq,
    //     [](Eigen::VectorXd x)
    //     {
    //         // -sin(x(1)*pi/2) < 2
    //         return -std::sin(x(1)*M_PI/2) - 2;
    //     },
    // });

    prob.con.push_back({
        Constraint::Ineq,
        [](Eigen::VectorXd x)
        {
            return -x(0)*x(1) - 1;
        },
    });

    Eigen::VectorXd x0(2);
    x0 << 0, 0.5;

    std::vector<double> x_, y_;

    //////////////////// 解く ////////////////////
    prob.use_slsqp = false; // Todo
    auto result = solver.solve(prob, x0, [&](auto x){ x_.push_back(x(0)); y_.push_back(x(1)); });

    std::cout << "min (x(0))^2 + x(1)^2" << std::endl;
    std::cout << "s.t. x(0)^2 + x(1)^2 <= 1" << std::endl;

    if(result.is_solved)
    {
        std::cout << "解けた" << std::endl;
    }
    else
    {
        std::cout << "解けなかった" << std::endl;
    }

    std::cout << "iter: " << result.iter_cnt << std::endl;
    std::cout << "constraint satisfy: " << ((prob.con.all_satisfy(result.x, prob.tol_con)) ? "true" : "false") << std::endl;
    std::cout << "optimal x =" << std::endl;
    std::cout << result.x << std::endl;

    namespace plt = matplotlibcpp;
    plt::plot(x_, y_, "o--");
    plt::xlim(-4, 4);
    plt::ylim(-4, 4);
    
    plt::show();


}