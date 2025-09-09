#include <iostream>
//#include "Persona.hpp"

int main()
{
    int* numero = new int(5);
    std::cout << *numero;
    
    delete(numero);
}
