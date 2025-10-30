#ifndef CALCULADORIMPOSITIVO_HPP
#define CALCULADORIMPOSITIVO_HPP

#include <vector>
#include "Dinero.hpp"
#include "Factura.hpp"
#include "Categoria.hpp"
#include "ReciboDePago.hpp"

class CalculadorImpositivo
{
private:
    std::string nombre;
    const Categoria* categoria;
    std::vector<Factura> facturas;

public:
    CalculadorImpositivo(std::string nombre, const Categoria* categoria);

    std::string getNombre() const;

    void agregarFactura(std::string detalle, int numero, Dinero monto);

    ReciboDePago calcularImpuestoTotal() const;
};

#endif