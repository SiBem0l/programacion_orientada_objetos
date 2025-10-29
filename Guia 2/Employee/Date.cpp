#include "Date.hpp"

Date::Date(int newDay, int newMonth, int newYear) : day(newDay),
                                                    month(newMonth),
                                                    year(newYear)
{}

void Date::set(int newDay, int newMonth, int newYear)
{
    day = newDay;
    month = newMonth;
    year = newYear;
}

std::ostream& operator<< (std::ostream& outStream, Date date)
{
    outStream << date.day << "/" << date.month << "/" << date.year;
    return outStream;
}