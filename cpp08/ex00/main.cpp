#include "easyfind.hpp"

template <typename T>
void testFind(T& container, int value, const char* containerName)
{
    try
    {
        typename T::iterator it = easyfind(container, value);
        std::cout << containerName << ": found " << value
                  << " (returned value: " << *it << ")" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << containerName << ": could not find " << value
                  << " (" << e.what() << ")";
    }
}

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(10);

    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(10);

    testFind(v, 1, "vector (first element)");
    testFind(v, 10, "vector (last element)");
    testFind(v, 42, "vector (missing element)");

    testFind(l, 5, "list (middle element)");
    testFind(l, 10, "list (last element)");
    testFind(l, -1, "list (missing element)");
}