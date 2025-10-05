#ifndef COCHE_HPP
#define COCHE_HPP

#include <iostream>
#include <string.h>
#include "Vehiculo.hpp"

class Coche: public Vehiculo
{
private:
    int cantidadPuertas;
    std::string  tipoCarroceria;

public:
    Coche(Vehiculo v, int cantidadPuertas, std::string tipoCarroceria);
    int getCantidadPuertas();
    std::string getTipoCarroceria();

    void print() override;
};

#endif