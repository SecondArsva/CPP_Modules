#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap a;
	ScavTrap b("Axton");

	a = b;
	
	ScavTrap scavtrap(a);

	scavtrap.guardGate();
	scavtrap.attack("Badass Psycho");
	scavtrap.takeDamage(5);
	scavtrap.takeDamage(4);
	scavtrap.beRepaired(9);
	scavtrap.attack("Badass Psycho");
	scavtrap.attack("Badass Psycho");
	scavtrap.attack("Badass Psycho");
	scavtrap.attack("Badass Psycho");
	scavtrap.attack("Badass Psycho");
	scavtrap.attack("Badass Psycho");
	scavtrap.attack("Badass Psycho");
	scavtrap.attack("Badass Psycho");
	scavtrap.attack("Badass Psycho");
	scavtrap.beRepaired(1);
	scavtrap.takeDamage(52);
	scavtrap.attack("Badass Psycho");
	scavtrap.beRepaired(100);
	scavtrap.takeDamage(999);

	return (0);
}
