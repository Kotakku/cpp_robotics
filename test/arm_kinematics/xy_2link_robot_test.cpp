#include <gtest/gtest.h>

#include <Eigen/Dense>
#include <cpp_robotics/arm_kinematics/xy_2link_robot.hpp>

#define EXPECT_NEAR_VEC(v1, v2, eps)\
    EXPECT_NEAR((v1-v2).norm(), 0.0, eps)

TEST(xy_2link_robot, fk_test) {
    using namespace cpp_robotics;

    XY2LinkRobot robot(0.5, 0.5);

    Eigen::Vector2d angles(0.0, 0.0);
    Eigen::Vector2d pos(1.0, 0.0);
    Eigen::Vector2d fk_pos = robot.solve_fk(angles);  
    EXPECT_NEAR_VEC(fk_pos, pos, 1e-6); 

    angles << M_PI/2, 0.0;
    pos << 0.0, 1.0;
    fk_pos = robot.solve_fk(angles);
    EXPECT_NEAR_VEC(fk_pos, pos, 1e-6);

    // EXPECT_NEAR_VEC(fk_pos, robot.solve_fk(robot.solve_ik(fk_pos)), 1e-6);
}

TEST(xy_2link_robot, ik_test) {
    using namespace cpp_robotics;

    XY2LinkRobot robot(0.5, 0.5);

    Eigen::Vector2d angles(0.0, 0.0);
    Eigen::Vector2d pos(1.0, 0.0);
    Eigen::Vector2d ik_angles = robot.solve_ik(pos);
    std::cout << ik_angles << std::endl;
    EXPECT_NEAR_VEC(robot.solve_fk(ik_angles), robot.solve_fk(angles), 1e-6); 

    angles << M_PI/4, 0.0;
    pos << 1.0/sqrt(2.0), 1.0/sqrt(2.0);
    ik_angles = robot.solve_ik(pos);
    std::cout << ik_angles << std::endl;
    EXPECT_NEAR_VEC(robot.solve_fk(ik_angles), robot.solve_fk(angles), 1e-6);
}

// TEST(xy_2deg_robot, numerical_ik_test) {
//     using namespace cpp_robotics;
    
//     XY2linkRobot robot(0.5, 0.5);

//     Eigen::Vector2d angles(0.3, 0.4);
//     Eigen::Vector2d fk_pos = robot.solve_fk(angles); 
//     EXPECT_NEAR_VEC(fk_pos, robot.solve_fk(robot.solve_ik(fk_pos)), 1e-6);
// }