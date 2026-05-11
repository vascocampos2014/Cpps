#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *NewZombie = new Zombie(name); // to allocate memory in the heap we use new to allocate raw data and call the objs constructor
    return NewZombie;
}