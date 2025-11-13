#include "Calculator.hpp"

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
	// Delete the numbers stored on the heap
	for(auto number : numbers)
	{
		delete number;
	}
}

void Calculator::addNumber(Number* num)
{
	numbers.push_back(num);
}

Number Calculator::sumNumbers() const
{
	Number sum(0);
	for(Number *num : numbers)
	{
		sum = sum + *num;
	}
	return sum;
}

Number Calculator::multiplyNumbers() const
{
	Number ans(1);
	for(Number *num : numbers)
	{
		ans = ans * *num;
	}
	return ans;
}