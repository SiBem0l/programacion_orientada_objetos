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

std::ostream& operator<<(std::ostream& outStream, const ReciboDePago& recibo)
{
    outStream << recibo.getNombre() << std::endl;
    outStream << "Impuesto total: " << recibo.getMontoTotal() << std::endl;
    outStream << "Impuesto fijo: " << recibo.getMontoFijo() << std::endl;
    outStream << "Impuesto variable: " << recibo.getMontoVariable() << std::endl;
    return outStream;
}