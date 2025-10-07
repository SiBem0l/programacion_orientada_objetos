#include "Checking.hpp"
#include <math.h>

Checking::Checking(std::string holder, int maxOverdraft) : Account(holder),
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
