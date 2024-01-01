// #include <cpp_robotics/core.hpp>
#include <cpp_robotics/controller/ilqr.hpp>
#include <cpp_robotics/third_party/matplotlib-cpp/matplotlibcpp.h>
#include <chrono>

int main()
{
    namespace cr = cpp_robotics;

    const double Ts = 0.05;

    Eigen::MatrixXd A(4, 4);
    A << 0, 0, 1, 0,
         0, 0, 0, 1,
         0, 0, -0.3, 0.0,
         0, 0, 0, -0.3;
    
    Eigen::MatrixXd B(4, 2);
    B << 0,0,
         0,0,
         1, 0,
         0, 1;
    
    Eigen::MatrixXd Q(4, 4);
    Q = (Eigen::VectorXd(4) << 5,5,0.5,0.5).finished().asDiagonal();
    
    Eigen::MatrixXd R(2, 2);
    R = (Eigen::VectorXd(2) << 0.1,0.1).finished().asDiagonal();

    Eigen::MatrixXd Qf = Q;

    Q = Q * Ts;
    R = R * Ts;

    std::cout << "tp0" << std::endl;

    auto model = cr::DiscreteLinearOCP::from_continuous(A, B, Q, R, Qf, Ts, 30);

    Eigen::VectorXd ulim(2);
    ulim << 5, 5;
    model.u_limit = std::make_pair(-ulim, ulim);

    std::cout << "tp1" << std::endl;
    cr::iLQR ilqr(model);

    std::cout << "tp2" << std::endl;

    Eigen::VectorXd x0(4);
    x0 << 5, 3, 0, 0;

    model.set_x_ref((Eigen::VectorXd(4) << 4, -1, 0, 0).finished());

    if(ilqr.generate_trajectory(x0) == cr::iLQR<>::Result::SUCCESS)
    {
        std::cout << "Success" << std::endl;

        namespace plt = matplotlibcpp;

        std::vector<double> u, x1, x2, t, solve_time;

        for(size_t i = 0; i < 100; i++)
        {
            auto start = std::chrono::system_clock::now();
            ilqr.generate_trajectory(x0);
            auto end = std::chrono::system_clock::now();

            double microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

            x0 = model.model(x0, ilqr.get_input()[0]);

            t.push_back(i * Ts);
            u.push_back(ilqr.get_input()[0](0));
            x1.push_back(ilqr.get_state()[0](0));
            x2.push_back(ilqr.get_state()[0](1));
            solve_time.push_back(microseconds);
        }

        plt::named_plot("u", t, u);
        plt::named_plot("x1", t, x1);
        plt::named_plot("x2", t, x2);
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