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

    // // Create bank accounts
    // galicia.accountsPushBack(Account{Client{"Julian", "Llinares", 45318793, Date{18, 12, 2003}}});
    // galicia.accountsPushBack(Account{Client{"Escoty", "Llinares", 11111111, Date{11, 11, 1111}}});
    // galicia.accountsPushBack(Account{Client{"Delfina", "Llinares", 22222222, Date{22, 22, 2222}}});

    // // Deposit to the accounts
    // galicia.getAccount(0).deposit(10);
    // galicia.getAccount(1).deposit(123);
    // galicia.getAccount(2).deposit(5);

    // // Store the accounts
    // galicia.storeBinary(filename);

    galicia.readBinary(filename);

    cout << galicia.getAccount(0) << endl;
    cout << galicia.getAccount(1) << endl;
    cout << galicia.getAccount(2) << endl;


    return 0;
}