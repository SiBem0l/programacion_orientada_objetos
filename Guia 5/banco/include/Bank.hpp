#ifndef BANK_HPP
#define BANK_HPP

#include <vector>
#include "Account.hpp"

class Bank
{
private:
    std::vector<Account> accounts;
    int activesTotal = 0;

public:
    Account& getAccount(size_t index);
    const Account& getAccount(size_t index) const;
    // Account& getAccount(int identification);
    // Account& getAccount(std::string holder);
    Account& getAccountsFirst();
    Account& getAccountsLast();
    int getActivesTotal() const;

    void accountsInsert(size_t index, const Account& account);
    void accountsErease(size_t index);

    void accountsPushBack(const Account& account);
    void accountsPopBack();

    bool storeAccounts(std::string fileName) const;
    bool readAccounts(std::string fileName);     
};


#endif