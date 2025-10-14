#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include "Client.hpp"

class Account
{
    friend std::ostream& operator<<(std::ostream& stream, Account& account);
private:
    std::string holder;
    int balance;

public:
    Account(std::string holder);
    virtual ~Account();

    std::string getHolder() const;
    int getBalance() const;
    bool transfer(Account& destinatary, int amount);

    void deposit(int amount);
    virtual bool withdrawal(int amount);
    
    virtual bool sufficientFonds(int amount);
};

#endif