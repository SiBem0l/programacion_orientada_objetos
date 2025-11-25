#include "Publicacion.hpp"
#include <iostream>
#include <stdexcept>

Publicacion::Publicacion(std::string titulo, std::string autor, Fecha fecha)
    : titulo(std::move(titulo)), autor(std::move(autor)), fechaPublicacion(fecha)
{
}

// Getters
const std::string &Publicacion::getTitulo() const
{
    return titulo;
}

const std::string &Publicacion::getAutor() const
{
    return autor;
}

Fecha Publicacion::getFechaPublicacion() const
{
    return fechaPublicacion;
}

Publicacion::dia_type Publicacion::getDiaPublicacion() const
{
    return fechaPublicacion.getDia();
}

Publicacion::mes_type Publicacion::getMesPublicacion() const
{
    return fechaPublicacion.getMes();
}

Publicacion::anio_type Publicacion::getAnioPublicacion() const
{
    return fechaPublicacion.getAnio();
}

void Publicacion::setTitulo(std::string t)
{
    titulo = std::move(t);
}

void Publicacion::setAutor(std::string a)
{
    autor = std::move(a);
}

void Publicacion::setFechaPublicacion(Fecha f)
{
    fechaPublicacion = std::move(f);
}

void Publicacion::setDiaPublicacion(dia_type dia)
{
    fechaPublicacion.setDia(dia);
}

void Publicacion::setMesPublicacion(mes_type mes)
{
    fechaPublicacion.setMes(mes);
}

void Publicacion::setAnioPublicacion(anio_type anio)
{
    fechaPublicacion.setAnio(anio);
}

static void guardarString(const std::string& s, std::ofstream &outStream)
{
    std::string::size_type lenght = s.size();
    outStream.write(reinterpret_cast<const char*>(&lenght), sizeof(lenght));
    outStream.write(s.data(), lenght);
}
void Publicacion::guardarBinario(std::ofstream &outStream) const
{
    if (outStream.fail())
    {
        throw std::runtime_error("Archivo no abrio para guardado de publicacion.");
    }

    guardarString(titulo, outStream);
    guardarString(autor, outStream);
    fechaPublicacion.guardadBinario(outStream);
}

static std::string leerString(std::ifstream &inStream)
{
    std::string s;
    std::string::size_type lenght;
    inStream.read(reinterpret_cast<char*>(&lenght), sizeof(lenght));
    s.resize(lenght);
    inStream.read(s.data(), lenght);

    return std::move(s);
}
std::unique_ptr<Publicacion> Publicacion::leerBinario(std::ifstream &inStream)
{
    if (inStream.fail())
    {
        throw std::runtime_error("Archivo no abrio para lecutra de publicacion.");
    }

    std::string titulo(leerString(inStream));
    std::string autor(leerString(inStream));
    Fecha fechaPublicacion(Fecha::leerBinario(inStream));

    return std::make_unique<Publicacion>(std::move(titulo),
                                         std::move(autor),
                                         fechaPublicacion);
}