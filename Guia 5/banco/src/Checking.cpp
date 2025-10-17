#include "Checking.hpp"
#include <math.h>

Checking::Checking(const Client& holder, int maxOverdraft) : Account(holder),
                                                             maxOverdraft(maxOverdraft)
{
}

bool Checking::withdrawal(int amount) 
{
    bool done = false;
    if(sufficientFonds(amount))
    {
        Account::withdrawal(amount);
        done = true;
    }
    return done;
}

bool Checking::sufficientFonds(int amount)
{
    return Account::getBalance() + maxOverdraft >= amount;
}
