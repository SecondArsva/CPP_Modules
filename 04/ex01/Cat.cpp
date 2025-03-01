#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->setType("Cat");
	this->_brain = new Brain();
}

Cat::Cat(Cat const &src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = src.getType();
	this->_brain = new Brain(*src.getBrain());
}

Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat copy assignment overloaded operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		if (this->_brain)  // Lieración de la memoria previa a la copia el cerebro
			delete this->_brain;
		this->_brain = new Brain(*rhs.getBrain()); // Copia profunda
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;  // Liberar memoria
}

void Cat::makeSound()const
{
	std::cout << "\"meow\"" << std::endl;
}

Brain *Cat::getBrain(void)const
{
	return (this->_brain);
}

/*	¿Debería usar getters y setters de los valores a los que la clase
	tiene acceso dentro del código de la clase en la que trabajo?
	No.
	
	Estos dos ejemplos son lo mismo dentro del archivo .cpp de la clase:
		- this->getBrain()->getIdeas(index);
		- this->_brain->getIdeas(index);
	*/
std::string Cat::getIdeas(int const index)const
{
	return (this->getBrain()->getIdeas(index));
}

void Cat::setIdeas(int const index, std::string const idea)
{
	this->_brain->setIdeas(index, idea);
}
