#include "ex04.hpp"

int main(int ac, char **av)
{
    if(ac != 4 || !av[2] || av[2][0] == '\0')
        return(perror("invallid arguments"), 0);
    std::ifstream inFile(av[1]);
    if (!inFile.is_open())
        return (std::cerr << "Error: could not open file\n", 0);
    std::string content;
    std::getline(inFile, content, '\0');
    content = replaceContent(content, av[2], av[3]);
    std::ofstream outFile(replaceNameFile(av[1]).c_str());
    outFile << content;
    return(1);
}