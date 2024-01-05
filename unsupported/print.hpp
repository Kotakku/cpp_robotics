#pragma once

#include <iostream>
#include <string>
#include <cpp_robotics/utility/cpp_support.hpp>

/**
 * @brief std::coutにprintfの形式でフォーマットされた文字列を出力する
 * 
 * @tparam Args 
 * @param format 
 * @param args 
 */
template <typename... Args>
void print(const std::string &format, Args const&... args)
{
    std::cout << c_format(format, args...);
}