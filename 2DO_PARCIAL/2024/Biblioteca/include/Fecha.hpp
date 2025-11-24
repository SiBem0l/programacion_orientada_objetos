#ifndef FECHA_HPP
#define FECHA_HPP

#include <fstream>

class Fecha
{
private:
    // Atributos privados
    int dia;
    int mes;
    int anio;

public:
    // Constructor
    Fecha(const int dia, const int mes, const int anio);

    // Getters
    int getDia() const;
    int getMes() const;
    int getAnio() const;

    // Setters
    void setDia(const int dia);
    void setMes(const int mes);
    void setAnio(const int anio);

    // File managment
    void storeBinary(std::ofstream& outStream);
    void readBinary(std::ifstream& inStream);
};

#endif // FECHA_HPP