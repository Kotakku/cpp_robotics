#pragma once

#include <Eigen/Dense>
#include "cpp_robotics/optimize/golden_serach.hpp"
#include "cpp_robotics/utility/math_utils.hpp"

namespace cpp_robotics
{

template<class VectorType>
struct eigen_spline_api
{
    using Vector = VectorType;
    static constexpr int Dim = Vector::RowsAtCompileTime;
    using Scalar = typename Vector::Scalar;
    using SplineCoeff = Eigen::Matrix<Scalar, Dim, 4>;
    using WeightVector = Eigen::Matrix<Scalar, 4, 1>;

    /////////////////////////////////////////// base spline functions ///////////////////////////////////////////
    static SplineCoeff bezier_spline(const Vector &p0, const Vector &p1, const Vector &p2, const Vector &p3)
    {
        SplineCoeff coeff;
        coeff << p0, p1, p2, p3;
        return coeff;
    }

    static SplineCoeff hermite_spline(const Vector &p0, const Vector &p1, const Vector &v0, const Vector &v1)
    {
        Vector bp1 = p0 + (1.0 / 3.0) * v0;
        Vector bp2 = p1 - (1.0 / 3.0) * v1;
        return bezier_spline(p0, bp1, bp2, p1);
    }

    static SplineCoeff catumull_spline(const Vector &p0, const Vector &p1, const Vector &p2, const Vector &p3)
    {
        Vector bp1 = p1 + (1.0 / 6.0) * (p2 - p0);
        Vector bp2 = p2 - (1.0 / 6.0) * (p3 - p1);
        return bezier_spline(p1, bp1, bp2, p2);
    }

    // f(t) = a t^3 + b t^2 + c t + d -> bezier
    static SplineCoeff cubic_function_to_bezier(const Vector &a, const Vector &b, const Vector &c, const Vector &d)
    {
        Vector bp1 = d + (1.0 / 3.0) * c;
        Vector bp2 = (1.0 / 3.0) * b + (2.0 / 3.0) * c + d;
        Vector bp3 = a + b + c + d;
        return bezier_spline(d, bp1, bp2, bp3);
    }

    /////////////////////////////////////////// bezier weigth & evaluate functions ///////////////////////////////////////////
    static WeightVector bezier_weight(const double t)
    {
        double s = 1.0 - t;
        double t2 = t * t;
        double t3 = t2 * t;
        double s2 = s * s;
        double s3 = s2 * s;
        return WeightVector(s3, 3.0 * s2 * t, 3.0 * s * t2, t3);
    }

    static WeightVector bezier_weight(const WeightVector t)
    {
        return WeightVector(
            t(0) - 3.0 * t(1) + 3.0 * t(2) - t(3),
            3.0 * t(1) - 6.0 * t(2) + 3.0 * t(3),
            3.0 * t(2) - 3.0 * t(3),
            t(3));
    }

    static inline Vector evaluate(const SplineCoeff &spline, const WeightVector &w)
    {
        return spline * w;
    }

    /////////////////////////////////////////// position, velocity, acceleration ///////////////////////////////////////////
    static Vector position(const SplineCoeff &spline, double t)
    {
        return evaluate(spline, bezier_weight(t));
    }

    static Vector velocity(const SplineCoeff &spline, double t)
    {
        WeightVector dt(0.0, 1.0, 2.0 * t, 3.0 * t * t);
        return evaluate(spline, bezier_weight(dt));
    }

    static Vector acceleration(const SplineCoeff &spline, double t)
    {
        WeightVector ddt(0.0, 0.0, 2.0, 6.0 * t);
        return evaluate(spline, bezier_weight(ddt));
    }

    /////////////////////////////////////////// split ///////////////////////////////////////////
    static inline void split(const WeightVector &spline, WeightVector &spline0, WeightVector &spline1, double t)
    {
        // assumption: seg = (P0, P1, P2, P3)
        double q0 = lerp(spline(0), spline(1), t);
        double q1 = lerp(spline(1), spline(2), t);
        double q2 = lerp(spline(2), spline(3), t);
        double r0 = lerp(q0, q1, t);
        double r1 = lerp(q1, q2, t);
        double s0 = lerp(r0, r1, t);
        double sx = spline(0);
        double sw = spline(3);

        spline0 = WeightVector(sx, q0, r0, s0);
        spline1 = WeightVector(s0, r1, q2, sw);
    }

