/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:06:51 by vaires-m          #+#    #+#             */
/*   Updated: 2026/05/21 22:06:52 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    //Animal a; //nao compila: Animal e agora abstrata, nao pode ser instanciada

    std::cout << "--- Array of 10 Animals (5 Dogs, 5 Cats) ---" << std::endl;
    const Animal* animals[10];
    for (int i = 0; i < 5; i++)
        animals[i] = new Dog();
    for (int i = 5; i < 10; i++)
        animals[i] = new Cat();

    std::cout << "\n--- makeSound through base pointer ---" << std::endl;
    for (int i = 0; i < 10; i++)
        animals[i]->makeSound();

    std::cout << "\n--- Deleting array ---" << std::endl;
    for (int i = 0; i < 10; i++)
        delete animals[i];

    std::cout << "\n--- Deep copy test ---" << std::endl;
    Cat c1;
    c1.getBrain()->ideas[0] = "sleep all day";
    Cat c2(c1);
    std::cout << "c1 idea[0]: " << c1.getBrain()->ideas[0] << std::endl;
    std::cout << "c2 idea[0]: " << c2.getBrain()->ideas[0] << std::endl;
    c2.getBrain()->ideas[0] = "hunt mice";
    std::cout << "After changing c2's idea:" << std::endl;
    std::cout << "c1 idea[0]: " << c1.getBrain()->ideas[0] << std::endl;
    std::cout << "c2 idea[0]: " << c2.getBrain()->ideas[0] << std::endl;

    std::cout << "\n--- Destructors ---" << std::endl;
    return 0;
}
