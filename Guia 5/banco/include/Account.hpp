#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>

#include "Client.hpp"

using Money = int;

class Account
{
    // Overload for text output stream
    friend std::ostream& operator<<(std::ostream& stream, const Account& account);
private:
    Client holder;
    Money balance = 0;

public:
    // Constructor and destructor:
    Account();
    Account(const Client& holder);
    virtual ~Account();

    // Getters:
    Client& getHolder();
    const Client& getHolder() const;
    Money getBalance() const;

    // Setters:
    void deposit(Money amount);
    virtual bool withdrawal(Money amount);
    bool transfer(Account& destinatary, Money amount);

    // Useful:
    virtual bool sufficientFonds(Money amount);

    // Files Management:
    virtual void storeBinary(std::ofstream& outFile) const;
    virtual void readBinary(std::ifstream& inFile);
};

#endif