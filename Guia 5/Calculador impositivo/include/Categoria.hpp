#ifndef CATEGORIA_HPP
#define CATEGORIA_HPP

#include "Dinero.hpp"
#include "Factura.hpp"

class Categoria
{
public:
    virtual Dinero getMontoFijo() const = 0;
    virtual Dinero getMontoVariable() const = 0;

    virtual Dinero calcularImpuesto(Factura& factura) const = 0;
    virtual Dinero calcularImpuesto(Factura& factura, Dinero& impuestoFijo, Dinero& impuestoVariable) const = 0;
};

#endif