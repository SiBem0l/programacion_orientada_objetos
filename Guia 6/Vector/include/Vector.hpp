#ifndef VECTOR_HPP
#define VECTOR_HPP

template<typename T = int, int _size = 10> class Vector
{
private:
    T elements[lenght] = 0;
    int size = _size;

public:
    T &operator[](int index) { return elements[index]; }
    T max() const 
    { 
        T max = element[0]; 
        for(auto elem : elements) 
        {
            max = (max < elem) elem : max;
        }
        return max;
    }
    void fill(T value)
    {
        for(auto elem : elements)
        {
            elem = value;
        }
    }
};

#endif