#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : Claptrap(name)
{
    std::cout << "FragTrap default constructor called\n";
    this->AD = 30;
    this->HP = 100;
    this->EP = 100;
}

FragTrap::~FragTrap() 
{
    std::cout << "FragTrap destructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
    std::cout << "FragTrap copy assigment called\n";
    if (this != &copy)
        Claptrap::operator=(copy);
    return(*this);
}

FragTrap::FragTrap(const FragTrap& copy) : Claptrap(copy)
{
    std::cout << "FragTrap copy constructor called\n";
}

void FragTrap::attack(const std::string& target)
{
    if (this->HP <= 0)
    {
        std::cout << "FragTrap " << this->Name << " is already dead!" << std::endl;
        return;
    }
    if (this->EP == 0)
    {
        std::cout << "FragTrap " << this->Name << " has no energy points!" << std::endl;
        return;
    }
    this->EP--;
    std::cout << "FragTrap " << this->Name << " savagely attacks " << target
              << ", causing " << this->AD << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap is requesting a highfive!\n";
}