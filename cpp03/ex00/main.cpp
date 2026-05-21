/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:07:12 by vaires-m          #+#    #+#             */
/*   Updated: 2026/05/21 22:07:13 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::cout << "--- Creating ClapTraps ---" << std::endl;
    ClapTrap a("Alpha");
    ClapTrap b("Beta");

    std::cout << "\n--- Combat ---" << std::endl;
    a.attack("Beta");
    b.takeDamage(5);
    b.beRepaired(3);
    b.attack("Alpha");
    a.takeDamage(3);

    std::cout << "\n--- No energy points (attack 10 times to drain EP) ---" << std::endl;
    for (int i = 0; i < 10; i++)
        a.attack("Beta");
    a.attack("Beta");
    a.beRepaired(5);

    std::cout << "\n--- Copy constructor ---" << std::endl;
    ClapTrap c(b);
    c.attack("Alpha");

    std::cout << "\n--- Copy assignment ---" << std::endl;
    ClapTrap d("Delta");
    d = b;
    d.attack("Alpha");

    std::cout << "\n--- Death ---" << std::endl;
    b.takeDamage(999);
    b.attack("Alpha");
    b.beRepaired(10);

    std::cout << "\n--- Destructors (reverse order of creation) ---" << std::endl;
    return 0;
}
