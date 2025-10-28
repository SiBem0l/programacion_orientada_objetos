#ifndef SAVING_HPP
#define SAVING_HPP

#include "Account.hpp"

class Saving: public Account
{
private:
    int numberExtractionsMonth = 0;
    int maxNumberExtractionsMonthly = 0;

    // Useful:
    bool allowExtraction() const;
    void extractionDone();

public:
    // Constructor:
    Saving();
    Saving(Client& holder, int maxNumberExtractionsMonthly);

    // Setters:
    bool withdrawal(Money amount) override;

    // Useful:
    void endMonth();

    // Files Management:
    void storeBinary(std::ofstream& accountFile, std::ofstream& clientFile) const override;
    void readBinary(std::ifstream& accountFile, std::ifstream& clientFile, Client& allocatedHolder);
};

#endif