#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *NewHorde = new Zombie[N]; // new[] for an array calls multiple constructors for each obj created
    std::cout << "\nHorde created with " << N << " Zombies\n" << std::endl;
    for(int i = 0; N > i; i++)
        NewHorde[i].setName(name);
    return NewHorde;
}