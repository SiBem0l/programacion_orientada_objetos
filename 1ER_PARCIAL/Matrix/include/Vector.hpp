#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

#define VECTOR_ELEMENT float
#define VECTOR_ELEMENT_DEFAULT 0
#define VECTOR_ERROR Vector(0)

class Vector
{
    friend std::ostream &operator<<(std::ostream &outStream, Vector &v);

private:
    VECTOR_ELEMENT *elements;
    int size;
    int maxSize;

    int getMaxSize() const;

public:
    // Constructor and destructor
    Vector(int newMaxSize = 0);
    Vector(const Vector& v);
    Vector(int size, VECTOR_ELEMENT value);
    ~Vector();

    // Getters and setters
    VECTOR_ELEMENT& operator[](int index);
    const VECTOR_ELEMENT& operator[](int index) const;
    int getSize() const;
    void setAll(VECTOR_ELEMENT value);

    void push_back(VECTOR_ELEMENT value);
    VECTOR_ELEMENT pop_back();

    void insert(int index, VECTOR_ELEMENT value);
    void erase(int index);
    void clear();

    void resize(int newMaxSize);

    // Operations
    Vector operator*(const VECTOR_ELEMENT& factor) const;
    Vector operator/(const VECTOR_ELEMENT& factor) const;

    // Asignation
    Vector& operator=(const Vector& v);
    Vector& operator*=(const VECTOR_ELEMENT& factor);
    Vector& operator/=(const VECTOR_ELEMENT& factor);
};

#endif