#include <iostream>
#include <cpp_robotics/controller/al_ilqr.hpp>
#include <cpp_robotics/third_party/matplotlib-cpp/matplotlibcpp.h>
#include <chrono>

class DiffBot : public cpp_robotics::OCPDiscreteNonlinearDynamics
{
public:
    DiffBot(size_t horizon, double dt):
        OCPDiscreteNonlinearDynamics(3,2,horizon), dt_(dt) {}

    void eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u, Eigen::VectorXd &x_next) const override
    {
        x_next << x[0] + dt_ * (u[0] * std::cos(x[2]) - u[1] * std::sin(x[2])),
                  x[1] + dt_ * (u[0] * std::sin(x[2]) + u[1] * std::cos(x[2])),
                  x[2] + dt_ * (u[0] - u[1]);
    }
private:
    double dt_;
};

class CartPole : public cpp_robotics::OCPContinuousNonlinearDynamics
{
public:
    CartPole(size_t horizon, double dt):
        OCPContinuousNonlinearDynamics(4,1,horizon,dt) {}

    void dynamics(const Eigen::VectorXd &x, const Eigen::VectorXd &u, Eigen::VectorXd &dx) const override
    {
        auto y = x(0);     // cart の水平位置[m]
        auto th = x(1);    // pole の傾き角[rad]
        auto dy = x(2);    // cart の水平速度[m/s]
        auto dth = x(3);   // pole の傾き角速度[rad/s]
        auto f = u(0);     // cart を押す力[N]（制御入力）
        auto s_th = sin(th);
        auto c_th = cos(th);
        // cart の水平加速度
        double ddy = (f+mp*s_th*(l*dth*dth+g*c_th)) / (mc+mp*s_th*s_th);
        // pole の傾き角加速度
        double ddth = (-f*c_th-mp*l*dth*dth*c_th*s_th-(mc+mp)*g*s_th) / (l * (mc+mp*s_th*s_th));  

        dx << dy, dth, ddy, ddth;
    }

    const double mc = 2.0;
    const double mp = 0.2;
    const double l = 0.5;
    const double g = 9.8;
};

int main()
{
    using namespace cpp_robotics;
    
    const double Ts = 0.05;
    auto model = std::make_shared<CartPole>(30, Ts);
    auto cost = std::make_shared<OCPCostServoQuadratic>(model);
    cost->Q = (Eigen::VectorXd(4) << 5, 10, 0.01, 0.01).finished().asDiagonal();
    cost->R = 0.1 * Eigen::MatrixXd::Identity(1, 1);
    cost->Qf = cost->Q;
    cost->set_x_ref_const((Eigen::VectorXd(4) << 0, M_PI, 0, 0).finished());
    OCPConstraintArray constraints =
    {
        OCPInputBoundConstraints(Eigen::VectorXd::Constant(1, -15), Eigen::VectorXd::Constant(1, 15))
    };
    ALiLQR ilqr(model, cost, constraints);

    Eigen::VectorXd x0(4);
    x0 << 0, 0, 0, 0;

    // std::cout << "start" << std::endl;

    if(1) //ilqr.generate_trajectory(x0) == detail::ALiLQRResult::SUCCESS)
    {
        // std::cout << "Success" << std::endl;
        // return 0;

        namespace plt = matplotlibcpp;

        std::vector<double> u, x, theta, t, solve_time;

        for(size_t i = 0; i < 100; i++)
        {
            auto start = std::chrono::system_clock::now();
            ilqr.generate_trajectory(x0);
            auto end = std::chrono::system_clock::now();

            double milliseconds = 1e-3 * std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

            x0 = model->eval(x0, ilqr.get_input()[0]);

            t.push_back(i * Ts);
            u.push_back(ilqr.get_input()[0](0));
            x.push_back(ilqr.get_state()[0](0));
            theta.push_back(ilqr.get_state()[0](1));
            solve_time.push_back(milliseconds);
        }

        plt::named_plot("u", t, u);
        plt::named_plot("x", t, x);
        plt::named_plot("theta", t, theta);
        plt::legend();
        plt::ylim(-20, 20);
        plt::show(false);

        plt::figure();
        plt::named_plot("solve_time[ms]", t, solve_time, ".");
        plt::legend();
        plt::show();

    }
    else
    {
        std::cout << "Failed" << std::endl;
    }

    return 0;
}