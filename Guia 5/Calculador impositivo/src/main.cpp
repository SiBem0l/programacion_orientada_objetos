#include <iostream>

#include "CalculadorImpositivo.hpp"
#include "Limitado.hpp"
#include "Extendido.hpp"
#include "Completo.hpp"

using namespace std;

int main()
{
    // Defino el contribuyente
    std::string yo = "Julian";
    Categoria* categoria = new Limitado();

    // Creo su calculador
    CalculadorImpositivo calculadora(yo, categoria);
    
    // Cargo las facturas
    calculadora.agregarFactura("Comida", 1, 10);
    calculadora.agregarFactura("Nafta", 2, 200);
    calculadora.agregarFactura("Fiesta", 3, 3000);

    // Calculo el importe
    ReciboDePago recibo = calculadora.calcularImpuestoTotal();

    // Imprimo el recibo
    cout << recibo << endl;

    // Elimino le contribuyente
    delete categoria;
    return 0;
}
