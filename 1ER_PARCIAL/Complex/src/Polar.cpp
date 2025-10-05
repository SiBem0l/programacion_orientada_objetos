#include "Coordinate.hpp"

// Constructor
Polar::Polar(COORDINATE_ELEMENT newModule, COORDINATE_ELEMENT newAngle) : module(newModule), angle(newAngle) {}

// Setters
void Polar::setModule(COORDINATE_ELEMENT newModule)
{
    module = newModule;
}

void Polar::setAngle(COORDINATE_ELEMENT newAngle)
{
    angle = newAngle;
}

void Polar::setPolar(COORDINATE_ELEMENT newModule, COORDINATE_ELEMENT newAngle)
{
    module = newModule;
    angle = newAngle;
}

// Getters
COORDINATE_ELEMENT Polar::getModule() const
{
    return module;
}

COORDINATE_ELEMENT Polar::getAngle() const
{
    return angle;
}

COORDINATE_ELEMENT Polar::getAngleDegree() const
{
    return getAngle() * 180.0 / PI;
}