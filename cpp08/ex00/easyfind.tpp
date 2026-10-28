#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, const int& value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
    {
        throw std::runtime_error("Error: Value not found in the container.\n");
    }
    return it;
}
