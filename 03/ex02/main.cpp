#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap a;
	FragTrap b("Axton");

	a = b;
	
	FragTrap fragtrap(a);

	fragtrap.highFivesGuys();
	fragtrap.attack("Badass Psycho");
	fragtrap.takeDamage(5);
	fragtrap.takeDamage(4);
	fragtrap.beRepaired(9);
	fragtrap.attack("Badass Psycho");
	fragtrap.attack("Badass Psycho");
	fragtrap.attack("Badass Psycho");
	fragtrap.attack("Badass Psycho");
	fragtrap.attack("Badass Psycho");
	fragtrap.attack("Badass Psycho");
	fragtrap.attack("Badass Psycho");
	fragtrap.attack("Badass Psycho");
	fragtrap.attack("Badass Psycho");
	fragtrap.beRepaired(1);
	fragtrap.takeDamage(52);
	fragtrap.attack("Badass Psycho");
	fragtrap.beRepaired(100);
	fragtrap.takeDamage(999);

	return (0);
}
