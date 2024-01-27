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
        {1, -1}
    };

    CatumullRomSplinePath2d cutmull_spline(waypoints);
    CubicSplinePath2d cubic_spline(waypoints);

    std::vector<double> x, y;
    {
        const double length = cutmull_spline.length();
        for (double i = 0; i < length; i += 0.05)
        {
            Eigen::Vector2d pos = cutmull_spline.position(i);
            x.push_back(pos[0]);
            y.push_back(pos[1]);
        }
        plt::named_plot("CatmullRomCurve", x, y);
    }

    x.clear();
    y.clear();
    {
        const double length = cubic_spline.length();
        for (double i = 0; i < length; i += 0.05)
        {
            Eigen::Vector2d pos = cubic_spline.position(i);
            x.push_back(pos[0]);
            y.push_back(pos[1]);
        }
        plt::named_plot("CubicSplineCurve", x, y);
    }

    x.clear();
    y.clear();
    // waypoints
    for (const auto& p : waypoints)
    {
        x.push_back(p[0]);
        y.push_back(p[1]);
    }
    plt::named_plot("Waypoints", x, y, "o");
    plt::legend();
    plt::show();

    return 0;
}