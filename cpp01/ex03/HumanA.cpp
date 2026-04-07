#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon &_weapon) : weapon(_weapon)
{
    this->name = Name; //name doestn need to be initialize on top because is a normal variable not a reference, references need to be inicitalized with a value
}

HumanA::~HumanA()
{

}

void HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}