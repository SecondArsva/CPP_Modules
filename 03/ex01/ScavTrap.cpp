#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}



ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
	std::cout << "ScavTrap name overloaded constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	if (this->_hitPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " its already dead" << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " has no energy to attack" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attackDamage << " points of damage" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode!" << std::endl;
}