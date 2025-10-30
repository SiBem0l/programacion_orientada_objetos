#include "ReciboDePago.hpp"

ReciboDePago::ReciboDePago(std::string &nombre, Dinero &montoTotal, Dinero &montoFijo, Dinero &montoVariable) : nombre(nombre),
                                                                                                                montoTotal(montoTotal),
                                                                                                                montoFijo(montoFijo),
                                                                                                                montoVariable(montoVariable)
{
}

std::string ReciboDePago::getNombre() const
{
    return nombre;
}

Dinero ReciboDePago::getMontoTotal() const
{
    return montoTotal;
}

Dinero ReciboDePago::getMontoFijo() const
{
    return montoFijo;
}

Dinero ReciboDePago::getMontoVariable() const
{
    return montoVariable;
}