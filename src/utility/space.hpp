#pragma once

#include <cmath>
#include <vector>
#include "../utility/math_utils.hpp"

namespace cpp_robotics
{

static std::vector<double> arrange(double start, double end, double step = 1.0)
{
    std::vector<double> vec(std::floor( (end-start) / step ));
    for(size_t i = 0; i < vec.size(); i++)
    {
        vec[i] = start + step * i;
    }
    return vec;
}

static std::vector<double> linspace(double start, double end, size_t n = 100)
{
    std::vector<double> vec(n);
    for(size_t i = 0; i < n; i++)
    {
        vec[i] = lerp(start, end, static_cast<double>(i) / (n-1));
    }
    return vec;
}

static std::vector<double> logspace(double start, double end, size_t n = 100)
{
    std::vector<double> vec(n);
    for(size_t i = 0; i < n; i++)
    {
        vec[i] = std::pow(10.0, lerp(start, end, static_cast<double>(i) / (n-1)));
    }
    return vec;
}

}