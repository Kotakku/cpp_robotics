#include <cpp_robotics/arm_kinematics/serial_link_kinematics.hpp>
#include <cpp_robotics/path_planning/spline_path.hpp>
#include <matplotlibcpp17/pyplot.h>
#include <matplotlibcpp17/mplot3d.h>

int main()
{
    using namespace cpp_robotics;

    SerialLinkKinematics arm = yaw_pitch_pitch_3dof_kinematics(0.1, 0.5, 0.5);

    std::vector<Eigen::Vector3d> qwaypoint =
    {
        {0.0*M_PI, -M_PI/6, M_PI/2},
        {0.2*M_PI, -M_PI/3, M_PI/3},
        {0.8*M_PI, -M_PI/3, M_PI/3},
        {1.0*M_PI, -M_PI/6, M_PI/2},
    };
    CubicSplinePath3d qspline(qwaypoint);

    py::scoped_interpreter guard{};
    auto plt = matplotlibcpp17::pyplot::import();
    matplotlibcpp17::mplot3d::import();
    auto fig = plt.figure();
    auto ax = fig.add_subplot(Args(), Kwargs("projection"_a = "3d"));
    for(size_t i = 0; i <= 110; i++)
    {
        Eigen::VectorXd q = qspline.position(qspline.length() * i/100.0);
        std::vector<Eigen::Vector3d> pos_list = arm.solve_each_fk(q);

        std::vector<double> x = {0};
        std::vector<double> y = {0};
        std::vector<double> z = {0};
        for(auto &pos: pos_list)
        {
            x.push_back(pos[0]);
            y.push_back(pos[1]);
            z.push_back(pos[2]);
        }

        ax.plot(Args(x, y, z), Kwargs("marker"_a = "o"));
        ax.set_xlim(Args(-1.0, 1.0));
        ax.set_ylim(Args(-1.0, 1.0));
        ax.set_zlim(Args(-1.0, 1.0));
        plt.pause(Args(0.03));
        plt.cla();
    }

    return 0;
}