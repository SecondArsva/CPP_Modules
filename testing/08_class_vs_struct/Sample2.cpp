#include <iostream>
#include "Sample2.hpp"

Sample2::Sample2()
{
	std::cout << "Class constructor called" << std::endl;
	return ;
}

Sample2::~Sample2()
{
	std::cout << "Class destructor called" << std::endl;
	return ;
}

void Sample2::bar()
{
	this->foo = 42;
	std::cout << "Class member function called" << std::endl;
	std::cout << "Class attribute this->foo = " << this->foo << std::endl;
}