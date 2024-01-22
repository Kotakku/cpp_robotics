#pragma once

#include <vector>
#include <numeric>
#include <memory>
#include <algorithm>
#include <cmath>

namespace cpp_robotics
{

/**
 * @brief k-d木
 * 
 * @tparam POINT_T データ型
 * @tparam DIM 次元サイズ
 */
template<class POINT_T>
class KDTree
{
public:
    using point_type = POINT_T;

    KDTree() = default;
    KDTree(std::vector<point_type> point, size_t dimention)
    {
        build(point, dimention);
    }

    void clear()
    {
        root_.reset();
    }

    void build(std::vector<point_type> point, size_t dimention)
    {
        dimention_ = dimention;
        points_ = point;
        pidx_.resize(points_.size());
        std::iota(pidx_.begin(), pidx_.end(), 0);
        root_ = build_recursive(pidx_.begin(), pidx_.end(), 0);
    }

    size_t nn_search(const point_type &point) const
    {
        size_t ret = 0;
        double min_dist = std::numeric_limits<double>::max();
        nn_search_recursive(root_, point, ret, min_dist);
        return ret;
    }

    std::vector<size_t> nn_search(const std::vector<point_type> &point) const
    {
        std::vector<size_t> ret(point.size());
        for(size_t i = 0; i < point.size(); i++)
        {
            ret[i] = nn_search(point[i]);
        }
        return ret;
    }

    std::vector<size_t> knn_search(const point_type &point, size_t k) const
    {
        std::vector<std::pair<size_t, double>> pair_ret;
        pair_ret.reserve(k+1);
        knn_search_recursive(root_, point, k, pair_ret);
        std::vector<size_t> ret(pair_ret.size());
        for(size_t i = 0; i < pair_ret.size(); i++)
        {
            ret[i] = pair_ret[i].first;
        }
        return ret;
    }

    std::vector<size_t> radius_search(const point_type &point, double radius) const
    {
        std::vector<size_t> ret;
        radius_search_recursive(root_, point, radius, ret);
        return ret;
    }

    std::vector<point_type> get_points(const std::vector<size_t> &idx) const
    {
        std::vector<point_type> ret(idx.size());

        for(size_t i = 0; i < idx.size(); i++)
        {
            ret[i] = points_[idx[i]];
        }
        
        return ret;
    }

    std::vector<point_type> knn_search_points(const point_type &point, size_t k) const
    {
        auto idx = knn_search(point, k);
        return get_points(idx);
    }

    std::vector<point_type> radius_search_points(const point_type &point, double radius) const
    {
        auto idx = radius_search(point, radius);
        return get_points(idx);
    }

    void debug_node()
    {
        debug_node_recursive(root_, 0);
    }

private:
    struct Node
    {
        // 元の点群でのインデックス
        int idx = -1;

        // 分割軸方向
        int axis = -1;

        // 子ノード
        std::unique_ptr<Node> child[2] = {nullptr, nullptr};
    };
    
    std::unique_ptr<Node> build_recursive(std::vector<size_t>::iterator start, std::vector<size_t>::iterator end, size_t depth)
    {
        if(start == end)
            return nullptr;

        const size_t axis = depth % dimention_;
        const size_t mid = (std::distance(start, end)-1) / 2;

        std::nth_element(start, start + mid, end, [&](size_t a, size_t b){
            return points_[a][axis] < points_[b][axis];
        });

        std::unique_ptr<Node> node_ = std::make_unique<Node>();
        node_->idx = *(start + mid);
        node_->axis = axis;

        node_->child[0] = build_recursive(start, start + mid, depth+1);
        node_->child[1] = build_recursive(start+mid+1, end, depth+1);

        return node_;
    }

    void nn_search_recursive(const std::unique_ptr<Node> &node, const point_type &point, size_t &guess, double &min_dist) const
    {
        if(node == nullptr)
            return;
        
        auto p = points_[node->idx];

        const double dist = distance(point, p);
        if(dist < min_dist)
        {
            min_dist = dist;
            guess = node->idx;
        }

        const int axis = node->axis;
        const int dir = point[axis] < p[axis] ? 0 : 1;
        nn_search_recursive(node->child[dir], point, guess, min_dist);

        if(dist < min_dist)
            nn_search_recursive(node->child[dir], point, guess, min_dist);
    }

    void knn_search_recursive(const std::unique_ptr<Node> &node, const point_type &point, size_t k, std::vector<std::pair<size_t, double>> &result) const
    {
        if(node == nullptr)
            return;
        
        auto p = points_[node->idx];

        const double dist = distance(point, p);
        auto val = std::make_pair(node->idx, dist);

        // distで昇順ソートして常にk個以下を保持する
        auto it = std::find_if(std::begin(result), std::end(result),
            [&](const auto& elem){ return val.second < elem.second; });
        result.insert(it, val);
        if (result.size() > k)
            result.resize(k);

        const int axis = node->axis;
        const int dir = point[axis] < p[axis] ? 0 : 1;
        knn_search_recursive(node->child[dir], point, k, result);

        const double diff = fabs(point[axis] - p[axis]);
        if (result.size() < k || diff < result.back().second)
            knn_search_recursive(node->child[!dir], point, k, result);
    }

    void radius_search_recursive(const std::unique_ptr<Node> &node, const point_type &point, double radius, std::vector<size_t> &result) const
    {
        if(node == nullptr)
            return;
        
        auto p = points_[node->idx];
        double sq_dist = squared_distance(p, point);
        if(sq_dist < radius*radius)
        {
            result.push_back(node->idx);
        }

        const int axis = node->axis;
        const int dir = point[axis] < p[axis] ? 0 : 1;
        radius_search_recursive(node->child[dir], point, radius, result);

        const double diff = fabs(point[axis] - p[axis]);
        if (diff < radius)
            radius_search_recursive(node->child[!dir], point, radius, result);
    }

    void debug_node_recursive(const std::unique_ptr<Node> &node, size_t depth)
    {
        if(node == nullptr)
            return;
        
        for(size_t i = 0; i < depth; i++)
            printf("  ");
        printf("%d\n", node->idx);

        debug_node_recursive(node->child[0], depth+1);
        debug_node_recursive(node->child[1], depth+1);
    }

    double squared_distance(const point_type &a, const point_type &b) const
    {
        double len_sq = 0;
        for(size_t i = 0; i < dimention_; i++)
        {
            len_sq += std::pow(a[i]-b[i], 2);
        }
        return len_sq;
    }

    double distance(const point_type &a, const point_type &b) const
    {
        return std::sqrt(squared_distance(a, b));
    }

    size_t dimention_;
    std::vector<point_type> points_;
    std::vector<size_t> pidx_;
    std::unique_ptr<Node> root_ = nullptr;

};

}