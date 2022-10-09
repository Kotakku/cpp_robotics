#pragma once

namespace cpp_robotics
{

static double normalized_mjm_position(double t)
{
    double t3 = t * t * t;
    return ( ((6.0*t - 15.0)*t + 10.0)*t3 );
}

static double normalized_mjm_velocity(double t)
{
    double t2 = t * t;
    return ( ((30.0*t - 60.0)*t + 30.0)*t2 );
}

static double normalized_mjm_acceleration(double t)
{
    return ( ((120.0*t - 180.0)*t + 60.0)*t );
}

static double normalized_mjm_jerk(double t)
{
    return (360.0*t - 360.0)*t + 60.0;
}

}