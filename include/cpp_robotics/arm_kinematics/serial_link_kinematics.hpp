#pragma once

#include "cpp_robotics/arm_kinematics/arm_kinematics.hpp"
#include "cpp_robotics/arm_kinematics/serial_link_config.hpp"

namespace cpp_robotics
{

class SerialLinkKinematics : public ArmForwardKinematics<SerialLinkKinematics>
{
public:
    SerialLinkKinematics(const std::vector<SerialLinkKinematicsConfig> &config):
        ArmForwardKinematics<SerialLinkKinematics>(config.size(), 3), config_(config) {}

    void forward_kinematics(const Eigen::VectorXd& q, Eigen::VectorXd& x)
    {
        Eigen::Vector3d xq = Eigen::Vector3d::Zero();
        for(size_t i = 0; i < nq(); i++)
        {
            xq = config_[nq()-1-i].transformation_matrix(q[nq()-1-i]) * xq;
        }
        x = xq;
    }

    std::vector<Eigen::Vector3d> solve_each_fk(Eigen::VectorXd joint_angles)
    {
        std::vector<Eigen::Vector3d> positions(nq());
        for(size_t i = 0; i < nq(); i++)
        {
            Eigen::Vector3d xq = Eigen::Vector3d::Zero();
            for(auto config = config_.rbegin() + (nq()-1-i); config != config_.rend(); config++)
            {
                xq = config->transformation_matrix(joint_angles[config_.rend() - config - 1]) * xq;
            }
            positions[i] = xq;
        }

        return positions;
    }

private:
    const std::vector<SerialLinkKinematicsConfig> config_;
};

static SerialLinkKinematics yaw_pitch_pitch_3dof_kinematics(double l1, double l2, double l3)
{
    std::vector<SerialLinkKinematicsConfig> config =
    {
        {
            SerialLinkKinematicsConfig::LinkType::RotationZ,
            Eigen::Translation3d(0, 0, l1),
            std::nullopt
        },
        {
            SerialLinkKinematicsConfig::LinkType::RotationY,
            Eigen::Translation3d(l2, 0, 0),
            std::nullopt
        },
        {
            SerialLinkKinematicsConfig::LinkType::RotationY,
            Eigen::Translation3d(l3, 0, 0),
            std::nullopt
        },
    };

    return SerialLinkKinematics(config);
};

}