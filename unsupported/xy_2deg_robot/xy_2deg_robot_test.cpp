// #include <gtest/gtest.h>

// #include <Eigen/Dense>
// #include <cpp_robotics/arm_ik/xy_2deg_robot.hpp>

// #define EXPECT_NEAR_VEC(v1, v2, eps)\
//     EXPECT_NEAR((v1-v2).norm(), 0.0, eps)

// TEST(xy_2deg_robot, analytical_ik_test) {
//     using namespace cpp_robotics;

//     XY2degRobot robot(0.5, 0.5, XY2degRobot::IkSolveMethod::Analytical);

//     Eigen::Vector2d angles(0.3, 0.4);
//     Eigen::Vector2d fk_pos = robot.solve_fk(angles);   
//     EXPECT_NEAR_VEC(fk_pos, robot.solve_fk(robot.solve_ik(fk_pos)), 1e-6);
// }

// TEST(xy_2deg_robot, numerical_ik_test) {
//     using namespace cpp_robotics;
    
//     XY2degRobot robot(0.5, 0.5, XY2degRobot::IkSolveMethod::Numerical);

//     Eigen::Vector2d angles(0.3, 0.4);
//     Eigen::Vector2d fk_pos = robot.solve_fk(angles); 
//     EXPECT_NEAR_VEC(fk_pos, robot.solve_fk(robot.solve_ik(fk_pos)), 1e-6);
// }