#include <gtest/gtest.h>
#include "../test_utility.hpp"

#include <cpp_robotics/system/polynomial.hpp>

TEST(polynomial, construct) {
    using namespace cpp_robotics;

    Polynomial p1;
    EXPECT_EQ(p1.coeff().size(), 0);

    std::vector<double> coeff1 = {2.0, 3.0, 4.0};
    Polynomial p2(coeff1);
    EXPECT_TRUE(p2.coeff() == coeff1);

    Polynomial p3 = {coeff1};
    EXPECT_TRUE(p3.coeff() == coeff1);
    EXPECT_TRUE(p2 == p3);

    coeff1[0] = -5.0;
    Polynomial p4(coeff1);
    EXPECT_TRUE(p4.coeff() == coeff1);
    EXPECT_TRUE(p2 != p4);
    EXPECT_FALSE(p2 == p4);
}

TEST(polynomial, expand) {
    using namespace cpp_robotics;

    Polynomial p1 = Polynomial::expand({1}); // (x-1)を展開する
    std::vector<double> ref1 = {1, -1};
    EXPECT_TRUE(p1.coeff() == ref1);

    Polynomial p2 = Polynomial::expand({1, 2}); // (x-1)(x-2)を展開する
    std::vector<double> ref2 = {1, -3, 2};
    EXPECT_TRUE(p2.coeff() == ref2);

    Polynomial p3 = Polynomial::expand({1, 2, -3}); // (x-1)(x-2)(x+3)を展開する
    std::vector<double> ref3 = {1, 0, -7, 6};
    EXPECT_TRUE(p3.coeff() == ref3);
}


TEST(polynomial, utility) {
    using namespace cpp_robotics;

    // add, sub
    std::vector<double> ref1 = {2.0, 3.0, 4.0};
    Polynomial p1({2.0, 3.0, 4.0});

    EXPECT_TRUE(ref1 == p1.coeff());
    EXPECT_TRUE(ref1 == (+p1).coeff());
    EXPECT_TRUE(ref1 != (-p1).coeff());
    
    for(auto &c : ref1)
        c *= -1;
    
    EXPECT_TRUE(ref1 == (-p1).coeff());

    Polynomial p;
    p += p1;

    EXPECT_TRUE(p == p1);
}

// TEST(polynomial, der) {
//     using namespace cpp_robotics;

//     Polynomial p1({2.0, 3.0, 4.0});

//     EXPECT_TRUE(p1.polyder(0) == p1);

//     std::vector<double> ref1 = {4, 3};
//     EXPECT_TRUE(p1.polyder(1).coeff() == ref1);

//     auto v = p1.polyder(1).coeff();
//     for(auto c : v)
//         std::cout << c << std::endl;
    

// }

// TEST(polynomial, inter) {
//     using namespace cpp_robotics;

//     Polynomial p1({4.0, 3.0});

//     // EXPECT_TRUE(p1.polyint(0) == p1);
    
//     Polynomial ref1({2.0, 3.0, 0.0});
//     EXPECT_TRUE(p1.polyint() == ref1);
// }

TEST(polynomial, with_scalar) {
    using namespace cpp_robotics;

    // add, sub
    std::vector<double> ref1 = {2.0, 3.0, 5.0};
    Polynomial p1({2.0, 3.0, 5.0});
    p1 += 2.0;
    p1 = p1+2.0;
    p1 = p1-2.0;
    p1 -= 2.0;
    EXPECT_TRUE(p1.coeff() == ref1);

    Polynomial p2(ref1);
    p2 = p2 * 2.0;
    p2 = 2.0 * p2;
    p2 *= 2.0;
    std::vector<double> ref2 = {16.0, 24.0, 40.0};
    EXPECT_TRUE(p2.coeff() == ref2);

    p2 = p2/4.0;
    p2 /= 2.0;

    EXPECT_TRUE(p2 == Polynomial(ref1));
}

TEST(polynomial, with_poly) {
    using namespace cpp_robotics;

    Polynomial p1({1, 1});
    Polynomial ref1({1, 2, 1});
    EXPECT_TRUE(p1*p1 == ref1);

    auto p2 = ref1 + p1;
    p2 += p1;
    p2 = p2 - p1;
    p2 -= p1;
    EXPECT_TRUE(ref1 == p2);
}