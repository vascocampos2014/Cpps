#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

// human A always needs to have a weapon and you cant change the weapon after creation because its a reference
// and you cant rebind references

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