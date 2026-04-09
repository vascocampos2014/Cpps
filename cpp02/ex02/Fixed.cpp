#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
}

Fixed::Fixed(const int nbr)
{
    this->value = nbr * 256;
}

Fixed::Fixed(const float nbr)
{
    this->value = roundf(nbr * 256);
}

Fixed::Fixed(const Fixed& name)
{
    this->value = name.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& name)
{
    if (this != &name)
        this->value = name.getRawBits();
    return(*this);
}

Fixed::~Fixed()
{

}

int Fixed::getRawBits(void) const
{
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

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2)
{
    if (obj1.value <= obj2.value)
        return(obj1);
    return(obj2);
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
    if (obj1.value <= obj2.value)
        return(obj1);
    return(obj2);
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2)
{
    if (obj1.value >= obj2.value)
        return(obj1);
    return(obj2);
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
    if (obj1.value >= obj2.value)
        return(obj1);
    return(obj2);
}

Fixed Fixed::operator--(int)
{
    Fixed old(*this);
    this->value -= 1;
    return(old);
}

Fixed& Fixed::operator--(void)
{
    this->value -= 1;
    return(*this);
}

Fixed Fixed::operator++(int)
{
    Fixed old(*this);
    this->value += 1;
    return(old);
}

Fixed& Fixed::operator++(void)
{
    this->value += 1;
    return(*this);
}

bool Fixed::operator==(const Fixed& name) const
{
    return(this->value == name.value);

}

bool Fixed::operator>=(const Fixed& name) const
{
    return(this->value >= name.value);
}

bool Fixed::operator<=(const Fixed& name) const
{
    return(this->value <= name.value);
}

bool Fixed::operator!=(const Fixed& name) const
{
    return(this->value != name.value);
}

bool Fixed::operator>(const Fixed& name) const
{
    return(this->value > name.value);
}

bool Fixed::operator<(const Fixed& name) const
{
    return(this->value < name.value);
}

Fixed Fixed::operator+(const Fixed& name) const
{
    Fixed after;
    after.setRawBits(this->value + name.value);
    return(after);
}

Fixed Fixed::operator-(const Fixed& name) const
{
    Fixed after;
    after.setRawBits(this->value - name.value);
    return(after);
}

Fixed Fixed::operator*(const Fixed& name) const
{
    Fixed after;
    after.setRawBits((this->value * name.value) / 256);
    return(after);
}

Fixed Fixed::operator/(const Fixed& name) const
{
    Fixed after;
    after.setRawBits((this->value * 256) / name.value);
    return(after);
}