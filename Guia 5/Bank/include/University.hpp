#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "Account.hpp"

class University: public Account
{
private:
    Money amountExtractionDay;
    Money maxAmountExtractionDaily;

    // Useful:
    void extractionDone(int Money);
    bool allowExtraction(int Money) const;
public:
    // Constructor:
    University(const Client& holder, Money maxAmountExtractionDaily);

    // Setters:
    bool withdrawal(int Money) override;
    
    // Useful:
    void endDay();
    
    // Files Management:
    void storeBinary(std::ofstream& outFile) const override;
    void readBinary(std::ifstream& inFile) override;
};

#endif