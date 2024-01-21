#pragma once

#include "cpp_robotics/path_planning/path_planning_utils.hpp"
#include "cpp_robotics/utility/space.hpp"
#include "cpp_robotics/utility/math_utils.hpp"

namespace cpp_robotics
{

struct DWAConfig
{
    double robot_radius;
    double max_velocity;
    double max_angular_velocity;
    size_t windows_size;
    double dt;
    double predict_time;

    double heading_angle_weight;
    double heading_velocity_weight;
    double to_goal_weight;
};

class DWA
{
public:
    DWA(const PathPlanningMap<Eigen::Vector2d> &map, const DWAConfig &config):
        map_(map), config_(config)
    {

    }

    /**
     * @brief
     * @param x0 位置 (x,y,theta)
     * @param goal 目標位置 (x,y)
    */
    Eigen::Vector2d control(Eigen::Vector3d x0, Eigen::Vector2d goal)
    {
        std::vector v_list = linspace(-config_.max_velocity, config_.max_velocity, config_.windows_size);
        std::vector omega_list = linspace(-config_.max_angular_velocity, config_.max_angular_velocity, config_.windows_size);
        Eigen::Vector2d best_u;
        best_u.setZero();
        double max_objective = -INFINITY;

        for(auto &v : v_list)
        {
            for(auto &omega : omega_list)
            {
                Eigen::Vector3d x = x0;
                Eigen::Vector3d x_nearest = x0;
                Eigen::Vector3d x1;
                bool is_collision_free = true;
                for(size_t i = 0; i < config_.predict_time / config_.dt; ++i)
                {
                    x = dynamics(x, v, omega, config_.dt);
                    if(i == 0)
                        x1 = x;
                    // 衝突判定
                    // Todo: robot_radiusを考慮する
                    if(not map_.is_valid(Eigen::Vector2d(x[0], x[1])))
                    {
                        is_collision_free = false;
                        break;
                    }

                    if((Eigen::Vector2d(x[0],x[1]) - goal).squaredNorm() < (Eigen::Vector2d(x_nearest[0],x_nearest[1])- goal).squaredNorm())
                    {
                        x_nearest = x;
                    }
                }

                if(is_collision_free)
                {
                    // スコア計算
                    double objective = 0.0;

                    double heading_angle = std::atan2(goal[1] - x[1], goal[0] - x[0]);
                    double heading_angle_diff = shortest_angular_distance(x[2], heading_angle);
                    objective += config_.heading_angle_weight * (M_PI - std::abs(heading_angle_diff))/M_PI;

                    objective += config_.heading_velocity_weight * v;

                    objective += config_.to_goal_weight * std::exp(-std::hypot(goal[0] - x1[0], goal[1] - x1[1]));

                    if(max_objective < objective)
                    {
                        max_objective = objective;
                        best_u = {v, omega};
                    }
                }
            }
        }

        return best_u;
    }

private:
    Eigen::Vector3d dynamics(const Eigen::Vector3d &x, double v, double omega, double dt)
    {
        Eigen::Vector3d x_next;
        x_next[0] = x[0] + v * std::cos(x[2]) * dt;
        x_next[1] = x[1] + v * std::sin(x[2]) * dt;
        x_next[2] = x[2] + omega * dt;
        return x_next;
    }

    const PathPlanningMap<Eigen::Vector2d> &map_;
    const DWAConfig config_;
};

}