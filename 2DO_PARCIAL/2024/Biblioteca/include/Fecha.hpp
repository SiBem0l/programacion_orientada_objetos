#ifndef FECHA_HPP
#define FECHA_HPP

#include <iostream>
#include <fstream> 

class Fecha {
public:
    using dia_type = unsigned char;
    using mes_type = unsigned char;
    using anio_type = unsigned int;

    Fecha(dia_type dia, mes_type mes, anio_type anio);

    bool operator<(const Fecha&) const;
    bool operator>(const Fecha&) const;
    Fecha operator+(const Fecha&) const;
    Fecha operator-(const Fecha&) const;

    void guardar(std::ofstream& outStream) const;
    static Fecha leer(std::ifstream& inStream);

    friend std::ostream& operator<<(std::ostream& outStream, const Fecha& fecha);

private:
    dia_type dia;
    mes_type mes;
    anio_type anio;
};

class FechaInvalida: public std::exception
{
    const char* what() const noexcept
    {
        return "Fecha invalida";
    } 
};


#endif // FECHA_HPP