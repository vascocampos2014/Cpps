#include "Harl.hpp"

void Harl::info(void)
{
    std::cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void)
{
    std::cout << "[WARNING]: I think I deserve to have some extra bacon for free. I’ve been coming foryears, whereas you started working here just last month.\n";
}

void Harl::error(void)
{
    std::cout << "[ERROR]: This is unacceptable! I want to speak to the manager now\n";
}

void Harl::debug(void)
{
    std::cout << "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for (size_t i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            (this->*functions[i])();
    }
}