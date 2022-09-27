#include <gtest/gtest.h>

#include <cpp_robotics/utility/singleton.hpp>

class Tester
{
public:
    int val;
};

TEST(singoleton, int_test) {
    using namespace cpp_robotics;

    auto a = Singleton<int>::get_shared_instance();
    auto b = Singleton<int>::get_shared_instance();

    EXPECT_TRUE(a == b);
    *a = 44;
    EXPECT_EQ(*b, 44);
}

TEST(singoleton, class_test) {
    using namespace cpp_robotics;

    auto a = Singleton<Tester>::get_shared_instance();
    auto b = Singleton<Tester>::get_shared_instance();

    EXPECT_TRUE(a == b);

    a->val = 33;
    EXPECT_EQ(b->val, 33);
}