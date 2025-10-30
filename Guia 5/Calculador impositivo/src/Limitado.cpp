#include "Limitado.hpp"

Dinero Limitado::getMontoFijo() const
{
    return 5;
}

Dinero Limitado::getMontoVariable() const
{
    return 0.5/100;
}

Dinero Limitado::calcularImpuesto(Factura& factura) const 
{
    Dinero monto = factura.getMonto();
    
    Dinero impuestoFijo = getMontoFijo();
    Dinero impuestoVariable = getMontoVariable() * monto;

    Dinero impuesto = impuestoFijo + impuestoVariable;
    return impuesto;
}

Dinero Limitado::calcularImpuesto(Factura& factura, Dinero& impuestoFijo, Dinero& impuestoVariable) const 
{
    Dinero monto = factura.getMonto();
    
    impuestoFijo = getMontoFijo();
    impuestoVariable = getMontoVariable() * monto;

    Dinero impuesto = impuestoFijo + impuestoVariable;
    return impuesto;
}
