#include "Zombie.hpp"

void		Zombie::setName(std::string name)
{
	this->_name = name;
}

std::string Zombie::getName(void)const
{
	return (this->_name);
}

void Zombie::announce()const
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(){}

Zombie::Zombie(std::string name)
{
	this->setName(name);
}

Zombie::~Zombie()
{
	std::cout << this->getName() << " was lobotomized" << std::endl;
}