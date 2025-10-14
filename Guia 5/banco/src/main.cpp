#include <iostream>
#include "Account.hpp"
#include "Checking.hpp"
#include "Saving.hpp"
#include "University.hpp"

int main() 
{
    // Account* cuentas[3] = 
    // {
    //     new University("Nerea", 100),
    //     new Checking("Julian", 10),
    //     new Saving("Escoty", 1)
    // };

    // Account& nere = *cuentas[0];
    // Account& juli = *cuentas[1];
    // Account& escoty = *cuentas[2];

    // juli.transfer(nere, 10);
    // nere.transfer(escoty, 10);
    // escoty.transfer(juli, 10);

    // std::cout << juli << nere << escoty;

    Client nerea("Nerea", "Arrospide", 46738897, 18, 12, 2003);

    return 0;
}