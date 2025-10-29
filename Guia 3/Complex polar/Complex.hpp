#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex
{
    // Console input-output
    friend std::ostream &operator<<(std::ostream &outStream, Complex z);

private:
    int real;
    int imaginary;

public:
    // Constructor and copy
    Complex(const int newReal = 0, const int newImaginary = 0);
    Complex(const Complex &z);

    // Getters and setters
    int getReal() const;
    int getImaginary() const;
    void setReal(const int valueReal);
    void setImaginary(const int valueImaginary);

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