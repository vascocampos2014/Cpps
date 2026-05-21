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
