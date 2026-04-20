#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScapTrap.hpp"

class FragTrap : public Claptrap{
    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap& copy);
        FragTrap& operator=(const FragTrap& copy);
        ~FragTrap();
        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif