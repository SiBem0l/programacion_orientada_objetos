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

std::string Vehiculo::getMarca() const
{
    return marca;
}

std::string Vehiculo::getModelo() const
{
    return modelo;
}

int Vehiculo::getAnio() const
{
    return anio;
}