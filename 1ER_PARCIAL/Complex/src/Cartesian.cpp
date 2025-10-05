#include "Coordinate.hpp"

// Constructor
Cartesian::Cartesian(COORDINATE_ELEMENT newX, COORDINATE_ELEMENT newY) : x(newX), y(newY) {}

// Setters
void Cartesian::setX(COORDINATE_ELEMENT newX)
{
    x = newX;
}

void Cartesian::setY(COORDINATE_ELEMENT newY)
{
    y = newY;
}

void Cartesian::setPolar(COORDINATE_ELEMENT newX, COORDINATE_ELEMENT newY)
{
    x = newX;
    y = newY;
}

// Getters
COORDINATE_ELEMENT Cartesian::getX() const
{
    return x;
}

COORDINATE_ELEMENT Cartesian::getY() const
{
    return y;
}
