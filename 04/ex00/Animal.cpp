#include "Animal.hpp"

Animal::Animal() : _type("Unknown")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &src) : _type("Unknown")
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal copy assignment overloaded operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound()const
{
	std::cout << "An unknown animal makes a sound" << std::endl;
}

std::string	Animal::getType()const
{
	return (this->_type);
}

void Animal::setType(std::string type)
{
	this->_type = type;
}
