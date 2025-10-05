#ifndef CAMION_HPP
#define CAMION_HPP

#include "Vehiculo.hpp"

class Camion : public Vehiculo
{
private:
    int capacidadCarga; // en toneladas
    int numEjes;
public:
    Camion(Vehiculo vehiculo, int capacidadCarga, int numEjes);
    int getCapacidadCarga();
    int getNumEjes();
    
    void print() override;
};

#endif