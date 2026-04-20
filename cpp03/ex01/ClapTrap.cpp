#include "ClapTrap.hpp"

Claptrap::Claptrap(std::string name)
{
    std::cout << "Claptrap default constructor called" << std::endl;
    this->Name = name;
    this->HP = 10;
    this->EP = 10;
    this->AD = 0;
}

Claptrap::~Claptrap()
{
    std::cout << "Claptrap destructor called\n";
}

Claptrap& Claptrap::operator=(const Claptrap& copy)
{
    std::cout << "Claptrap copy assignment called" << std::endl;
    if (this != &copy)
    {
        this->Name = copy.Name;
        this->AD = copy.AD;
        this->HP = copy.HP;
        this->EP = copy.EP;
    }
    return(*this);
}

Claptrap::Claptrap(const Claptrap& copy)
{
    std::cout << "Claptrap copy constructor called" << std::endl;
    if(this != &copy)
        *this = copy;
}

void Claptrap::attack(const std::string& target)
{
    if (this->HP <= 0)
    {
        std::cout << "ClapTrap " << this->Name << " is already dead!" << std::endl;
        return;
    }
    if (this->EP == 0)
    {
        std::cout << "No Energy points" << std::endl;
        return;
    }
    this->EP--;
    std::cout << "ClapTrap " << this->Name << " attacks " << target << " , causing " << this->AD << " points of damage!" << std::endl;
}

void Claptrap::takeDamage(unsigned int amount)
{
    if (this->HP <= 0)
    {
        std::cout << "ClapTrap " << this->Name << " is already dead!" << std::endl;
        return;
    }
    this->HP -= amount;
    std::cout << "ClapTrap " << this->Name << " took " << amount << " damage!" << std::endl;
}

void Claptrap::beRepaired(unsigned int amount)
{
    if (this->HP <= 0)
    {
        std::cout << "ClapTrap " << this->Name << " is already dead!" << std::endl;
        return;
    }
    if (this->EP == 0)
    {
        std::cout << "No Energy points\n";
        return;
    }
    std::cout << "ClapTrap " << this->Name << " Repaired: " << amount << std::endl;
    this->EP--;
    this->HP += amount;
}

