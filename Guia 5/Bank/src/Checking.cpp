#include "Checking.hpp"
#include <math.h>

// Constructor:
Checking::Checking(const Client& holder, Money maxOverdraft) : Account(holder),
                                                               maxOverdraft(maxOverdraft)
{
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
        Account::withdrawal(amount);
        done = true;
    }
    return done;
}

// Useful:
bool Checking::sufficientFonds(Money amount)
{
    return Account::getBalance() + maxOverdraft >= amount;
}

// Files Management:
void Checking::storeBinary(std::ofstream& outFile) const
{
    // Store all the Account basic information
    Account::storeBinary(outFile);

    // Store the Checking additional information
    outFile.write(reinterpret_cast<const char*>(maxOverdraft), sizeof(maxOverdraft));
}

void Checking::readBinary(std::ifstream& inFile)
{
    // Read all the Account basic information
    Account::readBinary(inFile);

    // Read the Checking additional information
    inFile.read(reinterpret_cast<char*>(maxOverdraft), sizeof(maxOverdraft));
}