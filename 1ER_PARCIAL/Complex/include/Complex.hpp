#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include "Coordinate.hpp"
#define COMPLEX_ELEMENT COORDINATE_ELEMENT

class Complex
{
    // Console input-output
    friend std::ostream &operator<<(std::ostream &outStream, const Complex &z);

private:
    COMPLEX_ELEMENT real;
    COMPLEX_ELEMENT imaginary;

public:
    // Constructor and copy
    Complex(Cartesian z);
    Complex(Polar z);
    Complex(const Complex &z);

    // Getters and setters
    COMPLEX_ELEMENT getReal() const;
    COMPLEX_ELEMENT getImaginary() const;
    void setReal(COMPLEX_ELEMENT valueReal);
    void setImaginary(COMPLEX_ELEMENT valueImaginary);

    // Functions
    Complex conjugate() const;

    // Operations with Complex
    Complex operator+(const Complex &z) const;
    Complex operator-(const Complex &z) const;
    Complex operator/(const Complex &z) const;
    Complex operator*(const Complex &z) const;

    // Operations with Reals
    Complex operator+(const COMPLEX_ELEMENT& real) const;
    Complex operator-(const COMPLEX_ELEMENT& real) const;
    Complex operator/(const COMPLEX_ELEMENT& real) const;
    Complex operator*(const COMPLEX_ELEMENT& real) const;

    // Asignation operations
    Complex &operator=(const Complex &z);
    Complex &operator+=(const Complex &z);
    Complex &operator-=(const Complex &z);
    Complex &operator*=(const Complex &z);
    Complex &operator/=(const Complex &z);

    // Polar
    float getModule() const;
    float getPhase() const;
    void setModule(COMPLEX_ELEMENT module);
    void setPhase(COMPLEX_ELEMENT phase);
};

#endif