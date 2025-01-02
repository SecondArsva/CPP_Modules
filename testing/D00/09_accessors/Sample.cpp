#include <iostream>
#include "Sample.hpp"

Sample::Sample()
{
	std::cout << "Constructor called" << std::endl;

	this->Foo = 0;
	std::cout << "this->Foo = " << this->getFoo() << std::endl;

	return ;
}

Sample::~Sample()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int Sample::getFoo()const
{
	return (this->Foo);
}

void Sample::setFoo(int v)
{
	this->Foo = v;
	return ;
}