#pragma once

#include "cpp_robotics/utility.hpp"
#include "cpp_robotics/vector/transform.hpp"
#include <optional>
#include <functional>

namespace cpp_robotics
{

/**
 * @brief Dubinsパス
 * 
 */
class DubinsPath
{
public:
    enum class Mode
    {
        LRL,
        RLR,
        LSL,
        LSR,
        RSL,
        RSR,

        NONE
    };

    DubinsPath(Transformd start, Transformd end, double cavature):
        start_(start), end_(end), cavature_(cavature)
    {
        auto distance = (end-start).make_vector2().get_rotated(-start.theta);
        double angle_distance = shortest_angular_distance(start.theta, end.theta);
        planning_from_origin({distance, angle_distance});
        all_length_ = plan_.t + plan_.p + plan_.q;
        build_pos_function();
    }

    double length() const { return all_length_; }
    double segment_length(size_t i) const
    {
        assert(i < 3);
        switch(i)
        {
            case 0: return plan_.t;
            case 1: return plan_.p;
            case 2: return plan_.q;
        }
        return 0;
    }

    Transformd position(double len) const
    {
        len = std::clamp(len, 0.0, all_length_);
        if(len == 0)
            return start_;
        for(size_t i = 0; i < 3; i++)
        {
            if(len < segment_length(i))
            {
                return pos_func_list_[i](len);
            }
            len -= segment_length(i);
        }
        return end_;
    }

    std::string path_type() const
    {
        switch (plan_.mode)
        {
        case Mode::LRL: return "LRL";
        case Mode::RLR: return "RLR";
        case Mode::LSL: return "LSL";
        case Mode::LSR: return "LSR";
        case Mode::RSL: return "RSL";
        case Mode::RSR: return "RSR";
        
        default:
            return "NONE";
        }
    }

private:
    struct PlanningResult
    {
        double t = 0;
        double p = 0;
        double q = 0;
        Mode mode = Mode::NONE;
    };

