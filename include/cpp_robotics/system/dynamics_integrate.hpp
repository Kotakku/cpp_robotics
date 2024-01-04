#pragma once

#include <functional>

namespace cpp_robotics
{

template<class T>
static T integrate_forward_euler(double dt, const T &x, const T &u, std::function<T(const T&, const T&)> dynamics)
{
    return x + dt*dynamics(x, u);
}

template<class T>
static T integrate_modified_euler(double dt, const T &x, const T &u, std::function<T(const T&, const T&)> dynamics)
{
    T k1 = dynamics(x, u);
    T k2 = dynamics(x+dt*k1, u);
    
    return x + dt*(k1+k2)/2;
}

template<class T>
static T integrate_rk4(double dt, const T &x, const T &u, std::function<T(const T&, const T&)> dynamics)
{
    T k1 = dynamics(x, u);
    T k2 = dynamics(x + dt / 2 * k1, u);
    T k3 = dynamics(x + dt / 2 * k2, u);
    T k4 = dynamics(x + dt * k3, u);
    return x + dt / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
}

}