#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *NewHorde = new Zombie[N];
    std::cout << "\nHorde created with " << N << " Zombies\n" << std::endl;
    for(int i = 0; N > i; i++)
        NewHorde[i].setName(name);
    return NewHorde;
}