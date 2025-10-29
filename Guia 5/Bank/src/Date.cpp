#include "Date.hpp"

// Overload for text output stream
std::ostream &operator<<(std::ostream &outStream, Date date)
{
    outStream << date.day << "/" << date.month << "/" << date.year;
    return outStream;
}

// Constructor:
Date::Date(Unit newDay, Unit newMonth, Unit newYear) : day(newDay),
                                                       month(newMonth),
                                                       year(newYear)
{
}

// Getters:
Unit Date::getDay() const
{
    return day;
}

Unit Date::getMonth() const
{
    return month;
}

Unit Date::getYear() const
{
    return year;
}

// Setters:
void Date::set(Unit newDay, Unit newMonth, Unit newYear)
{
    setDay(newDay);
    setMonth(newMonth);
    setYear(newYear);
}

void Date::setDay(Unit newDay)
{
    day = newDay;
}

void Date::setMonth(Unit newMonth)
{
    month = newMonth;
}

void Date::setYear(Unit newYear)
{
    year = newYear;
}

// Files Management:
static void storeUnit(std::ofstream& outFile, const Unit& unit)
{
    outFile.write(reinterpret_cast<const char*>(&unit), sizeof(unit));
}
void Date::storeBinary(std::ofstream& outFile) const
{
    storeUnit(outFile, getDay());
    storeUnit(outFile, getMonth());
    storeUnit(outFile, getYear());
}

static void readUnit(std::ifstream& inFile, Unit& unit)
{
    inFile.read(reinterpret_cast<char*>(&unit), sizeof(unit));
}
void Date::readBinary(std::ifstream& inFile)
{
    readUnit(inFile, day);
    readUnit(inFile, month);
    readUnit(inFile, year);
}
