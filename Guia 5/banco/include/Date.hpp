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

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void set(int day, int month, int year);
    void setDay(int newDay);
    void setMonth(int newMonth);
    void setYear(int newYear);
};

#endif