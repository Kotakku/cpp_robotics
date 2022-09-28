#include <gtest/gtest.h>

#include <cpp_robotics/filter/extended_kalman_filter.hpp>

class Tester : public cpp_robotics::ExtendedKalmanFilter
{
public:
    Tester():
        ExtendedKalmanFilter(0.01, 3, 3, 3)
    {
        F = Eigen::MatrixXd::Identity(state_size_, state_size_);
        B = Eigen::MatrixXd::Identity(state_size_, input_size_);
        H = Eigen::MatrixXd::Identity(observe_size_, state_size_);
    }

    virtual Eigen::VectorXd system(Eigen::VectorXd x, Eigen::VectorXd u)
    {
        return F*x + B*u;
    }

    virtual Eigen::VectorXd observe(Eigen::VectorXd x)
    {
        return H*x;
    }

    virtual void system_noise_conv(Eigen::MatrixXd &Q, Eigen::VectorXd x, Eigen::VectorXd u)
    {
        (void) x;
        (void) u;
        static bool is_inited = false;

        if(not is_inited)
        {
            Q = 0.03 * Eigen::MatrixXd::Identity(state_size_,state_size_);
        }
    }

    virtual void observe_noise_conv(Eigen::MatrixXd &R, Eigen::VectorXd x, Eigen::VectorXd u)
    {
        (void) x;
        (void) u;
        static bool is_inited = false;

        if(not is_inited)
        {
            R = 0.03 * Eigen::MatrixXd::Identity(observe_size_,observe_size_);
        }
    }

private:
    Eigen::MatrixXd F, B, X;
};

#define EXPECT_NEAR_VEC(v1, v2, eps)\
    EXPECT_NEAR((v1-v2).norm(), 0.0, eps)

TEST(extended_kalman_filter, test) {

    Tester tester;

    tester.reset(Eigen::VectorXd::Zero(3), 0.05*Eigen::MatrixXd::Identity(3,3));
    for(size_t i = 0; i < 100; i++)
        tester.filtering(Eigen::VectorXd::Zero(3), Eigen::VectorXd::Ones(3));
    Eigen::VectorXd est_x = tester.filtering(Eigen::VectorXd::Zero(3), Eigen::VectorXd::Ones(3));

    EXPECT_NEAR_VEC(est_x, Eigen::Vector3d::Ones(), 1e-6);

    Eigen::VectorXd test_vec;
    test_vec = tester.system(Eigen::Vector3d(0, 1, 0), Eigen::Vector3d(0,0,0));
    EXPECT_NEAR_VEC(test_vec, Eigen::Vector3d(0,1,0), 1e-6);

    test_vec = tester.system(Eigen::Vector3d(0, 0, 0), Eigen::Vector3d(0.3,0,0.3));
    EXPECT_NEAR_VEC(test_vec, Eigen::Vector3d(0.3,0,0.3), 1e-6);
}