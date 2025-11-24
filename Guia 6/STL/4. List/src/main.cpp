#include <iostream>
#include <list>

class Numbers
{
    std::list<int> m_data;

public:
    Numbers()
    {
        int number = readNumber();
        while(number != 0){
            addNumber(number);
            number = readNumber();
        }
    }
    static int readNumber()
    {
        int number = 0;
        std::cout << "Ingrese un numero: ";
        std::cin >> number;
        return number;
    }

    void addNumber(const int &number)
    {
        m_data.emplace_back(number);
    }

    void printForward()
    {
        for(const int& num : m_data)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    void printBackwards()
    {
        for(std::list<int>::const_reverse_iterator it = m_data.rbegin();
            it != m_data.rend(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Numbers numbers;
    numbers.printForward();
    numbers.printBackwards();
}