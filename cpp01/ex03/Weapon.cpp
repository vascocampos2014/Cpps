#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->Type = type;
}

Weapon::~Weapon()
{

}

const std::string& Weapon::getType(void)
{
    return(this->Type);
}

void Weapon::setType(const std::string& type)
{
    this->Type = type;
}
