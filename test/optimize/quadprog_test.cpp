#include <gtest/gtest.h>
#include "../test_utility.hpp"

#include <cpp_robotics/optimize/quadprog.hpp>

TEST(quadprog, newton_method) {
    using namespace cpp_robotics;

    QuadProg qp;

    QuadProgProblem qp_prob;
    qp_prob.set_problem_size(2, 0, 0, false); 

    qp_prob.Q << 
        1, 0, 
        0, 1;
    qp_prob.c << -3, -2;

    qp.set_problem(qp_prob);
    Eigen::VectorXd x0(2);
    x0 << 4, 1;
    auto result = qp.solve(x0);

    std::cout << "x:" << std::endl;
    std::cout << result.x << std::endl;

    std::cout << "iter: " << result.iter_cnt << std::endl;

    EXPECT_TRUE(result.is_solved);
    EXPECT_TRUE(qp.satisfy(result.x));
    EXPECT_NEAR_VEC(result.x, Eigen::Vector2d(3, 2), 1e-2);

    auto result2 = quad_prob(qp_prob.Q, qp_prob.c, x0);
    EXPECT_NEAR_VEC(result2.x, result.x, 1e-2);
}

TEST(quadprog, ineq_inactive_constraint) {
    using namespace cpp_robotics;

    QuadProgProblem qp_prob;
    qp_prob.set_problem_size(2, 2, 0, false); 

    qp_prob.Q << 1, 0, 
                 0, 1;
    qp_prob.c << -3, -1;

    qp_prob.A << 
        1, 0,
        0, 1;
    qp_prob.b << 10, 10;

    QuadProg qp(qp_prob);

    Eigen::VectorXd x0(2);
    x0 << 4, 1;
    auto result = qp.solve(x0);

    std::cout << "x:" << std::endl;
    std::cout << result.x << std::endl;

    std::cout << "iter: " << result.iter_cnt << std::endl;

    EXPECT_TRUE(result.is_solved);
    EXPECT_TRUE(qp.satisfy(result.x));
    EXPECT_NEAR_VEC(result.x, Eigen::Vector2d(3, 1), 1e-2);

    auto result2 = quad_prob_ineq_con(qp_prob.Q, qp_prob.c, qp_prob.A, qp_prob.b, x0);
    EXPECT_NEAR_VEC(result2.x, result.x, 1e-2);
}

TEST(quadprog, ineq_active_constraint) {
    using namespace cpp_robotics;

    QuadProgProblem qp_prob;
    qp_prob.set_problem_size(2, 2, 0, false); 

    qp_prob.Q << 1, 0, 
        0, 1;
    qp_prob.c << -3, -1;

    qp_prob.A << 
        1, 0,
        0, -1;
    qp_prob.b << 2, -2;

    QuadProg qp(qp_prob);

    Eigen::VectorXd x0(2);
    x0 << 4, 1;
    auto result = qp.solve(x0);

    std::cout << "x:" << std::endl;
    std::cout << result.x << std::endl;

    std::cout << "iter: " << result.iter_cnt << std::endl;

    EXPECT_TRUE(result.is_solved);
    EXPECT_TRUE(qp.satisfy(result.x));
    EXPECT_NEAR_VEC(result.x, Eigen::Vector2d(2, 2), 1e-2);

    auto result2 = quad_prob_ineq_con(qp_prob.Q, qp_prob.c, qp_prob.A, qp_prob.b, x0);
    EXPECT_NEAR_VEC(result2.x, result.x, 1e-2);
}

TEST(quadprog, bound_active_constraint) {
    using namespace cpp_robotics;

    QuadProgProblem qp_prob;
    qp_prob.set_problem_size(2, 0, 0, true); 

    qp_prob.Q << 1, 0, 
                 0, 1;
    qp_prob.c << -3, -1;

    qp_prob.lb << -1, -1;
    qp_prob.ub << 1, 1;

    QuadProg qp(qp_prob);

    Eigen::VectorXd x0(2);
    x0 << 0, 1;
    auto result = qp.solve(x0);

    std::cout << "x:" << std::endl;
    std::cout << result.x << std::endl;

    std::cout << "iter: " << result.iter_cnt << std::endl;

    EXPECT_TRUE(result.is_solved);
    EXPECT_TRUE(qp.satisfy(result.x));
    EXPECT_NEAR_VEC(result.x, Eigen::Vector2d(1, 1), 1e-2);

    auto result2 = quad_prob_bound_con(qp_prob.Q, qp_prob.c, qp_prob.lb, qp_prob.ub, x0);
    EXPECT_NEAR_VEC(result2.x, result.x, 1e-2);
}

TEST(quadprog, eq_active_constraint) {
    using namespace cpp_robotics;

    QuadProgProblem qp_prob;
    qp_prob.set_problem_size(2, 0, 2, false); 

    qp_prob.Q << 1, 0, 
        0, 1;
    qp_prob.c << -3, -1;

    qp_prob.Aeq << 
        1, 0,
        0, 1;
    qp_prob.beq << -10, 10;

    QuadProg qp(qp_prob);

    Eigen::VectorXd x0(2);
    x0 << 4, 1;
    auto result = qp.solve(x0);

    std::cout << "x:" << std::endl;
    std::cout << result.x << std::endl;

    std::cout << "iter: " << result.iter_cnt << std::endl;

    EXPECT_TRUE(result.is_solved);
    EXPECT_TRUE(qp.satisfy(result.x));
    EXPECT_NEAR_VEC(result.x, Eigen::Vector2d(-10, 10), 1e-2);

    auto result2 = quad_prob_eq_con(qp_prob.Q, qp_prob.c, qp_prob.Aeq, qp_prob.beq, x0);
    EXPECT_NEAR_VEC(result2.x, result.x, 1e-2);
}