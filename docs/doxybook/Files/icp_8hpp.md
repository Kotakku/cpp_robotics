---
title: include/cpp_robotics/algorithm/icp.hpp

---

# include/cpp_robotics/algorithm/icp.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |




## Source code

```cpp
// https://clientver2.hatenablog.com/entry/2015/11/27/160814
// http://nghiaho.com/?page_id=671

#pragma once

#include <Eigen/Dense>
#include "./kdtree.hpp"

namespace cpp_robotics
{

// destを回転させてsrcに重ねる時の回転量と移動量を計算する
template<size_t DIM>
static std::pair<Eigen::Matrix<double, DIM, DIM>, Eigen::Matrix<double, DIM, 1>> 
    calcu_transformatoin(
        std::vector<Eigen::Matrix<double, DIM, 1>> dest,
        std::vector<Eigen::Matrix<double, DIM, 1>> fixed)
{
    assert(fixed.size() == dest.size());
    using vector_type = Eigen::Matrix<double, DIM, 1>;
    using matrix_type = Eigen::Matrix<double, DIM, DIM>;

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

    // std::cout << "mean_fixed" << std::endl;
    // std::cout << mean_fixed.transpose() << std::endl;
    // std::cout << "mean_dest" << std::endl;
    // std::cout << mean_dest.transpose() << std::endl;
    
    // for(size_t i = 0; i < len; i++)
    // {
    //     std::cout << fixed[i].transpose() << std::endl;
    // }

    // for(size_t i = 0; i < len; i++)
    // {
    //     std::cout << dest[i].transpose() << std::endl;
    // }

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
template<size_t DIM>
static std::tuple<std::vector<Eigen::Matrix<double, DIM, 1>>, size_t> 
    icp(
        std::vector<Eigen::Matrix<double, DIM, 1>> dest,
        std::vector<Eigen::Matrix<double, DIM, 1>> fixed,
        size_t max_iter = 100) 
{
    KDTree<Eigen::Matrix<double, DIM, 1>, DIM> kdtree(fixed);

    auto old_dest = dest;
    size_t i = 0;
    for(; i < max_iter; i++)
    {
        auto nerghbor_idx = kdtree.nn_search(dest);

        decltype(fixed) target(nerghbor_idx.size());
        for(size_t j = 0; j < nerghbor_idx.size(); j++)
        {
            target[j] = fixed[nerghbor_idx[j]];

            // std::cout << dest[j].transpose() << ",    " << target[j].transpose() << std::endl;
            // std::cout << j << " -> " << nerghbor_idx[j] << std::endl;
        }

        auto [R, T] = calcu_transformatoin<DIM>(dest, target);

        std::cout << "R = " << std::endl;
        std::cout << R << std::endl << std::endl;
        std::cout << "T = " << std::endl;
        std::cout << T << std::endl << std::endl;
        
        for(size_t j = 0; j < dest.size(); j++)
        {
            dest[j] = R*dest[j] + T;
        }

        if(0)
            break;

        old_dest = dest;
    }
    return {dest, i};
}

}
```


-------------------------------

Updated on 2022-10-06 at 00:27:03 +0900
