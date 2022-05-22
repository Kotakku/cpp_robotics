#pragma once

#include <tuple>
#include <optional>
#include <algorithm>

namespace cpp_robotics
{

class Filter{
public:
	virtual double filtering(double input) = 0;
	virtual void reset(void) = 0;
};

class Differentiator : public Filter
{
public:
    // bandwidth[rad/s]
    // sample_time[s]
	Differentiator(double bandwidth, double sample_time): 
        Ts_(sample_time),
        gpd_(bandwidth)
    {
        
    }

    virtual void reset() override
    {
        u1_ = y1_ = 0;
    }

	virtual double filtering(double u)
    {
        double y;
        y = ( 2.0*gpd_*(u-u1_) + (2.0-Ts_*gpd_)*y1_ )/(2.0+Ts_*gpd_);
        u1_=u;
        y1_=y;        
        return y;
    }

private:
	double Ts_;
	double gpd_;
	double u1_;
	double y1_;
};


class LowPassFilter: public Filter
{

};

class Integrator: public Filter
{
public:
    Integrator(double ts):ts_(ts){}
    void reset()
    {
        val_ = 0;
        u1_ = 0;
    }
    
    double filtering(double u)
    {
        val_ += (u1_+u)*ts_*0.5;
        u1_ = u;
        return val_;
    }

private:
    double ts_;
    double val_, u1_ = 0;
};


namespace internal
{

// diff = s / (gpd*s + 1)
// pass = 1 / (gpd*s + 1)
class DiffPair
{
public:
    DiffPair(double Ts_, double gpd_): Ts(Ts_), gpd(gpd_) {}

    void reset()
    {
        reset(0.0f);
    }

    void reset(double u)
    {
        u1 = u;
        y1diff = 0;
        y1pass = 0;
    }
        
    std::tuple<double, double> calcu(double u)
    {
        double diff = ( 2.0*gpd*(u-u1) + (2.0-Ts*gpd)*y1diff )/(2.0+Ts*gpd);
        double pass = ( gpd*Ts*(u+u1) + (2.0-gpd*Ts)*y1pass )/(2.0+Ts*gpd);
        
        u1 = u;
        y1diff = diff;
        y1pass = pass;

        return {diff, pass};
    }

private:    
    double Ts, gpd;
    double u1 = 0, y1diff = 0, y1pass = 0;
};

class DiffTri
{
public:
    DiffTri(double Ts, double gpd): Ts_(Ts), gpd_(gpd) { reset(); }

    void reset()
    {
        u1_ = u2_ = 0;
        diff21_ = diff22_ = 0;
        diff11_ = diff12_ = 0;
        pass2_ = pass1_ = 0;
    }

    std::tuple<double, double, double> calcu(double u)
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

// G = 1/s
class Intr
{
public:
    Intr(double Ts_):Ts(Ts_){}

    void reset(double u = 0)
    {
        val = u;
        u1 = 0;
    }
    
    double calcu(double u)
    {
        val += (u1+u)*Ts*0.5;
        u1 = u;
        return val;
    }

private:
    double Ts;
    double val, u1 = 0;
};



}

class VelocityLimitFilter : public Filter
{
public:
    VelocityLimitFilter(double v_max_, double Ts_):
        VelocityLimitFilter(v_max_, Ts_, 1.0/Ts_, 0.5/Ts_){}

    VelocityLimitFilter(double v_max_, double Ts_, std::pair<double, double> limit):
        VelocityLimitFilter(v_max_, Ts_, 1.0/Ts_, 0.5/Ts_, limit){}
    
    VelocityLimitFilter(double v_max_, double Ts_, double gpd_, double fb_gain, std::optional<std::pair<double, double>> limit = std::nullopt): 
        Ts(Ts_), v_max(v_max_), gpd(gpd_), Cfb(fb_gain), dp(Ts, gpd), intr(Ts), limit_(limit)
    {
        reset();
    }

    virtual void reset() 
    {
        reset(0);
    }
    void reset(double u)
    {
        u1 = u;
        y1 = u;
        dp.reset(u);
        intr.reset(u);
    }

    virtual double filtering(double u) 
    {
        if(limit_)
        {
            u = std::clamp(u, limit_.value().first, limit_.value().second);
        }
        auto[diff, pass] = dp.calcu(u);
        double v = diff - (Cfb*(y1-pass));
        v = std::clamp(v, -v_max, v_max);
        prev_v_ = v;
        double y = intr.calcu(v);
        if(limit_)
        {
            y = std::clamp(y, limit_.value().first, limit_.value().second);
        }
        
        u1 = u;
        y1 = y;
        return y;
    }

    double prev_v_;

private:
    double Ts, v_max, gpd, Cfb;
    internal::DiffPair dp;
    internal::Intr intr;
    double u1 = 0, y1 = 0;

    std::optional<std::pair<double, double>> limit_;
};

class StateHoledVelocityLimitFilter : public VelocityLimitFilter
{
public:
    using VelocityLimitFilter::VelocityLimitFilter;
    void set_input(double u_)
    {
        u = u_;
    }

    double filtering()
    {
        y = VelocityLimitFilter::filtering(u);
        return y;
    }

    double u = 0, y = 0;
};

class AccelerationLimitFilter : public Filter
{
public:
    AccelerationLimitFilter(double acc_max, double Ts, double gpd, double Kx, double Kv, std::optional<std::pair<double, double>> limit = std::nullopt):
        acc_max_(acc_max), Ts_(Ts), gpd_(gpd), Kx_(Kx), Kv_(Kv), limit_(limit), diff_(Ts, gpd), vel_integ_(Ts), pos_integ_(Ts)
    {
        reset();
    }

    // 目安としてのパラメータ、加速度によってオーバーシュート量が変わるので注意
    AccelerationLimitFilter(double acc_max, double Ts, std::optional<std::pair<double, double>> limit = std::nullopt):
        AccelerationLimitFilter(acc_max, Ts, 1/Ts, 1000.0/Ts, 500.0/Ts/std::sqrt(acc_max), limit)
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
        auto[diff2, diff1, pass] = diff_.calcu(u);

        double acc = diff2 - (Kx_*(y1_-pass)) - (Kv_*(v1_-diff1));

        acc = std::clamp(acc, -acc_max_, acc_max_);
        double vel = vel_integ_.calcu(acc);
        double pos = pos_integ_.calcu(vel);

        v1_ = vel;
        y1_ = pos;
        return pos;
    }

private:
    const double acc_max_;
    const double Ts_; 
    const double gpd_; 
    const double Kx_; 
    const double Kv_; 
    const std::optional<std::pair<double, double>> limit_;

    internal::DiffTri diff_;
    internal::Intr vel_integ_, pos_integ_;
    double y1_, v1_;
};

class DelayFilter : public Filter
{
public:
    DelayFilter(double delay_time, double Ts)
    {
        delay_sample_cnt_ = std::floor(delay_time/Ts);
        delay_table_.resize(delay_sample_cnt_);
    }

    virtual void reset()
    {
        for(auto &val : delay_table_)
        {
            val = 0;
        }
    }

    virtual double filtering(double u)
    {
        if(delay_table_.size() == 0)
            return u;
        
        for(int i = delay_table_.size() - 2; i >= 0; i--)
        {
            delay_table_[i+1] = delay_table_[i];
        }
        delay_table_[0] = u;
        return delay_table_.back();
    }

private:
    size_t delay_sample_cnt_;
    std::vector<double> delay_table_;
};

}