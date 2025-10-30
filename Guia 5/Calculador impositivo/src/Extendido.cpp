#include "Extendido.hpp"

Dinero Extendido::getMontoFijo() const
{
    return 5;
}

Dinero Extendido::getMontoVariable() const
{
    return 50/100;
}

Dinero Extendido::getUmbralImpuestoVariable() const
{
    return 5000;
}

Dinero Extendido::calcularImpuesto(Factura& factura) const 
{
    Dinero monto = factura.getMonto();
    
    Dinero impuestoFijo = getMontoFijo();
    Dinero impuestoVariable = 0;
    if(monto > getUmbralImpuestoVariable())
    {
       impuestoVariable = getMontoVariable() * monto;
    }

    Dinero impuesto = impuestoFijo + impuestoVariable;
    return impuesto;
}

Dinero Extendido::calcularImpuesto(Factura& factura, Dinero& impuestoFijo, Dinero& impuestoVariable) const 
{
    Dinero monto = factura.getMonto();
    
    impuestoFijo = getMontoFijo();
    impuestoVariable = 0;
    if(monto > getUmbralImpuestoVariable())
    {
       impuestoVariable = getMontoVariable() * monto;
    }

    Dinero impuesto = impuestoFijo + impuestoVariable;
    return impuesto;
}
