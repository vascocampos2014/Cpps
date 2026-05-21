/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:06:49 by vaires-m          #+#    #+#             */
/*   Updated: 2026/05/21 22:06:50 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain(); //cria o cerebro no heap
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*copy.brain); //deep copy: cria um novo Brain com os mesmos dados
}

Dog& Dog::operator=(const Dog& copy)
{
    std::cout << "Dog copy assignment called" << std::endl;
    if (this != &copy)
    {
        Animal::operator=(copy);
        delete this->brain;
        this->brain = new Brain(*copy.brain); //deep copy: substitui o Brain existente por uma nova copia
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain; //evita memory leak
}

void Dog::makeSound() const
{
    std::cout << "Dog: Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
    return (this->brain);
}
