#ifndef FECHA_HPP
#define FECHA_HPP

#include <iostream>

class Date
{
    friend std::ostream& operator<< (std::ostream& outStream, Date date);
private:
    int day;
    int month;
    int year;

public:
    Date(int day = 0, int month = 0, int year = 0);
    void set(int day, int month, int year);
};

#endif