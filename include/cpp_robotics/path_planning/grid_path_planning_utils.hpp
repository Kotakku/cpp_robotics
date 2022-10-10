#pragma once

#include <vector>
#include <list>
#include <Eigen/Dense>

/**
 * @brief グリッドパスプランニング用関数・クラス郡
 * 
 */
namespace cpp_robotics::grid_path_planning_utils
{

struct GridNode
{
    GridNode():
        cost(0), hcost(0)
    {
        pos.setZero();
        parent.setZero();
    }
    bool operator == (const GridNode& o ) { return pos == o.pos; }
    bool operator == (const Eigen::Vector2i& o ) { return pos == o; }
    bool operator < (const GridNode& o ) { return hcost + cost < o.hcost + o.cost; }
    Eigen::Vector2i pos, parent;
    int cost, hcost;
    int score() { return cost + hcost; }
};

static bool contain_in_map(const Eigen::MatrixXi& map, const Eigen::Vector2i& p)
{
    if(0 <= p(0) && p(0) < map.rows() && 0 <= p(1) && p(1) < map.cols())
        return true;
    return false;
}

static int dist(const Eigen::Vector2i& pos, const Eigen::Vector2i& end)
{
    const Eigen::Vector2i d = end - pos;
    return std::min(std::abs(d(0)) , std::abs(d(0))); // 8方向移動を想定 https://qiita.com/2dgames_jp/items/f29e915357c1decbc4b7#%E6%8E%A2%E7%B4%A2%E3%82%92%E9%96%8B%E5%A7%8B
}

template<typename T>
bool in_range_open(T x, T min, T max) 
{
    return ((min < x && x < max) ? true : false);
}

bool is_valid(const Eigen::Vector2i& pos, size_t row, size_t col)
{
    if(in_range_open<int>(pos(0), -1, row) && in_range_open<int>(pos(1), -1, col))
        return true;
    return false;
}

bool is_wall(const Eigen::Vector2i& pos, size_t row, size_t col)
{
    if(in_range_open<int>(pos(0), -1, row) && in_range_open<int>(pos(1), -1, col))
        return true;
    return false;
}

bool is_correct_step(const Eigen::Vector2i& pos, const Eigen::MatrixXi& map)
{
    if(is_valid(pos, map.rows(), map.cols()))
    {
        if(not map(pos(0), pos(1)))
            return true;
    }
    return false;
}

bool exist(std::list<GridNode> &open, std::list<GridNode> &closed, const Eigen::Vector2i& p, int cost) {
    std::list<GridNode>::iterator i;
    i = std::find( closed.begin(), closed.end(), p );
    if( i != closed.end() ) { // 既にclosed内に存在する
        if( ( *i ).cost + ( *i ).hcost < cost ) return true; // 存在するのでtrueを返す
        else { closed.erase( i ); return false; } // 存在するが新しく見つかったほうがコストが小さいので書き換えるために消して、falseを返す
    }
    i = std::find( open.begin(), open.end(), p );
    if( i != open.end() ) { // open内に存在する
        if( ( *i ).cost + ( *i ).hcost < cost ) return true; // 上に同じ
        else { open.erase( i ); return false; }
    }
    return false; // 存在しない
}

}