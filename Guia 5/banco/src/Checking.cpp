#include "Checking.hpp"
#include <math.h>

// Constructor:
Checking::Checking()
{
    Account::type = typeChecking;
}

Checking::Checking(Client& newHolder, Money maxOverdraft) : Account(newHolder),
                                                            maxOverdraft(maxOverdraft)
{
    Account::type = typeChecking;
}

// Getters:
Money Checking::getMaxOverdraft() const
{
    return maxOverdraft;
}

// Setters:
bool Checking::withdrawal(Money amount) 
{
    bool done = false;
    if(sufficientFonds(amount))
    {
        Account::balance -= amount;
        done = true;
    }
    return done;
}

// Useful:
bool Checking::sufficientFonds(Money amount) const
{
    return Account::getBalance() + maxOverdraft >= amount;
}

// Files Management:
void Checking::storeBinary(std::ofstream& accountFile, std::ofstream& clientFile) const
{
    // Store all the Account basic information
    Account::storeBinary(accountFile, clientFile);

    // Store the Checking additional information
    accountFile.write(reinterpret_cast<const char*>(&maxOverdraft), sizeof(maxOverdraft));
}

void Checking::readBinary(std::ifstream& accountFile, std::ifstream& clientFile, Client& allocatedHolder)
{
    // Read all the Account basic information
    Account::readBinary(accountFile, clientFile, allocatedHolder);

    // Read the Checking additional information
    accountFile.read(reinterpret_cast<char*>(&maxOverdraft), sizeof(maxOverdraft));
}