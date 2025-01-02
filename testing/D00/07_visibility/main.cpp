#include <iostream>
#include "Sample.hpp"

int	main(void)
{

	Sample instance;

	std::cout << "Using an instance of Sample class" << std::endl;

	instance.publicFoo = 42;
	std::cout << "instance.publicFoo = " << instance.publicFoo << std::endl;
	instance.publicBar();
	
	// cant use private content from outside of the class, uncomment and try to compile it
	//instance._privateFoo = 42;
	//std::cout << "instance._privateFoo = " << instance._privateFoo << std::endl;
	//instance._privateBar();
	
	return (0);
}