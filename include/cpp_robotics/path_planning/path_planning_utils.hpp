#pragma once

#include <Eigen/Dense>
#include "cpp_robotics/utility/random.hpp"

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

    virtual bool is_valid(const Vector &p1, const Vector &p2) const = 0;

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
    GridMap(std::vector<GridVector> obstacles, GridVector map_size, double resolution)
        : PathPlanningMap<Vector>(), obstacles_(obstacles), map_size_(map_size), resolution_(resolution) 
    {
    }

    template <int N = Vector::RowsAtCompileTime,
              typename std::enable_if<N == Eigen::Dynamic, int>::type = 0>
    GridMap(size_t dim, std::vector<GridVector> obstacles, GridVector map_size, double resolution)
        : PathPlanningMap<Vector>(dim), obstacles_(obstacles), map_size_(map_size), resolution_(resolution) 
    {
    }

    bool is_valid(const Vector &p1, const Vector &p2) const override
    {
        GridVector gp1 = (p1/resolution_).template cast<int>();
        GridVector gp2 = (p2/resolution_).template cast<int>();
        if(auto it = std::find(obstacles_.begin(), obstacles_.end(), gp1); it != obstacles_.end())
        {
            return false;
        }
        if(auto it = std::find(obstacles_.begin(), obstacles_.end(), gp2); it != obstacles_.end())
        {
            return false;
        }

        GridVector look = gp1;
        Eigen::VectorXd look_start = (p1/resolution_);
        Eigen::VectorXd diff = (p2/resolution_) - look_start;
        for(size_t i = 0; i < 100; i++) {
            GridVector next = (look_start + i*diff/100.0).template cast<int>();
            if(next == gp2) {
                break;
            }
            if(next != look) {
                if(auto it = std::find(obstacles_.begin(), obstacles_.end(), next); it != obstacles_.end()) {
                    return false;
                }
                look = next;
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
        for (size_t i = 0; i < this->dimension(); i++) {
            p(i) = rand_engine_.value() * map_size_(i)*resolution_;
        }
        return p;
    }

    double map_size() const override
    {
        return map_size_.cwiseAbs().maxCoeff() * resolution_;
    }

private:
    std::vector<GridVector> obstacles_;
    GridVector map_size_;
    double resolution_;
    UniformRealRandomEngine rand_engine_ = {0.0, 1.0};
};

using GridMap2d = GridMap<2>;
using GridMap3d = GridMap<3>;
using GridMapXd = GridMap<Eigen::Dynamic>;

}