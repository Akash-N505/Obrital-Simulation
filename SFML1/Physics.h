#pragma once

#include <array>
#include "objects.h"

using State = std::array<double, 4>;

using Kinematics =
State(*)(double,const State&,const GravitySource&);

// operator overloads
State operator*(double s, State a);

State operator*(State a, double s);

State operator+(State a, State b);

// differential equation
State equation(double t,
    const State& s,
    const GravitySource& source);