#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class Vector
{
public:
    // Define all the types for the template
    using size_type = std::size_t;

    // Constructor and copying
    Vector();
    Vector(const Vector& v);
    Vector(const size_type& capacity);

    // Vector right value
    Vector(Vector&& v);



private:
    // Capacity:
    size_type size = 0;
    size_type capacity = 0;
    
    // Elements of the vector
    T* data;
};

#endif