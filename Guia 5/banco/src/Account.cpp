#include <iostream>
#include "Account.hpp"

Account::Account() : holder()
{
}

Account::Account(const Client& holder) : holder(holder)
{
}

Account::~Account() = default;

std::string Account::getHolderName() const
{
    return holder.getName();
}

int Account::getBalance() const
{
    return balance;
}

bool Account::transfer(Account& destinatary, int amount)
{
    bool done = false;
    if(withdrawal(amount))
    {
        destinatary.deposit(amount);
        done = true;
    }
    return done;
}

void Account::deposit(int amount)
{
    balance += amount;
}

bool Account::withdrawal(int amount)
{
    balance -= amount;
    return true;
}

bool Account::sufficientFonds(int amount)
{
    return amount <= getBalance();
}

std::ostream &operator<<(std::ostream &stream, Account &account)
{
    stream << account.getHolderName() << " balance: " << account.getBalance() << std::endl;
    return stream;
}
