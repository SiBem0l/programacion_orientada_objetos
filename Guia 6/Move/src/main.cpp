#include <iostream>
#include <cstring>

class String
{
    std::size_t lenght = 0;
    char* data = nullptr;

public:
    String() = default;

    // If given a chain of characters with null terminator
    String(const char* chain) : lenght(strlen(chain)),
                                data(new char[lenght+1])
    {
        // Also copies the null terminator for c string compability
        memcpy(data, chain, lenght+1);
        
        std::cout << "Created a String!" << std::endl;
    }

    // Copy constructor
    String(const String& s) : lenght(s.lenght),
                              data(new char[lenght+1])
    {
        memcpy(data, s.data, lenght+1);
        std::cout << "Created a String copy!" << std::endl;
    }

    // Apropiates the string
    String(String&& s) : lenght(s.lenght),
                         data(s.data)
    {
        // Take the data from s
        s.lenght = 0;
        s.data = nullptr;

        std::cout << "Moved String!" << std::endl;
    }

    ~String()
    {
        std::cout << "Deleted!" << std::endl;
        delete[] data;
    }
};

class Person
{
    String name;

public:
    Person() = default;
    Person(const String& newName) : name(newName)
    {
        std::cout << "Person created! (copied name)" << std::endl;
    }
    Person(String&& newName) : name(std::move(newName))
    {
        std::cout << "Person created! (using name)" << std::endl;
    }
    ~Person()
    {
        std::cout << "Persone deleted!" << std::endl;
    }
};


int main() 
{
    String name("Julian");
    Person player(std::move(name));

    return 0;
}