#include <gtest/gtest.h>

#include <iostream>
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

TEST(sqp, test2) {
    using namespace cpp_robotics;

    SQP solver;
    SQP::Problem prob;

    prob.print_variable = false;

    //////////////////// 目的関数設定 ////////////////////
    prob.func = [](Eigen::VectorXd x) -> double
    {
        Eigen::MatrixXd Q(1,1);
        Eigen::VectorXd c(1);
        Q << 0;
        c << 1;
        return 0.5*(x.transpose()*Q).dot(x) + c.dot(x);
    };
    
    //////////////////// 制約設定 ////////////////////
    
    std::vector<Constraint> cons_pattern = 
    {
        {
            Constraint::Ineq,
            [](Eigen::VectorXd x)
            {

                // minval < x
                const double minval = 0;
                return -(x(0) - minval);
            },
        },
    };

    Eigen::VectorXd x0(1);
    x0 << 100;

    size_t i = 0;
    for(auto &c : cons_pattern)
    {
        std::cout << "test num: " << i++ << std::endl;
        prob.con.clear();
        prob.con.push_back(c);
        auto result = solver.solve(prob, x0);
        std::cout << "x = " << std::endl;
        std::cout << result.x << std::endl;
        std::cout << "itr: " << result.iter_cnt << std::endl;
        bool satisfy = prob.con.all_satisfy(result.x, prob.tol_con);
        std::cout << "satisfy: " << satisfy << std::endl;
        EXPECT_TRUE(result.is_solved);
        EXPECT_TRUE(satisfy);
    }
}

TEST(sqp, test_inf) {
    using namespace cpp_robotics;

    SQP solver;
    SQP::Problem prob;

    prob.print_variable = false;

    //////////////////// 目的関数設定 ////////////////////
    prob.func = [](Eigen::VectorXd x) -> double
    {
        Eigen::MatrixXd Q(2,2);
        Eigen::VectorXd c(2);
        Q << 1,0,0,1;
        c << -3,1;
        return 0.5*(x.transpose()*Q).dot(x) + c.dot(x);
    };
    
    //////////////////// 制約設定 ////////////////////

    Eigen::VectorXd x0(2);
    x0 << 0, 0;

    prob.con.clear();
    prob.con.push_back({
        Constraint::Ineq,
        [](Eigen::VectorXd x)
        {
            const double minval = 0;
            return -(x(0) - minval);
        },
    });
    prob.con.push_back({
        Constraint::Ineq,
        [](Eigen::VectorXd x)
        {
            const double minval = 0;
            return -(x(1) - minval);
        },
    });

    ////// NAN constraint
    prob.con.push_back({
        Constraint::Ineq,
        [](Eigen::VectorXd x)
        {
            return x(0) + std::numeric_limits<double>::infinity();
        },
    });
    prob.print_variable = true;
    
    auto result = solver.solve(prob, x0);
    std::cout << "x = " << std::endl;
    std::cout << result.x << std::endl;
    std::cout << "itr: " << result.iter_cnt << std::endl;
    bool satisfy = prob.con.all_satisfy(result.x, prob.tol_con);
    std::cout << "satisfy: " << satisfy << std::endl;
    EXPECT_TRUE(result.is_solved);
    // EXPECT_TRUE(satisfy);
}