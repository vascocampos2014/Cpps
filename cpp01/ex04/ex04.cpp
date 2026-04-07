#include "ex04.hpp"

std::string replaceNameFile(std::string fileName)
{
    fileName = fileName + ".replace";
    return(fileName);
}

std::string replaceContent(std::string Content, std::string S1, std::string S2)
{
    size_t pos = 0;
    while (Content.find(S1) != std::string::npos)
    {
        pos = Content.find(S1);
        std::string before = Content.substr(0, pos);
        std::string after = Content.substr(pos + S1.length());
        Content = before + S2 + after;
        pos += S2.length();
    }
    return(Content);
}