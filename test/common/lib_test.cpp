#include <gtest/gtest.h>

// 一番大きいヘッダをincludeしてビルドが通るかどうかテスト
#include <cpp_robotics/cpp_robotics.hpp>

TEST(lib_test, test) {
    namespace cr = cpp_robotics;
    cr::print("hello world: %d, %.3lf\n", 100, 3.141);
}