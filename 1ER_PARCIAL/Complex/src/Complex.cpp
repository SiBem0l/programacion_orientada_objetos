#include <iostream>
#include <math.h>
#include <iomanip>
#include "Complex.hpp"

// Constructor and copy
Complex::Complex(Cartesian z) : real(z.getX()),
                                imaginary(z.getY())
{
}

Complex::Complex(Polar z) : real(cos(z.getAngle()) * z.getModule()),
                            imaginary(sin(z.getAngle()) * z.getModule())
{
}

Complex::Complex(const Complex& z) : real(z.getReal()), imaginary(z.getImaginary())
{
}

// Getters and setters
COMPLEX_ELEMENT Complex::getReal() const
{
    return real;
}

COMPLEX_ELEMENT Complex::getImaginary() const
{
    return imaginary;
}

void Complex::setReal(COMPLEX_ELEMENT valueReal)
{
    real = valueReal;
}

void Complex::setImaginary(COMPLEX_ELEMENT valueImaginary)
{
    imaginary = valueImaginary;
}

// Functions
Complex Complex::conjugate() const
{
    return Complex(Cartesian(real, imaginary*(-1)));
}

// Operations
Complex Complex::operator+(const Complex &z) const
{
    return Complex(Cartesian(real + z.getReal(), imaginary + z.getImaginary()));
}

Complex Complex::operator-(const Complex &z) const
{
    return Complex(Cartesian(real - z.getReal(), imaginary - z.getImaginary()));
}

Complex Complex::operator*(const Complex &z) const
{
    Polar a = {getModule(), getPhase()};
    Polar b = {z.getModule(), z.getPhase()};
    return Complex(Polar(a.getModule() * b.getModule(), a.getAngle() + b.getAngle()));
}

Complex Complex::operator/(const Complex &z) const
{
    Polar a = {getModule(), getPhase()};
    Polar b = {z.getModule(), z.getPhase()};
    return Complex(Polar(a.getModule() / b.getModule(), a.getAngle() - b.getAngle()));
}

// Operations with reals
Complex Complex::operator+(const COMPLEX_ELEMENT &real) const
{
    Complex numComplex(Cartesian(real,0));
    return (*this) + numComplex;
}

Complex Complex::operator-(const COMPLEX_ELEMENT &real) const
{
    Complex numComplex(Cartesian(real,0));
    return (*this) - numComplex;
}

Complex Complex::operator*(const COMPLEX_ELEMENT &real) const
{
    Complex numComplex(Cartesian(real,0));
    return (*this) * numComplex;
}

Complex Complex::operator/(const COMPLEX_ELEMENT &real) const
{
    Complex numComplex(Cartesian(real,0));
    return (*this) / numComplex;
}

// Asignation operations
Complex &Complex::operator=(const Complex &z)
{
    real = z.getReal();
    imaginary = z.getImaginary();
    return *this;
}

Complex &Complex::operator+=(const Complex &z)
{
    *this = *this + z;
    return *this;
}

Complex &Complex::operator-=(const Complex &z)
{
    *this = *this - z;
    return *this;
}

Complex &Complex::operator*=(const Complex &z)
{
    *this = *this * z;
    return *this;
}

Complex &Complex::operator/=(const Complex &z)
{
    *this = *this / z;
    return *this;
}

// Polar
float Complex::getModule() const
{
    return pow(pow(getReal(), 2) + pow(getImaginary(), 2), 0.5);
}

float Complex::getPhase() const
{
    return atan2(getImaginary(), getReal());
}

void Complex::setModule(COMPLEX_ELEMENT module)
{
    COMPLEX_ELEMENT phase = getPhase();
    imaginary = sin(phase)*module;
    real = cos(phase)*module;
}

void Complex::setPhase(COMPLEX_ELEMENT phase)
{
    COMPLEX_ELEMENT module = getModule();
    imaginary = sin(phase)*module;
    real = cos(phase)*module;
}

// Console input-output
std::ostream& operator<<(std::ostream& outStream, const Complex& z)
{
    // Set fixed width and precision for consistent formatting
    outStream << std::fixed << std::setprecision(2);

    // Always reserve 8 characters for real part
    outStream << std::setw(8) << z.getReal();

    if (z.getImaginary() >= 0)
    {
        outStream << " + " << std::setw(8) << z.getImaginary() << "j";
    }
    else
    {
        outStream << " - " << std::setw(8) << -z.getImaginary() << "j";
    }

    return outStream;
}