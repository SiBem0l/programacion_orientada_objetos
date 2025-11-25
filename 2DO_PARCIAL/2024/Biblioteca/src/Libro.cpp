#include "Libro.hpp"

Libro::Libro(std::string titulo, std::string autor, Fecha fecha)
    : Publicacion(std::move(titulo), std::move(autor), fecha)
{}

void Libro::guardarBinario(std::ofstream &outStream) const
{
    if (outStream.fail())
    {
        throw std::runtime_error("Archivo no abrio para guardado de Libro.");
    }

    

}
static std::unique_ptr<Publicacion> leerBinario(std::ifstream &inStream);