    // Optimised for t=0.5
    static inline void split(const WeightVector &spline, WeightVector &spline0, WeightVector &spline1)
    {
        double q0 = (spline(0) + spline(1)) * 0.5; // x + y / 2
        double q1 = (spline(1) + spline(2)) * 0.5; // y + z / 2
        double q2 = (spline(2) + spline(3)) * 0.5; // z + w / 2
        double r0 = (q0 + q1) * 0.5; // x + 2y + z / 4
        double r1 = (q1 + q2) * 0.5; // y + 2z + w / 4
        double s0 = (r0 + r1) * 0.5; // q0 + 2q1 + q2 / 4 = x+y + 2(y+z) + z+w / 8 = x + 3y + 3z + w
        double sx = spline(0);
        double sw = spline(3);

        spline0 = WeightVector(sx, q0, r0, s0);
        spline1 = WeightVector(s0, r1, q2, sw);
    }

    static void split(const SplineCoeff& spline, SplineCoeff& spline0, SplineCoeff& spline1)
    {
        WeightVector sp0, sp1;
        for(int i = 0; i < Dim; i++)
        {
            split(spline.row(i), sp0, sp1);
            spline0.row(i) = sp0;
            spline1.row(i) = sp1;
        }
    }

    static void split(const SplineCoeff& spline, SplineCoeff& spline0, SplineCoeff& spline1, double t)
    {
        WeightVector sp0, sp1;
        for(int i = 0; i < Dim; i++)
        {
            split(spline.row(i), sp0, sp1, t);
            spline0.row(i) = sp0;
            spline1.row(i) = sp1;
        }
    }

    /////////////////////////////////////////// length ///////////////////////////////////////////
    static double length_estimate(const SplineCoeff &s, double &error)
    {
        double d03 = (s.col(0) - s.col(3)).squaredNorm();
        double d01 = (s.col(0) - s.col(1)).squaredNorm();
        double d12 = (s.col(1) - s.col(2)).squaredNorm();
        double d23 = (s.col(2) - s.col(3)).squaredNorm();

        double min_length = std::sqrt(d03);
        double max_length = std::sqrt(d01) + std::sqrt(d12) + std::sqrt(d23);

        min_length *= 0.5;
        max_length *= 0.5;

        error = max_length - min_length;
        return min_length + max_length;
    }

    static double length(const SplineCoeff &s, double max_error)
    {
        double error;
        double len = length_estimate(s, error);

        if (error > max_error)
        {
            SplineCoeff s0;
            SplineCoeff s1;
            split(s, s0, s1);
            return length(s0, max_error) + length(s1, max_error);
        }

        return len;
    }

    static double length(const SplineCoeff &s, double t0, double t1, double max_error)
    {
        assert(0.0 <= t0 && t0 < 1.0);
        assert(0.0 <= t1 && t1 <= 1.0);
        assert(t0 <= t1);

        if(t0 == t1)
            return 0.0;

        SplineCoeff s0, s1;
        if (t0 == 0.0)
        {
            if (t1 == 1.0)
                return length(s, max_error);
            split(s, s0, s1, t1);
            return length(s0, max_error);
        }
        else
        {
            split(s, s0, s1, t0);
            if (t1 == 1.0)
                return length(s1, max_error);
            split(s1, s0, s1, (t1 - t0) / (1.0 - t0));
            return length(s0, max_error);
        }
    }
};

template<class VectorType>
class SplinePathBase
{
protected:
    using spline_api = eigen_spline_api<VectorType>;
public:
    using Vector = VectorType;
    SplinePathBase() = default;
    SplinePathBase(const std::vector<Vector> &waypoints)
    {
        set_path(waypoints);
    }

    virtual void set_path(const std::vector<Vector> &waypoints) = 0;

    bool is_empty() const { return waypoints_.size() == 0; }
    size_t waypoints_size() const { return waypoints_.size(); }
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
        assert(is_empty() == false);
        length = std::clamp(length, 0.0, total_length_);
        segment_info_t segment = get_segmet_idx_length(length);
        return spline_api::position(spline_segments_[segment.i].coeff, segment.t);
    }

    Vector direction(double length) const
    {
        assert(is_empty() == false);
        length = std::clamp(length, 0.0, total_length_);
        segment_info_t segment = get_segmet_idx_length(length);
        return spline_api::velocity(spline_segments_[segment.i].coeff, segment.t).normalized();
    }

protected:
    std::vector<Vector> waypoints_;
    std::vector<double> length_;
    double total_length_ = 0;

    struct segment_t
    {
        spline_api::SplineCoeff coeff;
        double length;
        std::vector<double> split_lengths;
    };

    std::vector<segment_t> spline_segments_;

    struct segment_info_t
    {
        size_t i;
        double t;
    };
    
    segment_info_t get_segmet_idx(const double t) const
    {
        segment_info_t result;
        if(waypoints_size() < 1)
        {
            result.i = 0;
            result.t = 0;
            return result;
        }
        result.i = std::min(static_cast<size_t>(std::floor(t)), waypoints_size()-1);
        result.t = t - static_cast<double>(result.i);
        return result;
    }

