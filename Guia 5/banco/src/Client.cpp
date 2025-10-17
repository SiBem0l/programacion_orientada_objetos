#include "Client.hpp"

Client::Client() : birth()
{
}

Client::Client(std::string newName, std::string newSurname, int newIdentification, const Date& newBirth) : name(newName),
                                                                                                        surname(newSurname),
                                                                                                        identification(newIdentification),
                                                                                                        birth(newBirth)
{
}

std::string Client::getName() const
{
    return name;
}

std::string Client::getSurname() const
{
    return surname;
}

int Client::getIdentification() const
{
    return identification;
}

Date Client::getBirth() const
{
    return birth;
}

void Client::set(std::string newName, std::string newSurname, int newIdentification, const Date& newBirth)
{
    setName(newName);
    setSurname(newSurname);
    setIdentification(newIdentification);
    setBirth(newBirth);
}

void Client::setName(std::string newName)
{
    name = newName;
}

void Client::setSurname(std::string newSurname)
{
    surname = newSurname;
}

void Client::setBirth(const Date& newBirth)
{
    birth = newBirth;
}

void Client::setIdentification(int newIdentification)
{
    identification = newIdentification;
}