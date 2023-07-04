#define CR_USE_MATPLOTLIB
#include <iostream>
#include <Eigen/Dense>
#include <cpp_robotics/system/link_robot.hpp>
#include <cpp_robotics/system.hpp>

int main()
{
    using namespace cpp_robotics;

    std::vector<LinkConfig> config_ =
    {
        LinkConfig{
            .link_type = LinkConfig::LinkType::RotationZ,
            .position = Eigen::Translation3d(1, 0, 0),
            .mass = 1.0,
            .link_com = Eigen::Translation3d(1, 0, 0),
            .I = (Eigen::Matrix3d() <<
                0,0,0,
                0,0,0,
                0,0,0).finished()
        },
        LinkConfig{
            .link_type = LinkConfig::LinkType::RotationZ,
            .position = Eigen::Translation3d(1, 0, 0),
            .mass = 1.0,
            .link_com = Eigen::Translation3d(1, 0, 0),
            .I = (Eigen::Matrix3d() <<
                0,0,0,
                0,0,0,
                0,0,0).finished()
        }
    };
    LinkRobot robot = {config_};
    
    robot.show_kinematics();
    robot.show_dynamics();
}