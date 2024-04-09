#pragma once

#include "cpp_robotics/geometry/intersect.hpp"
#include "cpp_robotics/geometry/shape.hpp"
#include "cpp_robotics/path_planning/path_planning_utils.hpp"

namespace cpp_robotics {

using ObstacleShapeType = std::variant<Rect, Circle>;
class GeometryMap : public PathPlanningMap<Eigen::Vector2d> {
public:
    GeometryMap(const std::vector<ObstacleShapeType> &obstacles, const Rect &boundary) : obstacles_(obstacles), boundary_(boundary) {
        for (size_t i = 0; i < 2; i++) {
            double bmin = boundary_.center[i] - boundary_.size[i] / 2;
            double bmax = boundary_.center[i] + boundary_.size[i] / 2;
            this->rand_engines_.emplace_back(UniformRealRandomEngine(bmin, bmax));
        }
    }

    bool is_valid(const Vector &point) const override {
        cpp_robotics::Vector2d p(point(0), point(1));
        for (const auto &o : obstacles_) {
            if (std::visit([&p](auto &&arg) { return intersect(p, arg); }, o)) {
                return false;
            }
        }
        return true;
    }

    double map_size() const override {
        return boundary_.size.norm();
    }

private:
    std::vector<ObstacleShapeType> obstacles_;
    Rect boundary_;
};

} // namespace cpp_robotics