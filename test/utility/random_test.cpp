#include <gtest/gtest.h>

#include <iostream>
#include <cpp_robotics/utility/random.hpp>
#include <array>

TEST(random, constructor) {
    using namespace cpp_robotics;
    
#define TEST_CONSTRUCTOR(con)\
    {\
        auto engine = con;\
        auto val = engine.value();\
    }

    TEST_CONSTRUCTOR(UniformIntRandomEngine(0, 9));
    TEST_CONSTRUCTOR(UniformRealRandomEngine(0.0, 1.0));

    TEST_CONSTRUCTOR(BernoulliRandomEngine(0.7));
    TEST_CONSTRUCTOR(BinomialRandomEngine(5, 0.5));
    TEST_CONSTRUCTOR(GeometricRandomEngine(0.5));
    TEST_CONSTRUCTOR(NegativeBinomialRandomEngine(5, 0.5));
    
    TEST_CONSTRUCTOR(PoissonRandomEngine(4.0));
    TEST_CONSTRUCTOR(ExponentialRandomEngine(1.0));
    TEST_CONSTRUCTOR(GammaRandomEngine(1.0, 1.0));
    TEST_CONSTRUCTOR(WeibullRandomEngine(1.0, 1.0));
    TEST_CONSTRUCTOR(ExtremeValueRandomEngine(0.0, 1.0));

    TEST_CONSTRUCTOR(NormalRandomEngine(0.0, 1.0));
    TEST_CONSTRUCTOR(LognormalRandomEngine(3.141592, 1.0));
    TEST_CONSTRUCTOR(ChiSquaredRandomEngine(1.0));
    TEST_CONSTRUCTOR(CauchyRandomEngine(0.0, 1.0));
    TEST_CONSTRUCTOR(FisherFRandomEngine(5, 10));
    TEST_CONSTRUCTOR(StudentTRandomEngine(1.0));
    
    std::vector<double> prob = { 0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 1.0, 0.9, 0.8, 0.7, 0.6};
    TEST_CONSTRUCTOR(DiscreteRandomEngine(prob.begin(), prob.end()));
    
    std::array<double, 3> intervals = {0.0, 5.0, 10.0};
    std::array<double, 2> densities = {0.3, 0.5};
    TEST_CONSTRUCTOR(PiecewiseConstantRandomEngine(intervals.begin(), intervals.end(), densities.begin()));
    TEST_CONSTRUCTOR(PiecewiseLinearRandomEngine(intervals.begin(), intervals.end(), densities.begin()));
    
#undef TEST_CONSTRUCTOR
}

TEST(random, normal_real) {
    namespace cr = cpp_robotics;

    cr::NormalRandomEngine engine(0.0, 1.0); // 平均0, 分散1
    EXPECT_DOUBLE_EQ(engine.mean(), 0.0);
    EXPECT_DOUBLE_EQ(engine.stddev(), 1.0);

    const int test_num = 10000;
    double avg = 0;
    for(int i = 0; i < test_num; i++)
    {
        double val = engine.value();
        avg += val / static_cast<double>(test_num);
    }
    printf("avg: %f\n", avg);
    EXPECT_NEAR(avg, 0.0, 0.1);
}

TEST(random, uniform_real) {
    namespace cr = cpp_robotics;

    cr::UniformRealRandomEngine engine(-1.0, 1.0); // 下限-1, 上限1
    EXPECT_DOUBLE_EQ(engine.a(), -1.0);
    EXPECT_DOUBLE_EQ(engine.b(), 1.0);

    const int test_num = 10000;
    double avg = 0;

    for(int i = 0; i < test_num; i++)
    {
        double val = engine.value();
        EXPECT_TRUE((-1.0 < val && val < 1.0));
        avg += val / static_cast<double>(test_num);
    }
    printf("avg: %f\n", avg);
    EXPECT_NEAR(avg, 0.0, 0.1);
}

TEST(random, generate_random) {
    namespace cr = cpp_robotics;

    const int test_num = 10000;
    double avg = 0;

    for(int i = 0; i < test_num; i++)
    {
        double val = cr::gererate_random();
        EXPECT_TRUE((0.0 < val && val < 1.0));
        avg += val / static_cast<double>(test_num);
    }
    printf("avg: %f\n", avg);
    EXPECT_NEAR(avg, 0.5, 0.1);
}