    void planning_from_origin(Transformd origin_to_goal)
    {
        const auto dist = origin_to_goal.make_vector2();

        const double D = dist.norm();
        const double d = D / cavature_;

        const double theta = mod2pi(dist.angle());
        const double alpha = mod2pi(-theta);
        const double beta = mod2pi(origin_to_goal.theta - theta);
        
        auto planner_bind = [this](auto mem_fn)
        {
            return std::bind(mem_fn, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
        };

        std::array planners = 
        {
            planner_bind(&DubinsPath::LRL),
            planner_bind(&DubinsPath::RLR),
            planner_bind(&DubinsPath::LSL),
            planner_bind(&DubinsPath::LSR),
            planner_bind(&DubinsPath::RSL),
            planner_bind(&DubinsPath::RSR)
        };

        double bcost = std::numeric_limits<double>::max();

        std::optional<PlanningResult> pret;

        for(auto &planner : planners)
        {
            if(auto ret = planner(alpha, beta, d); ret.has_value())
            {
                auto [t,p,q,mode] = ret.value();
                double cost = t+p+q;
                if(cost < bcost)
                {
                    plan_ = ret.value();
                    bcost = cost;
                }
            }
        }
    }

    std::optional<PlanningResult> LSL(double alpha, double beta, double d)
    {
        const double sa = std::sin(alpha);
        const double sb = std::sin(beta);
        const double ca = std::cos(alpha);
        const double cb = std::cos(beta);
        const double c_ab = std::cos(alpha - beta);

        const double tmp0 = d + sa - sb;

        const double p_squared = 2 + (d * d) - (2 * c_ab) + (2 * d * (sa - sb));
        if (p_squared < 0)
            return std::nullopt;
        const double tmp1 = std::atan2((cb - ca), tmp0);
        const double t = mod2pi(-alpha + tmp1);
        const double p = std::sqrt(p_squared);
        const double q = mod2pi(beta - tmp1);

        return PlanningResult{t, p, q, Mode::LSL};
    }

    std::optional<PlanningResult> RSR(double alpha, double beta, double d)
    {
        const double sa = std::sin(alpha);
        const double sb = std::sin(beta);
        const double ca = std::cos(alpha);
        const double cb = std::cos(beta);
        const double c_ab = std::cos(alpha - beta);

        const double tmp0 = d - sa + sb;
        const double p_squared = 2 + (d * d) - (2 * c_ab) + (2 * d * (sb - sa));
        if (p_squared < 0)
            return std::nullopt;
        const double tmp1 = std::atan2((ca - cb), tmp0);
        const double t = mod2pi(alpha - tmp1);
        const double p = std::sqrt(p_squared);
        const double q = mod2pi(-beta + tmp1);

        return PlanningResult{t, p, q, Mode::RSR};
    }

    std::optional<PlanningResult> LSR(double alpha, double beta, double d)
    {
        const double sa = std::sin(alpha);
        const double sb = std::sin(beta);
        const double ca = std::cos(alpha);
        const double cb = std::cos(beta);
        const double c_ab = std::cos(alpha - beta);

        const double p_squared = -2 + (d * d) + (2 * c_ab) + (2 * d * (sa + sb));
        if (p_squared < 0)
            return std::nullopt;
        const double p = std::sqrt(p_squared);
        const double tmp2 = std::atan2((-ca - cb), (d + sa + sb)) - std::atan2(-2.0, p);
        const double t = mod2pi(-alpha + tmp2);
        const double q = mod2pi(-mod2pi(beta) + tmp2);

        return PlanningResult{t, p, q, Mode::LSR};
    }

    std::optional<PlanningResult> RSL(double alpha, double beta, double d)
    {
        const double sa = std::sin(alpha);
        const double sb = std::sin(beta);
        const double ca = std::cos(alpha);
        const double cb = std::cos(beta);
        const double c_ab = std::cos(alpha - beta);

        const double p_squared = (d * d) - 2 + (2 * c_ab) - (2 * d * (sa + sb));
        if (p_squared < 0)
            return std::nullopt;
        const double p = std::sqrt(p_squared);
        const double tmp2 = std::atan2((ca + cb), (d - sa - sb)) - std::atan2(2.0, p);
        const double t = mod2pi(alpha - tmp2);
        const double q = mod2pi(beta - tmp2);

        return PlanningResult{t, p, q, Mode::RSL};
    }

    std::optional<PlanningResult> RLR(double alpha, double beta, double d)
    {
        const double sa = std::sin(alpha);
        const double sb = std::sin(beta);
        const double ca = std::cos(alpha);
        const double cb = std::cos(beta);
        const double c_ab = std::cos(alpha - beta);

        const double tmp_rlr = (6.0 - d * d + 2.0 * c_ab + 2.0 * d * (sa - sb)) / 8.0;
        if (std::abs(tmp_rlr) > 1.0)
            return std::nullopt;

        const double p = mod2pi(2 * M_PI - std::acos(tmp_rlr));
        const double t = mod2pi(alpha - std::atan2(ca - cb, d - sa + sb) + mod2pi(p / 2.0));
        const double q = mod2pi(alpha - beta - t + mod2pi(p));
        return PlanningResult{t, p, q, Mode::LRL};
    }

    std::optional<PlanningResult> LRL(double alpha, double beta, double d)
    {
        const double sa = std::sin(alpha);
        const double sb = std::sin(beta);
        const double ca = std::cos(alpha);
        const double cb = std::cos(beta);
        const double c_ab = std::cos(alpha - beta);

        const double tmp_lrl = (6.0 - d * d + 2 * c_ab + 2 * d * (- sa + sb)) / 8.0;
        if (std::abs(tmp_lrl) > 1)
            return std::nullopt;
        const double p = mod2pi(2 * M_PI - std::acos(tmp_lrl));
        const double t = mod2pi(-alpha - std::atan2(ca - cb, d + sa - sb) + p / 2.);
        const double q = mod2pi(mod2pi(beta) - alpha - t + mod2pi(p));

        return PlanningResult{t, p, q, Mode::LRL};
    }

    double mod2pi(double theta)
    {
        return theta - 2.0 * M_PI * std::floor(theta / 2.0 / M_PI);
    }

    enum class SegmentType
    {
        L, S, R, NONE
    };

    void build_pos_function()
    {
        Transformd start = start_;
        for(size_t i = 0; i < 3; i++)
        {
            switch(get_segment_type(i))
            {
                case SegmentType::L:
                    {
                        pos_func_list_[i] = [this, start](double len)
                        {
                            const double r = 1/cavature_;
                            const double theta = len/r;

                            Vector2d rot_origin = start.make_vector2() + Vector2d(r,0).get_rotated(start.theta + M_PI/2);
                            
                            Transformd pos = start;
                            pos.rotate(rot_origin, theta);
                            pos.theta += theta;
                            return pos;
                        };
                    }
                    break;

                case SegmentType::R:
                    {
                        pos_func_list_[i] = [this, start](double len)
                        {
                            const double r = 1/cavature_;
                            const double theta = len/r;
                            Vector2d rot_origin = start.make_vector2() + Vector2d(r,0).get_rotated(start.theta - M_PI/2);
                            
                            Transformd pos = start;
                            pos.rotate(rot_origin, -theta);
                            pos.theta += -theta;
                            return pos;
                        };
                    }
                    break;

                case SegmentType::S:
                    {
                        pos_func_list_[i] = [this, start](double len)
                        {
                            Transformd diff(Vector2d(len,0).get_rotated(start.theta), 0);
                            return start + diff;
                        };
                    }
                    break;

                default:
                    pos_func_list_[i] = [this](double len)
                    {
                        (void) len;
                        return start_;
                    };
            }
            start = pos_func_list_[i](segment_length(i));
        }
    }

    SegmentType get_segment_type(size_t seg)
    {
        switch(seg)
        {
            case 0:
                {
                    switch(plan_.mode)
                    {
                        case Mode::LRL:
                        case Mode::LSL:
                        case Mode::LSR:
                            return SegmentType::L;
                        case Mode::RLR:
                        case Mode::RSL:
                        case Mode::RSR:
                            return SegmentType::R;
                        default:
                            return SegmentType::NONE;
                    }
                }
                break;

            case 1:
                {
                    switch(plan_.mode)
                    {
                        case Mode::RLR:
                            return SegmentType::L;
                        case Mode::LRL:
                            return SegmentType::R;
                        case Mode::LSL:
                        case Mode::LSR:
                        case Mode::RSL:
                        case Mode::RSR:
                            return SegmentType::S;
                        default:
                            return SegmentType::NONE;
                    }
                }
                break;

            case 2:
                {
                    switch(plan_.mode)
                    {
                        case Mode::LRL:
                        case Mode::LSL:
                        case Mode::RSL:
                            return SegmentType::L;
                        case Mode::RLR:
                        case Mode::LSR:
                        case Mode::RSR:
                            return SegmentType::R;
                        default:
                            return SegmentType::NONE;
                    }
                }
                break;

            default:
                return SegmentType::NONE;
        }
        
    }

private:
    Transformd start_, end_;
    double cavature_;

    PlanningResult plan_;
    double all_length_ = 0;
    std::array<std::function<Transformd(double)>, 3> pos_func_list_;
};

}