#include <cpp_robotics/path_planning/fmt_star.hpp>
#include <cpp_robotics/path_planning/dwa.hpp>
#include <cpp_robotics/controller/ocp_dynamics.hpp>
#include <cpp_robotics/path_planning/line_path.hpp>
#include <cpp_robotics/matplotlibcpp.hpp>
#include <iostream>

class DiffBot : public cpp_robotics::OCPDiscreteNonlinearDynamics
{
public:
    DiffBot(double dt):
        OCPDiscreteNonlinearDynamics(3,2), dt_(dt) {}

    Eigen::VectorXd eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) override
    {
        Eigen::VectorXd x_next(3);
        double v = u[0];
        double omega = u[1];
        x_next << x[0] + v * cos(x[2]) * dt_,
                  x[1] + v * sin(x[2]) * dt_,
                  x[2] + omega * dt_;
        return x_next;
    }
private:
    double dt_;
};

void draw_robot(Eigen::Vector3d state, double width = 0.4, double height = 0.4, double heading = 0.25)
{
    namespace plt = matplotlibcpp;
    double x = state[0];
    double y = state[1];
    double theta = state[2];
    double x1 = x + cos(theta) * (-width / 2) - sin(theta) * (-height / 2);
    double y1 = y + sin(theta) * (-width / 2) + cos(theta) * (-height / 2);
    double x2 = x + cos(theta) * (width / 2) - sin(theta) * (-height / 2);
    double y2 = y + sin(theta) * (width / 2) + cos(theta) * (-height / 2);
    double x3 = x + cos(theta) * (width / 2) - sin(theta) * (height / 2);
    double y3 = y + sin(theta) * (width / 2) + cos(theta) * (height / 2);
    double x4 = x + cos(theta) * (-width / 2) - sin(theta) * (height / 2);
    double y4 = y + sin(theta) * (-width / 2) + cos(theta) * (height / 2);
    std::vector<double> x_data = {x1, x2, x3, x4, x1};
    std::vector<double> y_data = {y1, y2, y3, y4, y1};
    plt::plot(x_data, y_data, "k-");

    std::vector<double> dir_x_data = {x, x + cos(theta) * heading};
    std::vector<double> dir_y_data = {y, y + sin(theta) * heading};
    plt::plot(dir_x_data, dir_y_data, "r-");
}

int main() {
    using namespace cpp_robotics;
    namespace plt = matplotlibcpp;

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
    double margin = 0.2;
    GridMap2d global_planning_map(obstalces, Eigen::Vector2i(10, 10), obstacle_size, margin);

    Eigen::Vector2d x_init(0.25, 0.25);
    Eigen::Vector2d x_goal(4.75, 4.75);
    FMTStarConfig fmt_star_config;
    fmt_star_config.sampling_num = 2000;
    auto waypoint_list = fmt_star<Eigen::Vector2d>(global_planning_map, x_init, x_goal, fmt_star_config);

    if(waypoint_list.size() == 0)
    {
        std::cout << "No path found" << std::endl;
        return 0;
    }
    std::vector<double> waypoint_list_x, waypoint_list_y;
    for(const auto& p : waypoint_list)
    {
        waypoint_list_x.push_back(p(0));
        waypoint_list_y.push_back(p(1));
    }

    LinePath path(waypoint_list);

    GridMap2d local_planning_map(obstalces, Eigen::Vector2i(10, 10), obstacle_size);
    DWAConfig dwa_config;
    dwa_config.robot_radius = 0.5;
    dwa_config.max_velocity = 3.0;
    dwa_config.max_angular_velocity = 3.0;
    dwa_config.windows_size = 100;
    dwa_config.dt = 0.1;
    dwa_config.predict_time = 0.5;
    dwa_config.heading_angle_weight = 3.0;
    dwa_config.heading_velocity_weight = 0.5;
    dwa_config.to_goal_weight = 3.0;
    DWA dwa(local_planning_map, dwa_config);

    const double sim_dt = 0.1;
    DiffBot robot(sim_dt);
    Eigen::Vector3d x(x_init[0], x_init[1], 0.0);
    double folowing_point = 0;
    while(1)
    {
        plt::clf();

        // ゴールに到達したら終了
        if((x_goal - x.head<2>()).norm() < 0.05)
            break;

        // DWAの目標地点を計算
        double forward_distance = 0.4;
        Eigen::Vector2d pos(x[0], x[1]);
        folowing_point = path.nearest_position(pos, folowing_point, 0.5);
        Eigen::Vector2d dwa_goal = path.position(folowing_point + forward_distance);

        // DWAで制御入力を計算
        Eigen::Vector2d u = dwa.control(x, dwa_goal);

        // シミュレーション
        x = robot.eval(x, u);

        plt::plot(waypoint_list_x, waypoint_list_y, "b");
        plt::plot({x_init(0)}, {x_init(1)}, "go");
        plt::plot({x_goal(0)}, {x_goal(1)}, "ro");
        plt::plot({dwa_goal(0)}, {dwa_goal(1)}, "bo");
        draw_robot(x);

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
        plt::pause(0.05);
    }   

    std::cout << "navigation finished" << std::endl;
    std::cout << "press enter to exit" << std::endl;
    getchar();

    return 0;
}