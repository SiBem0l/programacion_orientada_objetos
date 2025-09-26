#include <iostream>
#include "Complex.hpp"

int main()
{
    Complex a(1,2);
    Complex b(4,5);

    Complex z = a / b;
    std::cout << z << std::endl;
}