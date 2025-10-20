#include "University.hpp"

// Constructor:
University::University(const Client& holder, Money max) : Account(holder),
                                                          amountExtractionDay(0),
                                                          maxAmountExtractionDaily(max)
{
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
        Account::withdrawal(amount);
        done = true;
    }
    return done;
}

// Files Management:
void University::storeBinary(std::ofstream& outFile) const
{
    // Store all the Account basic information
    Account::storeBinary(outFile);

    // Store the University additional information
    outFile.write(reinterpret_cast<const char*>(amountExtractionDay), sizeof(amountExtractionDay));
    outFile.write(reinterpret_cast<const char*>(maxAmountExtractionDaily), sizeof(maxAmountExtractionDaily));
}

void University::readBinary(std::ifstream& inFile)
{
    // Store all the Account basic information
    Account::readBinary(inFile);

    // Store the University additional information
    inFile.read(reinterpret_cast<char*>(amountExtractionDay), sizeof(amountExtractionDay));
    inFile.read(reinterpret_cast<char*>(maxAmountExtractionDaily), sizeof(maxAmountExtractionDaily));
}