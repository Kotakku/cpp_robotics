#pragma once

#include <Eigen/Dense>
#include "cpp_robotics/optimize/golden_serach.hpp"

namespace cpp_robotics
{

template<class VectorType>
class LinePath
{
public:
    using Vector = VectorType;
    LinePath() = default;
    LinePath(const std::vector<Vector> &path)
    {
        set_path(path);
    }

    void set_path(const std::vector<Vector> &path)
    {
        path_ = path;
        length_.resize(path.size());
        length_[0] = 0;
        for (size_t i = 1; i < path.size(); ++i)
        {
            length_[i] = length_[i - 1] + (path_[i] - path_[i - 1]).norm();
        }
        total_length_ = length_[path.size() - 1];
    }

    bool is_empty() const { return path_.size() == 0; }
    size_t size() const { return path_.size(); }
    double length() const { return total_length_; }

    double nearest_position(const Vector pos, double now_length = -1, double search_range = -1)
    {
        double low, high;
        if(now_length < 0)
        {
            low = 0;
            high = total_length_;
        }
        else
        {
            if(search_range < 0)
                search_range = total_length_ * 0.3;
            low = now_length - search_range;
            high = now_length + search_range;
            low = std::clamp(low, 0.0, total_length_);
            high = std::clamp(high, 0.0, total_length_);
        }

        return golden_search([&, pos](double length)
        {
            return (position(length) - pos).squaredNorm();
        }, low, high, total_length_*5e-3);
    }

    Vector position(double length) const
    {
        length = std::clamp(length, 0.0, total_length_);
        for(size_t i = 0; i < length_.size(); ++i)
        {
            if(length_[i] >= length)
            {
                double ratio = (length - length_[i - 1]) / (length_[i] - length_[i - 1]);
                return path_[i - 1] + ratio * (path_[i] - path_[i - 1]);
            }
        }
        return path_[path_.size() - 1];
    }

private:
    std::vector<Vector> path_;
    std::vector<double> length_;
    double total_length_;
};

}