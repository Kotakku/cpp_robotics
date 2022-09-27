#pragma once

#include <cstdio>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>

namespace cpp_robotics
{

/**
 * @brief 角度[rad]に対して範囲を指定する 複数の角度の範囲の合成をしたり逆を取ったりできる
 * 
 */
class AngleRange
{
public:
    using range_pair_t = std::pair<double, double>;
    constexpr static double PI = M_PI;
    AngleRange() = default;

    void add_range(const AngleRange &range)
    {
        for(auto r : range.ranges_)
        {
            add_range(r.first, r.second);
        }
    }
    void add_range(double start, double end)
    {
        if(start == end)
            return;
        
        // 一般角に分割して挿入する
        if(start > end)
            std::swap(start, end);
        
        double diff = end - start;
        start = normalize_angle_positive(start);
        end = start + diff;

        if(diff > 2*PI)
        {
            // 一周回ってる
            ranges_.push_back({0, 2*PI});
        }
        else
        {
            if(end > 2*PI)
            {
                ranges_.push_back({start, 2*PI});
                ranges_.push_back({0, end - 2*PI});
            }
            else
            {
                ranges_.push_back({start, end});
            }
        }

        // ranges_の結合・分割
        join_start:
        for(size_t look = 0; look < ranges_.size(); look++)
        {
            for(size_t dest = 0; dest < ranges_.size(); dest++)
            {
                if(look != dest)
                {
                    // 範囲がかぶってたら結合する
                    if(in_range_part(ranges_[look], ranges_[dest].first))
                    {
                        if(ranges_[look].second < ranges_[dest].second)
                            ranges_[look].second = ranges_[dest].second;
                        ranges_.erase(ranges_.begin()+dest);
                        goto join_start;
                    }
                    if(in_range_part(ranges_[look], ranges_[dest].second))
                    {
                        if(ranges_[look].first > ranges_[dest].first)
                            ranges_[look].first = ranges_[dest].first;
                        ranges_.erase(ranges_.begin()+dest);
                        goto join_start;
                    }
                }
            }
        }

        std::sort(ranges_.begin(), ranges_.end(), [](auto a, auto b){ return a.first < b.first; });
    }

    size_t size() const { return ranges_.size(); }

    AngleRange invert() const
    {
        AngleRange ret;

        if(size() == 0)
        {
            ret.add_range(0.0, 2*PI);
            return ret;
        }

        for(size_t i = 0; i < size()-1; i++)
        {
            ret.add_range(ranges_[i].second, ranges_[i+1].first);
        }
        ret.add_range(ranges_.back().second, ranges_.front().first + 2*PI);

        return ret;
    }

    // 引数の角度に対し範囲の中で一番近い角度を計算する
    double most_near_by(double angle)
    {
        angle = normalize_angle_positive(angle);
        if(in_range(angle))
            return angle;

        auto inv_ranges = this->invert().ranges_;
        // 2piをまたぐ場合は連結させる
        if(inv_ranges.front().first == 0.0 && inv_ranges.back().second == 2*PI)
        {
            range_pair_t new_back = 
            {
                inv_ranges.back().first,
                2*PI + inv_ranges.front().second
            };
            inv_ranges.erase(inv_ranges.begin());
            inv_ranges.back() = new_back;
            if(angle < inv_ranges.front().first)
                angle += 2*PI;
        }

        for(auto & ir : inv_ranges)
        {
            if(in_range_part(ir, angle))
            {
                if(std::abs(shortest_angular_distance(angle, ir.first)) < std::abs(shortest_angular_distance(angle, ir.second)))
                {
                    return normalize_angle_positive(ir.first);
                }
                else
                {
                    return normalize_angle_positive(ir.second);
                }
            }
        }

        // error
        return normalize_angle_positive(angle);
    }

    inline bool in_range_part(range_pair_t &range, double angle)
    {
        if(range.first <= angle && angle <= range.second)
            return true;
        return false;
    }

    bool in_range(double angle)
    {
        angle = normalize_angle_positive(angle);
        for(auto range : ranges_)
        {
            if(in_range_part(range, angle))
                return true;
        }
        return false;
    }

    std::vector<range_pair_t> ranges() const { return ranges_; }

private:
    double normalize_angle_positive(double angle)
    {
        return std::fmod(std::fmod(angle, 2*PI) + 2*PI, 2*PI);
    }

    double normalize_angle(double angle)
    {
        double a = normalize_angle_positive(angle);
        if (a > PI)
            a -= 2*PI;
        return a;
    }

    double shortest_angular_distance(double from, double to)
    {
        return normalize_angle(to-from);
    }

    void debug()
    {
        printf("debug\n");
        for(auto range : ranges_)
        {
            printf("(%8.2f, %8.2f)\n", range.first, range.second);
        }
        printf("\n");
    }
private:
    std::vector<range_pair_t> ranges_;
};

}