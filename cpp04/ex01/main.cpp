/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:06:34 by vaires-m          #+#    #+#             */
/*   Updated: 2026/05/21 22:06:35 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "--- Array of 10 Animals (5 Dogs, 5 Cats) ---" << std::endl;
    const Animal* animals[10];
    for (int i = 0; i < 5; i++)
        animals[i] = new Dog();
    for (int i = 5; i < 10; i++)
        animals[i] = new Cat();

    std::cout << "\n--- makeSound through base pointer (virtual dispatch) ---" << std::endl;
    for (int i = 0; i < 10; i++)
        animals[i]->makeSound();

    std::cout << "\n--- Deleting array (virtual destructor ensures Brain is deleted) ---" << std::endl;
    for (int i = 0; i < 10; i++)
        delete animals[i];

    std::cout << "\n--- Deep copy test ---" << std::endl;
    Dog d1;
    d1.getBrain()->ideas[0] = "chase the ball";
    Dog d2(d1); //copy constructor: d2 gets its own Brain
    std::cout << "d1 idea[0]: " << d1.getBrain()->ideas[0] << std::endl;
    std::cout << "d2 idea[0]: " << d2.getBrain()->ideas[0] << std::endl;
    d2.getBrain()->ideas[0] = "sleep";
    std::cout << "After changing d2's idea:" << std::endl;
    std::cout << "d1 idea[0]: " << d1.getBrain()->ideas[0] << std::endl; //must stay unchanged
    std::cout << "d2 idea[0]: " << d2.getBrain()->ideas[0] << std::endl;

    std::cout << "\n--- Destructors ---" << std::endl;
    return 0;
}
