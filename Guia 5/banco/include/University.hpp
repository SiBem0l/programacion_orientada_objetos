#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "Account.hpp"

class University: public Account
{
private:
    int amountExtractionDay;
    int maxAmountExtractionDaily;

    void extractionDone(int amount);
    bool allowExtraction(int amount) const;
public:
    University(std::string holder, int maxAmountExtractionDaily);

    void endDay();
    bool withdrawal(int amount) override;
};

#endif