#include "University.hpp"

// Constructor:
University::University()
{
    Account::type = typeUniversity;
}

University::University(Client& holder, Money max) : Account(holder),
                                                    amountExtractionDay(0),
                                                    maxAmountExtractionDaily(max)
{
    Account::type = typeUniversity;
}

// Useful:
void University::extractionDone(Money amount)
{
    amountExtractionDay += amount;
}

bool University::allowExtraction(Money amount) const
{
    return amountExtractionDay + amount <= maxAmountExtractionDaily;
}

void University::endDay()
{
    amountExtractionDay = 0;
}

// Setters:
bool University::withdrawal(Money amount)
{
    bool done = false;
    if(allowExtraction(amount) && sufficientFonds(amount))
    {
        Account::balance -= amount;
        done = true;
    }
    return done;
}

// Files Management:
void University::storeBinary(std::ofstream& accountFile, std::ofstream& clientFile) const
{
    // Store all the Account basic information
    Account::storeBinary(accountFile, clientFile);

    // Store the University additional information
    accountFile.write(reinterpret_cast<const char*>(&amountExtractionDay), sizeof(amountExtractionDay));
    accountFile.write(reinterpret_cast<const char*>(&maxAmountExtractionDaily), sizeof(maxAmountExtractionDaily));
}

void University::readBinary(std::ifstream& accountFile, std::ifstream& clientFile, Client& allocatedHolder)
{
    // Read all the Account basic information
    Account::readBinary(accountFile, clientFile, allocatedHolder);

    // Read the University additional information
    accountFile.read(reinterpret_cast<char*>(&amountExtractionDay), sizeof(amountExtractionDay));
    accountFile.read(reinterpret_cast<char*>(&maxAmountExtractionDaily), sizeof(maxAmountExtractionDaily));
}