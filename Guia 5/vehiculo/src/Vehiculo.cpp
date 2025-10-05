#include "Vehiculo.hpp"
#include <iostream>
#include <string.h>

Vehiculo::Vehiculo(std::string marca, std::string modelo, int anio) : marca(marca),
                                                                      modelo(modelo),
                                                                      anio(anio)
{
}

Vehiculo::~Vehiculo()
{
}

std::string Vehiculo::getMarca()
{
    return marca;
}

std::string Vehiculo::getModelo()
{
    return modelo;
}

int Vehiculo::getAnio()
{
    return anio;
}

void Vehiculo::print()
{
    std::cout << "Marca: " << getMarca() << std::endl;
    std::cout << "Modelo: " << getModelo() << std::endl;
    std::cout << "Anio: " << getAnio() << std::endl;
}