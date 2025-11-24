#include <iostream>
#include "Vector.hpp"

int main()
{
    Vector<int> vectorA(10, 0);
    Vector<int> vectorB(vectorA);
    Vector<int> vectorC(std::move(vectorB));
    
    vectorA[0] = 1;
    vectorA[1] = 2;
    vectorA[2] = 3;
    
    vectorB = vectorA;
    
    vectorA.reserve(11);
    vectorA.reserve(5);
    vectorA.resize(15);
    vectorA.resize(12);
    for(Vector<int>::size_type i = 0; i < vectorA.size(); i++)
    {
        vectorA[i] = 101;
    }
}