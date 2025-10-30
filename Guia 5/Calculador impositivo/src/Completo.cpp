#include "Completo.hpp"

Dinero Completo::getMontoFijo() const
{
    return 5;
}

Dinero Completo::getMontoVariable() const
{
    return 50/100;
}

Dinero Completo::getUmbralImpuestoVariable() const
{
    return 5000;
}

Dinero Completo::calcularImpuesto(Factura& factura) const 
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

Dinero Completo::calcularImpuesto(Factura& factura, Dinero& impuestoFijo, Dinero& impuestoVariable) const 
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

