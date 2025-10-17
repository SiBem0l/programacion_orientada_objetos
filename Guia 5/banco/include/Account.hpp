#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include "Client.hpp"

class Account
{
    friend std::ostream& operator<<(std::ostream& stream, Account& account);
private:
    Client holder;
    int balance = 0;

public:
    Account();
    Account(const Client& holder);
    virtual ~Account();

    std::string getHolderName() const;
    int getBalance() const;
    bool transfer(Account& destinatary, int amount);

    void deposit(int amount);
    virtual bool withdrawal(int amount);
    
    virtual bool sufficientFonds(int amount);
};

#endif