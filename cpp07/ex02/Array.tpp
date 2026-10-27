#include "Array.hpp"

template <typename T>
Array<T>::Array() : _n(0), _data(NULL)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n), _data(new T[n]())
{
}

template <typename T>
Array<T>::Array(const Array& copy) : _n(copy._n), _data(new T[copy._n])
{
    for (unsigned int i = 0; i < _n; ++i)
        _data[i] = copy._data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
    if (this != &copy)
    {
        T* newData = new T[copy._n];
        for (unsigned int i = 0; i < copy._n; ++i)
            newData[i] = copy._data[i];
        delete[] _data;
        _data = newData;
        _n = copy._n;
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] _data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _n)
        throw std::out_of_range("Array index out of bounds");
    return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _n)
        throw std::out_of_range("Array index out of bounds");
    return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _n;
}