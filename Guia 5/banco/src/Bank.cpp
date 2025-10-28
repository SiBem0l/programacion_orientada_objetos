#include <fstream>
#include "Bank.hpp"

// Constructor and destructor:
Bank::~Bank() {
    // Iterate over the vector of pointers and delete each Account object
    for(indexType i = 0; i < accounts.size(); i++)
    {
        delete accounts[i];
    }
}

// Getters:
Account& Bank::getAccount(indexType index)
{
    return *(accounts.at(index));
}

const Account& Bank::getAccount(indexType index) const
{
    return *(accounts.at(index));
}

Account& Bank::getAccountsFirst()
{
    return getAccount(0);
}

Account& Bank::getAccountsLast()
{
    return getAccount(accounts.size());
}

Money Bank::getActivesTotal() const
{
    return activesTotal;
}

// Setters:
void Bank::addChecking(Client& holder, Money maxOverdraft)
{
    Account* newAccount = new Checking(holder, maxOverdraft);
    accounts.push_back(newAccount);
}

void Bank::addUniversity(Client& holder, Money maxAmountExtractionDaily)
{
    Account* newAccount = new University(holder, maxAmountExtractionDaily);
    accounts.push_back(newAccount);
}

void Bank::addSaving(Client& holder, int maxNumberExtractionsMonthly)
{
    Account* newAccount = new Saving(holder, maxNumberExtractionsMonthly);
    accounts.push_back(newAccount);
}

void Bank::popAccount()
{
    accounts.pop_back();
}

// Files management:
bool Bank::storeBinary(std::string accountFileName, std::string clientFileName) const
{
    bool done = false;
    std::ofstream accountFile(accountFileName);
    std::ofstream clientFile(clientFileName);
    if(accountFile.fail() || clientFile.fail())
    {
        std::cout << "File not found" << std::endl;
    }
    else
    {  
        // Store the number of accounts on the bank
        indexType nAccounts = accounts.size();
        accountFile.write(reinterpret_cast<char*>(&nAccounts), sizeof(nAccounts));

        // Store the accounts
        for (indexType iAccount = 0; iAccount < nAccounts; iAccount++)
        {
            const Account& account = getAccount(iAccount);

            // Store the type of account
            AccountType type = account.getType();
            accountFile.write(reinterpret_cast<char*>(&type), sizeof(type));

            // Store the account
            account.storeBinary(accountFile, clientFile);
        }
        done = true;
    }
    return done;
}   

bool Bank::readBinary(std::string accountFileName, std::string clientFileName, std::vector<Client>& clients)
{
    bool done = false;
    std::ifstream accountFile(accountFileName);
    std::ifstream clientFile(clientFileName);
    if(accountFile.fail() || clientFile.fail())
    {
        std::cout << "File not found" << std::endl;
    }
    else
    {  
        // Read the number of accounts stored
        indexType nAccounts = 0;
        accountFile.read(reinterpret_cast<char*>(&nAccounts), sizeof(nAccounts));

        // Read the accounts and the clients
        int startingSize = clients.size();
        clients.resize(startingSize + nAccounts);
        for(indexType iAccount = startingSize; iAccount < startingSize + nAccounts; iAccount++)
        {
            Client& holder = clients[iAccount];

            // Read the type of account
            AccountType type = NoType;
            accountFile.read(reinterpret_cast<char*>(&type), sizeof(type));

            // Read the account into 
            Account* currentAccount = nullptr;
            if(type == typeChecking)
            {
                currentAccount = new Checking;
            }
            else if(type == typeSavings)
            {
                currentAccount = new Saving;
            }
            else if(type == typeUniversity)
            {
                currentAccount = new University;
            }
            currentAccount->readBinary(accountFile, clientFile, holder);
            accounts.push_back(currentAccount);
        }
        done = true;
    }
    return done;
}     