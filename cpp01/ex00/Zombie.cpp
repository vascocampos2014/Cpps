#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
}

Zombie::~Zombie()
{
        std::cout << this->_name << "has been deleted\n";
}

void Zombie::announce( void )
{
    std::cout << std::endl << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
