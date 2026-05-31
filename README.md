# Orbital Simulation using Numerical ODE Solvers

This project simulates gravitational orbital motion using numerical methods for solving ODEs.

Implemented methods:

* Euler Method
* RK4 (Runge-Kutta 4th Order)

Rendering and visualization are done using SFML,C++.

---

# Features

* Orbital simulation under Newtonian gravity
* Euler method implementation
* RK4 implementation
* Real-time visualization using SFML
* Orbit trails
* Comparison of numerical stability for different methods and step sizes

---

# Mathematical Model

The state vector is defined as:

```math
s = (x, y, v_x, v_y)
```

The governing equations are:

```math
\frac{dx}{dt} = v_x
```

```math
\frac{dy}{dt} = v_y
```

```math
\frac{dv_x}{dt} = \frac{k\,dx}{r^3}
```

```math
\frac{dv_y}{dt} = \frac{k\,dy}{r^3}
```

where:

```math
r = \sqrt{dx^2 + dy^2}
```

---

# Numerical Methods

## Euler Method

The Euler update scheme is:

```math
s_{n+1} = s_n + h f(t_n,s_n)
```

Euler method is simple but accumulates numerical error over time.

---

## RK4 Method

RK4 uses four intermediate slope evaluations:

```math
k_1,\ k_2,\ k_3,\ k_4
```

to achieve significantly higher accuracy and stability.

The final update is:

```math
s_{n+1} = s_n + \frac16(k_1 + 2k_2 + 2k_3 + k_4)
```

---

# Project Structure

## objects.h

Contains the particle and gravity source classes.

## Physics.cpp / Physics.h

Defines the differential equations governing motion.

## Solver.cpp / Solver.h

Implements Euler and RK4 numerical solvers.

## SFML1.cpp

Handles rendering, simulation loop, orbit visualization, and user interaction.

---

# Numerical Stability Comparison

Different step sizes and numerical methods produce noticeably different orbital behavior.

Euler method with larger step sizes tends to accumulate error causing orbital drift and instability.

RK4 remains significantly more stable for comparable step sizes.

---

# Additional Notes

A PDF report discussing numerical ODE methods used in this project is included in the repository.

---

# Future Improvements(Maybe)

* N-body simulation
* 3D orbital mechanics
* GPU acceleration
