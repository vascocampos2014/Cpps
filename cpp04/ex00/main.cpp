/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:06:03 by vaires-m          #+#    #+#             */
/*   Updated: 2026/05/22 14:14:44 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "--- Subject test ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound(); //calls Cats makeSound via virtual dispatch
    j->makeSound(); //calls Dogs makeSound via virtual dispatch
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    std::cout << "\n--- WrongAnimal test: no virtual, always calls base ---" << std::endl;
    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();
    std::cout << wc->getType() << std::endl;
    wc->makeSound(); //calls WrongAnimal's makeSound, nao WrongCat, porque nao e virtual
    wa->makeSound();
    delete wa;
    delete wc;

    std::cout << "\n--- Stack objects: destruction order ---" << std::endl;
    Dog d1;
    Cat c1;
    d1.makeSound();
    c1.makeSound();

    return 0;
}
