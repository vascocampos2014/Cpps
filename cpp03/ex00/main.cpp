#include "ClapTrap.hpp"

int main()
{
    std::cout << "--- Basic usage ---" << std::endl;
    Claptrap a("Alpha");
    a.attack("Beta");
    a.takeDamage(5);
    a.beRepaired(3);

    std::cout << "\n--- Copy constructor ---" << std::endl;
    Claptrap b(a);

    std::cout << "\n--- Copy assignment ---" << std::endl;
    Claptrap c("Gamma");
    c = a;

    std::cout << "\n--- Death: take lethal damage then try actions ---" << std::endl;
    a.takeDamage(100);
    a.beRepaired(5);
    a.attack("target");

    std::cout << "\n--- Destructors ---" << std::endl;
    return 0;
}