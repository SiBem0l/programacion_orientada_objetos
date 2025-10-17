#ifndef CHECKING_HPP
#define CHECKING_HPP

#include "Account.hpp"

class Checking: public Account
{
private:
    int maxOverdraft;

public:
    Checking(const Client& holder, int maxOverdraft);

    bool withdrawal(int amount) override;
    bool sufficientFonds(int amount) override;
};

#endif