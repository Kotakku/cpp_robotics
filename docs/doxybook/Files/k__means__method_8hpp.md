---
title: include/cpp_robotics/algorithm/k_means_method.hpp

---

# include/cpp_robotics/algorithm/k_means_method.hpp



## Namespaces

| Name           |
| -------------- |
| **[cpp_robotics](/cpp_robotics/doxybook/Namespaces/namespacecpp__robotics/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[cpp_robotics::KMeansMethod](/cpp_robotics/doxybook/Classes/classcpp__robotics_1_1KMeansMethod/)** <br>K-means法  |




## Source code

```cpp
#pragma once

#include <cpp_robotics/algorithm/kdtree.hpp>
#include <numeric>
#include <algorithm>

namespace cpp_robotics
{

template<class PointType>
class KMeansMethod
{
public:
    using point_t = PointType;
    KMeansMethod() = default;

    std::vector<size_t> fit(std::vector<point_t> &data_set, size_t cluster_size, size_t max_iter = 1000)
    {
        cluster_size_ = cluster_size;
        point_t zero_point = get_zero_point(data_set[0]);
        label_.resize(data_set.size());
        std::vector<size_t> prev_label(data_set.size(), 0);

        // ラベルの初期値生成
        size_t cnt = 0;
        for(auto &label : label_)
        {
            label = cnt++;
            cnt %= cluster_size_;
        }

        cluster_center_.resize(cluster_size_);
        
        for(size_t i = 0; i < max_iter; i++)
        {
            // クラスタの重心を計算
            std::vector<std::vector<point_t>> dist_(cluster_size_);
            for(auto &dist_item : dist_)
            {
                dist_item.reserve(data_set.size() / cluster_size_);
            }
            for(size_t p_idx = 0; p_idx < data_set.size(); p_idx++)
            {
                dist_[label_[p_idx]].push_back(data_set[p_idx]);
            }
            for(size_t c_idx = 0; c_idx < cluster_size_; c_idx++)
            {
                cluster_center_[c_idx] = std::accumulate(dist_[c_idx].begin(), dist_[c_idx].end(), zero_point) / (double)dist_[c_idx].size();
            }

            // 総当りでラベルを各クラスタ重心に近いものに変更する
            for(size_t p_idx = 0; p_idx < data_set.size(); p_idx++)
            {
                label_[p_idx] = predict(data_set[p_idx]);
            }

            // ラベルが変化しなかったらクラスタリングを終了
            if(prev_label == label_)
                break;
        }

        return label_;
    }

    size_t predict(const point_t &x)
    {
        auto min_itr = std::min_element(cluster_center_.begin(), cluster_center_.end(), [&](auto &a, auto &b){
            return (a-x).norm() < (b-x).norm();
        });
        return std::distance(cluster_center_.begin(), min_itr);
    }

private:
    point_t get_zero_point(const point_t &tmp)
    {
        (void) tmp;
        return point_t();
    }

private:
    std::vector<size_t> label_;
    std::vector<point_t> cluster_center_;
    size_t cluster_size_;
};

// 動的なEigenのベクトルは初期化時にデータの実態を持たないので特殊化
template<>
Eigen::VectorXd KMeansMethod<Eigen::VectorXd>::get_zero_point(const Eigen::VectorXd &tmp)
{
    return Eigen::VectorXd::Zero(tmp.size());
}

}
```


-------------------------------

Updated on 2022-10-06 at 00:27:03 +0900
