#pragma once

#include "./interface.hpp"

namespace cpp_robotics
{

/// @cond
template<class Interface>
class PendulumController
{
public:
    static_assert(is_base_of_robot_if_v<PendulumInterface, Interface>, "");
    PendulumController() = default;

    void control()
    {

    }
};
/// @endcond

}