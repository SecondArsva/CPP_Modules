#include <iostream>
#include "Sample.hpp"

Sample::Sample()
{
	std::cout << "Constructor called" << std::endl;
	
	this->foo = 42;
	std::cout << "this->foo: " << this->foo << std::endl;
	this->bar();
	return ;
}

Sample::~Sample()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void Sample::bar()
{
	std::cout << "Member function bar called" << std::endl;
	return ;
}