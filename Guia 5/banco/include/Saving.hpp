#ifndef SAVING_HPP
#define SAVING_HPP

#include "Account.hpp"

class Saving: public Account
{
private:
    int numberExtractionsMonth;
    int maxNumberExtractionsMonthly;

    // Useful:
    bool allowExtraction();
    void extractionDone();

public:
    // Constructor:
    Saving(const Client& holder, int maxNumberExtractionsMonthly);

    // Setters:
    bool withdrawal(Money amount) override;

    // Useful:
    void endMonth();

    // Files Management:
    void storeBinary(std::ofstream& outFile) const override;
    void readBinary(std::ifstream& inFile) override;
};

#endif