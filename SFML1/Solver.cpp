#include "Physics.h"
#include "objects.h"

State RK4(Kinematics f,double h,double t,const State& s,const GravitySource& source)

{
    State k1 = h * f(t, s, source);
	State k2 = h * f(t + 0.5 * h, s + 0.5 * k1, source);
	State k3 = h * f(t + 0.5 * h, s + 0.5 * k2, source);
	State k4 = h * f(t+h, s+k3, source);

	return s + (1.0 / 6.0) * (k1 + (2.0 * k2) + (2.0 * k3) + k4);
}

State euler(Kinematics f, double h, double t, const State& s, const GravitySource& source)
{
	return s + h * f(t, s, source);
}

