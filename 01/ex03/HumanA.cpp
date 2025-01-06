#include "HumanA.hpp"

//HumanA::HumanA(){}

/* Las referencias deben inicializarse en el momento de la construcción,
   ya que no pueden ser reasignadas posteriormente. */
HumanA::HumanA(std::string name, Weapon &weapon):_weapon(weapon)
{
	this->setName(name);
}

void	HumanA::attack(void)
{
	std::cout << this->getName() << " attacks with their " << this->getWeapon().getType() << std::endl;
}

void	HumanA::setName(std::string name)
{
	this->_name = name;
}

std::string	HumanA::getName(void)const
{
	return (this->_name);
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->_weapon = weapon;
}

Weapon HumanA::getWeapon(void)const
{
	return (this->_weapon);
}

HumanA::~HumanA(){}
