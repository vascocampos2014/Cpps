#include "HumanB.hpp"

HumanB::HumanB(std::string Name)
{
    this->name = Name;
    this->weapon = NULL;
}

HumanB::~HumanB()
{

}

void HumanB::setWeapon(Weapon &_weapon)
{
    this->weapon = &_weapon;
}

void HumanB::attack(void)
{
    if (this->weapon == NULL)
        std::cout << this->name << " doesnt have a weapon\n";
    else
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}