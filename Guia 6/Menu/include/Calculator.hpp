#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "Number.hpp"
#include <list>

class Calculator
{
private:
    std::list<Number*> numbers;
    int nNumbers = 0;

public:
    Calculator();
    ~Calculator();

    void addNumber(Number*);

    Number sumNumbers() const;
    Number multiplyNumbers() const;
};

#endif