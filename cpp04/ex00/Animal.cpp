/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:03:44 by vasco             #+#    #+#             */
/*   Updated: 2026/05/21 22:05:44 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}

Animal& Animal::operator=(const Animal& copy)
{
    std::cout << "Animal copy assignment called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal: ..." << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}
