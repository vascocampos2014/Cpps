/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:06:17 by vaires-m          #+#    #+#             */
/*   Updated: 2026/05/21 22:06:22 by vaires-m         ###   ########.fr       */
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
        virtual ~Animal(); //virtual para garantir que o destructor correto e chamado ao deletar por ponteiro base
        virtual void makeSound() const; //virtual permite que classes derivadas sobrescrevam este metodo (polimorfismo)
        std::string getType() const;
};

#endif
