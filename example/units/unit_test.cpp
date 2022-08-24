#include <iostream>
// #include <cpp_robotics/core.hpp>

#include "cpp_robotics/utility/utility.hpp"
#include "cpp_robotics/vector/vector.hpp"
#include "cpp_robotics/units/units.hpp"

int main()
{
    using namespace cpp_robotics;

    constexpr Meter width = 1.5_m;
    constexpr Meter height = 3000_mm;

    constexpr Meter perimeter = 2*(width + height); // 8.0

    constexpr Area rectangle_area = width*height; // 4.5

    constexpr Volt voltage = 20_V;
    constexpr Ohm res = 5_ohm;



    constexpr Ampere current = voltage / res; // 4.0
}



