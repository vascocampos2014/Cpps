/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:06:26 by vaires-m          #+#    #+#             */
/*   Updated: 2026/05/21 22:06:27 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain(*copy.brain);
}

Cat& Cat::operator=(const Cat& copy)
{
    std::cout << "Cat copy assignment called" << std::endl;
    if (this != &copy)
    {
        Animal::operator=(copy);
        delete this->brain;
        this->brain = new Brain(*copy.brain);
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "Cat: Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
    return (this->brain);
}
