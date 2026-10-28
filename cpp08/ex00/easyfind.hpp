#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, const int& value);

#include "easyfind.tpp"

#endif