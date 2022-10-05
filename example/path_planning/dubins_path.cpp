#define CR_USE_MATPLOTLIB
#include <iostream>
#include "cpp_robotics/cpp_robotics.hpp"

int main()
{
    using namespace cpp_robotics;
    namespace plt = matplotlibcpp;

    const Transformd start(4.0, 3.0, radians(-45));
    const Transformd end(1.0, 1.0, radians(45));
    const double cavature = 1;
    DubinsPath dpath(start, end, cavature);

    std::cout << dpath.path_type() << std::endl;

    for(size_t i = 0; i < 3; i++)
        std::cout << dpath.segment_length(i) << std::endl;

    auto l = linspace(0, dpath.length());

    std::vector<double> x(l.size()), y(l.size());

    for(size_t i = 0; i < l.size(); i++)
    {
        auto pos = dpath.position(l[i]);
        x[i] = pos.x;
        y[i] = pos.y;
    }
    
    plt::plot(x, y);
    plt::set_aspect(1.0);
    plt::show();
}



