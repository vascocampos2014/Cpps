/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:06:42 by vaires-m          #+#    #+#             */
/*   Updated: 2026/05/21 22:06:43 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
    protected:
        std::string type;

    public:
        Animal();
        Animal(const Animal& copy);
        Animal& operator=(const Animal& copy);
        virtual ~Animal();
        virtual void makeSound() const = 0; //pure virtual: torna Animal uma classe abstrata, nao pode ser instanciada diretamente
        std::string getType() const;
};

#endif
