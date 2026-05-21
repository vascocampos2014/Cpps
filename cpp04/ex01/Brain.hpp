/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:06:25 by vaires-m          #+#    #+#             */
/*   Updated: 2026/05/21 22:06:26 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
    public:
        std::string ideas[100];

        Brain();
        Brain(const Brain& copy);
        Brain& operator=(const Brain& copy);
        ~Brain();
};

#endif
