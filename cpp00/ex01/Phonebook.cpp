#include "Phonebook.hpp"
#include <limits>
#include <cctype>

Phonebook::Phonebook() : _index(0)
{
}

Phonebook::~Phonebook()
{
}

std::string Phonebook::getCommand(void) const
{
    std::string command;

    std::cout << "\nYOUR PHONEBOOK\n\n[ADD] Add a contact\n[SEARCH] Search a contact\n[EXIT] Exit\n";
    while (1)
    {
        std::cout << "\nType your Operation: ";
        if (!std::getline(std::cin, command))
            std::exit(0);
        if (command == "ADD" || command == "SEARCH" || command == "EXIT")
            break;
        std::cout << "Operation doesn't exist.";
    }
    return command;
}

std::string Phonebook::truncateString(std::string str, int width) const
{
    if (str.length() > (unsigned int)width)
        return str.substr(0, width - 1) + ".";
    return str;
}

void Phonebook::run(void)
{
    std::string command;

    while (1)
    {
        command = getCommand();
        if (command == "ADD")
            addContact();
        else if (command == "SEARCH")
            searchContact();
        else if (command == "EXIT")
            std::exit(0);
    }
}

void Phonebook::addContact(void)
{
    static int totalAdded = 0;
    int slot = totalAdded % 8;
    std::string input;

    std::cout << "\nFirst name: ";
    std::getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "Field cannot be empty. Please enter first name: ";
        std::getline(std::cin, input);
    }
    _contacts[slot].setFirstName(input);

    std::cout << "Last name: ";
    std::getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "Field cannot be empty. Please enter last name: ";
        std::getline(std::cin, input);
    }
    _contacts[slot].setLastName(input);

    std::cout << "Nickname: ";
    std::getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "Field cannot be empty. Please enter nickname: ";
        std::getline(std::cin, input);
    }
    _contacts[slot].setNickName(input);

    while (1)
    {
        std::cout << "Phone number (9 digits): ";
        std::getline(std::cin, input);
        
        if (input.empty())
        {
            std::cout << "Invalid phone number. Please enter exactly 9 digits." << std::endl;
            continue;
        }
        bool allDigits = true;
        for (std::string::size_type i = 0; i < input.length(); ++i)
        {
            if (!std::isdigit(static_cast<unsigned char>(input[i])))
            {
                allDigits = false;
                break;
            }
        }
        
        if (allDigits && input.length() == 9)
        {
            _contacts[slot].setPhoneNumber(input);
            break;
        }
        std::cout << "Invalid phone number. Please enter exactly 9 digits." << std::endl;
    }

    std::cout << "Darkest secret: ";
    std::getline(std::cin, input);
    while (input.empty())
    {
        std::cout << "Field cannot be empty. Please enter darkest secret: ";
        std::getline(std::cin, input);
    }
    _contacts[slot].setDarkestSecret(input);

    totalAdded++;
    if (_index < 8)
        _index++;

    std::cout << "Contact added successfully" << std::endl;
}

void Phonebook::searchContact(void)
{
    if (_index == 0)
    {
        std::cout << "No contacts saved." << std::endl;
        return;
    }

    std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;

    int i = 0;
    while(i < _index)
    {
        std::cout << "|" << std::setw(10) << std::right << (i + 1);
        std::cout << "|" << std::setw(10) << std::right << truncateString(_contacts[i].getFirstName(), 10);
        std::cout << "|" << std::setw(10) << std::right << truncateString(_contacts[i].getLastName(), 10);
        std::cout << "|" << std::setw(10) << std::right << truncateString(_contacts[i].getNickName(), 10);
        std::cout << "|" << std::endl;
        i++;
    }

    int indexToDisplay = -1;
    std::cout << "\nEnter contact index to display: ";
    if (!(std::cin >> indexToDisplay))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index." << std::endl;
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (indexToDisplay < 1 || indexToDisplay > _index)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    int contactIdx = indexToDisplay - 1;
    std::cout << "\n--- Contact #" << indexToDisplay << " ---" << std::endl;
    std::cout << "First Name: " << _contacts[contactIdx].getFirstName() << std::endl;
    std::cout << "Last Name: " << _contacts[contactIdx].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[contactIdx].getNickName() << std::endl;
    std::cout << "Phone Number: " << _contacts[contactIdx].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << _contacts[contactIdx].getDarkestSecret() << std::endl;
}
