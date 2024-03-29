#include <iostream>
#include <cpp_robotics/algorithm/kdtree.hpp>
#include <cpp_robotics/vector/vector2.hpp>
#include <Eigen/Dense>

int main()
{
    namespace cr = cpp_robotics;

    // for cpp_rototics::VectorXx
    std::cout << "for cpp_rototics::VectorXx" << std::endl;
    {
        cr::KDTree<cr::Vector2d> kdtree;

        std::vector<cr::Vector2d> points = {
            {0,1},
            {2,3},
            {3,4},
            {4,5},
            {5,6},
        };

        kdtree.build(points, 2);
        // kdtree.debug_node();

        auto ret = kdtree.knn_search_points(cr::Vector2d(0,1), 1);

        printf("size %ld\n", ret.size());
        std::for_each(ret.begin(), ret.end(), [&](cr::Vector2d p)
        {
            printf("%6.2f, %6.2f\n", p.x, p.y);
        });
    }

    // for Eigen::VectorXx
    std::cout << "for Eigen::VectorXx" << std::endl;
    {
        cr::KDTree<Eigen::Vector2d> kdtree;

        std::vector<Eigen::Vector2d> points = {
            {0,1},
            {2,3},
            {3,4},
            {4,5},
            {5,6},
        };

        kdtree.build(points, 2);
        // kdtree.debug_node();

        auto ret = kdtree.knn_search_points(Eigen::Vector2d(0,1), 1);

        printf("size %ld\n", ret.size());
        std::for_each(ret.begin(), ret.end(), [&](Eigen::Vector2d p)
        {
            printf("%6.2f, %6.2f\n", p[0], p[1]);
        });
    }

}