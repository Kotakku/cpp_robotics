/******************************************************************************
Copyright (c) 2017, Alexander W. Winkler, ETH Zurich. All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Neither the name of ETH ZURICH nor the names of its contributors may be
      used to endorse or promote products derived from this software without
      specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ETH ZURICH BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

#include <iostream>

#include <ifopt/problem.h>
#include <ifopt/ipopt_solver.h>
#include <ifopt/test_vars_constr_cost.h>

using namespace ifopt;


class MyVariables : public VariableSet {
public:
  // Every variable set has a name, here "var_set1". this allows the constraints
  // and costs to define values and Jacobians specifically w.r.t this variable set.
  MyVariables() : MyVariables("var_set1") {};
  MyVariables(const std::string& name) : VariableSet(2, name)
  {
    // the initial values where the NLP starts iterating from
    x0_ = 0;
    x1_ = 0;
  }

  // Here is where you can transform the Eigen::Vector into whatever
  // internal representation of your variables you have (here two doubles, but
  // can also be complex classes such as splines, etc..
  void SetVariables(const VectorXd& x) override
  {
    x0_ = x(0);
    x1_ = x(1);
  };

  // Here is the reverse transformation from the internal representation to
  // to the Eigen::Vector
  VectorXd GetValues() const override
  {
    return Vector2d(x0_, x1_);
  };

  // Each variable has an upper and lower bound set here
  VecBound GetBounds() const override
  {
    VecBound bounds(GetRows());
    bounds.at(0) = Bounds(-1.0, 1.0);
    bounds.at(1) = NoBound;
    return bounds;
  }

private:
  double x0_, x1_;
};

int main()
{
  // 1. define the problem
  Problem nlp;
  nlp.AddVariableSet  (std::make_shared<MyVariables>());
  nlp.AddConstraintSet(std::make_shared<ExConstraint>());
  nlp.AddCostSet      (std::make_shared<ExCost>());
  // nlp.PrintCurrent();

  // 2. choose solver and options
  IpoptSolver ipopt;
  ipopt.SetOption("sb", "yes");
  ipopt.SetOption("print_level", 0);
  ipopt.SetOption("linear_solver", "mumps");
  ipopt.SetOption("jacobian_approximation", "exact");

  // 3 . solve
  ipopt.Solve(nlp);
  Eigen::VectorXd x = nlp.GetOptVariables()->GetValues();
  std::cout << x.transpose() << std::endl;

  // 4. test if solution correct
  double eps = 1e-5; //double precision
  assert(1.0-eps < x(0) && x(0) < 1.0+eps);
  assert(0.0-eps < x(1) && x(1) < 0.0+eps);
}
