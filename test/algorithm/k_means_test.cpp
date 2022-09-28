#include <gtest/gtest.h>

#include <Eigen/Dense>
#include <cpp_robotics/algorithm/k_means_method.hpp>
#include <cpp_robotics/vector/vector2.hpp>

TEST(k_means_method, cr_vector_test) {
    namespace cr = cpp_robotics;

    cr::KMeansModel<cr::Vector2d> model;

    std::vector<cr::Vector2d> data_set = 
    {
        {1,1},
        {1,2},
        {10,1},
        {11,2},
        {30,1},
        {31,1},
        {1,1},
        {1,2},
        {1,3},
        {10,2},
        {11,3},
        {30,2},
        {31,2},
        {1,2}
    };

    auto label = model.fit(data_set, 3);

    for(size_t i = 0; i < data_set.size(); i++)
    {
        printf("cluster: %2ld (%5.1f, %5.1f)\n", label[i], data_set[i].x, data_set[i].y);
    }

    EXPECT_EQ(label[0], model.predict({0.3, 1.2}));
}

TEST(k_means_method, static_size_eigen_vector_test) {
    namespace cr = cpp_robotics;

    cr::KMeansModel<Eigen::Vector2d> model;

    std::vector<Eigen::Vector2d> data_set = 
    {
        {1,1},
        {1,2},
        {10,1},
        {11,2},
        {30,1},
        {31,1},
        {1,1},
        {1,2},
        {1,3},
        {10,2},
        {11,3},
        {30,2},
        {31,2},
        {1,2}
    };

    auto label = model.fit(data_set, 3);

    for(size_t i = 0; i < data_set.size(); i++)
    {
        printf("cluster: %2ld (%5.1f, %5.1f)\n", label[i], data_set[i](0), data_set[i](1));
    }

    EXPECT_EQ(label[0], model.predict({0.3, 1.2}));
}

TEST(k_means_method, dynamic_size_eigen_vector_test) {
    namespace cr = cpp_robotics;

    cr::KMeansModel<Eigen::VectorXd> model;

    std::vector<Eigen::VectorXd> data_set = 
    {
        Eigen::Vector2d{1,1},
        Eigen::Vector2d{1,2},
        Eigen::Vector2d{10,1},
        Eigen::Vector2d{11,2},
        Eigen::Vector2d{30,1},
        Eigen::Vector2d{31,1},
        Eigen::Vector2d{1,1},
        Eigen::Vector2d{1,2},
        Eigen::Vector2d{1,3},
        Eigen::Vector2d{10,2},
        Eigen::Vector2d{11,3},
        Eigen::Vector2d{30,2},
        Eigen::Vector2d{31,2},
        Eigen::Vector2d{1,2}
    };

    auto label = model.fit(data_set, 3);

    for(size_t i = 0; i < data_set.size(); i++)
    {
        printf("cluster: %2ld (%5.1f, %5.1f)\n", label[i], data_set[i](0), data_set[i](1));
    }

    EXPECT_EQ(label[0], model.predict(Eigen::Vector2d{0.3, 1.2}));
}