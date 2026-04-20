#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "default constructor called\n";
    this->value = 0;
}

Fixed::~Fixed()
{
    std::cout << "destructor called\n";
}

Fixed::Fixed(const Fixed& name)
{
    std::cout << "copy constructor called\n";
    this->value = name.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& name)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &name)
        this->value = name.getRawBits();
    return(*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return(this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}
