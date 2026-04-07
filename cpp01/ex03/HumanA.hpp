#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
    private:
        std::string name;
        Weapon &weapon;

    public:
        HumanA(std::string Name, Weapon &_weapon);
        ~HumanA();
        void attack(void);
};

#endif