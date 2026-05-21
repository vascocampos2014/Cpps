#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->HP = 100;
    this->EP = 100;
    this->AD = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) //chama o construtor da classe pai antes de executar o proprio
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->HP = 100;
    this->EP = 100;
    this->AD = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& copy)
{
    std::cout << "FragTrap copy assignment called" << std::endl;
    if (this != &copy)
        ClapTrap::operator=(copy); //chama o operator= da classe pai para copiar os atributos herdados
    return (*this);
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) //passa o objeto ao copy constructor da classe pai
{
    std::cout << "FragTrap copy constructor called" << std::endl;
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
    std::cout << "FragTrap " << this->Name << " violently attacks " << target
              << ", causing " << this->AD << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->Name << " is requesting a high five!" << std::endl;
}
