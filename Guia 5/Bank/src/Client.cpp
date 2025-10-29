#include <vector>

#include "Client.hpp"

// Overload for text output stream
std::ostream& operator<<(std::ostream& outStream, const Client& client)
{
    outStream << client.getName() << " " <<  client.getSurname() << std::endl;
    outStream << "Birth: " << client.getBirth() << std::endl;
    outStream << "Identification: " << client.getIdentification() << std::endl;
    return outStream;
}

// Constructor:
Client::Client() : birth()
{
}

Client::Client(std::string newName, std::string newSurname, IdType newIdentification, const Date& newBirth) : name(newName),
                                                                                                          surname(newSurname),
                                                                                                          identification(newIdentification),
                                                                                                          birth(newBirth)
{
}

// Getters:
std::string Client::getName() const
{
    return name;
}

std::string Client::getSurname() const
{
    return surname;
}

IdType Client::getIdentification() const
{
    return identification;
}

Date Client::getBirth() const
{
    return birth;
}

// Setters:
void Client::set(std::string newName, std::string newSurname, IdType newIdentification, const Date& newBirth)
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

void Client::setIdentification(IdType newIdentification)
{
    identification = newIdentification;
}

// Files Management:
static void storeString(std::ofstream& outFile, const std::string& str)
{
    // Store lenght of the string
    const std::string::size_type& lenght = str.length();
    outFile.write(reinterpret_cast<const char*>(&lenght), sizeof(lenght));

    // Store the characters
    const char* data = str.data();
    outFile.write(data, lenght);
}
void Client::storeBinary(std::ofstream& outFile) const
{
    storeString(outFile, name);
    storeString(outFile, surname);
    outFile.write(reinterpret_cast<const char*>(&identification), sizeof(identification));
    birth.storeBinary(outFile);
} 

static void readString(std::ifstream& inFile, std::string& str)
{
    // Read lenght of the string
    std::string::size_type lenght;
    inFile.read(reinterpret_cast<char*>(&lenght), sizeof(lenght));

    // Resize the string (it contemplates the /0)
    str.resize(lenght);

    // Read directly into the string data
    inFile.read(str.data(), lenght);
}
void Client::readBinary(std::ifstream& inFile)
{
    readString(inFile, name);
    readString(inFile, surname);
    inFile.read(reinterpret_cast<char*>(&identification), sizeof(identification));
    birth.readBinary(inFile);
}