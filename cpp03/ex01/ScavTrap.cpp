#include "ScapTrap.hpp"

ScavTrap::ScavTrap(std::string name) : Claptrap(name)
{
    std::cout << "Scavtrap default constructor called\n";
    this->AD = 20;
    this->HP = 100;
    this->EP = 50;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "Scavtrap destructor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
    std::cout << "Scavtrap copy assigment called\n";
    if (this != &copy)
        Claptrap::operator=(copy);
    return(*this);
}

ScavTrap::ScavTrap(const ScavTrap& copy) : Claptrap(copy)
{
    std::cout << "Scavtrap copy constructor called\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (this->HP <= 0)
    {
        std::cout << "ScavTrap " << this->Name << " is already dead!" << std::endl;
        return;
    }
    if (this->EP == 0)
    {
        std::cout << "ScavTrap " << this->Name << " has no energy points!" << std::endl;
        return;
    }
    this->EP--;
    std::cout << "ScavTrap " << this->Name << " savagely attacks " << target
              << ", causing " << this->AD << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    if (this->HP <= 0)
    {
        std::cout << "ScavTrap " << this->Name << " is dead and cannot guard!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->Name << " is now in Gate keeper mode!" << std::endl;
}
