#include <iostream>
#include "Sample1.hpp"

Sample1::Sample1()
{
	std::cout << "Struct constructor called" << std::endl;
	return ;
}

Sample1::~Sample1()
{
	std::cout << "Struct destructor called" << std::endl;
	return ;
}

void Sample1::bar()
{
	this->foo = 41;
	std::cout << "Struct member function called" << std::endl;
	std::cout << "Struct attribute this->foo = " << this->foo << std::endl;
}