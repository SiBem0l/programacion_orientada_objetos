#include <iostream>
#include "Fecha.hpp"

int main()
{
    Fecha birth(18, 12, 2003);
    Fecha today(25, 11, 2025);
    Fecha birthLimit(today - Fecha(0, 0, 18));

    if(birth < birthLimit)
    {
        std::cout << "You are over 18!" << std::endl;
    }
    else
    {
        std::cout << "You are under 18!" << std::endl;
    }
    
}