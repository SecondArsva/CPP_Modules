#ifndef INTEGER_HPP
# define INTEGER_HPP

# include <iostream>

class Integer
{
	public:

	Integer(int const n);
	~Integer();

	int	getValue(void)const;

	// C and C++ allows us to do this "a = b = c = d;"
	Integer &operator=(Integer const &rightHandSide);
	Integer operator+(Integer const &rightHandSide);

	private:

		int _n;
};

std::ostream &operator<<(std::ostream &o, Integer const &rightHandSide);
#endif
