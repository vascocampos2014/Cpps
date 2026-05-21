#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "--- Both inherit from ClapTrap but have different stats ---" << std::endl;
    ScavTrap s("Scout");
    FragTrap f("Frag");

    std::cout << "\n--- ScavTrap: 100hp / 50ep / 20ad ---" << std::endl;
    s.attack("Frag");
    s.takeDamage(40);
    s.beRepaired(10);
    s.guardGate();

    std::cout << "\n--- FragTrap: 100hp / 100ep / 30ad ---" << std::endl;
    f.attack("Scout");
    f.takeDamage(40);
    f.beRepaired(10);
    f.highFivesGuys();

    std::cout << "\n--- Copy constructor ---" << std::endl;
    FragTrap f2(f);
    f2.attack("Scout");

    std::cout << "\n--- Death ---" << std::endl;
    f.takeDamage(999);
    f.attack("Scout");
    f.highFivesGuys();

    std::cout << "\n--- Destruction (reverse order of creation) ---" << std::endl;
    return 0;
}
