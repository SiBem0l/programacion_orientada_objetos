#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "Account.hpp"

class University: public Account
{
private:
    Money amountExtractionDay = 0;
    Money maxAmountExtractionDaily = 0;

    // Useful:
    void extractionDone(int Money);
    bool allowExtraction(int Money) const;
public:
    // Constructor:
    University();
    University(Client& holder, Money maxAmountExtractionDaily);

    // Setters:
    bool withdrawal(int Money) override;
    
    // Useful:
    void endDay();
    
    // Files Management:
    void storeBinary(std::ofstream& accountFile, std::ofstream& clientFile) const override;
    void readBinary(std::ifstream& accountFile, std::ifstream& clientFile, Client& allocatedHolder);
};

#endif