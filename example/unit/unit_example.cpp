#include <iostream>
#include "cpp_robotics/unit.hpp"

int main()
{
    using namespace cpp_robotics;

    constexpr Meter width = 1.5_m;
    constexpr Meter height = 3000_mm;
    constexpr Meter perimeter = 2*(width + height);
    std::cout << "perimeter: " << perimeter << " m" << std::endl;    

    constexpr Area rectangle_area = width*height;
    std::cout << "rectangle_area: " << rectangle_area << " m^2" << std::endl;

    constexpr Volt voltage = 20_V;
    constexpr Ohm res = 5_ohm;
    constexpr Ampere current = voltage / res;
    std::cout << "current: " << current << " A" << std::endl;
}



