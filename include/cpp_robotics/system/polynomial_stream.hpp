#include "polynomial.hpp"
#include <iostream>

namespace cpp_robotics
{

static std::ostream& operator << (std::ostream& os, const Polynomial& v)
{
    os << "( ";

    bool is_outputed = false;
    for(size_t i = 0; i < v.size(); i++)
    {
        double coeff = v.coeff()[i];
        size_t deg = v.degree() - i;
        if(coeff != 0)
        {
            if(is_outputed)
            {
                if(coeff >= 0)
                    os << " + ";
                else
                    os << " - ";
            }
            
            os << std::abs(coeff);
            if(deg > 0)
                os << "x^" + std::to_string(deg);

            is_outputed = true;
        }
    }
    
    os << " )";
    return os;
}

} // namespace cpp_robotics