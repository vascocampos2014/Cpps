/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:07:35 by vaires-m          #+#    #+#             */
/*   Updated: 2026/05/21 22:07:36 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name(""), HP(10), EP(10), AD(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : Name(name), HP(10), EP(10), AD(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
    std::cout << "ClapTrap copy assignment called" << std::endl;
    if (this != &copy)
    {
        this->Name = copy.Name;
        this->AD = copy.AD;
        this->HP = copy.HP;
        this->EP = copy.EP;
    }
    return (*this);
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    if (this != &copy)
        *this = copy;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->HP <= 0)
    {
        std::cout << "ClapTrap " << this->Name << " is already dead!" << std::endl;
        return;
    }
    if (this->EP == 0)
    {
        std::cout << "ClapTrap " << this->Name << " has no energy points!" << std::endl;
        return;
    }
    this->EP--;
    std::cout << "ClapTrap " << this->Name << " attacks " << target
              << ", causing " << this->AD << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HP <= 0)
    {
        std::cout << "ClapTrap " << this->Name << " is already dead!" << std::endl;
        return;
    }
    this->HP -= amount;
    std::cout << "ClapTrap " << this->Name << " took " << amount << " damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->HP <= 0)
    {
        std::cout << "ClapTrap " << this->Name << " is already dead!" << std::endl;
        return;
    }
    if (this->EP == 0)
    {
        std::cout << "ClapTrap " << this->Name << " has no energy points!" << std::endl;
        return;
    }
    this->EP--;
    this->HP += amount;
    std::cout << "ClapTrap " << this->Name << " repaired " << amount << " hit points!" << std::endl;
}
