#ifndef TEXTO_HPP
#define TEXTO_HPP

#include <fstream>
#include "Fecha.hpp"

class Texto
{
private:
    std::string m_titulo;
    std::string m_autor;
    Fecha m_fechaPublicacion;

public:
    Texto(const std::string& titulo, const std::string& autor, const Fecha& fecha);
    
    void storeBinary(std::ofstream& outStream);
    void readBinary(std::ifstream& inStream);
};

#endif