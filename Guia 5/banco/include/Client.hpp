#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include "Date.hpp"

class Client
{
private:
    std::string name;
    std::string surname;
    int identification;
    Date birth;

public:
    Client(std::string newName, std::string newSurname, int newIdentification, 
           int newBirthDay, int newBirthMonth, int newBirthYear);

    std::string getName() const;
    std::string getSurname() const;
    int getIdentification() const;
    Date getBirth() const;

    void set(std::string newName, std::string newSurname, int newIdentification, 
             int newBirthDay, int newBirthMonth, int newBirthYear);
    void setName(std::string newName);
    void setSurname(std::string newSurname);
    void setBirth(int newBirthDay, int newBirthMonth, int newBirthYear);
    void setIdentification(int newIdentification);  
};

#endif