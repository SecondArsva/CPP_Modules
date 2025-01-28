#include "Fixed.hpp"

// Default constructor
Fixed::Fixed():_fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(Fixed const &src)
{	
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Int constructor
Fixed::Fixed(int const value):_fixedPointValue(value)
{
	std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = value << this->_fractionalBits;
}

// Float constructor
Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator overload
Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return (*this);
}

// --- Comparison operators ---
bool	Fixed::operator>(Fixed const &rhs)const
{
	return (this->_fixedPointValue > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs)const
{
	return (this->_fixedPointValue < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs)const
{
	return (this->_fixedPointValue >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs)const
{
	return (this->_fixedPointValue <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs)const
{
	return (this->_fixedPointValue == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs)const
{
	return (this->_fixedPointValue != rhs.getRawBits());
}

// --- Arithmetic operators ---
Fixed Fixed::operator+(Fixed const &rhs)const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rhs)const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const &rhs)const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rhs)const
{
	if (rhs.getRawBits() == 0)
	{
		std::cout << "Error: Division by zero!" << std::endl;
		return (Fixed());
	}
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

// --- Post/pre - increment/decrement operators ---
Fixed &Fixed::operator++()		// Pre-increment
{
	this->_fixedPointValue++;	// Incrementa el valor interno
	return (*this);				// Devuelve una referencia al objeto actualizado
}

Fixed Fixed::operator++(int)	// Post-increment
{
	Fixed temp(*this);			// Crea una copia del estado actual (valor antes de incrementar)
	this->_fixedPointValue++;	// Incrementa el valor interno
	return (temp);				// Devuelve la copia (estado previo al incremento)
}

Fixed &Fixed::operator--()		// Pre-decrement
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int)	// Post-decrement
{
	Fixed temp(*this);
	this->_fixedPointValue--;
	return (temp);
}

// Static member functions
// Ternaries (?:)
// (if_condition_is_true) ? return_this_value : else_return_this_other
Fixed const &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return ((a < b) ? a : b);
}

Fixed const &Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return ((a > b) ? a : b);
}

// --- Member Functions ---
int 	Fixed::getRawBits(void)const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

int		Fixed::toInt(void)const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

float	Fixed::toFloat(void)const
{
	return ((float)(this->_fixedPointValue) / (1 << _fractionalBits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();
    return (out);
}
