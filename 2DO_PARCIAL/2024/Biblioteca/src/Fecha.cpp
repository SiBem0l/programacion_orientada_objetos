#include "Fecha.hpp"

// Constructor
Fecha::Fecha(const int dia, const int mes, const int anio)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

// Getters
int Fecha::getDia() const
{
    return this->dia;
}

int Fecha::getMes() const
{
    return this->mes;
}

int Fecha::getAnio() const
{
    return this->anio;
}

// Setters
void Fecha::setDia(const int dia)
{
    this->dia = dia;
}

void Fecha::setMes(const int mes)
{
    this->mes = mes;
}

void Fecha::setAnio(const int anio)
{
    this->anio = anio;
}

// File managment
void Fecha::storeBinary(std::ofstream& outStream)
{
    outStream.write(reinterpret_cast<char*>(&dia), sizeof(int));
    outStream.write(reinterpret_cast<char*>(&mes), sizeof(int));
    outStream.write(reinterpret_cast<char*>(&anio), sizeof(int));
}
void Fecha::readBinary(std::ifstream& inStream)
{
    inStream.read(reinterpret_cast<char*>(&dia), sizeof(int));
    inStream.read(reinterpret_cast<char*>(&mes), sizeof(int));
    inStream.read(reinterpret_cast<char*>(&anio), sizeof(int));
}