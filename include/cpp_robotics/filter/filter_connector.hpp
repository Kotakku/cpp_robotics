#pragma once

#include <cmath>
#include <array>
#include <variant>

namespace cpp_robotics
{

template<class ...FILTER_TYPE>
class FilterConnector
{
public:
    static constexpr size_t filter_count = sizeof...(FILTER_TYPE);
    using variant_type = std::variant<FILTER_TYPE...>;

    FilterConnector()
    {
        
    }

private:
    std::array<variant_type, filter_count> filters_;
};

}