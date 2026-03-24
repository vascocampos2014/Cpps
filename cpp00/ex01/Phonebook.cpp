#include "Phonebook.hpp"
#include <limits>

int menu()
{
    int choice = 0;
    std::cout << "\nYOUR PHONEBOOK\n\n[1] ADD CONTACT\n[2] SEARCH CONTACT\n[3] EXIT\n";
    std::cout << "\nType your Operation:";
    while  (1)
    {
        if ((std::cin >> choice) && (choice == 1 || choice == 2 || choice == 3))
            break;
        std::cin.clear();
        std::cin.ignore();
        std::cout << "\nOperation doesnt exist.\nTry Again:";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return(choice);
}

int AddContact(Phonebook &phonebook)
{
    std::string Input;
    std::cout << "\nFirst name:";
    std::cin >> phonebook.contacts[phonebook.index].FirstName;
    std::cout << "\nLast name:";
    std::cin >> phonebook.contacts[phonebook.index].LastName;
    std::cout << "\nNickname:";
    std::cin >> phonebook.contacts[phonebook.index].NickName;
    std::cin.ignore();
    std::cout << "\nDarkest secret:";
    std::getline(std::cin, phonebook.contacts[phonebook.index].DarkestSecret);
    phonebook.index++;
    std::cout << "Contact added successfully" << std::endl;
    return(1);
}

std::string truncateString(std::string str, int width)
{
    if (str.length() > (unsigned int)width)
        return str.substr(0, width - 1) + ".";
    return str;
}

int SearchPhonebook(Phonebook phonebook)
{
    if (phonebook.index == 0)
    {
        std::cout << "No contacts saved." << std::endl;
        return(0);
    }

    std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;

    int i = 0;
    while(i < phonebook.index)
    {
        std::cout << "|" << std::setw(10) << std::right << (i + 1);
        std::cout << "|" << std::setw(10) << std::right << truncateString(phonebook.contacts[i].FirstName, 10);
        std::cout << "|" << std::setw(10) << std::right << truncateString(phonebook.contacts[i].LastName, 10);
        std::cout << "|" << std::setw(10) << std::right << truncateString(phonebook.contacts[i].NickName, 10);
        std::cout << "|" << std::endl;
        i++;
    }

    int index_to_display = -1;
    std::cout << "\nEnter contact index to display: ";
    if (!(std::cin >> index_to_display))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index." << std::endl;
        return(0);
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (index_to_display < 1 || index_to_display > phonebook.index)
    {
        std::cout << "Invalid index." << std::endl;
        return(0);
    }

    int contact_idx = index_to_display - 1;
    std::cout << "\n--- Contact #" << index_to_display << " ---" << std::endl;
    std::cout << "First Name: " << phonebook.contacts[contact_idx].FirstName << std::endl;
    std::cout << "Last Name: " << phonebook.contacts[contact_idx].LastName << std::endl;
    std::cout << "Nickname: " << phonebook.contacts[contact_idx].NickName << std::endl;
    std::cout << "Phone Number: " << phonebook.contacts[contact_idx].PhoneNumber << std::endl;
    std::cout << "Darkest Secret: " << phonebook.contacts[contact_idx].DarkestSecret << std::endl;

    return(0);
}

void Exit()
{
    std::exit(0);
}

int main()
{
    int choice = 0;
    Phonebook phonebook;
    phonebook.index = 0;
    while(1)
    {
        choice = menu();
        if(choice == 1)
            AddContact(phonebook);
        if(choice == 2)
            SearchPhonebook(phonebook);
        if(choice == 3)
            Exit();
    }
    return(0);
}
