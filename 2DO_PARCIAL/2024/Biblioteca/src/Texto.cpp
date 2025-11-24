#include "Texto.hpp"

Texto::Texto(const std::string &titulo, const std::string &autor, const Fecha &fecha) : m_titulo(titulo),
                                                                                        m_autor(autor),
                                                                                        m_fechaPublicacion(fecha)
{
}

static void storeString(std::string& str, std::ofstream &outStream)
{
    // using std::string::size_type type;
    outStream.write(reinterpret_cast<type*>(&(str.size())), sizeof(std::string::size_type));
    outStream.write(str.data(), str.size()+1);
}
void Texto::storeBinary(std::ofstream &outStream)
{
    storeString(m_titulo, outStream);
    storeString(m_autor, outStream);
    m_fechaPublicacion.storeBinary(outStream);
}

static void readString(std::string& str, std::ifstream &inStream)
{
    inStream.read()
}
void Texto::readBinary(std::ifstream &inStream)
{
    readString(m_titulo, inStream);
    readString(m_autor, inStream);
    m_fechaPublicacion.readBinary(inStream);
}
