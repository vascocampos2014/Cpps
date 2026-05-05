#include "Zombie.hpp"

int main()
{
    int choice;
    int N;
    std::string nbrHorde;
    std::string line;
    Zombie *NewHorde = NULL;
    while(1)
    {
        std::cout << "[1] Created horde\n[2] Anounce horde\n[3] Exit\nOption: ";
        getline(std::cin, line);
        std::istringstream iss(line);
        char extra;
        if ((iss >> choice) && !(iss >> extra) && (choice == 1 || choice == 2 || choice == 3))
        {
            if(choice == 1)
            {
                if(NewHorde != NULL)
                {
                    delete[] NewHorde;
                    NewHorde = NULL;
                }
                while (true)
                {
                    std::cout << "\nhow many zombies you want the horde to have: ";
                    getline(std::cin, nbrHorde);
                    if (!nbrHorde.empty() && nbrHorde.find_first_not_of("0123456789") == std::string::npos)
                    {
                        std::istringstream iss1(nbrHorde);
                        iss1 >> N;
                        break;
                    }
                    std::cout << "\nInput valid number: ";
                }
                NewHorde = zombieHorde(N,"test");
            }
            if(choice == 2)
            {
                if(NewHorde == NULL)
                    std::cout << "\nhorde not created yet press 1 first\n\n";
                else
                {
                    for (int i = 0; i < N; ++i)
                    {
                        NewHorde[i].announce();
                    }
                    std::cout << std::endl << std::endl;
                }
            }
            if(choice == 3)
                break;
        }
        else
            std::cout << "Invalid choice type a number 1-3\n";
    }
    if(NewHorde != NULL)
        delete[] NewHorde;
    return(1);
}