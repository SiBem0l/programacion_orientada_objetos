#ifndef FACTURA_HPP
#define FACTURA_HPP

#include <string>
#include "Dinero.hpp"

class Factura
{
private:
    std::string detalle;
    unsigned int numero;
    Dinero monto;

public:
    Factura(std::string detalle, int numero, Dinero monto);

    std::string getDetalle() const;
    unsigned int getNumero() const;
    Dinero getMonto() const;
};

#endif