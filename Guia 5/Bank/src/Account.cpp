#include <iostream>
#include "Account.hpp"

// Overload for text output stream
std::ostream &operator<<(std::ostream &outStream, const Account &account)
{
    outStream << account.getHolder();
    outStream << "Balance: " << account.getBalance() << std::endl;
    return outStream;
}

// Constructor and destructor:
Account::Account() : holder()
{
}

Account::Account(const Client& holder) : holder(holder)
{
}

Account::~Account() = default;

// Getters:
Client& Account::getHolder()
{
    return holder;
}

const Client& Account::getHolder() const
{
    return holder;
}

Money Account::getBalance() const
{
    return balance;
}

// Setters:
void Account::deposit(Money amount)
{
    balance += amount;
}

bool Account::withdrawal(Money amount)
{
    balance -= amount;
    return true;
}

bool Account::transfer(Account& destinatary, Money amount)
{
    bool done = false;
    if(withdrawal(amount))
    {
        destinatary.deposit(amount);
        done = true;
    }
    return done;
}

// Useful:
bool Account::sufficientFonds(Money amount)
{
    return amount <= getBalance();
}

// Files Management:
void Account::storeBinary(std::ofstream& outFile) const
{
    const Client& client = getHolder();
    client.storeBinary(outFile);

    const Money& balance = getBalance();
    outFile.write(reinterpret_cast<const char*>(&balance), sizeof(balance));
}

void Account::readBinary(std::ifstream& inFile)
{
    holder.readBinary(inFile);

    inFile.read(reinterpret_cast<char*>(&balance), sizeof(balance));
}