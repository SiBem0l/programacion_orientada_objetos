#include "Coche.hpp"

Coche::Coche(Vehiculo vehiculo, int cantidadPuertas, std::string tipoCarroceria) : Vehiculo(vehiculo),
                                                                                   cantidadPuertas(cantidadPuertas),
                                                                                   tipoCarroceria(tipoCarroceria)
{
}

int Coche::getCantidadPuertas()
{
    return cantidadPuertas;
}

std::string Coche::getTipoCarroceria()
{
    return tipoCarroceria;
}

void Coche::print()
{
    Vehiculo::print();
    std::cout << "Cantidad de puertas: " << cantidadPuertas << std::endl;
    std::cout << "Tipo de carroceria: " << tipoCarroceria << std::endl;
}