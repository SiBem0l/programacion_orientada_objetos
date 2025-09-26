#include <iostream>
#include "Vector.hpp"

// Constructor and destructor
Vector::Vector(int newMaxSize)
{
    size = 0;
    maxSize = newMaxSize;
    elements = new VECTOR_ELEMENT[newMaxSize];
}

Vector::~Vector()
{
    delete[] elements;
}

void Vector::incrementMaxSize()
{
    maxSize = (maxSize + 1)*2;
    VECTOR_ELEMENT *newElements = new VECTOR_ELEMENT[maxSize];
    memmove((void*)newElements, (void*)elements, size*sizeof(VECTOR_ELEMENT));
    delete[] elements;
    elements = newElements;
}

// Getters and setters
int Vector::getSize()
{
    return size;
}

VECTOR_ELEMENT& Vector::operator[](int index)
{
    return elements[index];
}

// Modifiers
void Vector::push_back(VECTOR_ELEMENT value)
{
    if(size >= maxSize)
    {
        incrementMaxSize();
    }
    elements[size] = value;
    size++;
}

VECTOR_ELEMENT Vector::pop_back()
{
    VECTOR_ELEMENT backElement = VECTOR_DEFAULT;
    if(size > 0)
    {
        size--;
        backElement = elements[size];
        elements[size] = VECTOR_DEFAULT;
    }
    return backElement;
}

void Vector::insert(int index, VECTOR_ELEMENT value)
{
    if(size >= maxSize)
    {
        incrementMaxSize();
    }
    // memmove((void*)elements[index + 1], (void*)elements[index], sizeof(VECTOR_ELEMENT)*(size-index));
    for(int i = size; i > index; i--)
    {
        elements[i] = elements[i-1];
    }
    elements[index] = value;
    size++;
}

void Vector::erase(int index)
{
    if(0 < index && index <= size)
    {
        for(int i = index; i < size; i++)
        {
            elements[index] = elements[index+1];
        }
        size--;
    }
}

void Vector::clear()
{
    size = 0;
}

// Console print
std::ostream &operator<<(std::ostream &outStream, Vector &v)
{
    for(int i = 0; i < v.size; i++)
    { 
        VECTOR_ELEMENT element = v[i];
        outStream << "Elements number " << i << ": " << element << std::endl;
    }
    return outStream;
}