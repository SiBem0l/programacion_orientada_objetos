#ifndef CHECKING_HPP
#define CHECKING_HPP

#include "Account.hpp"

class Checking: public Account
{
private:
    Money maxOverdraft = 0;

public:
    // Constructor:
    Checking();
    Checking(Client& holder, Money maxOverdraft);

    // Getters:
    Money getMaxOverdraft() const;

    // Setters:
    bool withdrawal(Money amount) override;

    // Useful:
    bool sufficientFonds(Money amount) const override;
     
    // Files Management:
    void storeBinary(std::ofstream& accountFile, std::ofstream& clientFile) const override;
    void readBinary(std::ifstream& accountFile, std::ifstream& clientFile, Client& allocatedHolder);
};

#endif