#include "Fecha.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>

Fecha::Fecha(dia_type d, mes_type m, anio_type a)
    : dia(d), mes(m), anio(a)
{
    if(d > 31 || m > 12)
    {
        // throw FechaInvalida("Constructor");
    }
}

bool Fecha::operator<(const Fecha& fecha) const
{
    return (anio < fecha.anio) ||
           (anio == fecha.anio && mes < fecha.mes) ||
           (anio == fecha.anio && mes == fecha.mes && dia < fecha.dia);
}

bool Fecha::operator>(const Fecha& fecha) const
{
    return (anio > fecha.anio) ||
           (anio == fecha.anio && mes > fecha.mes) ||
           (anio == fecha.anio && mes == fecha.mes && dia > fecha.dia);
}

Fecha Fecha::operator+(const Fecha& fecha) const
{
    return Fecha(dia + fecha.dia, mes + fecha.mes, anio + fecha.anio);
}

Fecha Fecha::operator-(const Fecha& fecha) const
{
    return Fecha(dia - fecha.dia, mes - fecha.mes, anio - fecha.anio);
}

void Fecha::guardar(std::ofstream &outStream) const
{
    if (outStream.fail())
    {
        throw std::runtime_error("Archivo no abrio para guardado de fecha.");
    }

    outStream.write(reinterpret_cast<const char *>(&dia), sizeof(dia));
    outStream.write(reinterpret_cast<const char *>(&mes), sizeof(mes));
    outStream.write(reinterpret_cast<const char *>(&anio), sizeof(anio));
}

Fecha Fecha::leer(std::ifstream &inStream)
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

std::ostream& operator<<(std::ostream& outStream, const Fecha& fecha)
{
    return outStream << fecha.dia << '/' << fecha.mes << '/' << fecha.anio;
}