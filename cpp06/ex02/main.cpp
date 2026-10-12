#include "identify.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    for (int i = 0; i < 5; i++)
    {
        Base* obj = generate();

        std::cout << "Test " << i + 1 << std::endl;
        std::cout << "  identify(Base*): ";
        identify(obj);
        std::cout << "  identify(Base&): ";
        identify(*obj);
        delete obj;
    }

    std::cout << "Test with a plain Base" << std::endl;
    Base base;
    std::cout << "  identify(Base*): ";
    identify(&base);
    std::cout << "  identify(Base&): ";
    identify(base);

    std::cout << "Test with NULL" << std::endl;
    std::cout << "  identify(Base*): ";
    identify(static_cast<Base*>(NULL));
    return 0;
}
