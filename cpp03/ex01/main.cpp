#include "ScapTrap.hpp"

int main()
{
    ScavTrap s("Scout");
    s.attack("enemy");
    s.takeDamage(10);
    s.beRepaired(5);
    s.guardGate();

    s.takeDamage(200);
    s.attack("enemy");

    return 0;
}
