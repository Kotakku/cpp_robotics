---
title: example/controller/pid_vs_nctf.cpp

---

# example/controller/pid_vs_nctf.cpp



## Functions

|                | Name           |
| -------------- | -------------- |
| std::tuple< std::vector< double >, std::vector< double >, std::vector< double >, std::vector< double >, std::vector< double > > | **[step_test](/cpp_robotics/doxybook/Files/pid__vs__nctf_8cpp/#function-step-test)**([cpp_robotics::SisoFeedbackSystem](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1SisoFeedbackSystem/) & sys, double time, double dt) |
| void | **[make_nct_test](/cpp_robotics/doxybook/Files/pid__vs__nctf_8cpp/#function-make-nct-test)**(std::function< double(double)> f) |
| int | **[main](/cpp_robotics/doxybook/Files/pid__vs__nctf_8cpp/#function-main)**() |


## Functions Documentation

### function step_test

```cpp
static std::tuple< std::vector< double >, std::vector< double >, std::vector< double >, std::vector< double >, std::vector< double > > step_test(
    cpp_robotics::SisoFeedbackSystem & sys,
    double time,
    double dt
)
```


### function make_nct_test

```cpp
void make_nct_test(
    std::function< double(double)> f
)
```


### function main

```cpp
int main()
```




## Source code

```cpp
#include <iostream>
#include <cpp_robotics/core.hpp>
#include <cpp_robotics/motor/dc_motor_list.hpp>
#include <cpp_robotics/motor/motor_tf.hpp>

static std::tuple<std::vector<double>, std::vector<double>, std::vector<double>, std::vector<double>, std::vector<double>> step_test(cpp_robotics::SisoFeedbackSystem &sys, double time, double dt)
{
    std::vector<double> t = cpp_robotics::arrange(0, time, dt);
    std::vector<double> target(t.size());
    std::vector<double> res(t.size());
    std::vector<double> dres(t.size());
    std::vector<double> input(t.size());

    cpp_robotics::Differentiator diff_(1/dt, dt);
    

    for(size_t i = 0; i < res.size(); i++)
    {
        target[i] = (res.size()/2 < i ) ? ( (res.size()*3/4 < i ) ? 0: 20 ) : 20*std::cos(i*0.03); // : 1.0;
        res[i] = sys.control(target[i]);
        dres[i] = diff_.filtering(res[i]);
        input[i] = sys.u();
    }

    return {t, target, input, res, dres};
}

void make_nct_test(std::function<double(double)> f)
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
    using namespace cpp_robotics;

    const double dt = 0.01;
    const double max_output = 24;

    PIDController::pid_param_t pid_param = 
    {
        .Ts = dt,
        .gpd = 100,
        .Kp = 10.0,
        .Ki = 0.0,
        .Kd = 0.09,
        .output_limit = std::pair(-max_output, max_output)
    };
    PIDController pid(pid_param);

    PIDController::pid_param_t nctf_pid_param = 
    {
        .Ts = dt,
        .gpd = 500,
        .Kp = 0.8,
        .Ki = 0.0,
        .Kd = 0.005,
        .output_limit = std::pair(-max_output, max_output)
    };
    
    const double nct_max_velocity = 300.0;
    const double nct_slope = 10;
    NctfController nctf(nct_max_velocity, nct_slope, nctf_pid_param, dt);

    auto motor = DCGearedMotorParam(24_V, RZ_735VA_9517, IG42C_17);
    auto plant = make_geared_motor_pos_tf(motor, dt); // [rad]

    // make_nct_test(nctf.nct());
    // {
    //     auto vel_plant = make_geared_motor_vel_tf(motor, dt); // [rad]
    //     namespace plt = matplotlibcpp;
    //     auto [t, res] = step(vel_plant, 3.0, max_output);
    //     plt::named_plot("responce", t, res);
    //     plt::legend();
    //     plt::show();
    // }

    {
        namespace plt = matplotlibcpp;
        {
            SisoFeedbackSystem siso_sys = cpp_robotics::make_feedback_system(pid, plant);
            siso_sys.reset();
            auto [t, target, input, ret, dres] = step_test(siso_sys, 5.0, dt);

            plt::named_plot("target", t, target);
            plt::named_plot("PID responce", t, ret);
        }

        {
            SisoFeedbackSystem siso_sys = cpp_robotics::make_feedback_system(nctf, plant);
            auto [t, target, input, ret, dres] = step_test(siso_sys, 5.0, dt);
            plant.set_state_zero();
            siso_sys.reset();
            // plt::named_plot("target", t, target);
            plt::named_plot("NCTF responce", t, ret);
            // plt::named_plot("input", t, input);
        }

        // plt::named_plot("input", t, input);
        // plt::named_plot("d responce / dt", t, dres);

        plt::ylim(-30.0, 30.0);
        plt::legend();
        plt::show();

        // // show NCT
        // plt::named_plot("actual NCT", nctf.e_, nctf.e_dot_);
        // plt::named_plot("target NCT", nctf.e_, nctf.target_e_dot_);
        // plt::show();
    }

}
```


-------------------------------

Updated on 2022-09-25 at 23:29:49 +0900
