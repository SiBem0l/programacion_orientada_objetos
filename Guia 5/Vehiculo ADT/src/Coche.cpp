#include "Coche.hpp"

Coche::Coche(std::string marca, std::string modelo, int anio, int cantidadPuertas, std::string tipoCarroceria) : Vehiculo(marca, modelo, anio),
                                                                                                                 cantidadPuertas(cantidadPuertas),
                                                                                                                 tipoCarroceria(tipoCarroceria)
{
}

int Coche::getCantidadPuertas() const
{
    return cantidadPuertas;
}

std::string Coche::getTipoCarroceria() const
{
    return tipoCarroceria;
}

void Coche::print() const
{
    std::cout << "Marca: " << getMarca() << std::endl;
    std::cout << "Modelo: " << getModelo() << std::endl;
    std::cout << "Anio: " << getAnio() << std::endl;
    std::cout << "Cantidad de puertas: " << cantidadPuertas << std::endl;
    std::cout << "Tipo de carroceria: " << tipoCarroceria << std::endl;
}