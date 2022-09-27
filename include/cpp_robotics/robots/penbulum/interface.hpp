#pragma once

#include "../robot_utils/robot_utils.hpp"

namespace cpp_robotics
{

///@cond
// StateとInputはここで定義するんじゃなくてユーザー側で定義できるべき?
class PendulumInterface
{
public:
    PendulumInterface() = default;

    struct State
    {
        double angle;
        double omega;
        double domega;
        
        double pos;
        double vel;
        double acc;

        std::shared_ptr<void> arg;
    };
    

    struct Input
    {
        double input;

        std::shared_ptr<void> arg;
    };

    virtual State get_state() = 0;
    virtual void control(const Input &input) = 0;
};
/// @endcond

}