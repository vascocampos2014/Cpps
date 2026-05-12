#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const int nbr)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = nbr * 256;
}

Fixed::Fixed(const float nbr)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(nbr * 256);
}

Fixed::Fixed(const Fixed& name)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = name.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& name)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &name)
        this->value = name.getRawBits();
    return(*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called\n";
    return(this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

int Fixed::toInt(void) const
{
    return(this->value / 256);
}

float Fixed::toFloat(void) const
{
    return((float)this->value / 256);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& name)
{
    stream << name.toFloat();
    return(stream);
}