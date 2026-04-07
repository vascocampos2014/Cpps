#include "Zombie.hpp"

int main()
{
    int choice;
    int i = 0;
    int N;
    Zombie *NewHorde = NULL;
    while(1)
    {
        std::cout << "[1] Created horde\n[2] Anounce horde\n[3] Exit\nOption: ";
        std::cin >> choice;
        if(choice == 1)
        {
            if(NewHorde != NULL)
            {
                delete[] NewHorde;
                NewHorde = NULL;
            }
            std::cout << "\nhow many zombies you want the horde to have: ";
            std::cin >> N;
            NewHorde = zombieHorde(N,"test");
        }
        if(choice == 2)
        {
            if(NewHorde == NULL)
                std::cout << "\nhorde not created yet press 1 first\n\n";
            else
            {
                while(i < N)
                {
                    NewHorde[i].announce();
                    i++;
                }
                std::cout << std::endl << std::endl;
            }
        }
        if(choice == 3)
            break;
    }
    if(NewHorde != NULL)
        delete[] NewHorde;
    return(1);
}