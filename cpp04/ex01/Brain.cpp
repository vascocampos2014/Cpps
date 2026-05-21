/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:06:23 by vaires-m          #+#    #+#             */
/*   Updated: 2026/05/21 22:06:24 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = copy;
}

Brain& Brain::operator=(const Brain& copy)
{
    std::cout << "Brain copy assignment called" << std::endl;
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = copy.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}
