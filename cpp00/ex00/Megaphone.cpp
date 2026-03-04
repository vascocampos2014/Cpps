#include <iostream>

int capitalize(char *s)
{
    int i = 0;
    while(s[i])
    {
        if (s[i] >= 97 && s[i] <= 122)
            std::cout << (char)(s[i] - 32);
        else
            std::cout << s[i];
        i++;
    }
    return(0);
}

int main(int argc, char **argv)
{
    int i = 1;
    int spaces = argc - 1;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return(0);
    }
    while (argv[i])
    {
        capitalize(argv[i]);
        if (spaces)
        {
            std::cout << " ";
            spaces--;
        }
        i++;
    }
    std::cout << std::endl;
    return(1);
}