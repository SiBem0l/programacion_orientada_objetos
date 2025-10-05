#include "Camion.hpp"

Camion::Camion(Vehiculo vehiculo, int capacidadCarga, int numEjes) : Vehiculo(vehiculo),
                                                                     capacidadCarga(capacidadCarga),
                                                                     numEjes(numEjes)
{
}

int Camion::getCapacidadCarga()
{
    return capacidadCarga;
}

int Camion::getNumEjes()
{
    return numEjes;
}

void Camion::print()
{
    Vehiculo::print();
    std::cout << "Capacidad de carga: " << getCapacidadCarga() << " toneladas" << std::endl;
    std::cout << "Numero de ejes: " << getNumEjes() << std::endl;
}