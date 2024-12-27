#include <iostream>
#include "Sample.hpp"

Sample::Sample(float const f) : pi(f), qd(42)
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample::~Sample()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

// A constant member function is set to read-only object mode,
// so the member attributes cant be modified.
void Sample::bar(void) const
{
	std::cout << "this->pi = " << this->pi << std::endl;
	std::cout << "this->qd = " << this->qd << std::endl;

	//this->qd = 0; // If try this, cant compile.

	return ;
}
