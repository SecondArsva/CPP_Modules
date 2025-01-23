#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	{
		Fixed	a;
		Fixed	b(a);
		Fixed	c;

		c = b;
		std::cout << "instance a: " << a.getRawBits() << std::endl;
		std::cout << "instance b: " << b.getRawBits() << std::endl;
		std::cout << "instance c: " << c.getRawBits() << std::endl;
		// El ex00 termina aquí.
	}
	{
		// El subject no requiere crear un constructor sobrecargado,
		// pero a mi me apetece implentarlo.
		std::cout << std::endl << "	--- Constructor Overload ---" << std::endl;
		Fixed	d(42);
		Fixed	e;
		Fixed	f(d);

		std::cout << "instance d: " << d.getRawBits() << std::endl;
		std::cout << "instance e: " << e.getRawBits() << std::endl;
		std::cout << "instance f: " << f.getRawBits() << std::endl;
		std::cout << std::endl;
		e = d;
		std::cout << "instance e: " << e.getRawBits() << std::endl;
	}
	return (0);
}