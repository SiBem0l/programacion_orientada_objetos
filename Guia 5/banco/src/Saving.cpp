#include "Saving.hpp"

Saving::Saving(std::string holder, int max) : Account(holder),
                                              numberExtractionsMonth(0),
                                              maxNumberExtractionsMonthly(max)

{
}

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

bool Saving::withdrawal(int amount)
{
    bool done = false;
    if (allowExtraction() && sufficientFonds(amount))
    {
        Account::withdrawal(amount);
        done = true;
    }
    return done;
}
