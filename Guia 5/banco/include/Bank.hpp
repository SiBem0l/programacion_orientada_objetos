#ifndef BANK_HPP
#define BANK_HPP

#include <vector>
#include "Checking.hpp"
#include "Saving.hpp"
#include "University.hpp"

// Index type for the vector of Accounts
using indexType = std::vector<Account>::size_type;

class Bank
{
private:
    std::vector<Account*> accounts;
    Money activesTotal = 0;

public: 
    // Constructor and destructor:
    // Bank();
    ~Bank();

    // Getters:
    Account& getAccount(indexType index);
    const Account& getAccount(indexType index) const;
    Account& getAccountsFirst();
    Account& getAccountsLast();
    Money getActivesTotal() const;

    // Setters:
    void addChecking(Client& holder, Money maxOverdraft);
    void addUniversity(Client& holder, Money maxAmountExtractionDaily);
    void addSaving(Client& holder, int maxNumberExtractionsMonthly);
    void popAccount();

    // Files management:
    bool storeBinary(std::string accountFileName, std::string clientFileName) const;
    bool readBinary(std::string accountFileName, std::string clientFileName, std::vector<Client>& clients);     
};


#endif