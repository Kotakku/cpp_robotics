#pragma once

#include <cmath>
#include <optional>
#include <tuple>
#include <algorithm>
#include "integrator.hpp"

namespace cpp_robotics
{

/// 速度制限フィルタ
// 熊本大学の岡島研究室の文献を参考にした
class VelocityLimitFilter
{
public:
    VelocityLimitFilter(double v_max, double dt):
        VelocityLimitFilter(v_max, dt, 0.5/dt, 0.5/dt){}

    VelocityLimitFilter(double v_max, double dt, std::pair<double, double> limit):
        VelocityLimitFilter(v_max, dt, 0.5/dt, 0.5/dt, limit){}
    
    VelocityLimitFilter(double v_max, double dt, double gpd, double fb_gain, std::optional<std::pair<double, double>> limit = std::nullopt): 
        Ts_(dt), v_max_(v_max), gpd_(gpd), cfb_(fb_gain), dp_(gpd, dt), intr_(dt), limit_(limit)
    {
        reset();
    }

    virtual void reset() 
    {
        reset(0);
    }
    void reset(double u)
    {
        u1_ = u;
        y1_ = u;
        dp_.reset(u);
        intr_.reset(u);
    }

    virtual double filtering(double u) 
    {
        if(limit_)
        {
            u = std::clamp(u, limit_.value().first, limit_.value().second);
        }
        auto[diff, pass] = dp_.filtering(u);
        double v = diff - (cfb_*(y1_-pass));
        v = std::clamp(v, -v_max_, v_max_);
        double y = intr_.filtering(v);
        if(limit_)
        {
            y = std::clamp(y, limit_.value().first, limit_.value().second);
        }
        
        u1_ = u;
        y1_ = y;
        return y;
    }

    double Ts() const { return Ts_; }

private:
    // diff = s / (gpd*s + 1)
    // pass = 1 / (gpd*s + 1)
    class DiffPair
    {
    public:
        DiffPair(double gpd, double Ts): Ts_(Ts), gpd_(gpd) {}

        void reset()
        {
            reset(0.0);
        }

        void reset(double u)
        {
            u1_ = u;
            y1diff_ = 0;
            y1pass_ = 0;
        }
            
        std::tuple<double, double> filtering(double u)
        {
            double diff = ( 2.0*gpd_*(u-u1_) + (2.0-Ts_*gpd_)*y1diff_ )/(2.0+Ts_*gpd_);
            double pass = ( gpd_*Ts_*(u+u1_) + (2.0-gpd_*Ts_)*y1pass_ )/(2.0+Ts_*gpd_);
            
            u1_ = u;
            y1diff_ = diff;
            y1pass_ = pass;

            return {diff, pass};
        }

    private:    
        double Ts_, gpd_;
        double u1_ = 0, y1diff_ = 0, y1pass_ = 0;
    };

    double Ts_, v_max_, gpd_, cfb_;
    DiffPair dp_;
    Integrator intr_;
    double u1_ = 0, y1_ = 0;

    std::optional<std::pair<double, double>> limit_;
};

}