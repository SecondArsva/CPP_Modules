#include "Fixed.hpp"

// Default Constructor
Fixed::Fixed():_fixedPointValue(0)
{
	std::cout << "Default constuctor called" << std::endl;
}

// Copy Constructor
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy destructor called" << std::endl;
	*this = src;
}

// Copy assignment operator overload
Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destuctor called" << std::endl;
}

// Getter
int Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

// Setter
void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}