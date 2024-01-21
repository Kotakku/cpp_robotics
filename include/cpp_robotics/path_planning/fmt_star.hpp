#pragma once

#include <vector>
#include <queue>
#include <set>
#include <type_traits>
#include "path_planning_utils.hpp"

namespace cpp_robotics
{

struct FMTStarConfig
{
    size_t sampling_num = 1000;
    double radius_near_multiplier = 1.1;
    // bool use_k_nearest = true;
};

template<class EigenVector>
class FMTStar
{
public:
    using Vector = EigenVector;
    using Node = PathPlanningNode<Vector>;
    using Map = PathPlanningMap<Vector>;

    template <int N = Vector::RowsAtCompileTime,
              typename std::enable_if<N != Eigen::Dynamic, int>::type = 0>
    FMTStar(const Map &map, FMTStarConfig config = FMTStarConfig()):
        dimension_(Vector::RowsAtCompileTime), map_(map), config_(config)  {}

    template <int N = Vector::RowsAtCompileTime,
              typename std::enable_if<N == Eigen::Dynamic, int>::type = 0>
    FMTStar(int dimension, const Map &map, FMTStarConfig config = FMTStarConfig())
        : dimension_(dimension), map_(map), config_(config) {}

    std::vector<Vector> solve(const Vector &start, const Vector &goal)
    {
        radius_near_ = map_.map_size() * config_.radius_near_multiplier * std::pow(std::log(config_.sampling_num) / config_.sampling_num, 1.0 / dimension_);
        squared_radius_near_ = radius_near_ * radius_near_;

        nodes_.reserve(config_.sampling_num);
        for (size_t i = 1; i < config_.sampling_num; i++) // sampling sampling_num-1 points
        {
            nodes_.push_back(Node(map_.random_sampling()));
        }
        nodes_.push_back(Node(goal));

        std::priority_queue<Node*, std::vector<Node*>, CompareNode> V_open;
        std::set<Node*> V_closed;
        std::set<Node*> V_unvisited;
        for (auto& node : nodes_) {
            V_unvisited.insert(&node);
        }

        Node start_node(start);
        start_node.cost = 0;
        V_open.push(&start_node);

        while (!V_open.empty()) 
        {
            Node* z = V_open.top();
            V_open.pop();
            V_closed.insert(z);

            if (z->point == goal)
            {
                std::vector<Vector> path;
                while (z != nullptr)
                {
                    path.push_back(z->point);
                    z = z->parent;
                }
                std::reverse(path.begin(), path.end());
                return path;
            }

            auto x_near = near(V_unvisited, *z);
            for (auto* x : x_near) {
                auto y_near = near(V_closed, *x);
                Node* y_min = nullptr;
                double min_cost = INFINITY;
                for (auto* y : y_near) {
                    double c = y->cost + distance(y->point, x->point);
                    if (c < min_cost && collision_free(*y, *x)) {
                        min_cost = c;
                        y_min = y;
                    }
                }
                if (y_min) {
                    x->parent = y_min;
                    x->cost = min_cost;
                    V_open.push(x);
                    V_unvisited.erase(x);
                }
            }
        }

        return {};
    }

    std::vector<Node> get_nodes() const { return nodes_; }

    size_t dimension() const { return dimension_; }

private:
    struct CompareNode {
        bool operator()(const Node* lhs, const Node* rhs) const {
            return lhs->cost > rhs->cost;
        }
    };
    double distance(const Vector& a, const Vector& b) {
        return (a - b).norm();
    }

    bool collision_free(const Node& node1, const Node& node2) {
        return map_.is_valid(node1.point, node2.point);
    }

    std::vector<Node*> near(const std::set<Node*>& nodes, const Node& node) {
        std::vector<Node*> neighbors;
        for (auto* other_node : nodes) {
            if ((node.point-other_node->point).squaredNorm() < squared_radius_near_) {
                neighbors.push_back(other_node);
            }
        }
        return neighbors;
    }

    const size_t dimension_; // dimension
    const Map &map_;
    const FMTStarConfig config_;
    double radius_near_;
    double squared_radius_near_;
    std::vector<Node> nodes_;
};

template<class EigenVector, class Map>
static std::vector<EigenVector> fmt_star(const Map &map, const EigenVector &x_init, const EigenVector &x_goal, const FMTStarConfig &config = FMTStarConfig())
{
    if constexpr (EigenVector::RowsAtCompileTime == Eigen::Dynamic) {
        FMTStar<EigenVector> fmt_star(x_init.size(), map, config);
        return fmt_star.solve(x_init, x_goal);
    }
    else
    {
        FMTStar<EigenVector> fmt_star(map, config);
        return fmt_star.solve(x_init, x_goal);
    }
}

} // namespace cpp_robotics