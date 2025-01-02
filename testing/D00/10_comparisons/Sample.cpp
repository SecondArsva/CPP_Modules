#include <iostream>
#include "Sample.hpp"

Sample::Sample(int v)
{
	std::cout << "Constructor called" << std::endl;
	
	this->_foo = v;
	
	return ;
}

Sample::~Sample()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Sample::getFoo(void)const
{
	return (this->_foo);
}

int Sample::compareFoo(Sample *other)const
{
	if (this->_foo < other->_foo)
		return (-1);
	else if (this->_foo > other->_foo)
		return (1);
	return (0);
}