#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class Contact {
public:
    std::string PhoneNumber;
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string DarkestSecret;
};

class Phonebook {
public:
    Contact contacts[8];
    int index;
};