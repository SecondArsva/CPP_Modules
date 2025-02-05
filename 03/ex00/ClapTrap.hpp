#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <string>

class ClapTrap
{
	private:

		std::string	_name;
		int			_hitPoints = 10;
		int			_energyPoints = 10;
		int			_attackDamage = 0;
	public:

		ClapTrap(void);	// Default constructor
		ClapTrap(ClapTrap const &src);	// Copy constructor
		ClapTrap(std::string name);
		~ClapTrap();	// Destructor

		ClapTrap &operator=(ClapTrap const &rhs);	// Copy assignment operator overload

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		// getters & setters
		std::string	getName(void);
		void		setName(std::string name);
		
		int		getHitPoints(void);
		void	setHitPoints(int value);
		
		int		getEnergyPoints(void);
		void	setEnergyPoints(int value);
		
		int		getAttackDamage(void);
		void	setAttackDamage(int value);
};

#endif