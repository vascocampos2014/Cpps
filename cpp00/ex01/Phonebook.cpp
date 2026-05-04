#include "Phonebook.hpp"
#include <limits>
#include <algorithm>
#include <cctype>
#include <sstream>

// operador >> extrai a data(token) de uma variavel para outra. so pode ser usado com cin ou string streams types.
/*
por exemplo:
std::string input;
cin >> input; "input foi 123"
std::istringstream iss(input);
std::string line;
iss >> line; "line agr é 123 e input nao tem nada";
*/

int menu()
{
    int choice = 0;
    std::string line;

    std::cout << "\nYOUR PHONEBOOK\n\n[1] ADD CONTACT\n[2] SEARCH CONTACT\n[3] EXIT\n";
    while (1)
    {
        std::cout << "\nType your Operation:";
        if (!std::getline(std::cin, line))
            std::exit(0);
        std::istringstream iss(line);
        char extra;
        if ((iss >> choice) && !(iss >> extra) && (choice == 1 || choice == 2 || choice == 3))
            break;
        std::cout << "\nOperation doesnt exist.";
    }
    return(choice);
}

int AddContact(Phonebook &phonebook)
{
    static int total_added = 0;
    int slot = total_added % 8;

    std::cout << "\nFirst name:";
    std::getline(std::cin, phonebook.contacts[slot].FirstName);
    while (phonebook.contacts[slot].FirstName.empty())
    {
        std::cout << "\nField cannot be empty. Please enter first name: ";
        std::getline(std::cin, phonebook.contacts[slot].FirstName);
    }

    std::cout << "\nLast name:";
    std::getline(std::cin, phonebook.contacts[slot].LastName);
    while (phonebook.contacts[slot].LastName.empty())
    {
        std::cout << "\nField cannot be empty. Please enter last name: ";
        std::getline(std::cin, phonebook.contacts[slot].LastName);
    }

    std::cout << "\nNickname:";
    std::getline(std::cin, phonebook.contacts[slot].NickName);
    while (phonebook.contacts[slot].NickName.empty())
    {
        std::cout << "\nField cannot be empty. Please enter nickname: ";
        std::getline(std::cin, phonebook.contacts[slot].NickName);
    }

    while (1)
    {
        std::cout << "\nPhone number:";
        std::string num;
        std::getline(std::cin, num);
        
        if (num.empty())
        {
            std::cout << "Invalid phone number. Please enter exactly 9 digits." << std::endl;
            continue;
        }
        bool all_digits = true;
        for (std::string::size_type i = 0; i < num.length(); ++i)
        {
            if (!std::isdigit(static_cast<unsigned char>(num[i])))
            {
                all_digits = false;
                break;
            }
        }
        
        if (all_digits && num.length() == 9)
        {
            phonebook.contacts[slot].PhoneNumber = num;
            break;
        }
        std::cout << "Invalid phone number. Please enter exactly 9 digits." << std::endl;
    }

    std::cout << "\nDarkest secret:";
    std::getline(std::cin, phonebook.contacts[slot].DarkestSecret);
    while (phonebook.contacts[slot].DarkestSecret.empty())
    {
        std::cout << "\nField cannot be empty. Please enter darkest secret: ";
        std::getline(std::cin, phonebook.contacts[slot].DarkestSecret);
    }

    total_added++;
    if (phonebook.index < 8)
        phonebook.index++;

    std::cout << "Contact added successfully" << std::endl;
    return (1);
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
