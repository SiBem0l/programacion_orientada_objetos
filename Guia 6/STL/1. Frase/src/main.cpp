#include <iostream>
#include <list>

class Word
{
    std::list<char> m_data;

public:
    Word(const std::string& word)
    {
        for(const char& letter : word)
        {
            m_data.emplace_back(letter);
        }
    }
    void print_foward() const
    {
        for(const char& letter : m_data)
        {
            std::cout << letter;
        }
    }
    void print_backward() const 
    {
        for(std::list<char>::const_reverse_iterator it = m_data.rbegin(); 
            it != m_data.rend(); it++)
        {
            const char& letter = *it;
            std::cout << letter;
        }
    }
};

class Sentence
{
    std::list<Word> data;

public:
    Sentence()
    {
        std::string newStr = "";
        std::cout << "Add new word: ";
        std::cin >> newStr;
        while(newStr != "0")
        {
            data.emplace_back(Word(newStr));
            std::cout << "Add new word: ";
            std::cin >> newStr;
        }
    }
    void print_foward() const
    {
        for(const Word& word : data)
        {
            word.print_foward();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    void print_backward() const
    {
        for(std::list<Word>::const_reverse_iterator it = data.rbegin();
            it != data.rend(); it++)
        {
            const Word& word = *it;
            word.print_backward();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Sentence sentence;
    sentence.print_foward();
    sentence.print_backward();

    return 0;
}