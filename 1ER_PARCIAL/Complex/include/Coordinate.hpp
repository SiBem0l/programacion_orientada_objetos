#ifndef COORDINATE_H
#define COORDINATE_H

#define PI 3.14159265358979323846
#define COORDINATE_ELEMENT float

class Polar
{
private:
    COORDINATE_ELEMENT module;
    COORDINATE_ELEMENT angle;
public:
    Polar(COORDINATE_ELEMENT newModule, COORDINATE_ELEMENT newAngle);

    void setModule(COORDINATE_ELEMENT newModule);
    void setAngle(COORDINATE_ELEMENT newAngle);
    void setPolar(COORDINATE_ELEMENT newModule, COORDINATE_ELEMENT newAngle);

    COORDINATE_ELEMENT getModule() const;
    COORDINATE_ELEMENT getAngle() const;
    COORDINATE_ELEMENT getAngleDegree() const;
};

class Cartesian
{
private:
    COORDINATE_ELEMENT x;
    COORDINATE_ELEMENT y;
public:
    Cartesian(COORDINATE_ELEMENT newX, COORDINATE_ELEMENT newY);

    void setX(COORDINATE_ELEMENT newX);
    void setY(COORDINATE_ELEMENT newY);
    void setPolar(COORDINATE_ELEMENT newX, COORDINATE_ELEMENT newY);

    COORDINATE_ELEMENT getX() const;
    COORDINATE_ELEMENT getY() const;
};

#endif