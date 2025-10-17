#include <iostream>

#include "Bank.hpp"
// #include "Account.hpp" //included in Bank.hpp 
#include "Checking.hpp"
#include "Saving.hpp"
#include "University.hpp"

using namespace std;

int main() 
{
    std::string filename = "accounts";

    Bank galicia;
    // galicia.accountsPushBack(Account{Client{"Julian", "Llinares", 45318793, Date{18, 12, 2003}}});
    // galicia.accountsPushBack(Account{Client{"Escoty", "Llinares", 11111111, Date{11, 11, 1111}}});
    // galicia.accountsPushBack(Account{Client{"Delfina", "Llinares", 22222222, Date{22, 22, 2222}}});
    // galicia.storeAccounts(filename);

    galicia.readAccounts(filename);

    cout << galicia.getAccount(0);
    cout << galicia.getAccount(1);
    cout << galicia.getAccount(2);

    

    return 0;
}