#include <iostream>
#include <cpp_robotics/algorithm/mahalanobis.hpp>
#include <Eigen/Dense>
#include <Eigen/Geometry>

#define PRINT_MAT(MAT) \
    std::cout << #MAT << std::endl;\
    std::cout << MAT << std::endl << std::endl;

int main()
{
    namespace cr = cpp_robotics;

    std::cout << "mahalanobis example" << std::endl;

    Eigen::Matrix2d cov;
    cov << 1, 0,
           0, 2;

    Eigen::Vector2d a, b, zero;
    a << 1, 0;
    b << 0, 1;
    zero = Eigen::Vector2d::Zero();

    PRINT_MAT(cov);

    std::cout << cr::mahalanobis(zero, a, cov.inverse()) << std::endl;
    std::cout << cr::mahalanobis(zero, b, cov.inverse()) << std::endl;
    
    
    cov = Eigen::Rotation2D(M_PI/4)*cov;
    PRINT_MAT(cov);

    std::cout << cr::mahalanobis(zero, a, cov.inverse()) << std::endl;
    std::cout << cr::mahalanobis(zero, b, cov.inverse()) << std::endl;

    

}