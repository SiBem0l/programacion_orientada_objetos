#include "Saving.hpp"

// Constructor:
Saving::Saving(const Client& holder, int max) : Account(holder),
                                                numberExtractionsMonth(0),
                                                maxNumberExtractionsMonthly(max)

{
}

// Useful:
bool Saving::allowExtraction()
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
        Account::withdrawal(amount);
        done = true;
    }
    return done;
}

// Files Management:
void Saving::storeBinary(std::ofstream& outFile) const
{
    // Store all the Account basic information
    Account::storeBinary(outFile);

    // Store the Saving additional information
    outFile.write(reinterpret_cast<const char*>(numberExtractionsMonth), sizeof(numberExtractionsMonth));
    outFile.write(reinterpret_cast<const char*>(maxNumberExtractionsMonthly), sizeof(maxNumberExtractionsMonthly));
}

void Saving::readBinary(std::ifstream& inFile)
{
    // Store all the Account basic information
    Account::readBinary(inFile);

    // Store the Saving additional information
    inFile.read(reinterpret_cast<char*>(numberExtractionsMonth), sizeof(numberExtractionsMonth));
    inFile.read(reinterpret_cast<char*>(maxNumberExtractionsMonthly), sizeof(maxNumberExtractionsMonthly));
}