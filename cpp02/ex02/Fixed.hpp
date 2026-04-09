#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int value;
        static const int fracBits = 8;

    public:
        Fixed();
        Fixed(const int nbr);
        Fixed(const float nbr);
        Fixed(const Fixed& name);
        Fixed& operator=(const Fixed& name);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
        bool operator==(const Fixed& name) const;
        bool operator>=(const Fixed& name) const;
        bool operator<=(const Fixed& name) const;
        bool operator!=(const Fixed& name) const;
        bool operator>(const Fixed& name) const;
        bool operator<(const Fixed& name) const;
        Fixed operator+(const Fixed& name) const;
        Fixed operator*(const Fixed& name) const;
        Fixed operator/(const Fixed& name) const;
        Fixed operator-(const Fixed& name) const;
        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);
        static Fixed& min(Fixed& obj1, Fixed& obj2);
        static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
        static Fixed& max(Fixed& obj1, Fixed& obj2);
        static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
};

std::ostream& operator<<(std::ostream& stream, const Fixed& name);

#endif