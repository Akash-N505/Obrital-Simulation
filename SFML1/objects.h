#pragma once

class GravitySource
{
public:

    double mass;
    double Position_X;
    double Position_Y;

    GravitySource(double mass,
        double Position_X,
        double Position_Y)
    {
        this->mass = mass;
        this->Position_X = Position_X;
        this->Position_Y = Position_Y;
    }
};

class GravityParticle
{
public:

    double mass;
    double Position_X;
    double Position_Y;
    double Velocity_X;
    double Velocity_Y;

    GravityParticle(double mass,
        double Position_X,
        double Position_Y,
        double Velocity_X,
        double Velocity_Y)
    {
        this->mass = mass;
        this->Position_X = Position_X;
        this->Position_Y = Position_Y;
        this->Velocity_X = Velocity_X;
        this->Velocity_Y = Velocity_Y;
    }
};