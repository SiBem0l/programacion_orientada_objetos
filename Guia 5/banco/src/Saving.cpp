#include "Saving.hpp"

// Constructor:
Saving::Saving()
{
    Account::type = typeSavings;
}

Saving::Saving(Client& holder, int max) : Account(holder),
                                          maxNumberExtractionsMonthly(max)

{
    Account::type = typeSavings;
}

// Useful:
bool Saving::allowExtraction() const
{
    return numberExtractionsMonth <= maxNumberExtractionsMonthly;
}

void Saving::extractionDone()
{
    numberExtractionsMonth++;
}

void Saving::endMonth()
{
    numberExtractionsMonth = 0;
}

// Setters:
bool Saving::withdrawal(Money amount)
{
    bool done = false;
    if (allowExtraction() && sufficientFonds(amount))
    {
        Account::balance -= amount;
        done = true;
    }
    return done;
}

// Files Management:
void Saving::storeBinary(std::ofstream& accountFile, std::ofstream& clientFile) const
{
    // Store all the Account basic information
    Account::storeBinary(accountFile, clientFile);

    // Store the Saving additional information
    accountFile.write(reinterpret_cast<const char*>(&numberExtractionsMonth), sizeof(numberExtractionsMonth));
    accountFile.write(reinterpret_cast<const char*>(&maxNumberExtractionsMonthly), sizeof(maxNumberExtractionsMonthly));
}

void Saving::readBinary(std::ifstream& accountFile, std::ifstream& clientFile, Client& allocatedHolder)
{
    // Read all the Account basic information
    Account::readBinary(accountFile, clientFile, allocatedHolder);

    // Store the Saving additional information
    accountFile.read(reinterpret_cast<char*>(&numberExtractionsMonth), sizeof(numberExtractionsMonth));
    accountFile.read(reinterpret_cast<char*>(&maxNumberExtractionsMonthly), sizeof(maxNumberExtractionsMonthly));
}