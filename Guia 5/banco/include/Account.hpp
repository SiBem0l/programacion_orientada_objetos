#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>

#include "Client.hpp"

using Money = int;

enum AccountType
{
    NoType,
    typeChecking, 
    typeSavings,
    typeUniversity 
};

class Account
{
    // Overload for text output stream
    friend std::ostream& operator<<(std::ostream& stream, const Account& account);
protected:
    Client* holder = nullptr;
    Money balance = 0;
    AccountType type = NoType;

public:
    // Constructor and destructor:
    Account();
    Account(Client& newHolder);
    virtual ~Account();

    // Getters:
    const Client& getHolder() const;
    Money getBalance() const;
    AccountType getType() const;

    // Setters:
    void deposit(Money amount);
    virtual bool withdrawal(Money amount) = 0;
    // bool transfer(Account& destinatary, Money amount);

    // Useful:
    virtual bool sufficientFonds(Money amount) const;

    // Files Management:
    virtual void storeBinary(std::ofstream& accountFile, std::ofstream& clientFile) const;
    virtual void readBinary(std::ifstream& accountFile, std::ifstream& clientFile, Client& allocatedHolder);
};

#endif