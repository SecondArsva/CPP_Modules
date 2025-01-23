#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;
	
	c = b;
	std::cout << "instance a: " << std::endl << a.getRawBits() << std::endl;
	std::cout << "instance b: " << std::endl << b.getRawBits() << std::endl;
	std::cout << "instance c: " << std::endl << c.getRawBits() << std::endl;

	return (0);
}