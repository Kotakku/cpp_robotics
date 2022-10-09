#include <gtest/gtest.h>

#include <Eigen/Dense>
#include <cpp_robotics/controller/pfc.hpp>

TEST(pfc, test) {
    namespace cr = cpp_robotics;

    Eigen::Matrix<double, 1, 1> A;

    A << 1;

    Eigen::Matrix<double, 1, 1> b, c;
    b << 1e-2;
    c << 1;
    cr::SISOPFC pfc(A, b, c, 0.0, 1.0, 1e-2);

    double u = pfc.calculate([](double){ return 1.0; }, 0.0);
    std::cout << "u = " << u << std::endl;
}