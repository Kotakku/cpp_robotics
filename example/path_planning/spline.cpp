#include <cpp_robotics/path_planning/spline_path.hpp>
#include <cpp_robotics/matplotlibcpp.hpp>
#include <Eigen/Dense>

int main()
{
    using namespace cpp_robotics;
    namespace plt = matplotlibcpp;

    std::vector<Eigen::Vector2d> waypoints =
    {
        {0, 0},
        {1, 2},
        {2, 3},
        {3, 1},
        {4, 1},
        {5, 0},
        {4, -1},
        {2, -2},
        {1, -1},
        {0, 0},
    };

    CatumullRomSplinePath<Eigen::Vector2d> spline(waypoints, true);

    std::vector<double> x, y;
    const double length = spline.length();
    for (double i = 0; i < length; i += 0.05)
    {
        Eigen::Vector2d pos = spline.position(i);
        x.push_back(pos[0]);
        y.push_back(pos[1]);
    }
    plt::plot(x, y);

    x.clear();
    y.clear();
    // waypoints
    for (const auto& p : waypoints)
    {
        x.push_back(p[0]);
        y.push_back(p[1]);
    }
    plt::plot(x, y, "o");
    plt::show();

    return 0;
}