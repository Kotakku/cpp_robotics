#include <cpp_robotics/matplotlibcpp.hpp>
#include <cpp_robotics/path_planning/fmt_star.hpp>
#include <cpp_robotics/path_planning/geometry_map.hpp>

#include <iostream>

int main() {
    using namespace cpp_robotics;

    std::vector<ObstacleShapeType> obstacles = {
        Rect{{2, 4}, {2, 2}},
        Circle{{5, 1}, 1.25},
        Circle{{3, 3}, 1.25},
        Circle{{1, 5}, 1.25},
    };

    GeometryMap map(obstacles, Rect({3, 3}, {6, 6}));

    Eigen::Vector2d x_init(0.25, 0.25);
    Eigen::Vector2d x_goal(5.75, 5.75);
    FMTStarConfig config;
    config.sampling_num = 1000;
    FMTStar<Eigen::Vector2d> fmt_star(map, config);
    auto path = fmt_star.solve(x_init, x_goal);

    namespace plt = matplotlibcpp;

    for (auto &o : obstacles) {
        if (std::holds_alternative<Rect>(o)) {
            auto rect = std::get<Rect>(o);
            auto verts = rect.vertex();
            plt::fill(std::vector<double>{verts[0].x, verts[1].x, verts[2].x, verts[3].x, verts[0].x},
                      std::vector<double>{verts[0].y, verts[1].y, verts[2].y, verts[3].y, verts[0].y}, std::map<std::string, std::string>{{"c", "k"}});
        } else if (std::holds_alternative<Circle>(o)) {
            auto circle = std::get<Circle>(o);
            plt::draw_circle(circle.center.x, circle.center.y, circle.r, true, "k");
        }
    }

    // // result
    if (path.size() == 0) {
        std::cout << "No path found" << std::endl;
    } else {
        std::vector<double> x, y;
        for (const auto &p : path) {
            x.push_back(p(0));
            y.push_back(p(1));
        }
        plt::plot(x, y, "b");
        plt::plot({x_init(0)}, {x_init(1)}, "go");
        plt::plot({x_goal(0)}, {x_goal(1)}, "ro");
    }

    plt::xlim(0, 6);
    plt::ylim(0, 6);
    plt::set_aspect_equal();
    plt::show();

    return 0;
}