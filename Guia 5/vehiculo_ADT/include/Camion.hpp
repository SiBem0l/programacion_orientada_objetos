#ifndef CAMION_HPP
#define CAMION_HPP

#include "Vehiculo.hpp"

class Camion : public Vehiculo
{
private:
    int capacidadCarga; // en toneladas
    int numEjes;
public:
    Camion(std::string marca, std::string modelo, int anio, int capacidadCarga, int numEjes);
    int getCapacidadCarga() const;
    int getNumEjes() const;
    
    void print() const override;
};

#endif