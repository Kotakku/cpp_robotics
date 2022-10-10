#define CR_USE_MATPLOTLIB
#include <iostream>
#include <cpp_robotics/core.hpp>
#include <cpp_robotics/motor/dc_motor_list.hpp>
#include <cpp_robotics/motor/motor_tf.hpp>

static std::tuple<std::vector<double>, std::vector<double>> ref_trajectory(double time, double dt)
{
    std::vector<double> t = cpp_robotics::arrange(0, time, dt);
    std::vector<double> target(t.size());

    target[0] = 0;
    for(size_t i = 1; i < target.size(); i++)
    {
        if(0.5*target.size() < i)
            target[i] = 20*std::cos(i*3.5*dt);
        else
            target[i] = ( (i < 0.25*target.size()) ? 20 : 0 );
    }
    return {t, target};
}

int main()
{
    namespace cr = cpp_robotics;
    namespace plt = matplotlibcpp;
    using namespace cr::unit;

    const double dt = 0.001;
    const double max_output = 24;

    //////////////////// PID ////////////////////
    cr::PID::pid_param_t pid_param = 
    {
        /*.Ts =           */ dt,
        /*.gpd =          */ 100*2*M_PI,
        /*.Kp =           */ 6.0,
        /*.Ki =           */ 0.0,
        /*.Kd =           */ 0.2,
        /*.output_limit = */ std::pair(-max_output, max_output)
    };
    cr::PID pid(pid_param);

    //////////////////// Plant ////////////////////
    auto motor = cr::DCGearedMotorParam(24_V, cr::RZ_735VA_9517, cr::IG42C_17);
    auto plant = make_geared_motor_pos_tf(motor, dt); // [V] -> [rad]

    //////////////////// Simulation ////////////////////
    auto [t, ref_trajecoty] = ref_trajectory(5.0, dt);
    plt::named_plot("ref trajecoty", t, ref_trajecoty, "--");

    cr::SisoFeedbackSystem siso_sys = cr::make_feedback_system(pid, plant);
    auto [t2, responce] = cr::lsim(siso_sys, ref_trajecoty);
    plt::named_plot("PID responce", t2, responce);

    // show
    plt::ylim(-30.0, 30.0);
    plt::legend();
    plt::show();
}



