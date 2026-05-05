#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

// // human B doesnt needs to have a weapon and you can change the weapon after creation because its a pointer with a setWeapon fucntion

class HumanB{
    private:
        std::string name;
        Weapon *weapon;

    public:
        HumanB(std::string Name);
        ~HumanB();
        void setWeapon(Weapon &_weapon);
        void attack(void);
};

#endif