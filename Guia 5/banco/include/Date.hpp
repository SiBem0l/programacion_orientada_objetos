#ifndef FECHA_HPP
#define FECHA_HPP

#include <iostream>
#include <fstream>

using Unit = int;

class Date
{
    // Overload for text output stream
    friend std::ostream& operator<< (std::ostream& outStream, Date date);
private:
    Unit day = 0;
    Unit month = 0;
    Unit year = 0;

public:
    // Constructor:
    Date(Unit day = 0, Unit month = 0, Unit year = 0);

    // Getters:
    Unit getDay() const;
    Unit getMonth() const;
    Unit getYear() const;

    // Setters:
    void set(Unit day, Unit month, Unit year);
    void setDay(Unit newDay);
    void setMonth(Unit newMonth);
    void setYear(Unit newYear);

    // Files Management:
    void storeBinary(std::ofstream& outFile) const;
    void readBinary(std::ifstream& outFile);
};

#endif