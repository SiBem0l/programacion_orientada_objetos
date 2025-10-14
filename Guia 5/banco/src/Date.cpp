#include "Date.hpp"

Date::Date(int newDay, int newMonth, int newYear) : day(newDay),
                                                    month(newMonth),
                                                    year(newYear)
{
}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

void Date::set(int newDay, int newMonth, int newYear)
{
    setDay(newDay);
    setMonth(newMonth);
    setYear(newYear);
}

void Date::setDay(int newDay)
{
    day = newDay;
}

void Date::setMonth(int newMonth)
{
    month = newMonth;
}

void Date::setYear(int newYear)
{
    year = newYear;
}

std::ostream &operator<<(std::ostream &outStream, Date date)
{
    outStream << date.day << "/" << date.month << "/" << date.year;
    return outStream;
}