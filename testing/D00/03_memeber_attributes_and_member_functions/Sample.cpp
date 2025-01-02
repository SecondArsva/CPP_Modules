#include <iostream>
#include "Sample.hpp"

Sample::Sample()
{
	std::cout << "Hi, Im the Constructor" << std::endl;
	return ;
}

Sample::~Sample()
{
	std::cout << "Hi, Im the Destructor" << std::endl;
	return ;
}

void Sample::bar(void)
{
	std::cout << "Member Function bar called" << std::endl;
	return ;
}