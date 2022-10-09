
#pragma once

#include <cmath>
#include <optional>
#include <tuple>
#include <algorithm>
#include "integrator.hpp"

namespace cpp_robotics
{

/**
 * @brief 加速度制限フィルタ(速度制限込み)
 * 
 */
/// 熊本大学の岡島研究室の文献を参考にした
class AccelerationLimitFilter
{
public:
    AccelerationLimitFilter(double acc_max, double Ts, double gpd, double Kx, double Kv, std::optional<std::pair<double, double>> limit = std::nullopt):
        acc_max_(acc_max), Ts_(Ts), gpd_(gpd), Kx_(Kx), Kv_(Kv), limit_(limit), diff_(Ts, gpd), vel_integ_(Ts), pos_integ_(Ts)
    {
        reset();
    }

    // 目安としてのパラメータ、加速度によってオーバーシュート量が変わるので注意
    AccelerationLimitFilter(double acc_max, double Ts, std::optional<std::pair<double, double>> limit = std::nullopt):
        AccelerationLimitFilter(acc_max, Ts, 0.5/Ts, 1000.0/Ts, 500.0/Ts/std::sqrt(acc_max), limit)
    {
    }

    virtual void reset()
    {
        y1_ = 0;
        v1_ = 0;
        diff_.reset();
        vel_integ_.reset();
        pos_integ_.reset();
    }

    virtual double filtering(double u) 
    {
        auto[diff2, diff1, pass] = diff_.filtering(u);

        double acc = diff2 - (Kx_*(y1_-pass)) - (Kv_*(v1_-diff1));

        acc = std::clamp(acc, -acc_max_, acc_max_);
        double vel = vel_integ_.filtering(acc);
        double pos = pos_integ_.filtering(vel);

        v1_ = vel;
        y1_ = pos;
        return pos;
    }

    double Ts() const { return Ts_; }

private:
    class DiffTri
    {
    public:
        DiffTri(double gpd, double Ts): Ts_(Ts), gpd_(gpd) { reset(); }

        void reset()
        {
            u1_ = u2_ = 0;
            diff21_ = diff22_ = 0;
            diff11_ = diff12_ = 0;
            pass2_ = pass1_ = 0;
        }

        std::tuple<double, double, double> filtering(double u)
        {
            const double tau_ = 1/gpd_;
            const double y1_coeff = (-4*tau_*tau_ + 2*Ts_*Ts_);
            const double y2_coeff = (2*tau_*tau_ - 4*tau_*Ts_ + Ts_*Ts_);
            const double y_coeff = 2*tau_*tau_ + 4*tau_*Ts_ + Ts_*Ts_; 
            // double prev_y = (-4*tau_*tau_ + 2*Ts_*Ts_)*y1_ + (2*tau_*tau_ - 4*tau_*Ts_ + Ts_*Ts_)*y2_;
            // double prev_y = (-4*tau_*tau_ + 2*Ts_*Ts_)*y1_ + (2*tau_*tau_ - 4*tau_*Ts_ + Ts_*Ts_)*y2_;
            
            const double prev_diff2 = y1_coeff*diff21_ + y2_coeff*diff22_;
            const double prev_diff1 = y1_coeff*diff11_ + y2_coeff*diff12_;
            const double prev_pass  = y1_coeff*pass1_ + y2_coeff*pass2_;
            

            double diff2 = ( 4*(u -2*u1_ + u2_) - prev_diff2) / y_coeff;
            double diff1 = ( 2*Ts_*(u - u2_) - prev_diff1) / y_coeff;
            double pass = ( Ts_*Ts_*(u +2*u1_ + u2_) - prev_pass) / y_coeff;

            u2_ = u1_;
            u1_ = u;

            diff22_ = diff21_;
            diff21_ = diff2;
            diff12_ = diff11_;
            diff11_ = diff1;
            pass2_ = pass1_;
            pass1_ = pass;

            return {diff2, diff1, pass};
        }

    private:
        double Ts_, gpd_;
        double u1_, u2_;
        double diff21_, diff22_;
        double diff11_, diff12_;
        double pass1_, pass2_;
    };

    const double acc_max_;
    const double Ts_; 
    const double gpd_; 
    const double Kx_; 
    const double Kv_; 
    const std::optional<std::pair<double, double>> limit_;

    DiffTri diff_;
    Integrator vel_integ_, pos_integ_;
    double y1_, v1_;
};

}


