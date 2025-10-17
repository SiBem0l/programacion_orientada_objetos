#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include "Date.hpp"

class Client
{
private:
    std::string name = "";
    std::string surname = "";
    int identification = 0;
    Date birth;

public:
    Client();
    Client(std::string newName, std::string newSurname, int newIdentification, const Date &newBirth);

    std::string getName() const;
    std::string getSurname() const;
    int getIdentification() const;
    Date getBirth() const;

    void set(std::string newName, std::string newSurname, int newIdentification, const Date &newBrith);
    void setName(std::string newName);
    void setSurname(std::string newSurname);
    void setBirth(const Date &newBrith);
    void setIdentification(int newIdentification);
};

#endif