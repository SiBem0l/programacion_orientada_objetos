#ifndef FECHA_HPP
#define FECHA_HPP

#include <fstream> 

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    using dia_type = char;
    using mes_type = char;
    using anio_type = int;

    Fecha(dia_type dia, mes_type mes, anio_type anio);

    dia_type getDia() const;
    mes_type getMes() const;
    anio_type getAnio() const;

    void setDia(dia_type nuevoDia);
    void setMes(mes_type nuevoMes);
    void setAnio(anio_type nuevoAnio);

    void guardadBinario(std::ofstream& outStream) const;
    static Fecha leerBinario(std::ifstream& inStream);
};

#endif // FECHA_HPP