#include "Client.hpp"

Client::Client(std::string newName, std::string newSurname, int newIdentification,
               int newBirthDay, int newBirthMonth, int newBirthYear) : name(newName),
                                                                       surname(newSurname),
                                                                       identification(newIdentification),
                                                                       birth(newBirthDay, newBirthMonth, newBirthYear)
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

void Client::set(std::string newName, std::string newSurname, int newIdentification,
                 int newBirthDay, int newBirthMonth, int newBirthYear)
{
    setName(newName);
    setSurname(newSurname);
    setIdentification(newIdentification);
    setBirth(newBirthDay, newBirthMonth, newBirthYear);
}

void Client::setName(std::string newName)
{
    name = newName;
}

void Client::setSurname(std::string newSurname)
{
    surname = newSurname;
}

void Client::setBirth(int newBirthDay, int newBirthMonth, int newBirthYear)
{
    birth.set(newBirthDay, newBirthMonth, newBirthYear);
}

void Client::setIdentification(int newIdentification)
{
    identification = newIdentification;
}