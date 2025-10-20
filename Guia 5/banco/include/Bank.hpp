#ifndef BANK_HPP
#define BANK_HPP

#include <vector>
#include "Account.hpp"

// Index type for the vector of Accounts
using indexType = std::vector<Account>::size_type;

class Bank
{
private:
    std::vector<Account> accounts;
    Money activesTotal = 0;

public: 
    // Getters:
    Account& getAccount(indexType index);
    const Account& getAccount(indexType index) const;
    Account& getAccountsFirst();
    Account& getAccountsLast();
    Money getActivesTotal() const;

    // Setters:
    void accountsInsert(indexType index, const Account& account);
    void accountsErease(indexType index);

    void accountsPushBack(const Account& account);
    void accountsPopBack();

    // Files management:
    bool storeBinary(std::string fileName) const;
    bool readBinary(std::string fileName);     
};


#endif