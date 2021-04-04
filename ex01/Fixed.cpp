#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	// this->value = other.getRawBits();
}

Fixed::Fixed(const int inte)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = inte << Fixed::bits;
}

Fixed::Fixed(const float floa)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(floa * (1 << Fixed::bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << Fixed::bits));
}

int Fixed::toInt(void) const
{
	return (this->value >> Fixed::bits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
