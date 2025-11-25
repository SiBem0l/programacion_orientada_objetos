#include "Fecha.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

Fecha::Fecha(dia_type d, mes_type m, anio_type a)
    : dia(d), mes(m), anio(a)
{
}

Fecha::dia_type Fecha::getDia() const
{
    return dia;
}

Fecha::mes_type Fecha::getMes() const
{
    return mes;
}

Fecha::anio_type Fecha::getAnio() const
{
    return anio;
}

void Fecha::setDia(dia_type nuevoDia)
{
    dia = nuevoDia;
}

void Fecha::setMes(mes_type nuevoMes)
{
    mes = nuevoMes;
}

void Fecha::setAnio(anio_type nuevoAnio)
{
    anio = nuevoAnio;
}

void Fecha::guardadBinario(std::ofstream &outStream) const
{
    if (outStream.fail())
    {
        throw std::runtime_error("Archivo no abrio para guardado de fecha.");
    }

    outStream.write(reinterpret_cast<const char *>(&dia), sizeof(dia));
    outStream.write(reinterpret_cast<const char *>(&mes), sizeof(mes));
    outStream.write(reinterpret_cast<const char *>(&anio), sizeof(anio));
}

Fecha Fecha::leerBinario(std::ifstream &inStream)
{
    if (inStream.fail())
    {
        throw std::runtime_error("Archivo no abrio para lectura de fecha.");
    }

    dia_type dia;
    mes_type mes;
    anio_type anio;
    inStream.read(reinterpret_cast<char *>(&dia), sizeof(dia));
    inStream.read(reinterpret_cast<char *>(&mes), sizeof(mes));
    inStream.read(reinterpret_cast<char *>(&anio), sizeof(anio));

    return Fecha(dia, mes, anio);
}