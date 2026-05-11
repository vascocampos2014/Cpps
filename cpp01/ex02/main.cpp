#include <iostream>

int main()
{
    std::string Text = "HI THIS IS BRAIN";
    std::string *stringPTR = &Text; // this pointer will point to the address of Text if you change stringPTR it would change the string inside Text
    std::string &stringREF = Text; // this is a reference to Text, it creates an alias of Text if i change stringREF it would change the data inside Text

    std::cout << "Memory adresses\n\n";
    std::cout << "Memory of Text: " << &Text << std::endl;
    std::cout << "Memory of stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory of stringREF: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "Contents of variables\n\n";
    std::cout << "Data of Text: " << Text << std::endl;
    std::cout << "Data of stringPTR: " << *stringPTR << std::endl;
    std::cout << "Data of stringREF: " << stringREF << std::endl;
    return (0);
}