    segment_info_t get_segmet_idx_length(double length) const
    {
        segment_info_t result;
        result.i = 0;
        result.t = 1.0;
        while (length > spline_segments_[result.i].length)
        {
            length -= spline_segments_[result.i].length;
            result.i++;
        }

        double dt = 1.0 / spline_segments_[result.i].split_lengths.size();
        for(size_t i = 1; i < spline_segments_[result.i].split_lengths.size(); i++)
        {
            if(length < spline_segments_[result.i].split_lengths[i])
            {
                double diff = length - spline_segments_[result.i].split_lengths[i-1];
                double seg_diff = spline_segments_[result.i].split_lengths[i] - spline_segments_[result.i].split_lengths[i-1];
                result.t = static_cast<double>(i) * dt + (diff/seg_diff) * dt;
                return result;
            }
        }

        return result;
    }
};

template<class VectorType>
class CatumullRomSplinePath : public SplinePathBase<VectorType>
{
    using spline_api = eigen_spline_api<VectorType>;
    using segment_t = typename SplinePathBase<VectorType>::segment_t;
public:
    static constexpr double DEFAULT_LENGTH_ERROR = 0.05;
    using Vector = VectorType;
    CatumullRomSplinePath() = default;
    CatumullRomSplinePath(std::vector<Vector>& waypoints, bool trajectory_loop = false, const double error = DEFAULT_LENGTH_ERROR)
    {
        set_path_with_config(waypoints, trajectory_loop, error);
    }
    
    void set_path_with_config(std::vector<Vector>& waypoints, bool trajectory_loop = false, const double error = DEFAULT_LENGTH_ERROR)
    {
        trajectory_loop_ = trajectory_loop;
        error_ = error;
        set_path(waypoints);
    }

    virtual void set_path(const std::vector<Vector> &waypoints) override
    {
        auto &waypoints_ = this->waypoints_;
        auto &spline_segments_ = this->spline_segments_;
        auto &total_length_ = this->total_length_;

        waypoints_ = waypoints;
        const size_t p_size = this->waypoints_.size();

        switch (p_size)
        {
            case 0:
                return;
            case 1:
                {
                    Vector& p0 = waypoints_[0];
                    spline_segments_.push_back({spline_api::catumull_spline(p0, p0, p0, p0), 0, {}});
                    return;
                }
            case 2:
                spline_segments_.resize(1);
                calcu_segment(spline_segments_[0], waypoints_, error_, 0, 0, 0, 1, 1);
                total_length_ = spline_segments_[0].length;
                return;
        }

        const int segment_size = p_size - 1;
        spline_segments_.resize(segment_size);
        
        if(trajectory_loop_)
            calcu_segment(spline_segments_[0], waypoints_, error_, 0, p_size-2, 0, 1, 2);
        else
            calcu_segment(spline_segments_[0], waypoints_, error_, 0, 0, 0, 1, 2);
        for (size_t i = 0; i < p_size - 3; i++)
        {
            calcu_segment(spline_segments_[i+1], waypoints_, error_, i, 0, 1, 2, 3);
        }
        if(trajectory_loop_)
            calcu_segment(spline_segments_[segment_size-1], waypoints_, error_, 0, p_size-3, p_size-2, p_size-1, 1);
        else
            calcu_segment(spline_segments_[segment_size-1], waypoints_, error_, p_size-3, 0, 1, 2, 2);

        total_length_ = 0;
        for(auto& seg : spline_segments_)
        {
            total_length_ += seg.length;
        }
    }

private:
    void calcu_segment(segment_t& seg, std::vector<Vector>& waypoints_, const double error, const size_t start, const size_t i0 = 0, const size_t i1 = 1, const size_t i2 = 2, const size_t i3 = 3)
    {
        Vector &p0 = waypoints_[start + i0];
        Vector &p1 = waypoints_[start + i1];
        Vector &p2 = waypoints_[start + i2];
        Vector &p3 = waypoints_[start + i3];
        
        seg.coeff = spline_api::catumull_spline(p0, p1, p2, p3);
        seg.length = spline_api::length(seg.coeff, error_);
        seg.split_lengths.resize(100);
        for(size_t i = 0; i < 100; i++)
        {
            seg.split_lengths[i] = spline_api::length(seg.coeff, 0.0, static_cast<double>(i) / 100.0, error);
        }
    }

    bool trajectory_loop_ = false;
    double error_ = DEFAULT_LENGTH_ERROR;
};

template<class VectorType>
class CubicSplinePath : public SplinePathBase<VectorType>
{
    using spline_api = eigen_spline_api<VectorType>;
    using segment_t = typename SplinePathBase<VectorType>::segment_t;
public:
    static constexpr double DEFAULT_LENGTH_ERROR = 0.05;
    using Vector = VectorType;

