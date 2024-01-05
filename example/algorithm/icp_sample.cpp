#define CR_USE_MATPLOTLIB
#include <iostream>
#include <iomanip>
#include <cpp_robotics/matplotlibcpp.hpp>
#include <cpp_robotics/algorithm/icp.hpp>
#include <cpp_robotics/vector/vector2.hpp>
#include <Eigen/Geometry> 

int main()
{
    namespace cr = cpp_robotics;

    std::cout << std::fixed << std::setprecision(3);
    {
        std::vector<Eigen::Vector2d> fixed = {
            {0,9},
            {0,7},
            {0,5},
            {0,3},
            {2,1},
            {4,1},
            {6,1},
            {8,3},
            {8,5},
            {8,9},
        };

        std::vector<Eigen::Vector2d> p2 = fixed;
        Eigen::Rotation2Dd t(M_PI/3);
        t.toRotationMatrix();
        for(size_t i = 0; i < fixed.size(); i++)
        {
            p2[i][0] += 3.0;
            p2[i][1] += 1.0;
            p2[i] = t*p2[i];
        }
        auto [R, T] = cr::calcu_transformatoin<2>(p2, fixed);

        std::cout << "R = " << std::endl;
        std::cout << R << std::endl;
        std::cout << "T = " << std::endl;
        std::cout << T << std::endl;
        std::cout << "t = " << std::endl;
        std::cout << t.matrix() << std::endl;

        std::cout << "///// check /////" << std::endl;

        for(size_t i = 0; i < p2.size(); i++)
        {
            auto moved_p = R*p2[i] + T;

            std::cout << moved_p.transpose() << ", err = " << (moved_p-fixed[i]).transpose() << std::endl;
        }
    }

    {
        std::vector<Eigen::Vector2d> p1 = {
            {6,9},
            {5,8},
            {5,7},
            {5,6},
            {5,5},
            {5,4},
            {1,3},
            {1,2},
            {2,1},
            {3,1},
            {4,1},
            {5,1},
            {6,1},
            {7,1},
            {8,3},
            {8,4},
            {8,5},
            {8,6},
            {8,7},
            {8,8},
            {8,9},
        };

        std::vector<Eigen::Vector2d> p2 = p1;
        Eigen::Rotation2Dd t(M_PI/3);
        t.toRotationMatrix();
        for(size_t i = 0; i < p2.size(); i++)
        {
            p2[i][0] += 3.0;
            p2[i][1] += 1.0;
            p2[i] = t*p2[i];
        }

        auto [points, H, cnt] = cr::icp<2>(p2, p1, 1e-4, 50);

        auto gen = [](std::vector<Eigen::Vector2d> ps)
        {
            std::vector<double> x_(ps.size()), y_(ps.size());

            for(size_t i = 0; i < (ps.size()); i++)
            {
                x_[i] = ps[i][0];
                y_[i] = ps[i][1];
            }

            return std::tuple<std::vector<double>, std::vector<double>>(x_, y_);
        };

        auto gen_tf = [&](std::vector<Eigen::Vector2d> ps, Eigen::MatrixXd H)
        {
            std::vector<double> x_(ps.size()), y_(ps.size());

            for(size_t i = 0; i < (ps.size()); i++)
            {
                auto p = cr::transform_by_homogeneous(H, ps[i]);
                x_[i] = p[0];
                y_[i] = p[1];
            }

            return std::tuple<std::vector<double>, std::vector<double>>(x_, y_);
        };

        std::cout << "H" << std::endl;
        std::cout << H << std::endl;

        auto [x, y] = gen(p1);
        matplotlibcpp::plot(x, y, "o--");
        auto [x2, y2] = gen(p2);
        matplotlibcpp::plot(x2, y2, "o--");
        auto [xr, yr] = gen(points);
        matplotlibcpp::plot(xr, yr, "o--");
        
        auto [xp, yp] = gen_tf(p2, H);
        matplotlibcpp::plot(xp, yp); // 一致しない？
        matplotlibcpp::show();

    }
}