#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void printT(T& value)
{
    std::cout << value;
}

template <typename T, typename F>
void iter(T* address, const unsigned int length, F function)
{
    for (unsigned int i = 0; i < length; i++)
        function(address[i]);
}

#endif