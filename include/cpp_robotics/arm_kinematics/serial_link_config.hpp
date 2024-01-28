#pragma once

#include "cpp_robotics/arm_kinematics/arm_kinematics.hpp"
#include <Eigen/Geometry>
#include <optional>

namespace cpp_robotics
{

// 右手座標系
struct SerialLinkKinematicsConfig
{    
    enum class LinkType
    {
        RotationX,
        RotationY,
        RotationZ,
        LinearX,
        LinearY,
        LinearZ
    };
    LinkType link_type;
    Eigen::Translation3d position; // 親リンクからの相対位置
    std::optional<std::pair<double, double>> limit;

    Eigen::Affine3d transformation_matrix(double q) const
    {
        Eigen::Affine3d affine;
        switch(link_type)
        {
            case LinkType::RotationX:
                affine = Eigen::AngleAxis(q, Eigen::Vector3d::UnitX()) * position;
                break;
            case LinkType::RotationY:
                affine = Eigen::AngleAxis(q, Eigen::Vector3d::UnitY()) * position;
                break;
            case LinkType::RotationZ:
                affine = Eigen::AngleAxis(q, Eigen::Vector3d::UnitZ()) * position;
                break;

            case LinkType::LinearX:
                affine = position * Eigen::Translation3d(q, 0, 0);
                break;
            case LinkType::LinearY:
                affine = position * Eigen::Translation3d(0, q, 0);
                break;
            case LinkType::LinearZ:
                affine = position * Eigen::Translation3d(0, 0, q);
                break;
            default:
                affine = Eigen::Matrix3d::Identity();
        }

        return affine;
    };
};

struct SerialLinkDynamicsConfig
{
    double mass;
    Eigen::Vector3d center_of_mass;
    Eigen::Matrix3d inertia_tensor;
};

}