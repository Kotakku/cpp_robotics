#pragma once

#include <vector>
#include <list>
#include <Eigen/Dense>
#include "grid_path_planning_utils.hpp"

namespace cpp_robotics
{

/**
 * @brief Wave propagation法
 * 
 * @param start 
 * @param end 
 * @param map 
 * @return std::vector<Eigen::Vector2i> 
 */
std::vector<Eigen::Vector2i> wave_propagation(const Eigen::Vector2i& start, const Eigen::Vector2i& end, const Eigen::MatrixXi& map)
{
    using namespace grid_path_planning_utils;

    if(not contain_in_map(map, start) || not contain_in_map(map, end))
        return {start};

    if(start == end)
        return {start};
    if(!is_correct_step(start, map) || !is_correct_step(end, map))
        return {}; // not exist path

    const static std::array<Eigen::Vector2i,8> nb = {Eigen::Vector2i{1,0}, {0,1}, {-1,0}, {0,-1},
                            {1,1}, {-1,1}, {-1,-1}, {1,-1}};

    std::vector<std::vector<int>> costs_mat;
    costs_mat.resize(map.rows());
    for(auto &r : costs_mat)
    {
        r.resize(map.cols());
    }

    auto costs = [&](int x, int y) -> int&
    {
        return costs_mat.at(y).at(x);
    };

    std::list<GridNode> nodes = {}, new_nodes = {};

    GridNode enode;
    enode.pos = end;
    enode.cost = 1;
    nodes.push_back(enode);
    costs(end(0), end(1)) = enode.cost;

    // propagate a wave
    auto exist_wp = [&costs](const Eigen::Vector2i& p) { return costs(p(0), p(1)) != 0; };
    while(not nodes.empty())
    {
        
        for(auto &n : nodes)
        {
            for(size_t i = 0; i < 4; i++)
            {
                auto pos = n.pos + nb[i];
                if(is_correct_step(pos, map)) // コストが0のとき
                {
                    if(!exist_wp(pos))
                    {
                        int new_cost = n.cost + 1;
                        costs(pos(0), pos(1)) = new_cost;
                        GridNode nnode;
                        nnode.pos = pos;
                        nnode.cost = new_cost;
                        new_nodes.push_back(nnode);
                    }
                }
            }
        }
        nodes.clear();
		nodes.insert(nodes.begin(), new_nodes.begin(), new_nodes.end());
        new_nodes.clear();            
    }

    // create path
    std::vector<Eigen::Vector2i> path;
    Eigen::Vector2i look = start;
    path.push_back(start);
    std::array<int, 8> nb_costs;

    // 壁の部分はコスト0&nb_costsの書き換えを行わないため壁側に進むのを防ぐ
    for(auto &c : nb_costs)
        c = costs(look(0), look(1));

    while(look != end)
    {
        size_t correct_step_count = 0;
        for(size_t i = 0; i < 8; i++)
        {
            auto neighbor = look + nb[i];
            if(is_correct_step(neighbor, map))
            {
                int cost = costs(neighbor(0), neighbor(1));
                if(cost != 0)
                {
                    correct_step_count++;
                    nb_costs[i] = cost;
                }
            }
        }
        if(correct_step_count == 0)
        {
            // no exist path
            // std::cout << "------------------- no exist path" << std::endl;
            return {};
        }

        auto min_it = std::min_element(nb_costs.begin(), nb_costs.end());
        look += nb[std::distance(nb_costs.begin(), min_it)];
        // std::cout << "------------------- push" << look(0) << ", " << look(1) << std::endl;
        path.push_back(look);
    }

    return path;
}

}