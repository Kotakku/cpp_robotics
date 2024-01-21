#pragma once

#include <cpp_robotics/controller/ocp_dynamics.hpp>
#include <cpp_robotics/controller/ocp_cost.hpp>
#include <cpp_robotics/controller/ocp_constraint.hpp>

namespace cpp_robotics
{

class OptimalControlProblem
{
public:
    std::shared_ptr<OCPDynamics> dynamics;
    std::shared_ptr<OCPCost> cost;
    OCPConstraintArray constraints;

    OptimalControlProblem() = default;
    OptimalControlProblem(OCPDynamics::SharedPtr dynamics, OCPCost::SharedPtr cost):
        dynamics(dynamics), cost(cost) {}
    OptimalControlProblem(OCPDynamics::SharedPtr dynamics, OCPCost::SharedPtr cost, const OCPConstraintArray &constraints):
        dynamics(dynamics), cost(cost), constraints(constraints) {}

    size_t input_size() const { return dynamics->input_size(); }
    size_t state_size() const { return dynamics->state_size(); }
    size_t horizon() const { return cost->horizon(); }

};

}