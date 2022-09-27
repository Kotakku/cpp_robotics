#pragma once

#include <cmath>
#include <vector>

namespace cpp_robotics
{

/**
 * @brief 遅延フィルタ
 * 
 */
/// G(s) = e^(-T*s)
/// 遅延時間はサンプリング時間の整数倍のみ
class DelayFilter
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