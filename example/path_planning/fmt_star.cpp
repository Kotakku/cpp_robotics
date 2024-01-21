#include <cpp_robotics/path_planning/fmt_star.hpp>
#include <iostream>
#include <cpp_robotics/matplotlibcpp.hpp>

int main() {
    using namespace cpp_robotics;

    std::vector<Eigen::Vector2i> obstalces =
    {
        {1, 8},
        {1, 7},
        {2, 7},
        {3, 7},
        {4, 7},
        {5, 7},
        {6, 7},
        {7, 7},
        {8, 7},
        {9, 7},
        {1, 6},
        {3, 6},
        {3, 5},
        {5, 5},
        {6, 5},
        {7, 5},
        {8, 5},
        {1, 4},
        {3, 4},
        {8, 4},
        {3, 3},
        {4, 3},
        {5, 3},
        {6, 3},
        {8, 3},
        {8, 2},
        {0, 1},
        {1, 1},
        {2, 1},
        {3, 1},
        {4, 1},
        {5, 1},
        {6, 1},
        {7, 1},
        {8, 1},
    };
    double obstacle_size = 0.5;
    GridMap2d map(obstalces, Eigen::Vector2i(10, 10), obstacle_size);

    Eigen::Vector2d x_init(0.25, 0.25);
    Eigen::Vector2d x_goal(4.75, 4.75);
    auto path = fmt_star<Eigen::Vector2d>(map, x_init, x_goal);

    namespace plt = matplotlibcpp;
    // result
    if(path.size() == 0)
    {
        std::cout << "No path found" << std::endl;
    }
    else
    {
        std::vector<double> x, y;
        for(const auto& p : path)
        {
            x.push_back(p(0));
            y.push_back(p(1));
        }
        plt::plot(x, y, "b");
        plt::plot({x_init(0)}, {x_init(1)}, "go");
        plt::plot({x_goal(0)}, {x_goal(1)}, "ro");
    }

    // obstacles
    for(auto o : obstalces)
    {
        // plot tile
        std::vector<double> x, y;
        x.push_back(obstacle_size*o(0));
        x.push_back(obstacle_size*o(0)+obstacle_size);
        x.push_back(obstacle_size*o(0)+obstacle_size);
        x.push_back(obstacle_size*o(0));
        x.push_back(obstacle_size*o(0));
        y.push_back(obstacle_size*o(1));
        y.push_back(obstacle_size*o(1));
        y.push_back(obstacle_size*o(1)+obstacle_size);
        y.push_back(obstacle_size*o(1)+obstacle_size);
        y.push_back(obstacle_size*o(1));
        plt::fill(x, y, std::map<std::string, std::string>{{"c", "k"}});
    }

    plt::xlim(0, 5);
    plt::ylim(0, 5);
    plt::set_aspect_equal();
    plt::show();

    return 0;
}