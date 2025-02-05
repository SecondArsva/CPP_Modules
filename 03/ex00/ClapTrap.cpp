#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):_name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::ClapTrap(std::string name):_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Name overloaded constructor called. Name: " << this->_name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is alredy dead" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has " << this->_energyPoints << " energy points. Can't attack." << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is alredy dead" << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage. Remaining HP of " << this->_name << ": " << this->_hitPoints << std::endl;
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " died" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is alredy dead" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has " << this->_energyPoints << " energy points. Can't be repaired." << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " repairs itself " << amount << " hit points. Total hit points: " << this->_hitPoints << std::endl;
}