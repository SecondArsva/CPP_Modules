#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
class Fixed
{
	public:

		Fixed();					// Default constructor
		Fixed(Fixed const &src);	// Copy constructor
		Fixed(int const value);		// Overload constructor, takes int
		Fixed(float const value);	// Overload constructor, takes float
		~Fixed();					// Destructor

		Fixed	&operator=(Fixed const &rhs);	// Copy assignment aoperator overload

		// Comparison operators
		bool	operator>(Fixed const &rhs)const;
		bool	operator<(Fixed const &rhs)const;
		bool	operator>=(Fixed const &rhs)const;
		bool	operator<=(Fixed const &rhs)const;
		bool	operator==(Fixed const &rhs)const;
		bool	operator!=(Fixed const &rhs)const;

		// Arithmetic operators
		Fixed	operator+(Fixed const &rhs)const;
		Fixed	operator-(Fixed const &rhs)const;
		Fixed	operator*(Fixed const &rhs)const;
		Fixed	operator/(Fixed const &rhs)const;

		// Post/pre - increment/decrement operators
		Fixed &operator++();     // Pre-increment
    	Fixed operator++(int);   // Post-increment
    	Fixed &operator--();     // Pre-decrement
    	Fixed operator--(int);   // Post-decrement

		// Faltan las cuatro funciones miembro raras del min max const 

		int 	getRawBits(void)const;		// Non-processed value getter
		void	setRawBits(int const raw);	// Non-processed value setter
		
		int		toInt(void)const;	// Converts to int		
		float	toFloat(void)const;	// Converts to float

	private:

		int					_fixedPointValue;
		int static const	_fractionalBits = 8;

};

std::ostream &operator<<(std::ostream &out, Fixed const &rhs);

#endif