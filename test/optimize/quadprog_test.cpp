#include <gtest/gtest.h>
#include "../test_utility.hpp"

#include <cpp_robotics/optimize/quadprog.hpp>

TEST(quadprog, newton_method) {
    using namespace cpp_robotics;

    QuadProg qp;

    qp.set_problem_size(2, 0, 0); 

    qp.Q << 
        1, 0, 
        0, 1;
    qp.c << -3, -2;

    Eigen::VectorXd x0(2);
    x0 << 4, 1;
    auto result = qp.solve(x0);

    EXPECT_TRUE(result.is_solved);
    EXPECT_NEAR_VEC(result.x, Eigen::Vector2d(3, 2), 1e-2);
}

TEST(quadprog, small_size_no_active_constraint) {
    using namespace cpp_robotics;

    QuadProg qp;

    qp.set_problem_size(2, 2, 0); 

    qp.Q << 1, 0, 
        0, 1;
    qp.c << -3, -1;

    qp.A << 
        1, 0,
        0, -1;
    qp.b << 4, -1;

    Eigen::VectorXd x0(2);
    x0 << 4, 1;
    auto result = qp.solve(x0);

    EXPECT_TRUE(result.is_solved);
    EXPECT_NEAR_VEC(result.x, Eigen::Vector2d(3, 1), 1e-2);
}

TEST(quadprog, active_constraint) {
    using namespace cpp_robotics;

    QuadProg qp;

    qp.set_problem_size(2, 2, 0); 

    qp.Q << 1, 0, 
        0, 1;
    qp.c << -3, -1;

    qp.A << 
        1, 0,
        0, -1;
    qp.b << 2, -2;

    Eigen::VectorXd x0(2);
    x0 << 4, 1;
    auto result = qp.solve(x0);

    EXPECT_TRUE(result.is_solved);
    EXPECT_NEAR_VEC(result.x, Eigen::Vector2d(2, 2), 1e-2);
}

TEST(quadprog, no_active_constraint) {
    using namespace cpp_robotics;

    QuadProg qp;

    qp.set_problem_size(2, 4, 0); 

    qp.Q << 
        1, 0, 
        0, 1;
    qp.c << -3, -1;

    qp.A << 
        1, 0,
        0, 1,
        -1, 0,
        0, -1;
    qp.b << 
        10, 10, 0, 0;

    qp.param.print_variable = true;

    Eigen::VectorXd x0(2);
    x0 << 4, 1;
    auto result = qp.solve(x0);

    std::cout << result.x << std::endl;

    EXPECT_TRUE(result.is_solved);
    EXPECT_NEAR_VEC(result.x, Eigen::Vector2d(3, 1), 1e-2);
}

TEST(quadprog, active_constraint2) {
    using namespace cpp_robotics;

    QuadProg qp;

    qp.set_problem_size(2, 4, 0); 

    qp.Q << 
        1, 0, 
        0, 1;
    qp.c << -3, -1;

    qp.A << 
        1, 0,
        0, 1,
        -1, 0,
        0, -1;
    qp.b << 
        2, 10, 0, -3;

    qp.param.print_variable = true;

    Eigen::VectorXd x0(2);
    x0 << 4, 1;
    auto result = qp.solve(x0);

    std::cout << result.x << std::endl;

    EXPECT_TRUE(result.is_solved);
    EXPECT_NEAR_VEC(result.x, Eigen::Vector2d(2, 3), 1e-2);
}