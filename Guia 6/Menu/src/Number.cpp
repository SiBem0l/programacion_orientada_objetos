#include "Number.hpp"

// Define the errors classes for Number
const char* zeroDivision::what() const noexcept
{
    return "Zero division";
}

const char *outOfRange::what() const noexcept
{
    return "Out of range Number";
}

// Number class
Number::Number(NUMBER_TYPE val)
{
    if(val > -1000 && val < 1000)
    {
        value = val;
    }
    else
    {
        throw(outOfRange());
    }
}

Number Number::operator+(const Number &addend) const 
{
    return Number(value + addend.value);
}

Number Number::operator-(const Number &subtrahend) const 
{
    return Number(value - subtrahend.value);
}

Number Number::operator*(const Number &factor) const
{
    return Number(value * factor.value);
}

Number Number::operator/(const Number &divisor) const
{
    if(divisor.value == 0)
    {
        throw(zeroDivision());
    }
    return Number(value / divisor.value);
}

std::ostream &operator<<(std::ostream &out, const Number &num)
{
    out << num.value; 
    return out;
}
