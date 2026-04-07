#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class Zombie
{
    private:
            std::string _name;
    public:
        Zombie(std::string name);
        ~Zombie();
        void announce( void );
};