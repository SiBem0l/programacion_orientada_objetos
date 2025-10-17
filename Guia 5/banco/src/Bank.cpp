#include <fstream>
#include "Bank.hpp"

Account& Bank::getAccount(size_t index)
{
    return accounts.at(index);
}

const Account& Bank::getAccount(size_t index) const
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

int Bank::getActivesTotal() const
{
    return activesTotal;
}

void Bank::accountsInsert(size_t index, const Account& account)
{
    if(0 < index && index < accounts.size())
    {   
        accounts.insert(accounts.begin() + index, account);
        activesTotal += account.getBalance();
    }
}

void Bank::accountsErease(size_t index)
{
    if(0 < index && index < accounts.size())
    {
        accounts.erase(accounts.begin() + index);
    }
}

void Bank::accountsPushBack(const Account& account)
{
    accounts.push_back(account);
    activesTotal += account.getBalance();
}

void Bank::accountsPopBack()
{
    accounts.pop_back();
}

bool Bank::storeAccounts(std::string fileName) const
{
    bool done = false;
    std::ofstream outFile(fileName);
    if(outFile.fail())
    {
        std::cout << "File not found" << std::endl;
    }else{  
        size_t nAccounts = accounts.size();
        outFile.write(reinterpret_cast<const char*>(&nAccounts), sizeof(nAccounts));
        for (size_t iAccount = 0; iAccount < nAccounts; iAccount++)
        {
            const Account& currentAccount = getAccount(iAccount);
            outFile.write(reinterpret_cast<const char*>(&currentAccount), sizeof(Account));
        }
        done = true;
    }
    return done;
}   

bool Bank::readAccounts(std::string fileName)
{
    bool done = false;
    std::ifstream inFile(fileName);
    if(inFile.fail())
    {
        std::cout << "File not found" << std::endl;
    }else{  
        size_t nAccounts = 0;
        inFile.read(reinterpret_cast<char*>(&nAccounts), sizeof(nAccounts));
        for(size_t iAccount = 0; iAccount < nAccounts; iAccount++)
        {
            Account currentAccount;
            inFile.read(reinterpret_cast<char*>(&currentAccount), sizeof(Account));
            accounts.push_back(currentAccount);
        }
        done = true;
    }
    return done;
}     