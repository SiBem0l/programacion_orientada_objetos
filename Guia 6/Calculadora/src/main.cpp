#include <iostream>
#include <exception>


#define NUMBER_TYPE float

// Define the errors as class
class zeroDivision : public std::exception
{
    const char* what() const noexcept override
    {
        return "Zero division";
    }
};
class outOfRange : public std::exception
{
    const char* what() const noexcept override
    {
        return "Out of range Number";
    }
};


class Number
{
    friend std::ostream& operator<<(std::ostream& out, const Number& num) { out << num.value; return out;}
private:
    NUMBER_TYPE value = 0;

public:
    Number(NUMBER_TYPE val)
    {
        if(-1000 < val && val < 1000)
        {
            value = val;
        }
        else
        {
            throw(outOfRange());
        }
    };
    Number operator+(const Number& addend) { return Number(value + addend.value); };
    Number operator-(const Number& subtrahend) { return Number(value - subtrahend.value); };
    Number operator*(const Number& factor) { return Number(value * factor.value); }
    Number operator/(const Number& divisor) 
    {
        if(divisor.value == 0)
        {
            throw(zeroDivision());
        }
        return Number(value / divisor.value);
    };
};

int main()
{
    // Division with zero
    try
    {
        std::cout << Number(1) / Number(2) << std::endl;
        std::cout << Number(1) / Number(0) << std::endl;
        std::cout << Number(1) / Number(4) << std::endl;
    }
    catch(std::exception& error)
    {
        std::cout << "Error: " << error.what() << std::endl;
    }

    // Out of range number
    try
    {
        std::cout << Number(6) * Number(2) << std::endl;
        std::cout << Number(1000) * Number(0) << std::endl;
        std::cout << Number(1000) * Number(4) << std::endl;
    }
    catch(std::exception& error)
    {
        std::cout << "Error: " << error.what() << std::endl;
    }

    return 0;
}
