#include <iostream>

#include "Bank.hpp"
#include "Checking.hpp"
#include "Saving.hpp"
#include "University.hpp"

using namespace std;

#define READ true
#define WRITE false

int main() 
{
    std::string accountFileName = "accounts";
    std::string clientFileName = "client";

    Bank galicia;
    std::vector<Client> clients;

    if(WRITE)
    {
        // Create clients
        clients.push_back(Client("Julian", "Llinares", 45318793, Date{18, 12, 2003}));
        clients.push_back(Client("Escoty", "Llinares", 11111111, Date{11, 11, 1111}));
        clients.push_back(Client("Delfina", "Llinares", 22222222, Date{22, 22, 2222}));
        
        
        // Create bank accounts
        galicia.addChecking(clients[0], 10);
        galicia.addSaving(clients[1], 100);
        galicia.addUniversity(clients[2], 1000);

        // Deposit to the accounts

        // Store the accounts
        galicia.storeBinary(accountFileName, clientFileName);
    }
    
    if(READ)
    {
        galicia.readBinary(accountFileName, clientFileName, clients);
    }


    cout << galicia.getAccount(0) << endl;
    cout << galicia.getAccount(1) << endl;
    cout << galicia.getAccount(2) << endl;

    return 0;
}