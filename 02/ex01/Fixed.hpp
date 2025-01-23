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

		Fixed &operator=(Fixed const &rhs);	// Copy assignment aoperator overload

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