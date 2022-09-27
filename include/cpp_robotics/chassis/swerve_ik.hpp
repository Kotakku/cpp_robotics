#pragma once

#include <array>
#include <Eigen/Dense>
#include "cpp_robotics/vector/transform.hpp"
#include "cpp_robotics/vector/vector2.hpp"

namespace cpp_robotics
{

/**
 * @brief メカナムの逆運動学モデル
 * 
 */
class SwerveIk
{
public:
    using VecArray = std::array<Vector2d, 4>;
    
    SwerveIk(const double width, const double length)
    {
        const double hw = width/2;
        const double hl = length/2;
        wheel_place_ =
        {
            Vector2d{ hw,  hl},
            Vector2d{-hw,  hl},
            Vector2d{-hw, -hl},
            Vector2d{ hw, -hl}
        };
    }

    SwerveIk(VecArray wheel_place):
        wheel_place_(wheel_place)
    {

    }

    VecArray calculate(Transformd velocity)
    {
        VecArray wv;
        for(size_t i = 0; i < 4; i++)
        {
            const double wangle = wheel_place_[i].angle();
            const double wpnorm = wheel_place_[i].norm();
            wv[i].x = velocity.x - wpnorm * velocity.theta * std::sin(wangle);
            wv[i].y = velocity.y + wpnorm * velocity.theta * std::cos(wangle);
        }
        return wv;
    }

    VecArray wheel_place() const { return wheel_place_; }

private:
    VecArray wheel_place_;
};
}