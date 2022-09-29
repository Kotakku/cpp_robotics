#include <gtest/gtest.h>
#include <vector>
#include <cpp_robotics/algorithm/poly_regression.hpp>

// Demonstrate some basic assertions.
TEST(polyregression, second_regression) {
    namespace cr = cpp_robotics;

    std::vector<double> x = {83,71,64,69,69,64,68,59,81,91};
    std::vector<double> y = {183,168,171,178,176,172,165,158,183,182};

    auto poly = cr::poly_regression(x, y, 2);

    auto coeff = poly.coeff();
    const std::vector<double> ans_coeff = {-18.39065381, 4.561419406, -0.02585526068};
    for(size_t i = 0; i < ans_coeff.size(); i++)
    {
        // printf("%6.2f\n", coeff[i]);
        EXPECT_NEAR(coeff[i], ans_coeff[i], 0.01);
    }

    EXPECT_NEAR(poly.evalute(77.8), 180.0, 0.01);
    // printf("f(77.8) = %6.2f\n", poly.evalute(77.8));
}