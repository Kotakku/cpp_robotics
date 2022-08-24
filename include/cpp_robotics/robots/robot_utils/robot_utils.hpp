#pragma once

#include <type_traits>
#include <memory>

namespace cpp_robotics
{

template<class Interface, class UserInterface>
struct is_base_of_robot_if
{
    static constexpr bool value = std::is_base_of<Interface, UserInterface>::value;
};

template<class Interface, class UserInterface>
static constexpr bool is_base_of_robot_if_v = is_base_of_robot_if<Interface, UserInterface>::value;

}