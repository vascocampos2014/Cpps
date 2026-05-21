/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:03:53 by vasco             #+#    #+#             */
/*   Updated: 2026/05/21 22:05:56 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
    std::cout << "Dog copy assignment called" << std::endl;
    if (this != &copy)
        Animal::operator=(copy);
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog: Woof! Woof!" << std::endl;
}
