#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T& target1, T& target2)
{
    T temp;
    temp = target1;
    target1 = target2;
    target2 = temp;
}

template <typename T>
const T& max(const T& target1, const T& target2)
{
    if (target1 > target2)
        return target1;
    return target2;
}

template <typename T>
const T& min(const T& target1, const T& target2)
{
    if (target1 < target2)
        return target1;
    return target2;
}

#endif