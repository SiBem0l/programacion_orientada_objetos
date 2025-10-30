#ifndef EXTENDIDO_HPP
#define EXTENDIDO_HPP

#include "Categoria.hpp"

class Extendido: public Categoria
{
public:
    Dinero getMontoFijo() const override;
    Dinero getMontoVariable() const override;
    Dinero getUmbralImpuestoVariable() const;
    
    Dinero calcularImpuesto(Factura& factura) const override;
    Dinero calcularImpuesto(Factura& factura, Dinero& impuestoFijo, Dinero& impuestoVariable) const override;
};

#endif