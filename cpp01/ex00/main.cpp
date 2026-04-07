#include "Zombie.hpp"
#include <iostream>


Zombie* newZombie(std::string name);
void randomChump(std::string name);

int choices() 
{
    int choice;
    std::string name = "mario";
    Zombie* heapZombie = NULL; 

    while (true) 
    {
        std::cout << "\n[1] New Zombie\n[2] Random Chump\n[3] Announce & Delete\n[4] Exit\n\n";
        std::cin >> choice;

        if (choice == 1) {
            heapZombie = newZombie(name);
            std::cout << "\nCreated " << name << " on the heap.\n";
        }
        else if (choice == 2) {
            randomChump("tiago");
        }
        else if (choice == 3) {
            if (heapZombie != NULL) {
                heapZombie->announce(); 
                delete heapZombie;      
                heapZombie = NULL;      
            } else {
                std::cout << "\nNo heap zombie exists yet!\n";
            }
        }
        else break;
    }
    return 0;
}

int main() {
    choices();
    return 0;
}