#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.hpp"

class Employee
{
    friend std::ostream& operator<< (std::ostream& outStream, Employee employee);
private:
    std::string name;
    std::string surname;
    Date birth;
    Date entryCompany;

public:
    Employee(std::string name, std::string surname, Date birth, Date entryCompany);
    ~Employee();
};

#endif