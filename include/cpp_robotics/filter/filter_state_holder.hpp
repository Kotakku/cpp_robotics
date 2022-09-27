#pragma once

#include <tuple>
#include <optional>
#include <algorithm>

namespace cpp_robotics
{

/**
 * @brief フィルタの入力と計算を非同期にして最後の入力と出力を保持しておけるようにするクラス

 * 
 * @tparam BASE_FILTER_TYPE 
 */
template<class BASE_FILTER_TYPE>
class FilterStateHolder : public BASE_FILTER_TYPE
{
public:
    using BASE_FILTER_TYPE::BASE_FILTER_TYPE;
    void set_input(double u)
    {
        u_ = u;
    }

    double filtering()
    {
        y_ = BASE_FILTER_TYPE::filtering(u);
        return y_;
    }

    double u() const { return u_; }
    double y() const { return y_; }
private:
    double u_ = 0, y_ = 0;
};

}