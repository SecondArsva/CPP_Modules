#ifndef FIXED_HPP
# define  FIXED_HPP

#include <iostream>

class Fixed
{
	public:

		Fixed(void);							// Default Constructor - Orthodox Canonical Class
		Fixed(int const n);						// Constructor overload to set a value ussing parameters
		Fixed(Fixed const &src);				// Copy Constructor - Orthodox Canonical Class
		Fixed &operator=(Fixed const &rhs);		// Copy Assignment Operator Overload - Orthodox Canonical Class
		~Fixed(void);							// Destructor - Orthodox Canonical Class

		int		getRawBits(void)const;
		void	setRawBits(int const raw);

	private:

		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
};

#endif