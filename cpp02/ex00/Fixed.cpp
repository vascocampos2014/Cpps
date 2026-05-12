#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}
