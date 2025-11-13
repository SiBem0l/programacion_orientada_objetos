#include <iostream>
#include "Vector.hpp"

template <typename T> void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T> T max(const T &a, const T &b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a = 2;
    int b = 3;

    std::cout << "a: " << a << std::endl; 
    std::cout << "b: " << b << std::endl << std::endl;
    
    swap(a, b);
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl << std::endl;
}