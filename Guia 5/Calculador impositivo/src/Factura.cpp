#include "Factura.hpp"

Factura::Factura(std::string detalle, int numero, Dinero monto) : detalle(detalle),
                                                                  numero(numero),
                                                                  monto(monto)
{
}

std::string Factura::getDetalle() const
{
    return detalle;
}

unsigned int Factura::getNumero() const
{
    return numero;
}

Dinero Factura::getMonto() const
{
    return monto;
}