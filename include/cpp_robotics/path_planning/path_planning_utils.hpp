#pragma once

#include <Eigen/Dense>
#include "cpp_robotics/utility/random.hpp"
#include "cpp_robotics/algorithm/kdtree.hpp"
#include <unordered_set>

namespace cpp_robotics
{

template<class Vector>
class PathPlanningNode {
public:
    Vector point;
    double cost;
    PathPlanningNode* parent;

    PathPlanningNode(const Vector& point) : point(point), cost(INFINITY), parent(nullptr) {}

    bool operator>(const PathPlanningNode& other) const {
        return cost > other.cost;
    }

    bool operator<(const PathPlanningNode& other) const {
        return cost < other.cost;
    }
};

template<class EigenVector>
class PathPlanningMap
{
public:
    using Vector = EigenVector;

    template <int N = Vector::RowsAtCompileTime,
              typename std::enable_if<N != Eigen::Dynamic, int>::type = 0>
    PathPlanningMap(): dimension_(Vector::RowsAtCompileTime) {}

    template <int N = Vector::RowsAtCompileTime,
              typename std::enable_if<N == Eigen::Dynamic, int>::type = 0>
    PathPlanningMap(int dimension): dimension_(dimension) {}

    size_t dimension() const { return dimension_; }

    virtual bool is_valid(const Vector &point) const = 0;
    virtual bool is_valid(const Vector &from, const Vector &to) const = 0;

    virtual Vector random_sampling() const = 0;

    virtual double map_size() const = 0;

private:
    const size_t dimension_;
};

/**
 * @brief GridMap は障害物を格子点の集合で表現するマップ、座標は正の値かつmap_size未満であること
*/
template<int Dim = Eigen::Dynamic>
class GridMap : public PathPlanningMap<Eigen::Matrix<double, Dim, 1>>
{
public:
    using GridVector = Eigen::Matrix<int, Dim, 1>;
    using Vector = Eigen::Matrix<double, Dim, 1>;

    template <int N = Vector::RowsAtCompileTime,
              typename std::enable_if<N != Eigen::Dynamic, int>::type = 0>
    GridMap(std::vector<GridVector> obstacles, GridVector map_size, double resolution, double margin = 0.0)
        : PathPlanningMap<Vector>(), map_size_(map_size), resolution_(resolution), margin_(margin)
    {
        for(const auto& o : obstacles)
        {
            obstacles_.insert(o);
        }
        if(0.0 < margin_)
        {
            kdtree_.build(obstacles, this->dimension());
        }
    }

    template <int N = Vector::RowsAtCompileTime,
              typename std::enable_if<N == Eigen::Dynamic, int>::type = 0>
    GridMap(size_t dim, std::vector<GridVector> obstacles, GridVector map_size, double resolution, double margin = 0.0)
        : PathPlanningMap<Vector>(dim), map_size_(map_size), resolution_(resolution), margin_(margin)
    {
        for(const auto& o : obstacles)
        {
            obstacles_.insert(o);
        }
        if(0.0 < margin_)
        {
            kdtree_.build(obstacles, this->dimension());
        }
    }

    bool is_valid(const Vector &point) const override
    {
        GridVector gp = (point/resolution_).template cast<int>();
        if(obstacles_.find(gp) != obstacles_.end())
        {
            return false;
        }
        if(0.0 < margin_)
        {
            Vector min_diff;
            if constexpr( Dim == Eigen::Dynamic )
            {
                min_diff.resize(this->dimension());
            }
            auto near_points = kdtree_.radius_search_points(gp, margin_/resolution_ + 2);
            for(auto& ngp : near_points)
            {
                for(size_t i = 0; i < this->dimension(); i++)
                {
                    min_diff(i) = std::max({ngp(i)*resolution_ - point(i), point(i) - (ngp(i)+1)*resolution_, 0.0});
                }
                if(min_diff.squaredNorm() < margin_*margin_)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool is_valid(const Vector &from, const Vector &to) const override
    {
        GridVector gp1 = (from/resolution_).template cast<int>();
        GridVector gp2 = (to/resolution_).template cast<int>();
        if(not is_valid(from))
        {
            return false;
        }
        if(not is_valid(to))
        {
            return false;
        }

        const size_t split = 30;
        if (0.0 < margin_)
        {
            Eigen::VectorXd diff = to - from;
            for(size_t i = 0; i < split; i++) {
                Vector nextd = (from + i*diff/split);
                if(not is_valid(nextd)) {
                    return false;
                }
            }
        }
        else
        {
            GridVector look = gp1;
            Eigen::VectorXd diff = to - from;
            for(size_t i = 0; i < split; i++) {
                Vector nextd = (from + i*diff/split);
                GridVector next = (nextd/resolution_).template cast<int>();
                if(next == gp2) {
                    break;
                }
                if(next != look) {
                    if(not is_valid(nextd)) {
                        return false;
                    }
                    look = next;
                }
            }
        }

        return true;
    }

    Vector random_sampling() const override
    {
        Vector p;
        if constexpr( Dim == Eigen::Dynamic )
        {
            p.resize(this->dimension());
        }
        for(size_t r = 0; r < 1000; r++)
        {
            for (size_t i = 0; i < this->dimension(); i++) {
                p(i) = rand_engine_.value() * map_size_(i)*resolution_;
            }
            if(is_valid(p))
            {
                return p;
            }
        }
        return p;
    }

    double map_size() const override
    {
        return map_size_.cwiseAbs().maxCoeff() * resolution_;
    }

private:
    struct VectorHash {
        size_t operator()(const GridVector& v) const {
            size_t seed = 0;
            for (int i = 0; i < v.size(); ++i) {
                seed ^= std::hash<int>()(v[i]) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

    struct VectorEqual {
        bool operator()(const GridVector& v1, const GridVector& v2) const {
            return v1 == v2;
        }
    };
    std::unordered_set<GridVector, VectorHash, VectorEqual> obstacles_;
    KDTree<GridVector> kdtree_;
    GridVector map_size_;
    double resolution_;
    double margin_;
    UniformRealRandomEngine rand_engine_ = {0.0, 1.0};
};

using GridMap2d = GridMap<2>;
using GridMap3d = GridMap<3>;
using GridMapXd = GridMap<Eigen::Dynamic>;

}