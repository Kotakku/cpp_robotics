#include <iostream>
#include <iomanip>
#include <cpp_robotics/system/system.hpp>
#include <cpp_robotics/controller/controller.hpp>

#define PRINT_MAT(MAT) \
    std::cout << #MAT << std::endl;\
    std::cout << MAT << std::endl << std::endl;

int main()
{
    namespace cr = cpp_robotics;
    
    Eigen::MatrixXd A(3,3);
    Eigen::MatrixXd B(3,1);
    Eigen::MatrixXd C(1,3);
    Eigen::MatrixXd D(1,1);

    A << 
        -0.313, 56.7, 0,
        -0.0139, -0.426, 0,
        0, 56.7, 0;
    B << 0.232, 0.0203, 0;
    C << 0, 0, 1;
    D << 0;

    const double dt = 0.01;
    cr::StateSpaceSystem sys(A, B, C, D, dt);

    std::cout << "//////////////////////////////" << std::endl;
    std::cout << "controllability: " << (cr::is_controllable(sys) ? "true" : "false") << std::endl;
    std::cout << "observability  : " << (cr::is_observable(sys) ? "true" : "false") << std::endl;
    
    std::cout << "\n//////////////////////////////" << std::endl;
    std::cout << "canonicalize" << std::endl;
    auto [A_tilde, B_tilde, C_tilde, D_tilde] = cr::canonicalize_system(sys, cr::CanonicalizeMode::CONTROLLABLE );
    
    std::cout << std::fixed << std::setprecision(2);
    PRINT_MAT(A_tilde);
    PRINT_MAT(B_tilde);
    PRINT_MAT(C_tilde);
    PRINT_MAT(D_tilde);
}