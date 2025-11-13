#ifndef NUMERO_HPP
#define NUMERO_HPP

#include <iostream>
#include <execution>

#define NUMBER_TYPE float

// Define the errors as class
class zeroDivision : public std::exception
{
    const char* what() const noexcept override;
};
class outOfRange : public std::exception
{
    const char* what() const noexcept override;
};


class Number
{
    friend std::ostream& operator<<(std::ostream& out, const Number& num);
private:
    NUMBER_TYPE value;

public:
    Number(NUMBER_TYPE val = 0);

    Number operator+(const Number& addend) const;
    Number operator-(const Number& subtrahend) const;
    Number operator*(const Number& factor) const;
    Number operator/(const Number& divisor) const;
};

#endif