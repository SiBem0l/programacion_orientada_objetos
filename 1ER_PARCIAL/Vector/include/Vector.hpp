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

    int getMaxSize() const;
    void incrementMaxSize();

public:
    Vector(int newMaxSize = 0);
    Vector(int size, VECTOR_ELEMENT value);
    ~Vector();
    Vector& operator=(const Vector v);

    int getSize() const;
    void setAll(VECTOR_ELEMENT value);
    VECTOR_ELEMENT& operator[](int index);
    const VECTOR_ELEMENT& operator[](int index) const;

    void push_back(VECTOR_ELEMENT value);
    VECTOR_ELEMENT pop_back();

    void insert(int index, VECTOR_ELEMENT value);
    void erase(int index);
    void clear();
};

#endif