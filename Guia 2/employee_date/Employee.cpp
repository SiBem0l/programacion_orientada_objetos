#include <iostream>
#include "Employee.hpp"

Employee::Employee(std::string newName, std::string newSurname, Date newBirth, Date newEntryCompany) : name(newName),
                                                                                                       surname(newSurname),
                                                                                                       birth(newBirth),
                                                                                                       entryCompany(newEntryCompany)
{
    std::cout << "Welcome " << name << std::endl;
}

Employee::~Employee()
{
    std::cout << "Goodbye " << name << std::endl;
}

std::ostream& operator<< (std::ostream& outStream, Employee employee)
{
    outStream << "\n";
    outStream << employee.name << " " << employee.surname << "\n";
    outStream << "birth: " << employee.birth << "\n";
    outStream << "entry to the company: " << employee.entryCompany << "\n";
    return outStream;
}