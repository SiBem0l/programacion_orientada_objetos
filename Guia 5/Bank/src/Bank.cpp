#include <fstream>
#include "Bank.hpp"

// Getters:
Account& Bank::getAccount(indexType index)
{
    return accounts.at(index);
}

const Account& Bank::getAccount(indexType index) const
{
    return accounts.at(index);
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
void Bank::accountsInsert(indexType index, const Account& account)
{
    if(0 < index && index < accounts.size())
    {   
        activesTotal += account.getBalance();
        accounts.insert(accounts.begin() + index, account);
    }
}

void Bank::accountsErease(size_t index)
{
    if(0 < index && index < accounts.size())
    {
        activesTotal -= getAccount(index).getBalance();
        accounts.erase(accounts.begin() + index);
    }
}

void Bank::accountsPushBack(const Account& account)
{
    activesTotal += account.getBalance();
    accounts.push_back(account);
}

void Bank::accountsPopBack()
{
    activesTotal -= getAccount(accounts.size()).getBalance();
    accounts.pop_back();
}

// Files management:
bool Bank::storeBinary(std::string fileName) const
{
    bool done = false;
    std::ofstream outFile(fileName);
    if(outFile.fail())
    {
        std::cout << "File not found" << std::endl;
    }
    else
    {  
        indexType nAccounts = accounts.size();
        outFile.write(reinterpret_cast<char*>(&nAccounts), sizeof(nAccounts));
        for (indexType iAccount = 0; iAccount < nAccounts; iAccount++)
        {
            const Account& account = getAccount(iAccount);
            account.storeBinary(outFile);
        }
        done = true;
    }
    return done;
}   

bool Bank::readBinary(std::string fileName)
{
    bool done = false;
    std::ifstream inFile(fileName);
    if(inFile.fail())
    {
        std::cout << "File not found" << std::endl;
    }
    else
    {  
        indexType nAccounts = 0;
        inFile.read(reinterpret_cast<char*>(&nAccounts), sizeof(nAccounts));
        for(indexType iAccount = 0; iAccount < nAccounts; iAccount++)
        {
            Account currentAccount;
            currentAccount.readBinary(inFile);
            accounts.push_back(currentAccount);
        }
        done = true;
    }
    return done;
}     