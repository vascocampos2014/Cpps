#include "FragTrap.hpp"

int main()
{
    FragTrap f("Frag");
    f.attack("enemy");
    f.takeDamage(10);
    f.beRepaired(5);
    f.highFivesGuys();

    f.takeDamage(200);
    f.attack("enemy");

    return 0;
}
