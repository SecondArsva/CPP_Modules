#include <iostream>
#include "Sample.hpp"

int main(void)
{
	Sample instance;

	instance.setFoo(42);
	std::cout << "instance.Foo = " << instance.getFoo() << std::endl;
	instance.setFoo(-88);
	std::cout << "instance.Foo = " << instance.getFoo() << std::endl;
	return (0);
}
