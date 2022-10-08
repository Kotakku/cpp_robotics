#include <gtest/gtest.h>
#include "../test_utility.hpp"

#include <cpp_robotics/system/discret.hpp>

TEST(discret_tf, lpf) {
    using namespace cpp_robotics;

    const double tau = 0.1;
    const double dt = 1e-3;

    std::vector<double> num_ref = {dt, dt};
    std::vector<double> den_ref = {dt+2*tau, dt-2*tau};

    auto [num, den] = DiscretTransferFunction::discritize({1}, {tau, 1}, dt);

    // std::cout << "ref" << std::endl;
    // std::cout << Polynomial(num_ref) << std::endl;
    // std::cout << "------------------------" << std::endl;
    // std::cout << Polynomial(den_ref) << std::endl;
    
    // std::cout << "test" << std::endl;
    // std::cout << Polynomial(num) << std::endl;
    // std::cout << "------------------------" << std::endl;
    // std::cout << Polynomial(den) << std::endl;

    EXPECT_NEAR_STD_VECTOR(num, num_ref, 1e-6);
    EXPECT_NEAR_STD_VECTOR(den, den_ref, 1e-6);
}

TEST(discret_tf, second_order_system) {
    using namespace cpp_robotics;

    const double zeta = 0.1;
    const double omega = 100;
    const double dt = 1e-3;

    std::vector<double> num_ref = {dt*dt*omega*omega, 2*dt*dt*omega*omega, dt*dt*omega*omega};
    std::vector<double> den_ref = {(4+4*dt*zeta*omega+dt*dt*omega*omega), (-8+2*dt*dt*omega*omega), (4-4*dt*zeta*omega+dt*dt*omega*omega)};

    auto [num, den] = DiscretTransferFunction::discritize({omega*omega}, {1, 2*zeta*omega, omega*omega}, dt);

    // std::cout << "ref" << std::endl;
    // std::cout << Polynomial(num_ref) << std::endl;
    // std::cout << "------------------------" << std::endl;
    // std::cout << Polynomial(den_ref) << std::endl;
    
    // std::cout << "test" << std::endl;
    // std::cout << Polynomial(num) << std::endl;
    // std::cout << "------------------------" << std::endl;
    // std::cout << Polynomial(den) << std::endl;

    EXPECT_NEAR_STD_VECTOR(num, num_ref, 1e-6);
    EXPECT_NEAR_STD_VECTOR(den, den_ref, 1e-6);
}