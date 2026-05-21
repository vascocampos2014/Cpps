/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:07:30 by vaires-m          #+#    #+#             */
/*   Updated: 2026/05/21 22:07:31 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{ //heranca publica: scavTrap herda todos os membros publicos/protected de clap
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& copy);
        ScavTrap& operator=(const ScavTrap& copy);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
};

#endif