#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Unknown")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src) : _type("Unknown")
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
	std::cout << "AAnimal copy assignment overloaded operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

void AAnimal::makeSound()const
{
	std::cout << "An unknown animal makes a sound" << std::endl;
}

std::string	AAnimal::getType()const
{
	return (this->_type);
}

void AAnimal::setType(std::string type)
{
	this->_type = type;
}