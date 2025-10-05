#include "Camion.hpp"

Camion::Camion(std::string marca, std::string modelo, int anio, int capacidadCarga, int numEjes) : Vehiculo(marca, modelo, anio),
                                                                                                   capacidadCarga(capacidadCarga),
                                                                                                   numEjes(numEjes)
{
}

int Camion::getCapacidadCarga() const
{
    return capacidadCarga;
}

int Camion::getNumEjes() const
{
    return numEjes;
}

void Camion::print() const
{
    std::cout << "Marca: " << getMarca() << std::endl;
    std::cout << "Modelo: " << getModelo() << std::endl;
    std::cout << "Anio: " << getAnio() << std::endl;
    std::cout << "Capacidad de carga: " << getCapacidadCarga() << " toneladas" << std::endl;
    std::cout << "Numero de ejes: " << getNumEjes() << std::endl;
}