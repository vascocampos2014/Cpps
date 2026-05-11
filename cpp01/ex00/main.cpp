#include "Zombie.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>


Zombie* newZombie(std::string name);
void randomChump(std::string name);

int choices() 
{
    int choice;
    std::string name = "mario";
    Zombie* heapZombie = NULL; 
    std::string line;

    while (true) 
    {
        std::cout << "\n[1] New Zombie\n[2] Random Chump\n[3] Announce & Delete\n[4] Exit\n\n";
        getline(std::cin, line);
        std::istringstream iss(line);
        if (line.empty())
            std::cout << "\nWrite option number\n";
        char extra;
        if ((iss >> choice) && !(iss >> extra) && (choice == 1 || choice == 2 || choice == 3 || choice == 4))
        {
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
                    delete heapZombie;   // delete clears the memory in the heap and calls the objs destructor   
                    heapZombie = NULL;      
                } else {
                    std::cout << "\nNo heap zombie exists yet!\n";
                }
            }
            else if(choice == 4)
                std::exit(0);
        }
        else
            std::cout << "\nInsert valid number\n";
    }
    return 0;
}

int main() {
    choices();
    return 0;
}