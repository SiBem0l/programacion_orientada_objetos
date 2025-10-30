#ifndef LIMITADO_HPP
#define LIMITADO_HPP

#include "Categoria.hpp"

class Limitado: public Categoria
{
public:
    Dinero getMontoFijo() const override;
    Dinero getMontoVariable() const override;

    Dinero calcularImpuesto(Factura& factura) const override;
    Dinero calcularImpuesto(Factura& factura, Dinero& impuestoFijo, Dinero& impuestoVariable) const override;
};

#endif