#ifndef VEHICULO_HPP
#define VEHICULO_HPP

#include <iostream>
#include <string.h>

class Vehiculo
{
private:
    std::string marca;
    std::string modelo;
    int anio;
    
public:
    Vehiculo(std::string marca, std::string modelo, int anio);
    virtual ~Vehiculo();
    std::string getMarca();
    std::string getModelo();
    int getAnio();

    virtual void print();
};

#endif