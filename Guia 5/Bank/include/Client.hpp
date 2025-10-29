#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <fstream>

#include "Date.hpp"

using IdType = int;

class Client
{
    // Overload for text output stream
    friend std::ostream& operator<<(std::ostream& outStream, const Client& client);
private:
    std::string name = "";
    std::string surname = "";
    IdType identification = 0;
    Date birth;

public:
    // Constructor:
    Client();
    Client(std::string newName, std::string newSurname, IdType newIdentification, const Date &newBirth);

    // Getters:
    std::string getName() const;
    std::string getSurname() const;
    IdType getIdentification() const;
    Date getBirth() const;

    // Setters:
    void set(std::string newName, std::string newSurname, IdType newIdentification, const Date &newBrith);
    void setName(std::string newName);
    void setSurname(std::string newSurname);
    void setBirth(const Date &newBrith);
    void setIdentification(IdType newIdentification);

    // Files Management:
    void storeBinary(std::ofstream& outFile) const;
    void readBinary(std::ifstream& inFile);
};

#endif