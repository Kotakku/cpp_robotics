#pragma once

// https://hamachannel.hatenablog.com/entry/2018/01/13/233521

#include <Eigen/Dense>
#include <cmath>
#include <functional>

namespace cpp_robotics
{

class SISOPFC
{
public:

    /**
     * @brief Construct a new SISOPFC object
     * 
     * @param Ad
     * @param Bd 
     * @param Cd 
     * @param delay 
     * @param target_responce_time 
     * @param dt 
     */
    SISOPFC(const Eigen::MatrixXd& Ad, const Eigen::VectorXd& Bd, const Eigen::VectorXd& Cd, const double delay, const double target_responce_time, const double dt):
        A(Ad), B(Bd), C(Cd), delay_(delay), target_responce_time_(target_responce_time), dt_(dt), prev_input_(0)
    {
        h1 = std::ceil(target_responce_time_ / (dt_ * 3));
        h2 = std::ceil(target_responce_time_ / (dt_ * 2));
        h3 = std::ceil(target_responce_time_ / (dt_ * 1));

        lh <<
            (1.0 - std::exp(-3.0 * (double)(h1) * dt_ / target_responce_time_)),
            (1.0 - std::exp(-3.0 * (double)(h2) * dt_ / target_responce_time_)),
            (1.0 - std::exp(-3.0 * (double)(h3) * dt_ / target_responce_time_));

        CAh1 = CAh2 = CAh3 = C.transpose().eval();
        for(size_t i = 0; i < h1; i++)
            CAh1 *= A;
        for (size_t i = 0; i < h2; i++)
            CAh2 *= A;
        for (size_t i = 0; i < h3; i++)
            CAh3 *= A;

        G_inv.setZero();
        Eigen::RowVectorXd tmp = C.transpose();
        for (size_t i = 0; i < h1; i++)
        {
            if(i > 0)
                tmp *= A;
            double ele = tmp.dot(B);
            double t1 = dt_ * (h1-1-i);
            double t2 = t1 * t1;
            G_inv(0, 0) += ele;
            G_inv(0, 1) += ele * t1;
            G_inv(0, 2) += ele * t2;
        }

        tmp = C.transpose();
        for (size_t i = 0; i < h2; i++)
        {
            if (i > 0)
                tmp *= A;
            double ele = tmp.dot(B);
            double t1 = dt_ * (h2-1-i);
            double t2 = t1 * t1;
            G_inv(1, 0) += ele;
            G_inv(1, 1) += ele * t1;
            G_inv(1, 2) += ele * t2;
        }
        tmp = C.transpose();
        for (size_t i = 0; i < h3; i++)
        {
            if (i > 0)
                tmp *= A;
            double ele = tmp.dot(B);
            double t1 = dt_ * (h3-1 - i);
            double t2 = t1 * t1;
            G_inv(2, 0) += ele;
            G_inv(2, 1) += ele * t1;
            G_inv(2, 2) += ele * t2;
        }

        G_inv = G_inv.inverse().eval();
        xm = Eigen::VectorXd::Zero(A.cols());
    }

    double calculate(std::function<double(double)> ref_target, double now_state)
    {
        return calculate(ref_target, now_state, prev_input_);
    }

    double calculate(std::function<double(double)> ref_target, double now_state, double prev_input)
    {
        Eigen::Vector3d SV_future;
        Eigen::Vector3d SF;

        xm = A * xm + B * prev_input;
        double y = C.dot(xm);

        double now_tsarget = ref_target(delay_);

        SV_future <<
            ref_target(delay_ + h1 * dt_) - now_tsarget,
            ref_target(delay_ + h2 * dt_) - now_tsarget,
            ref_target(delay_ + h3 * dt_) - now_tsarget;
        
        SF <<
            CAh1.dot(xm),
            CAh2.dot(xm),
            CAh3.dot(xm);

        auto buf = G_inv * (SV_future + (now_tsarget - now_state) * lh - SF + Eigen::Vector3d::Constant(y));
        prev_input_ = std::clamp<double>(buf(0), -12, 12);

        return prev_input_;
    }

    double prev_input() const { return prev_input_; }
private:
    Eigen::Matrix3d G_inv;
    Eigen::MatrixXd A;
    Eigen::VectorXd B, xm, MV_pre;
    Eigen::VectorXd C;
    Eigen::RowVectorXd CAh1, CAh2, CAh3;
    Eigen::Vector3d lh;
    size_t h1, h2, h3;
    double delay_;
    double target_responce_time_, dt_;
    double prev_input_;
};

}