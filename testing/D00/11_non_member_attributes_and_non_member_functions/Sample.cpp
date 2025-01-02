#include <iostream>
#include "Sample.hpp"

Sample::Sample()
{
	std::cout << "Constructor called" << std::endl;

	Sample::_nbFoo += 1;

	return ;
}

Sample::~Sample()
{
	std::cout << "Destructor called" << std::endl;
	
	Sample::_nbFoo -= 1;
	
	return ;
}

int Sample::getNbInst(void)
{
	return (Sample::_nbFoo);
}

int Sample::_nbFoo = 0;