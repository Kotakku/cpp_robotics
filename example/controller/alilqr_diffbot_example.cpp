#include <iostream>
#include <cpp_robotics/controller/al_ilqr.hpp>
#include <cpp_robotics/third_party/matplotlib-cpp/matplotlibcpp.h>
#include <chrono>

class DiffBot : public cpp_robotics::OCPDiscreteNonlinearDynamics
{
public:
    DiffBot(size_t horizon, double dt):
        OCPDiscreteNonlinearDynamics(3,2,horizon), dt_(dt) {}

    Eigen::VectorXd eval(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        Eigen::VectorXd x_next(3);
        x_next << x[0] + dt_ * (u[0] * std::cos(x[2]) - u[1] * std::sin(x[2])),
                  x[1] + dt_ * (u[0] * std::sin(x[2]) + u[1] * std::cos(x[2])),
                  x[2] + dt_ * (u[0] - u[1]);
        return x_next;
    }
private:
    double dt_;
};

int main()
{
    using namespace cpp_robotics;
    namespace plt = matplotlibcpp;
    
    const double Ts = 0.05;
    auto model = std::make_shared<DiffBot>(30, Ts);
    auto cost = std::make_shared<OCPCostServoQuadratic>(model);
    cost->Q = (Eigen::VectorXd(3) << 5, 5, 3).finished().asDiagonal();
    cost->R = 0.1 * Eigen::MatrixXd::Identity(2, 2);
    cost->Qf = cost->Q;
    cost->set_x_ref_const((Eigen::VectorXd(4) << 3, 4, M_PI/2).finished());
    OCPConstraintArray constraints =
    {
        OCPInputBoundConstraints(Eigen::VectorXd::Constant(2, -3), Eigen::VectorXd::Constant(2, 3))
    };
    ALiLQR ilqr(model, cost, constraints);

    Eigen::VectorXd x0(3);
    x0 << 0, 0, 0;

    std::vector<double> u1, u2, x, y, theta, t, solve_time;
    for(size_t i = 0; i < 100; i++)
    {
        auto start = std::chrono::system_clock::now();
        auto ret = ilqr.generate_trajectory(x0);
        auto end = std::chrono::system_clock::now();

        if(ret != ALiLQR::Result::SUCCESS)
        {
            std::cout << "Failed to solve at " << i << " code: " << static_cast<int>(ret) << std::endl;
        }

        double milliseconds = 1e-3 * std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        x0 = model->eval(x0, ilqr.get_input()[0]);

        t.push_back(i * Ts);
        u1.push_back(ilqr.get_input()[0](0));
        u2.push_back(ilqr.get_input()[0](1));
        x.push_back(ilqr.get_state()[0](0));
        y.push_back(ilqr.get_state()[0](1));
        theta.push_back(ilqr.get_state()[0](2));
        solve_time.push_back(milliseconds);
    }

    plt::named_plot("u1", t, u1);
    plt::named_plot("u2", t, u2);
    plt::named_plot("x", t, x);
    plt::named_plot("y", t, y);
    plt::named_plot("theta", t, theta);
    plt::legend();
    plt::show(false);

    plt::figure();
    plt::named_plot("solve_time[ms]", t, solve_time, ".");
    plt::legend();
    plt::show();

    return 0;
}