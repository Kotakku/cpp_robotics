#include <gtest/gtest.h>
#include "../test_utility.hpp"

#include <cpp_robotics/optimize/quadprog.hpp>

constexpr double VEC_EPS = 2e-2;

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
    EXPECT_NEAR_VEC(result.x, Eigen::Vector2d(3, 2), VEC_EPS);

    auto result2 = quadprog(qp_prob.Q, qp_prob.c, x0);
    EXPECT_NEAR_VEC(result2.x, result.x, VEC_EPS);
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
    EXPECT_NEAR_VEC(result.x, Eigen::Vector2d(3, 1), VEC_EPS);

    auto result2 = quadprog_ineq_con(qp_prob.Q, qp_prob.c, qp_prob.A, qp_prob.b, x0);
    EXPECT_NEAR_VEC(result2.x, result.x, VEC_EPS);
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
    EXPECT_NEAR_VEC(result.x, Eigen::Vector2d(2, 2), VEC_EPS);

    auto result2 = quadprog_ineq_con(qp_prob.Q, qp_prob.c, qp_prob.A, qp_prob.b, x0);
    EXPECT_NEAR_VEC(result2.x, result.x, VEC_EPS);
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
    EXPECT_NEAR_VEC(result.x, Eigen::Vector2d(1, 1), VEC_EPS);

    auto result2 = quadprog_bound_con(qp_prob.Q, qp_prob.c, qp_prob.lb, qp_prob.ub, x0);
    EXPECT_NEAR_VEC(result2.x, result.x, VEC_EPS);
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
    EXPECT_NEAR_VEC(result.x, Eigen::Vector2d(-10, 10), 2e-2);

    auto result2 = quadprog_eq_con(qp_prob.Q, qp_prob.c, qp_prob.Aeq, qp_prob.beq, x0);
    EXPECT_NEAR_VEC(result2.x, result.x, VEC_EPS);
}

TEST(quadprog, eq_active_constraint2) {
    using namespace cpp_robotics;

using namespace cpp_robotics;

    QuadProgProblem problem;
    QuadProg qp;
    // qp.param.admm.sigma = 1e-4;

    // 変数のサイズ      : 2
    // 不等式制約のサイズ : 0
    // 等式制約のサイズ   : 1
    // box制約          : true
    problem.set_problem_size(2, 0, 1, true); 

    problem.Q << 
        1.55356e+14, 6.74972e+13,
        6.74972e+13, 2.93254e+13;

    problem.c <<
        -0.928814,
        1.89986;
    problem.lb << -0.1, -0.1;
    problem.ub << 0.1, 0.1;

    problem.Aeq << 1, 1;
    problem.beq << 0.05;

    Eigen::VectorXd x0(2);
    x0 << 1, 0;

    qp.set_problem(problem);
    auto result = qp.solve(x0);

    std::cout << "x:" << std::endl;
    std::cout << result.x << std::endl;

    std::cout << "x1 + x2: " << result.x(0) + result.x(1) << std::endl;

    std::cout << "iter: " << result.iter_cnt << std::endl;

    EXPECT_TRUE(result.is_solved);
    EXPECT_TRUE(qp.satisfy(result.x));
}

TEST(quadprog, linprog1) {
    using namespace cpp_robotics;

    QuadProgProblem problem;
    QuadProg qp;

    problem.set_problem_size(2, 0, 0, true); 

    problem.Q.setZero();

    problem.c <<
        5,3;

    problem.lb << 0, 0;
    problem.ub << 1, 1;

    Eigen::VectorXd x0(2);
    x0 << 1, 0;

    qp.set_problem(problem);
    auto result = qp.solve(x0);

    std::cout << "x:" << std::endl;
    std::cout << result.x << std::endl;
    std::cout << "iter: " << result.iter_cnt << std::endl;

    EXPECT_TRUE(result.is_solved);
    EXPECT_TRUE(qp.satisfy(result.x));
}

TEST(quadprog, linprog2) {
    using namespace cpp_robotics;

    QuadProgProblem problem;
    QuadProg qp;

    problem.set_problem_size(2, 2, 0, false); 

    problem.Q.setZero();

    problem.c <<
        5,3;

    problem.A <<
        1, -1,
        -1, 0;

    problem.b << 0, 0;

    Eigen::VectorXd x0(2);
    x0 << 1, 0;

    qp.set_problem(problem);
    auto result = qp.solve(x0);

    std::cout << "x:" << std::endl;
    std::cout << result.x << std::endl;
    std::cout << "iter: " << result.iter_cnt << std::endl;

    EXPECT_TRUE(result.is_solved);
    EXPECT_TRUE(qp.satisfy(result.x));
}

TEST(quadprog, random_problem1) {
    using namespace cpp_robotics;

    QuadProgProblem problem;
    QuadProg qp;

    problem.set_problem_size(2, 2, 0, false); 

    problem.Q <<
        0.0160804, -0.159151,
        -0.159151,   4.81169;

    problem.c <<
        0.50996,
        -1.44417;

    // Todo: 無効な制約を削除してから解く
    problem.A <<
        0,        0,
        0.357277,        0;

    problem.b << 
        0.0344884,
        0.378081;

    Eigen::VectorXd x0(2);
    x0 << 1, 0;

    qp.set_problem(problem);
    auto result = qp.solve(x0);

    std::cout << "x:" << std::endl;
    std::cout << result.x << std::endl;
    std::cout << "iter: " << result.iter_cnt << std::endl;

    EXPECT_TRUE(result.is_solved);
    EXPECT_TRUE(qp.satisfy(result.x));
    EXPECT_TRUE(result.lambda_ineq.size() == 2);
    EXPECT_NEAR(result.lambda_ineq(0), 0, 1e-3);
}

TEST(quadprog, random_problem2) {
    using namespace cpp_robotics;

    QuadProgProblem problem;
    QuadProg qp;

    problem.set_problem_size(2, 2, 0, false); 

    problem.Q <<
        1.574, -1.25304,
        -1.25304,  1.01822;

    problem.c <<
        0.848236,
        1.06342;

    problem.A <<
        0, 0,
        0, 0;

    problem.b << 
        0.219452,
        0.740985;

    Eigen::VectorXd x0(2);
    x0 << 1, 0;

    qp.set_problem(problem);
    auto result = qp.solve(x0);

    std::cout << "x:" << std::endl;
    std::cout << result.x << std::endl;
    std::cout << "iter: " << result.iter_cnt << std::endl;

    EXPECT_TRUE(result.is_solved);
    EXPECT_TRUE(qp.satisfy(result.x));
    EXPECT_TRUE(result.lambda_ineq.size() == 2);
    EXPECT_NEAR_VEC(result.lambda_ineq, Eigen::Vector2d(0, 0), 2e-2);
}

TEST(quadprog, sqp_sub_problem1) {
    using namespace cpp_robotics;

    QuadProgProblem problem;
    QuadProg qp(QuadProg::Method::ADMM);

    problem.set_problem_size(1, 1, 0, false); 

    problem.Q << 5.12e-07;
    problem.c << 1;
    problem.A << -1;
    problem.b << 2.22125e-11;

    Eigen::VectorXd x0(1);
    x0 << 1;

    qp.set_problem(problem);
    auto result = qp.solve(x0);

    std::cout << "x:" << std::endl;
    std::cout << result.x << std::endl;
    std::cout << "iter: " << result.iter_cnt << std::endl;

    EXPECT_TRUE(result.is_solved);
    EXPECT_TRUE(qp.satisfy(result.x));
}