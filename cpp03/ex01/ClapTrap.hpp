#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class Claptrap{
    protected:
        std::string Name;
        int HP;
        int EP;
        int AD;

    public:
        Claptrap(std::string name);
        Claptrap(const Claptrap& copy);
        Claptrap& operator=(const Claptrap& copy);
        ~Claptrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif