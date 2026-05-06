#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Contact.hpp"

class Phonebook {
private:
    Contact _contacts[8];
    int _index;
    std::string getCommand(void) const;
    std::string truncateString(std::string str, int width) const;

public:
    Phonebook();
    ~Phonebook();
    
    void run(void);
    void addContact(void);
    void searchContact(void);
};

#endif