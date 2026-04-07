#include "Zombie.hpp"

Zombie::Zombie()
{

};


void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie killed " << this->name << std::endl;
}

void Zombie::announce(void)
{
    std::cout << std::endl << this->name << ": BraiiiiiiinnnzzzZ...";
}