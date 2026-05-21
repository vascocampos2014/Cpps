/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:07:42 by vaires-m          #+#    #+#             */
/*   Updated: 2026/05/21 22:07:43 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->HP = 100;
    this->EP = 50;
    this->AD = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) //chama o construtor da classe pai antes de executar o proprio
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->HP = 100;
    this->EP = 50;
    this->AD = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
    std::cout << "ScavTrap copy assignment called" << std::endl;
    if (this != &copy)
        ClapTrap::operator=(copy); //chama o operator= da classe pai para copiar os atributos herdados
    return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) //passa o objeto ao copy constructor da classe pai
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
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
    std::cout << "ScavTrap " << this->Name << " is now in Gate keeper mode!" << std::endl;
}
