/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:06:55 by vaires-m          #+#    #+#             */
/*   Updated: 2026/05/21 22:06:56 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
    protected:
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& copy);
        WrongAnimal& operator=(const WrongAnimal& copy);
        ~WrongAnimal(); //sem virtual: o destructor correto nao e chamado ao deletar por ponteiro base
        void makeSound() const; //sem virtual: sempre chama esta versao, mesmo com ponteiro base a apontar para derivada
        std::string getType() const;
};

#endif
