#ifndef MULTIPLY_NUMBERS_HPP
#define MULTIPLY_NUMBERS_HPP

#include "MenuItem.hpp"
#include "Calculator.hpp"

class MultiplyNumbers : public MenuItem
{
private: 
    Calculator& calculator;

public:
    MultiplyNumbers(Calculator& calc) : calculator(calc) {}
    
    + execute() override: void
    + name() const override: const &string
};

#endif