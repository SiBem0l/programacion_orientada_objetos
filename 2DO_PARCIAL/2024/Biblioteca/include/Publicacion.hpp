#ifndef PUBLICACION_HPP
#define PUBLICACION_HPP

#include <string>
#include <fstream>
#include <memory>
#include "Fecha.hpp"

class Publicacion
{
private:
    std::string titulo;
    std::string autor;
    Fecha fechaPublicacion;

protected:
    Publicacion(std::string titulo, std::string autor, Fecha fechaPublicacion);

public:
    using dia_type = Fecha::dia_type;
    using mes_type = Fecha::mes_type;
    using anio_type = Fecha::anio_type;

    const std::string &getTitulo() const;
    const std::string &getAutor() const;
    Fecha getFechaPublicacion() const;
    dia_type getDiaPublicacion() const;
    mes_type getMesPublicacion() const;
    anio_type getAnioPublicacion() const;

    void setTitulo(std::string titulo);
    void setAutor(std::string autor);
    void setFechaPublicacion(Fecha fecha);
    void setDiaPublicacion(dia_type dia);
    void setMesPublicacion(mes_type mes);
    void setAnioPublicacion(anio_type anio);

    virtual void guardarBinario(std::ofstream &outStream) const;
    static std::unique_ptr<Publicacion> leerBinario(std::ifstream &inStream);

    static void guardarString(const std::string &s, std::ofstream &outStream);
};

#endif // PUBLICACION_HPP