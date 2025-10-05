#ifndef COCHE_HPP
#define COCHE_HPP

#include <iostream>
#include <string.h>
#include "Vehiculo.hpp"

class Coche: public Vehiculo
{
private:
    int cantidadPuertas;
    std::string tipoCarroceria;

public:
    Coche(std::string marca, std::string modelo, int anio, int cantidadPuertas, std::string tipoCarroceria);
    int getCantidadPuertas() const;
    std::string getTipoCarroceria() const;

    void print() const override;
};

#endif