#pragma once
#include "objects.h"
#include "Physics.h"
State RK4(Kinematics f, double h, double t, const State& s, const GravitySource& source);
State euler(Kinematics f,double h,double t,const State& s,const GravitySource& source);