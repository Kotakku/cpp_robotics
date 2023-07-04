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
        if(0.75*target.size() < i)
            target[i] = 20*std::cos(i*3.5*dt);
        else if(0.5*target.size() < i)
            target[i] = ( (i < 0.625*target.size()) ? 10 : 20 );
        else if(0.25*target.size() < i)
            target[i] = 0;
        else 
            target[i] = -15 + 30 * ((double)(i) / (0.25*target.size()));
    }
    return {t, target};
}

void plot_nct_test(std::function<double(double)> f)
{
    std::vector<double> e = cpp_robotics::arrange(-10, 10, 0.05);
    std::vector<double> e_dot(e.size());

    for(size_t i = 0; i < e.size(); i++)
    {
        e_dot[i] = f(e[i]);
    }

    namespace plt = matplotlibcpp;
    plt::plot(e, e_dot);
    plt::ylim(-10, 10);
    plt::show();
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

    //////////////////// NCTF ////////////////////
    cr::PID::pid_param_t nctf_pid_param = 
    {
        /*.Ts =           */ dt,
        /*.gpd =          */ 100*2*M_PI,
        /*.Kp =           */ 0.5,
        /*.Ki =           */ 0,
        /*.Kd =           */ 0,
        /*.output_limit = */ std::pair(-max_output, max_output)
    };
    
    const double nct_max_velocity = 300.0;
    const double nct_slope = 25;
    cr::NctfController nctf(nct_max_velocity, nct_slope, nctf_pid_param, dt);

    //////////////////// Plant ////////////////////
    auto motor = cr::DCGearedMotorParam(24_V, cr::RZ_735VA_9517, cr::IG42C_17);
    auto plant = make_geared_motor_pos_tf(motor, dt); // [V] -> [rad]

    // plot_nct_test(nctf.nct());

    //////////////////// Simulation ////////////////////
    auto [t, ref_trajecoty] = ref_trajectory(5.0, dt);
    plt::named_plot("ref trajecoty", t, ref_trajecoty, "--");

    // PID controller system simulation
    {
        cr::SisoFeedbackSystem siso_sys = cr::make_feedback_system(pid, plant);
        siso_sys.reset();
        auto [t, u, responce] = cr::lsim(siso_sys, ref_trajecoty);
        plt::named_plot("PID responce(dt = 0.001)", t, responce);
    }

    // NCTF constoller system simulation
    {
        cr::SisoFeedbackSystem siso_sys = cr::make_feedback_system(nctf, plant);
        siso_sys.reset();
        auto [t, u, responce] = cr::lsim(siso_sys, ref_trajecoty);
        plt::named_plot("NCTF responce(dt = 0.001)", t, responce);
    }

    // NCTF constoller system simulation(long time period)
    {
        const double ldt = dt * 10;
        auto plant2 = make_geared_motor_pos_tf(motor, ldt); // [V] -> [rad]
        cr::NctfController nctf2(nct_max_velocity, nct_slope, nctf_pid_param, ldt);
        cr::SisoFeedbackSystem siso_sys = cr::make_feedback_system(nctf2, plant2);
        siso_sys.reset();
        auto [tref, ref_trajecoty] = ref_trajectory(5.0, ldt);
        auto [t, u, responce] = cr::lsim(siso_sys, ref_trajecoty);
        plt::named_plot("NCTF responce(dt = 0.01)", t, responce);
    }

    // show
    plt::ylim(-30.0, 30.0);
    plt::legend();
    plt::show();
}



