#include <cpp_robotics/path_planning/path_planning_utils.hpp>
#include <cpp_robotics/path_planning/dwa.hpp>
#include <cpp_robotics/matplotlibcpp.hpp>
#include <cpp_robotics/controller/ocp_dynamics.hpp>
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

void draw_robot(Eigen::Vector3d state, double width = 1.0, double height = 1.0, double heading = 0.5)
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

    plt::plot(x_data, y_data, "b-");

    std::vector<double> dir_x_data = {x, x + cos(theta) * heading};
    std::vector<double> dir_y_data = {y, y + sin(theta) * heading};
    plt::plot(dir_x_data, dir_y_data, "r-");
}

int main()
{
    using namespace cpp_robotics;
    DWAConfig config;
    config.robot_radius = 0.5;
    config.max_velocity = 5.0;
    config.max_angular_velocity = 1.5;
    config.windows_size = 100;
    config.dt = 0.1;
    config.predict_time = 0.5;
    config.heading_angle_weight = 1.0;
    config.heading_velocity_weight = 0.1;
    config.to_goal_weight = 5.0;

    GridMap2d map({}, Eigen::Vector2i(10, 10), 1.0);

    DWA dwa(map, config);

    Eigen::Vector3d x(1, 1, 0);
    Eigen::Vector2d goal(5, 5);
    DiffBot robot(0.01);

    namespace plt = matplotlibcpp;
    for(size_t i = 0; i < 1000; i++)
    {
        plt::clf();

        Eigen::Vector2d u = dwa.control(x, goal);
        x = robot.eval(x, u);

        draw_robot(x);
        plt::plot({goal[0]}, {goal[1]}, "rx");

        plt::xlim(0, 6);
        plt::ylim(0, 6);
        plt::set_aspect_equal();
        plt::pause(0.01);
    }
}