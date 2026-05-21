#include "ScavTrap.hpp"

int main()
{
    std::cout << "--- Construction chaining (ClapTrap first, then ScavTrap) ---" << std::endl;
    ScavTrap s("Scout");

    std::cout << "\n--- ScavTrap has different attack message and higher stats ---" << std::endl;
    s.attack("enemy");
    s.takeDamage(30);
    s.beRepaired(20);
    s.guardGate();

    std::cout << "\n--- Copy constructor (chaining visible) ---" << std::endl;
    ScavTrap s2(s);
    s2.attack("target");

    std::cout << "\n--- Copy assignment ---" << std::endl;
    ScavTrap s3("Ghost");
    s3 = s;
    s3.attack("target");

    std::cout << "\n--- Death ---" << std::endl;
    s.takeDamage(999);
    s.attack("enemy");
    s.guardGate();

    std::cout << "\n--- Destruction chaining (ScavTrap first, then ClapTrap) ---" << std::endl;
    return 0;
}
