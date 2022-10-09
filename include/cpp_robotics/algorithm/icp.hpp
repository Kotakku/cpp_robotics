// https://clientver2.hatenablog.com/entry/2015/11/27/160814
// http://nghiaho.com/?page_id=671

#pragma once

#include <Eigen/Dense>
#include "./kdtree.hpp"
#include "./transformation.hpp"

namespace cpp_robotics
{

// destを回転させてsrcに重ねる時の回転量と移動量を計算する
template<int DIM>
static std::pair<Eigen::Matrix<double, DIM, DIM>, Eigen::Matrix<double, DIM, 1>> 
    calcu_transformatoin(
        std::vector<Eigen::Matrix<double, DIM, 1>> dest,
        std::vector<Eigen::Matrix<double, DIM, 1>> fixed)
{
    assert(fixed.size() == dest.size());
    using vector_type = Eigen::Matrix<double, DIM, 1>;
    using matrix_type = Eigen::Matrix<double, DIM, DIM>;

    const size_t dim = dest[0].size();
    const size_t len = fixed.size();

    // detrend
    vector_type mean_fixed = vector_type::Zero();
    vector_type mean_dest = vector_type::Zero();
    for(auto & v : fixed)
        mean_fixed += v/static_cast<double>(len);
    for(auto & v : fixed)
        v -= mean_fixed;

    for(auto & v : dest)
        mean_dest += v/static_cast<double>(len);
    for(auto & v : dest)
        v -= mean_dest;

    // 回転量と移動量を求める
    Eigen::Matrix<double, DIM, DIM> H = Eigen::Matrix<double, DIM, DIM>::Zero();

    for(size_t i = 0; i < len; i++)
    {
        H += dest[i] * fixed[i].transpose(); 
    }

    Eigen::JacobiSVD svd(H, Eigen::ComputeFullU | Eigen::ComputeFullV);

    matrix_type R = svd.matrixV() * svd.matrixU().transpose();
    vector_type T = (-R*mean_dest) + mean_fixed;
    return {R, T};
}

// Todo: R, Tを返すようにする
// Todo: 終了条件つける
template<int DIM>
static std::tuple<std::vector<Eigen::Matrix<double, DIM, 1>>, Eigen::MatrixXd, size_t> 
    icp(
        std::vector<Eigen::Matrix<double, DIM, 1>> dest,
        const std::vector<Eigen::Matrix<double, DIM, 1>> &fixed,
        double eps = 1e-4,
        size_t max_iter = 100) 
{
    const size_t dim = dest[0].size();
    KDTree<Eigen::Matrix<double, DIM, 1>> kdtree(fixed, dim);
    Eigen::MatrixXd H = Eigen::MatrixXd::Identity(dim+1, dim+1);

    size_t i = 0;
    for(; i < max_iter; i++)
    {
        // 点群現在の状態で点群の対応を取る
        auto nerghbor_idx = kdtree.nn_search(dest);
        std::vector<Eigen::Matrix<double, DIM, 1>> target(nerghbor_idx.size());
        for(size_t j = 0; j < nerghbor_idx.size(); j++)
        {
            // std::cout << nerghbor_idx[j] << std::endl;
            target[j] = fixed[nerghbor_idx[j]];
            // target[j] = fixed[j]; // debug
        }

        // 点群の対応で移動量を計算する
        auto [R, T] = calcu_transformatoin(dest, target);

        // 移動させる
        for(size_t j = 0; j < dest.size(); j++)
        {
            dest[j] = R*dest[j] + T;
        }

        // homogeneous transformation行列の更新
        Eigen::MatrixXd Ht = homogeneous(R, T);
        H *= Ht;

        // 収束判定
    }
    return {dest, H, i};
}

}