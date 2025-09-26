#include <iostream>
#include "Vector.hpp"

// Constructor and destructor
Vector::Vector(int newMaxSize)
{
    size = 0;
    maxSize = newMaxSize;
    elements = new VECTOR_ELEMENT[newMaxSize];
}
Vector::Vector(int newSize, VECTOR_ELEMENT value)
{
    size = newSize;
    maxSize = 2*newSize;
    elements = new VECTOR_ELEMENT[maxSize];
    setAll(value);
}

Vector::~Vector()
{
    delete[] elements;
}

Vector& Vector::operator=(const Vector v)
{
    clear();
    for(int index = 0; index < size; index++)
    {
        push_back(v[index]);
    }
    return *this;
}

int Vector::getMaxSize() const
{
    return maxSize;
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
int Vector::getSize() const
{
    return size;
}

void Vector::setAll(int value)
{
    for(int i = 0; i < size; i++)
    {
        (*this)[i] = value;
    }
}

VECTOR_ELEMENT& Vector::operator[](int index)
{
    return elements[index];
}

const VECTOR_ELEMENT& Vector::operator[](int index) const
{
    return elements[index];
}


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