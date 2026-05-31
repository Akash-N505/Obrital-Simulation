#include <cmath>
#include <array>
#include <iostream>
#include "objects.h"
#include <vector>

using State = std::array<double, 4>;
using Kinematics = State(*)(double, const State&, const GravitySource& );//makes it easier while we input function 

//overloading operators to handle our state vector easier
State operator*(double s,State a)
{
	return { a[0] * s ,a[1] * s , a[2] * s, a[3] * s };

}
State operator*(State a, double s)
{
	return { a[0] * s ,a[1] * s , a[2] * s, a[3] * s };
}
State operator+(State a, State b)
{
	return { a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3] };
}




//our equation which we are gonna input into our solver, this will basically be our intial state which will be upadated using solver later
State equation(double t,
    const State& s,
    const GravitySource& source)
{
    
   double k = 150000.0;
    

    double x = s[0];
    double y = s[1];
    double vx = s[2];
    double vy = s[3];

    double dx = source.Position_X - x;
    double dy = source.Position_Y - y;

    double r = std::hypot(dx, dy);

    double gx = k * dx / (r * r * r);
    double gy = k * dy / (r * r * r);

    return {vx, vy, gx, gy};
}