    CubicSplinePath() = default;
    CubicSplinePath(std::vector<Vector>& waypoints, const double error = DEFAULT_LENGTH_ERROR)
    {
        set_path_with_config(waypoints, error);
    }
    
    void set_path_with_config(std::vector<Vector>& waypoints, const double error = DEFAULT_LENGTH_ERROR)
    {
        error_ = error;
        set_path(waypoints);
    }

    virtual void set_path(const std::vector<Vector> &waypoints) override
    {
        auto &waypoints_ = this->waypoints_;
        auto &spline_segments_ = this->spline_segments_;
        auto &total_length_ = this->total_length_;

        waypoints_ = waypoints;
        const size_t p_size = waypoints_.size();

        switch (p_size)
        {
            case 0:
                return;
            case 1:
                {
                    Vector& p0 = waypoints_[0];
                    spline_segments_.push_back({spline_api::catumull_spline(p0, p0, p0, p0), 0, {}});
                    return;
                }
        }

        std::vector<double> w;
        const size_t segment_size = p_size - 1;
        spline_segments_.resize(p_size);
        w.resize(p_size);

        Vector zero;
        if constexpr (Vector::RowsAtCompileTime == Eigen::Dynamic)
        {
            zero = Vector::Zero(waypoints[0].size());
        }
        else
        {
            zero = Vector::Zero();
        }

        // f(t) = a t^3 + b t^2 + c t + d 
        auto coeff_a = [&](size_t i) -> Vector { return spline_segments_[i].coeff.col(0); };
        auto coeff_b = [&](size_t i) -> Vector { return spline_segments_[i].coeff.col(1); };
        // auto coeff_c = [&](size_t i) -> Vector { return spline_segments_[i].coeff.col(2); };
        auto coeff_d = [&](size_t i) -> Vector { return spline_segments_[i].coeff.col(3); };
        auto set_coeff_a = [&](size_t i, const Vector& v) { spline_segments_[i].coeff.col(0) = v; };
        auto set_coeff_b = [&](size_t i, const Vector& v) { spline_segments_[i].coeff.col(1) = v; };
        auto set_coeff_c = [&](size_t i, const Vector& v) { spline_segments_[i].coeff.col(2) = v; };
        auto set_coeff_d = [&](size_t i, const Vector& v) { spline_segments_[i].coeff.col(3) = v; };

        {
            for(size_t i = 0; i < p_size; i++)
            {
                set_coeff_d(i, waypoints[i]);
            }

            set_coeff_b(0, zero);
            set_coeff_b(segment_size, zero);
            for(size_t i = 1; i < segment_size; i++)
            {
                set_coeff_b(i, 3.0 * (coeff_d(i-1) - 2.0 * coeff_d(i) + coeff_d(i+1)));
            }

            w[0] = 0.0;
            for(size_t i = 1; i < segment_size; i++)
            {
                double tmp = 4.0 - w[i-1];
                w[i] = 1.0 / tmp;
                set_coeff_b(i, (coeff_b(i) - coeff_b(i-1)) / tmp);
            }

            for(size_t i = segment_size-1; i > 0; i--) {
                set_coeff_b(i, coeff_b(i) - coeff_b(i+1) * w[i]);
            }

            set_coeff_a(segment_size, zero);
            set_coeff_c(segment_size, zero);
            for(size_t i = 0; i < segment_size; i++)
            {
                set_coeff_a(i, (coeff_b(i+1) - coeff_b(i)) / 3.0);
                set_coeff_c(i, coeff_d(i+1) - coeff_d(i) - coeff_b(i) - coeff_a(i));
            }
        }
        spline_segments_.erase(spline_segments_.begin()+spline_segments_.size()-1);

        total_length_ = 0;
        for(auto& seg : spline_segments_)
        {
            auto c = seg.coeff;
            seg.coeff = spline_api::cubic_function_to_bezier(c.col(0), c.col(1), c.col(2), c.col(3));
            seg.length = spline_api::length(seg.coeff, error_);
            seg.split_lengths.resize(100);
            for(size_t i = 0; i < 100; i++)
            {
                seg.split_lengths[i] = spline_api::length(seg.coeff, 0.0, static_cast<double>(i) / 100.0, error_);
            }
            total_length_ += seg.length;
        }
    }

private:
    double error_;
};

using CatumullRomSplinePath2d = CatumullRomSplinePath<Eigen::Vector2d>;
using CatumullRomSplinePath3d = CatumullRomSplinePath<Eigen::Vector3d>;

using CubicSplinePath2d = CubicSplinePath<Eigen::Vector2d>;
using CubicSplinePath3d = CubicSplinePath<Eigen::Vector3d>;

}