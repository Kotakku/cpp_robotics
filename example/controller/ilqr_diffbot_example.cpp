#include <cpp_robotics/controller/ilqr.hpp>
#include <cpp_robotics/third_party/matplotlib-cpp/matplotlibcpp.h>
#include <chrono>

class DiffBotOCP : public cpp_robotics::DiscreteNonlinearOCP
{
public:
    DiffBotOCP(size_t horizon, double dt):
        cpp_robotics::DiscreteNonlinearOCP(3,2,horizon), dt_(dt)
    {
        Q = (Eigen::VectorXd(3) << 5,5,3).finished().asDiagonal();
        R = (Eigen::VectorXd(2) << 0.1,0.1).finished().asDiagonal();
        Qf = Q;

        x_ref_ = Eigen::VectorXd::Zero(3);

        Eigen::VectorXd ulim(2);
        ulim << 3, 3;

        u_limit = std::make_pair(-ulim, ulim);
    }

    Eigen::VectorXd dynamics(const Eigen::VectorXd &x, const Eigen::VectorXd &u) const override
    {
        Eigen::VectorXd x_next(3);
        x_next << x[0] + dt_ * (u[0] * std::cos(x[2]) - u[1] * std::sin(x[2])),
                  x[1] + dt_ * (u[0] * std::sin(x[2]) + u[1] * std::cos(x[2])),
                  x[2] + dt_ * (u[0] - u[1]);
        return x_next;
    }

    double running_cost(const Eigen::VectorXd &x, const Eigen::VectorXd &u, size_t /**/) const override
    {
        auto e = x - x_ref_;
        return (0.5*e.transpose() * Q * e + u.transpose() * R * u)[0];
    }

    double terminal_cost(const Eigen::VectorXd &x) const override
    {
        auto e = x - x_ref_;
        return (0.5*e.transpose() * Qf * e)[0];
    }

    void set_x_ref(const Eigen::VectorXd &x_ref)
    {
        x_ref_ = x_ref;
    }

private:
    double dt_;
    Eigen::VectorXd x_ref_;
    Eigen::MatrixXd Q, R, Qf;
};

int main()
{
    namespace cr = cpp_robotics;

    const double Ts = 0.05;
    DiffBotOCP model(30, Ts);
    cr::iLQR ilqr(model);

    Eigen::VectorXd x0(3);
    x0 << 0, 0, 0;

    model.set_x_ref((Eigen::VectorXd(3) << 3, 4, 0).finished());

    if(ilqr.generate_trajectory(x0) == cr::iLQRResult::SUCCESS)
    {
        std::cout << "Success" << std::endl;

        namespace plt = matplotlibcpp;

        std::vector<double> u1, u2, x, y, theta, t, solve_time;

        for(size_t i = 0; i < 100; i++)
        {
            auto start = std::chrono::system_clock::now();
            ilqr.generate_trajectory(x0);
            auto end = std::chrono::system_clock::now();

            double microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

            x0 = model.dynamics(x0, ilqr.get_input()[0]);

            t.push_back(i * Ts);
            u1.push_back(ilqr.get_input()[0](0));
            u2.push_back(ilqr.get_input()[0](1));
            x.push_back(ilqr.get_state()[0](0));
            y.push_back(ilqr.get_state()[0](1));
            theta.push_back(ilqr.get_state()[0](2));
            solve_time.push_back(microseconds);
        }

        plt::named_plot("u1", t, u1);
        plt::named_plot("u2", t, u2);
        plt::named_plot("x", t, x);
        plt::named_plot("y", t, y);
        plt::named_plot("theta", t, theta);
        plt::legend();
        plt::show(false);

        plt::figure();
        plt::named_plot("solve_time[us]", t, solve_time);
        plt::legend();
        plt::show();

    }
    else
    {
        std::cout << "Failed" << std::endl;
    }

    return 0;
}