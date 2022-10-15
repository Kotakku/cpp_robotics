#include <gtest/gtest.h>

#include <iostream>
#include <cpp_robotics/algorithm/algorithm.hpp>
#include <cpp_robotics/optimize/sqp.hpp>


// 複数の制約において全て解けるのかチェック
TEST(sqp, test) {
    using namespace cpp_robotics;

    SQP solver;
    SQP::Problem prob;

    //////////////////// 目的関数設定 ////////////////////
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
    
    //////////////////// 制約設定 ////////////////////
    
    std::vector<Constraint> cons_pattern = 
    {
        {
            Constraint::Ineq,
            [](Eigen::VectorXd x)
            {
                const double radius = 2.0;
                return (x.squaredNorm() - std::pow(radius, 2.0));
            },
        },

        {
            Constraint::Ineq,
            [](Eigen::VectorXd x)
            {
                const double radius = 2.0;
                return (x.squaredNorm() - std::pow(radius, 2.0));
            },
        },

        {
            Constraint::Eq,
            [](Eigen::VectorXd x)
            {
                const double radius = 2.0;
                return (x.squaredNorm() - std::pow(radius, 2.0));
            },
        },

        {
            Constraint::Eq,
            [](Eigen::VectorXd x)
            {
                const double radius = 1.0;
                return (x.squaredNorm() - std::pow(radius, 2.0));
            },
        },

        {
            Constraint::Eq,
            [](Eigen::VectorXd x)
            {
                const double radius = 4.0;
                return (x.squaredNorm() - std::pow(radius, 2.0));
            },
        },

        {
            Constraint::Ineq,
            [](Eigen::VectorXd x)
            {
                return (-x(1));
            },
        },

        {
            Constraint::Ineq,
            [](Eigen::VectorXd x)
            {
                return (x(1));
            },
        },

        {
            Constraint::Ineq,
            [](Eigen::VectorXd x)
            {
                const double radius = 1.0;
                return (x.squaredNorm() - std::pow(radius, 2.0));
            },
        },

        {
            Constraint::Ineq,
            [](Eigen::VectorXd x)
            {
                // -sin(x(1)*pi/2) < 2
                return -std::sin(x(1)*M_PI/2) - 2;
            },
        },

        {
            Constraint::Ineq,
            [](Eigen::VectorXd x)
            {
                // -sin(x(1)*pi/2) < 2
                return -std::sin(x(1)*M_PI/2) - 4;
            },
        },

        {
            Constraint::Ineq,
            [](Eigen::VectorXd x)
            {
                return -x(0)*x(1) - 1;
            },
        },

        {
            Constraint::Ineq,
            [](Eigen::VectorXd x)
            {
                return x(0)*x(1) - 1;
            },
        },
    };

    Eigen::VectorXd x0(2);
    x0 << 0, 0.5;

    size_t i = 0;
    for(auto &c : cons_pattern)
    {
        std::cout << "test num: " << i++ << std::endl;
        prob.con.clear();
        prob.con.push_back(c);
        auto result = solver.solve(prob, x0);
        EXPECT_TRUE(result.is_solved);
        EXPECT_TRUE(prob.con.all_satisfy(result.x, prob.tol_con));
    }
}

// TEST(sqp, test2) {
//     using namespace cpp_robotics;

//     SQP solver;
//     SQP::Problem prob;

//     //////////////////// 目的関数設定 ////////////////////
//     prob.func = [](Eigen::VectorXd x) -> double
//     {
//         Eigen::MatrixXd Q(1,1);
//         Eigen::VectorXd c(1);
//         Q << 1;
//         c << 1;
//         return 0.5*(x.transpose()*Q).dot(x) + c.dot(x);
//     };
    
//     //////////////////// 制約設定 ////////////////////
    
//     std::vector<Constraint> cons_pattern = 
//     {
//         {
//             Constraint::Ineq,
//             [](Eigen::VectorXd x)
//             {

//                 // minval < x
//                 const double minval = 1;
//                 return -(x(0) - minval);
//             },
//         },
//     };

//     Eigen::VectorXd x0(1);
//     x0 << 0;

//     size_t i = 0;
//     for(auto &c : cons_pattern)
//     {
//         std::cout << "test num: " << i++ << std::endl;
//         prob.con.clear();
//         prob.con.push_back(c);
//         auto result = solver.solve(prob, x0);
//         EXPECT_TRUE(result.is_solved);
//         EXPECT_TRUE(prob.con.all_satisfy(result.x, prob.tol_con));
//     }
// }