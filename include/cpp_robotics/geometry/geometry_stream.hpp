#pragma once
#include <iostream>
#include "../vector/vector2.hpp"
#include "../vector/vector3.hpp"
#include "../vector/vector4.hpp"
#include "../vector/transform.hpp"

namespace cpp_robotics
{

std::ostream& operator << (std::ostream& os, const Vector2d& v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

std::ostream& operator << (std::ostream& os, const Vector3d& v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

std::ostream& operator << (std::ostream& os, const Vector4d& v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
    return os;
}

std::ostream& operator << (std::ostream& os, const Transformd& v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.theta << ")";
    return os;
}

}