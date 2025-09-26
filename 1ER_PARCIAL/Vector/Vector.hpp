#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iostream"
#define VECTOR_ELEMENT int
#define VECTOR_DEFAULT 0

class Vector
{
    friend std::ostream &operator<<(std::ostream &outStream, Vector &v);

private:
    VECTOR_ELEMENT *elements;
    int size;
    int maxSize;

    void incrementMaxSize();

public:
    // Constructor and destructor
    Vector(int size = 0);
    ~Vector();

    // Getter and setters
    int getSize();
    VECTOR_ELEMENT& operator[](int index);

    // Modifier
    void push_back(VECTOR_ELEMENT value);
    VECTOR_ELEMENT pop_back();
    void insert(int index, VECTOR_ELEMENT value);
    void erase(int index);
    void clear();
};

#endif