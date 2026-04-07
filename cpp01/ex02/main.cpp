#include <iostream>

int main()
{
    std::string Text = "HI THIS IS BRAIN";
    std::string *PointerToText = &Text;
    std::string &RefToText = Text;

    std::cout << "Memory adresses\n\n";
    std::cout << "Memory of Text: " << &Text << std::endl;
    std::cout << "Memory of PointerToText: " << PointerToText << std::endl;
    std::cout << "Memory of RefToText: " << &RefToText << std::endl;
    std::cout << std::endl;
    std::cout << "Contents of variables\n\n";
    std::cout << "Data of Text: " << Text << std::endl;
    std::cout << "Data of PointerToText: " << *PointerToText << std::endl;
    std::cout << "Data of RefToText: " << RefToText << std::endl;
    return(1);
}