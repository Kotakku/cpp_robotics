#pragma once

#include <cmath>
#include <vector>
#include <functional>
#include "../utility/math_utils.hpp"

namespace cpp_robotics
{

/**
 * @brief startからendまでstepずつ増える点のベクトルを返す
 * 
 * @param start 
 * @param end 
 * @param step 
 * @return std::vector<double> 
 */
static std::vector<double> arrange(double start, double end, double step = 1.0)
{
    std::vector<double> vec(std::floor( (end-start) / step ));
    for(size_t i = 0; i < vec.size(); i++)
    {
        vec[i] = start + step * i;
    }
    return vec;
}

/**
 * @brief startからendまでをn分割した点のベクトルを返す
 * 
 * @param start 
 * @param end 
 * @param n 
 * @return std::vector<double> 
 */
static std::vector<double> linspace(double start, double end, size_t n = 100)
{
    std::vector<double> vec(n);
    for(size_t i = 0; i < n; i++)
    {
        vec[i] = lerp(start, end, static_cast<double>(i) / (n-1));
    }
    return vec;
}

/**
 * @brief 10^startから10^endまで対数的に等間隔なn個の点のベクトルを返す
 * 
 * @param start 
 * @param end 
 * @param n 
 * @return std::vector<double> 
 */
static std::vector<double> logspace(double start, double end, size_t n = 100)
{
    std::vector<double> vec(n);
    for(size_t i = 0; i < n; i++)
    {
        vec[i] = std::pow(10.0, lerp(start, end, static_cast<double>(i) / (n-1)));
    }
    return vec;
}

/**
 * @brief 
 * 
 * @param f 
 * @param n 
 * @return std::vector<double> 
 */
static std::vector<double> funcspace(std::function<double(size_t, size_t)> f, size_t n = 100)
{
    std::vector<double> vec(n);
    for(size_t i = 0; i < n; i++)
    {
        vec[i] = f(i, n);
    }
    return vec;
}

// 仕様が曖昧すぎる
static std::vector<double> sinspace(double a, double b, size_t n = 100)
{
    return funcspace([a, b](size_t i, size_t n_){ (void) n_; return a * std::sin(b * i); }, n );
}

}