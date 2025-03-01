#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->setType("Dog");
	this->_brain = new Brain();
}

Dog::Dog(Dog const &src) : AAnimal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = src.getType();
	this->_brain = new Brain(*src.getBrain());
}

Dog &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog copy assignment overloaded operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*rhs.getBrain());
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

void Dog::makeSound()const
{
	std::cout << "\"bark\"" << std::endl;
}

Brain *Dog::getBrain(void)const
{
	return (this->_brain);
}
std::string Dog::getIdeas(int const index)const
{
	return (this->getBrain()->getIdeas(index));
}

void Dog::setIdeas(int const index, std::string const idea)
{
	this->_brain->setIdeas(index, idea);
}
