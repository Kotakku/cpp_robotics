#define CR_USE_MATPLOTLIB
#include <iostream>

#include <cpp_robotics/core.hpp>
#include <cpp_robotics/controller/linear_mpc.hpp>
#include <cpp_robotics/system/state_space_system.hpp>
#include <limits>


int main()
{
    namespace cr = cpp_robotics;
    namespace plt = matplotlibcpp;
    //////////////////// System ////////////////////
    const double dt = 0.01;
    Eigen::MatrixXd Ad(2,2);
    Eigen::VectorXd Bd(2);
    Eigen::RowVectorXd C(2);
    Ad << 
        0.8, 1.0,
        0.0, 0.9;
    Bd <<
        -0.01,
        0.02;
    C << 0, 1;

    cr::StateSpaceSystem system;
    system.set_discrite(Ad, Bd, C, dt);

    // initial state
    Eigen::Vector2d x0(0.2, 5);
    system.set_state(x0);

    //////////////////// MPC ////////////////////
    Eigen::MatrixXd Q = 3.0 * Eigen::MatrixXd::Identity(2,2);
    Eigen::MatrixXd Qf = 5.0 * Eigen::MatrixXd::Identity(2,2); 
    Eigen::MatrixXd R = 0.01 * Eigen::MatrixXd::Identity(1,1);
    Eigen::VectorXd u_min = -5.0 * Eigen::VectorXd::Ones(1);
    Eigen::VectorXd u_max =  5.0 * Eigen::VectorXd::Ones(1);
    size_t horizon = 10;
    cr::LinearMPC mpc(Ad, Bd, Q, R, Qf, horizon, std::make_pair(u_min, u_max));

    //////////////////// Simulation ////////////////////
    const double sim_time = 0.5;
    const size_t loop_num = sim_time/dt;
    std::vector<double> t = cr::linspace(0, sim_time, loop_num);
    std::vector<double> u, x1, x2;
    for(size_t i = 0; i < sim_time/dt; i++)
    {
        auto x = system.x();
        x1.push_back(x(0));
        x2.push_back(x(1));
        auto [is_success, u_opt] = mpc.control(system.x(), true);
        if(not is_success)
            std::cout << "[error]: optimize failue" << std::endl;
        u.push_back(u_opt(0));
        system.responce(u_opt);
    }

    plt::named_plot("u", t, u, "--");
    plt::named_plot("x1", t, x1, "o-");
    plt::named_plot("x2", t, x2, "o-");
    plt::legend();
    plt::show();
}



