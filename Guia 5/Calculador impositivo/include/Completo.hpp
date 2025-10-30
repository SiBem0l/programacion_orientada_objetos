#ifndef COMPLETO_HPP
#define COMPLETO_HPP

#include "Categoria.hpp"

class Completo: public Categoria
{
public:
    Dinero getMontoFijo() const override;
    Dinero getMontoVariable() const override;
    Dinero getUmbralImpuestoVariable() const;

    Dinero calcularImpuesto(Factura& factura) const override;
    Dinero calcularImpuesto(Factura& factura, Dinero& impuestoFijo, Dinero& impuestoVariable) const override;
};

#endif