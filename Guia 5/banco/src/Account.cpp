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
Account::Account()
{
}

Account::Account(Client& newHolder) : holder(&newHolder)
{
}

Account::~Account()
{
}

// Getters:
const Client& Account::getHolder() const 
{
    return *holder;
}

Money Account::getBalance() const
{
    return balance;
}

AccountType Account::getType() const
{
    return type;
}

// Setters:
// bool Account::transfer(Account& destinatary, Money amount)
// {
//     bool done = false;
//     if(withdrawal(amount))
//     {
//         destinatary.deposit(amount);
//         done = true;
//     }
//     return done;
// }

// Useful:
bool Account::sufficientFonds(Money amount) const
{
    return amount <= getBalance();
}

// Files Management:
void Account::storeBinary(std::ofstream& accountFile, std::ofstream& clientFile) const
{
    // Store the client
    (*holder).storeBinary(clientFile);

    // Store the balance of the account
    accountFile.write(reinterpret_cast<const char*>(&balance), sizeof(balance));
}

void Account::readBinary(std::ifstream& accountFile, std::ifstream& clientFile, Client& allocatedHolder)
{
    // Read the client 
    allocatedHolder.readBinary(clientFile);
    holder = &allocatedHolder;

    // Store the balance of the account
    accountFile.read(reinterpret_cast<char*>(&balance), sizeof(balance));
}