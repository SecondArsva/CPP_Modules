#include <iostream>
#include "Sample.hpp"

Sample::Sample()
{
	std::cout << "Constructor called" << std::endl;

	std::cout << "Directly from the Sample class" << std::endl;

	this->publicFoo = 0;
	std::cout << "this->publicFoo = " << this->publicFoo << std::endl;
	this->_privateFoo = 0;
	std::cout << "this->_privateFoo = " << this->_privateFoo << std::endl;
	
	this->publicBar();
	this->_privateBar();

	return ;
}

Sample::~Sample()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void Sample::publicBar()const
{
	std::cout << "Member function publicBar called" << std::endl;
}

void Sample::_privateBar()const
{
	std::cout << "Member function _privateBar called" << std::endl;
}