#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>

class Fixed
{
    private:
        int value;
        static const int fractionalBits = 8;

    public:
        Fixed();
        Fixed(const Fixed& copy); //usado para copiar um objeto ja existente para um novo objeto
        Fixed& operator=(const Fixed& copy); //usado para dar overwrite a um objeto existente
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif