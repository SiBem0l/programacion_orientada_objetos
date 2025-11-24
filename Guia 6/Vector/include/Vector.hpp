#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class Vector
{
public:
    // Define all the types for the template
    using size_type = std::size_t;


    // Constructor destructor and copying
    Vector();
    Vector(Vector&& v);
    Vector(size_type capacity);
    Vector(size_type capacity, const T& value);

    ~Vector();

    Vector(const Vector& v);
    Vector<T>& operator=(const Vector& v);


    // Capacity
    size_type size() const;
    size_type capacity() const;

    void resize(size_type n, const T& value);
    void resize(size_type n);
    void reserve(size_type n);
    
    bool empty() const;


    // Access to elements
    T& operator[](size_type index);
    const T& operator[](size_type index) const;
    
    T& at(size_type index);
    const T& at(size_type index) const;

    T* data();
    const T* data() const;


    // Modifiers
    void push_back(const T& element);
    void pop_back();
    void emplace_back(T&& element);

private:
    // Capacity:
    size_type m_size = 0;
    size_type m_capacity = 0;

    // Elements of the vector
    T* m_data = nullptr;

};


// Constructord destructor and copying
template <typename T>
Vector<T>::Vector() = default;

template <typename T>
Vector<T>::Vector(Vector&& v)
    : m_size(v.size()),
      m_capacity(v.capacity()),
      m_data(v.data())
{
    v.m_size = 0;
    v.m_capacity = 0;
    v.m_data = nullptr;
}

template <typename T>
Vector<T>::Vector(size_type newCapacity)
    : m_size(newCapacity),
      m_capacity(newCapacity),
      m_data(new T[newCapacity])
{
}

template <typename T>
Vector<T>::Vector(size_type newCapacity, const T &value)
    : m_size(newCapacity),
      m_capacity(newCapacity),
      m_data(new T[newCapacity])
{
    for(size_type i = 0; i < capacity(); i++)
    {
        data()[i] = value;
    }
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] m_data;
}

template <typename T>
Vector<T>::Vector(const Vector &v)
    : m_size(v.size()),
      m_capacity(v.capacity()),
      m_data(new T[v.capacity()])
{
    for (size_type i = 0; i < capacity(); i++)
    {
        data()[i] = v.data()[i];
    }
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &v)
{
    resize(v.size());
    for (size_type i = 0; i < v.size(); i++)
    {
        data()[i] = v.data()[i];
    }
    return *this;
}


// Capacity
template <typename T>
Vector<T>::size_type Vector<T>::size() const
{
    return m_size;
}

template <typename T>
Vector<T>::size_type Vector<T>::capacity() const
{
    return m_capacity;
}

template <typename T>
void Vector<T>::resize(size_type n)
{
    if(n > size() && n > capacity())
    {
        reserve(n);
    }
    m_size = n;
}
// void resize(size_type n, T value);

template <typename T>
void Vector<T>::reserve(size_type n)
{
    if(n > capacity())
    {
        T *newData = new T[n];
        for(size_type i = 0; i < size(); i++)
        {
            newData[i] = m_data[i];
        }
        delete[] m_data;
        m_data = newData;
        m_capacity = n;
    }
}

template <typename T>
bool Vector<T>::empty() const
{
    return size() == 0;
}


// Access to elements
template <typename T>
T& Vector<T>::operator[](size_type index)
{
    return data()[index];
}
template <typename T>
const T& Vector<T>::operator[](size_type index) const
{
    return data()[index];
}

template <typename T>
T& Vector<T>::at(size_type index)
{
    if(index >= size())
    {
        throw std::out_of_range("at index out of range");
    }
    return data()[index];
}
template <typename T>
const T& Vector<T>::at(size_type index) const
{
    if(index >= size())
    {
        throw(std::out_of_range());
    }
    return data()[index]; 
}

template <typename T>
T* Vector<T>::data()
{
    return m_data;
}
template <typename T>
const T* Vector<T>::data() const
{
    return m_data;
}


// Modifiers
template <typename T>
void Vector<T>::push_back(const T& element)
{
    size_type currentSize = size();
    if(currentSize >= capacity)
    {
        reserve(2*currentSize + 1);
    }
    data()[currentSize] = element; 
    size++;
}

template <typename T>
void Vector<T>::pop_back()
{
    if(!isEmpty())
    {
        size--;
    }
}

template <typename T>
void Vector<T>::emplace_back(T&& element)
{
    size_type currentSize = size();
    if(currentSize >= capacity)
    {
        reserve(2*currentSize+1);
    }
    new (&data()[m_size]) T(std::move(element));
    size++;
}

#endif