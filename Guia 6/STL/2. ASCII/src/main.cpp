#include <iostream>


class Letter
{
    std::pair<char, char> pair;
    
    char readLetter()
    {
        std::cout << "Ingrese un numero entre 65...90 o 97...122: ";
        int number;
        std::cin >> number;
        // Conversion problem!
        while( !isUppercase(static_cast<char>(number)) && !isLowercase(static_cast<char>(number)) )
        {
            std::cout << "Ingrese un numero entre 65...90 o 97...122: ";
            std::cin >> number;
        }
        return number;
    }


public:
    Letter()
    {
        char letter = readLetter();

        // Check it meets the boundaries
        if(isUppercase(letter))
        {
            pair.first = letter + 32;
            pair.second = letter;
        }
        else if(isLowercase(letter))
        {
            pair.first = letter;
            pair.second = letter - 32;
        }
    }
    char lowercase()
    {
        return pair.first;
    }
    char uppercase()
    {
        return pair.second;
    }

    static bool isLowercase(char letter)
    {
        return (97 <= letter && letter <= 122);
    }
    static bool isUppercase(char letter)
    {
        return (65 <= letter && letter <= 90);
    }
};

int main()
{
    Letter letter;
    std::cout << letter.lowercase() << " " << letter.uppercase() << std::endl;
}