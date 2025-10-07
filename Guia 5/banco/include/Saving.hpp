#ifndef SAVING_HPP
#define SAVING_HPP

#include "Account.hpp"

class Saving: public Account
{
private:
    int numberExtractionsMonth;
    int maxNumberExtractionsMonthly;

    bool allowExtraction();
    void extractionDone();

public:
    Saving(std::string holder, int maxNumberExtractionsMonthly);

    void endMonth();

    bool withdrawal(int amount) override;
};

#endif