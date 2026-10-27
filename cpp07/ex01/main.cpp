#include "iter.hpp"

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5};
    std::string words[] = {"hello", "world"};
    char c[] = {'a','b','c','d','e'};

    iter(numbers, 5, printT<int>);
    std::cout << std::endl;
    iter(words, 2, printT<std::string>);
    std::cout << std::endl;
    iter(c, 5, printT<char>);
    std::cout << std::endl;
    return (0);
}