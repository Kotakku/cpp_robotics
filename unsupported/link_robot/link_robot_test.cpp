#include <gtest/gtest.h>
#include "../test_utility.hpp"

#include <cpp_robotics/system/link_robot.hpp>

TEST(link_robot, init) {
    using namespace cpp_robotics;

    std::vector<LinkConfig> config_ =
    {
        LinkConfig{
            .link_type = LinkConfig::LinkType::RotationZ,
            .position = Eigen::Translation3d(1, 0, 0),
            .mass = 1.0,
            .link_com = Eigen::Translation3d(0.5, 0, 0),
            .I = (Eigen::Matrix3d() <<
                1,0,0,
                0,1,0,
                0,0,1).finished()
        },
        LinkConfig{
            .link_type = LinkConfig::LinkType::RotationZ,
            .position = Eigen::Translation3d(1, 0, 0),
            .mass = 1.0,
            .link_com = Eigen::Translation3d(0.5, 0, 0),
            .I = (Eigen::Matrix3d() <<
                1,0,0,
                0,1,0,
                0,0,1).finished()
        }
    };
    LinkRobot robot = {config_};

    robot.show_dynamics();

}