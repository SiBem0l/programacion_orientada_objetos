#include <iostream>
#include <cmath>
#include "Complex.hpp"

// Constructor and copy
Complex::Complex(const COMPLEX_ELEMENT newReal, const COMPLEX_ELEMENT newImaginary) : real(newReal),
                                                                                      imaginary(newImaginary)
{
}

Complex::Complex(const Complex &z) : real(z.real),
                                     imaginary(z.imaginary)
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

void Complex::setReal(const COMPLEX_ELEMENT valueReal)
{
    real = valueReal;
}

void Complex::setImaginary(const COMPLEX_ELEMENT valueImaginary)
{
    imaginary = valueImaginary;
}

// Functions
Complex Complex::getConjugate()
{
    return Complex(real, imaginary*(-1));
}

// Operations
Complex Complex::operator+(const Complex &z) const
{
    return Complex(real + z.real, imaginary + z.imaginary);
}

Complex Complex::operator-(const Complex &z) const
{
    return Complex(real - z.real, imaginary - z.imaginary);
}

Complex Complex::operator*(const Complex &z) const
{
    return Complex(real*z.real - imaginary*z.imaginary, real*z.imaginary + imaginary*z.real);
}

Complex Complex::operator/(const Complex &z2) const
{
    const Complex &z1 = *this;
    Complex ans(z1*z2);
    COMPLEX_ELEMENT denominador = (z2.real)^2 - (z2.imaginary)^2;
    ans.real = ans.real/denominador;
    ans.imaginary = ans.imaginary/denominador;    
    return ans;
}

// Asignation operations
Complex &Complex::operator=(const Complex &z)
{
    real = z.real;
    imaginary = z.imaginary;
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

// Console input-output
std::ostream &operator<<(std::ostream &outStream, Complex z)
{
    outStream << z.real << " + " << z.imaginary << " j";
    return outStream;
}