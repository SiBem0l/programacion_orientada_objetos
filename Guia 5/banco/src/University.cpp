#include "University.hpp"

University::University(const Client& holder, int max) : Account(holder),
                                                        amountExtractionDay(0),
                                                        maxAmountExtractionDaily(max)
{
}

void University::extractionDone(int amount)
{
    amountExtractionDay += amount;
}


bool University::allowExtraction(int amount) const
{
    return amountExtractionDay + amount <= maxAmountExtractionDaily;
}

void University::endDay()
{
    amountExtractionDay = 0;
}

bool University::withdrawal(int amount)
{
    bool done = false;
    if(allowExtraction(amount) && sufficientFonds(amount))
    {
        Account::withdrawal(amount);
        done = true;
    }
    return done;
}
