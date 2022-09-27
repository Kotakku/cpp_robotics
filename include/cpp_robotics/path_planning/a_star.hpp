#pragma once

#include <vector>
#include <list>
#include <Eigen/Dense>
#include "grid_path_planning_utils.hpp"

namespace cpp_robotics
{

/**
 * @brief A*法
 * 
 * @param start 
 * @param end 
 * @param map 
 * @return std::vector<Eigen::Vector2i> 
 */
static std::vector<Eigen::Vector2i> a_star(const Eigen::Vector2i& start, const Eigen::Vector2i& end, const Eigen::MatrixXi& map)
{
    using namespace grid_path_planning_utils;

    if(not contain_in_map(map, start) || not contain_in_map(map, end))
        return {start};

    const static std::array<Eigen::Vector2i,8> nb = {Eigen::Vector2i{1,0}, {0,1}, {-1,0}, {0,-1},
                            {1,1}, {-1,1}, {-1,-1}, {1,-1}};
        
    std::list<GridNode> open;
    std::list<GridNode> closed;
    GridNode sn;
    sn.pos = start;
    sn.parent = start;
    sn.cost = 0;
    sn.hcost = dist(start,end);

    // first step open
    open.push_back(sn);
    while(not open.empty())
    {
        // 基準ノードを選ぶ
        // Todo: 最小スコアが複数あれば複数開く?
        // ゴールに到達する直前に最小スコアが複数あってもそんなに問題ない気もする
        auto min_itr = open.begin();
        int min_score = open.front().score();
        for(auto i = open.begin(); i != open.end(); i++)
        {
            if(min_score > (*i).score())
            {
                min_itr = i;
                min_score = (*i).score();
            }
        }

        // スコア最小ノードを基準にする
        GridNode n = *min_itr;
        open.erase(min_itr);

        // 基準ノードをクローズ
        closed.push_back(n);

        // 基準ノードから8方向オープン
        for(size_t i = 0; i < 8; i++)
        {
            Eigen::Vector2i np = n.pos + nb[i];
            if(np == end)
            {
                std::vector<Eigen::Vector2i> path;
                path.push_back(np);
                // closedから逆順にパスを取得
                Eigen::Vector2i parent = closed.back().pos;
                for(auto it = closed.rbegin(); it != closed.rend(); it++)
                {
                    if((*it).pos == parent)
                    {
                        path.insert(path.begin(), (*it).pos);
                        parent = (*it).parent;
                    }
                }
                return path;
            }
            if(is_correct_step(np, map))
            {
                ///////////////////// functionで汎用化できそう
                GridNode nn;
                nn.pos = np;
                nn.parent = n.pos;
                nn.cost = n.cost + 3; // ８方向どの移動でもコストは同等とする
                Eigen::Vector2i d1 = n.pos-n.parent, d2 = nn.pos-nn.parent;
                if(d1(0) != d2(0))
                    nn.cost++; // 屈折する場合はコストを増やす
                if(d1(1) != d2(1))
                    nn.cost++; // 屈折する場合はコストを増やす
                //////////////////////
                nn.hcost = dist(np, end);
                if(not exist(open, closed, nn.pos, nn.cost + nn.hcost))
                {
                    open.push_front(nn);
                } 
            }
        }
    }

    return {};
}

}