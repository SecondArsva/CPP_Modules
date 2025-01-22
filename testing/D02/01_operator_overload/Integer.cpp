#include "Integer.hpp"
#include <iostream>

Integer::Integer(int const n)
{
	std::cout << "Constructor called with value " << n << std::endl;
	return ;
}

Integer::~Integer()
{
	std::cout << "Destructor called with value " << this->_n << std::endl;
	return ;
}

int Integer::getValue(void)const
{
	return (this->_n);
}

Integer &Integer::operator=(Integer const &rightHandSide)
{
	std::cout << "Assignation operator called from " << this->_n;
	std::cout << " to " << rightHandSide.getValue() << std::endl;

	this->_n = rightHandSide.getValue();

	return (*this);
}

Integer Integer::operator+(Integer const &rightHandSide)
{
	std::cout << "Addition operator called with " << this->_n;
	std::cout << " and " << rightHandSide.getValue() << std::endl;

	return (Integer(this->_n + rightHandSide.getValue()));;
}

std::ostream &operator<<(std::ostream &o, Integer const &rightHandSide)
{
	o << rightHandSide.getValue();
	return (o);
}