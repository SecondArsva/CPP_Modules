#include "HumanB.hpp"

// Inicialización del puntero "_weapon" a NULL mediante una lista de inicialización.
HumanB::HumanB():_weapon(NULL){}

HumanB::HumanB(std::string name)
{
	this->setName(name);
}

void	HumanB::attack(void)
{
	std::cout << this->getName() << " attacks with their " << this->getWeapon()->getType() << std::endl;
}

void	HumanB::setName(std::string name)
{
	this->_name = name;
}

std::string	HumanB::getName(void)const
{
	return (this->_name);
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

Weapon *HumanB::getWeapon(void)const
{
	return (this->_weapon);
}

HumanB::~HumanB(){}
