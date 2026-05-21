/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:07:39 by vaires-m          #+#    #+#             */
/*   Updated: 2026/05/21 22:07:40 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{ //heranca publica: FragTrap herda todos os membros publicos/protected de ClapTrap
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& copy);
        FragTrap& operator=(const FragTrap& copy);
        ~FragTrap();
        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif
