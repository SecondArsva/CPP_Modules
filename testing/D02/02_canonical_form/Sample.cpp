#include "Sample.hpp"
#include <iostream>

Sample::Sample(void):_foo(0)
{
	std::cout << "Default Constructor called" << std::endl;
	
	return ;
}

Sample::Sample(int const n):_foo(n)
{
	std::cout << "Parametric Constructor called" << std::endl;
	
	return ;
}

Sample::Sample(Sample const &src)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this=src;

	return ;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	
	return ;
}

int Sample::getValue(void)const
{
	return (this->_foo);
}

Sample &Sample::operator=(Sample const &src)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_foo = src.getValue();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Sample const &i)
{
        o << "The value of _foo is: " << i.getValue();
        return (o);
}
