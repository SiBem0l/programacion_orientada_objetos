#include "CalculadorImpositivo.hpp"

CalculadorImpositivo::CalculadorImpositivo(std::string nombre, const Categoria* categoria) : nombre(nombre),
                                                                                             categoria(categoria)
{
}

std::string CalculadorImpositivo::getNombre() const
{
    return nombre;
}

void CalculadorImpositivo::agregarFactura(std::string detalle, int numero, Dinero monto)
{
    facturas.push_back(Factura(detalle, numero, monto));
}

ReciboDePago CalculadorImpositivo::calcularImpuestoTotal() const
{
    std::string nombre = getNombre();

    Dinero montoTotal = 0;
    Dinero montoFijo = 0;
    Dinero montoVariable = 0;

    for(auto factura : facturas)
    {
        montoFijo = categoria->calcularImpuesto(factura, montoFijo, montoVariable);
    }

    ReciboDePago recibo(nombre, montoTotal, montoFijo, montoVariable);
    return recibo;
} 