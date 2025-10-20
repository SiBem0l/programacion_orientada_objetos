#ifndef CHECKING_HPP
#define CHECKING_HPP

#include "Account.hpp"

class Checking: public Account
{
private:
    Money maxOverdraft;

public:
    // Constructor:
    Checking(const Client& holder, Money maxOverdraft);

    // Getters:
    Money getMaxOverdraft() const;

    // Setters:
    bool withdrawal(Money amount) override;

    // Useful:
    bool sufficientFonds(Money amount) override;
     
    // Files Management:
    void storeBinary(std::ofstream& outFile) const override;
    void readBinary(std::ifstream& inFile) override;
};

#endif