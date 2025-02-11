#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:

		std::string	_name;
		int	_hitPoints;
		int	_energyPoints;
		int	_attackDamage;

	public:

		ClapTrap(void);	// Default constructor
		ClapTrap(ClapTrap const &src);	// Copy constructor
		ClapTrap(std::string name);
		~ClapTrap();	// Destructor

		ClapTrap &operator=(ClapTrap const &rhs);	// Copy assignment operator overload

		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif