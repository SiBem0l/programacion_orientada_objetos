#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#define COMPLEX_ELEMENT float

class Complex
{
    // Console input-output
    friend std::ostream &operator<<(std::ostream &outStream, Complex z);

private:
    COMPLEX_ELEMENT real;
    COMPLEX_ELEMENT imaginary;

public:
    // Constructor and copy
    Complex(const COMPLEX_ELEMENT newReal = 0, const COMPLEX_ELEMENT newImaginary = 0);
    Complex(const Complex &z);

    // Getters and setters
    COMPLEX_ELEMENT getReal() const;
    COMPLEX_ELEMENT getImaginary() const;
    void setReal(const COMPLEX_ELEMENT valueReal);
    void setImaginary(const COMPLEX_ELEMENT valueImaginary);

    // Functions
    Complex getConjugate();

    // Operations
    Complex operator+(const Complex &z) const;
    Complex operator-(const Complex &z) const;
    Complex operator/(const Complex &z) const;
    Complex operator*(const Complex &z) const;

    // Asignation operations
    Complex &operator=(const Complex &z);
    Complex &operator+=(const Complex &z);
    Complex &operator-=(const Complex &z);
    Complex &operator*=(const Complex &z);
    Complex &operator/=(const Complex &z);
};

#endif