#include <iostream>
#include "Employee.hpp"

int main()
{
    Employee first_employee("Julian", "Llinares", Date(18, 12, 2003), Date(8, 9, 2025));
    std::cout << first_employee << std::endl;

    std::cout<< "hola" << std::endl;
    
    return 0;
}
