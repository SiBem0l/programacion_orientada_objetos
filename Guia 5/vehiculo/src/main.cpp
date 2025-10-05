#include <iostream>
#include "Vehiculo.hpp"
#include "Coche.hpp"
#include "Camion.hpp"

int main() 
{   
    Vehiculo* vehiculos[2];
    vehiculos[0] = new Coche(Vehiculo("Volkswagen", "Voyage", 2016), 5, "Sedan");
    vehiculos[1] = new Camion(Vehiculo("Scania", "113", 1990), 66, 3);

    for(int i = 0; i < 2; i++)
    {
        vehiculos[i]->print();
        std::cout << std::endl;
    }

    return 0;
}