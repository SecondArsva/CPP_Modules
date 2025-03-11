#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->_name << " name overloaded constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	std::cout << "FragTrap " << this->_name << " copy constructor called" << std::endl;
	*this = src;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "FragTrap " << this->_name << " copy assignment operator called" << std::endl;
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

/*void FragTrap::attack(std::string const &target) // smeixoei advice
{
	if (this->_hitPoints <= 0)
		std::cout << "FragTrap " << this->_name << " its already dead" << std::endl;
		else if (this->_energyPoints <= 0)
		std::cout << "FragTrap " << this->_name << " has no energy to attack" << std::endl;
		else
		{
			this->_energyPoints--;
			std::cout << "FragTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_attackDamage << " points of damage" << std::endl;
		}
	}	
*/

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " raise its hand waiting for a 'high five'" << std::endl;
}