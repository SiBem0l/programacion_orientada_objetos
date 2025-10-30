#ifndef RECIBODEPAGO_HPP
#define RECIBODEPAGO_HPP

#include <string>
#include "Dinero.hpp"

class ReciboDePago
{
private:
    std::string nombre;
    Dinero montoTotal;
    Dinero montoFijo;
    Dinero montoVariable;

public:
    ReciboDePago(std::string &nombre, Dinero &montoTotal, Dinero &montoFijo, Dinero &montoVariable);

    std::string getNombre() const;
    Dinero getMontoTotal() const;
    Dinero getMontoFijo() const;
    Dinero getMontoVariable() const;
};
#endif