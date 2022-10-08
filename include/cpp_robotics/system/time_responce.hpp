#pragma once

#include <tuple>
#include "../utility/space.hpp"
#include "./transfer_function.hpp"
#include "./discrete_transfer_function.hpp"


namespace cpp_robotics
{

/**
 * @brief インパルス応答を求める
 * 
 * @param sys 
 * @param time 
 * @return std::tuple<std::vector<double>, std::vector<double>> 
 */
static std::tuple<std::vector<double>, std::vector<double>> impluse(TransferFunction &sys, double time)
{
    std::vector<double> t = arrange(0, time, sys.Ts());
    std::vector<double> res(t.size());

    for(size_t i = 0; i < res.size(); i++)
    {
        res[i] = sys.responce( i == 0 ? 1.0/sys.Ts() : 0.0);
    }

    return {t, res};
}

/**
 * @brief ステップ応答を求める
 * 
 * @param sys 
 * @param dt 
 * @param time 
 * @param gain 
 * @return std::tuple<std::vector<double>, std::vector<double>> 
 */
static std::tuple<std::vector<double>, std::vector<double>> step(const std::function<double(double)> &sys, double dt, double time, const double gain = 1.0)
{
    std::vector<double> t = arrange(0, time, dt);
    std::vector<double> res(t.size());

    for(size_t i = 0; i < res.size(); i++)
    {
        res[i] = sys(gain);
    }

    return {t, res};
}

/**
 * @brief ステップ応答を求める
 * 
 * @param sys 
 * @param time 
 * @param gain 
 * @return std::tuple<std::vector<double>, std::vector<double>> 
 */
static std::tuple<std::vector<double>, std::vector<double>> step(TransferFunction &sys, double time, const double gain = 1.0)
{
    return step([&](double u){ return sys.responce(u); }, sys.Ts(), time, gain);
}

/**
 * @brief ステップ応答を求める
 * 
 * @param sys 
 * @param time 
 * @param gain 
 * @return std::tuple<std::vector<double>, std::vector<double>> 
 */
static std::tuple<std::vector<double>, std::vector<double>> step(DiscreteTransferFunction &sys, double time, const double gain = 1.0)
{
    return step([&](double u){ return sys.responce(u); }, sys.Ts(), time, gain);
}

/**
 * @brief 任意の入力による応答を求める
 * 
 * @param sys 
 * @param input 
 * @return std::tuple<std::vector<double>, std::vector<double>> 
 */
static std::tuple<std::vector<double>, std::vector<double>> lsim(TransferFunction &sys, std::vector<double> input)
{
    std::vector<double> t = linspace(0, sys.Ts()*input.size(), input.size());
    std::vector<double> res(t.size());

    for(size_t i = 0; i < res.size(); i++)
    {
        res[i] = sys.responce(input[i]);
    }

    return {t, res};
}

}