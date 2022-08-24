#include <iostream>
#include <cpp_robotics/core.hpp>


int main()
{
    using namespace cpp_robotics;

    const double dt = 0.01;

    //////////////////// plant ////////////////////
    Eigen::MatrixXd A(2,2), B(2,1), C(2,2);
    A << 0, 1, -10, -1;
    B << 0, 1;
    C.setIdentity();

    StateSpaceSystem<2,1,2> sys;
    sys.set_continuous(A, B, C, dt);

    //////////////////// controller ////////////////////
    Eigen::MatrixXd Q(2,2), R(1,1);
    Q << 3000, 0, 0, 60;
    R << 0.01;
    Eigen::MatrixXd K = lqr(A, B, Q, R);

    std::cout << "fb gain" << std::endl;
    std::cout << K << std::endl;

    Eigen::Vector2d target_vec;
    target_vec << 30, 0;
    

    {
        namespace plt = matplotlibcpp;
        auto t = arrange(0, 5.0, dt);
        std::vector<double> x1(t.size()), x2(t.size()), x1_ref(t.size());

        //////////////////// simulation ////////////////////
        for(size_t i = 0; i < t.size(); i++)
        {
            Eigen::VectorXd u = K*(target_vec-sys.x());

            auto x = sys.responce(u);
            x1[i] = x(0);
            x2[i] = x(1);
            x1_ref[i] = target_vec(0);
        }

        std::cout << "plot" << std::endl;

        plt::named_plot("x1", t, x1);
        plt::named_plot("x2", t, x2);
        plt::named_plot("x1_ref", t, x1_ref);
        plt::legend();
        plt::show();
    }

}



